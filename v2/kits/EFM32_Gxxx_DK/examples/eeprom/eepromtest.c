/**************************************************************************//**
 * @file
 * @brief EEPROM example for EFM32_G8xx_DK
 * @details
 *   Read/write data to EEPROM on DVK.
 *
 * @par Usage
 * @li Joystick Up/Down increases/decreases data stored in first 3 bytes.
 *       of EEPROM.
 *
 * @note
 *   This example requires BSP version 1.0.6 or later.
 *
 * @version 3.20.5
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#include <string.h>
#include <stdlib.h>
#include "em_device.h"
#include "em_emu.h"
#include "em_dbg.h"
#include "em_gpio.h"
#include "em_chip.h"
#include "bsp.h"
#include "bsp_trace.h"
#include "segmentlcd.h"
#include "rtcdrv.h"
#include "i2cdrv.h"
#include "eeprom.h"

/** Interrupt pin used to detect joystick activity */
#define GPIO_INT_PIN 14

/** Byte stored in first 3 bytes of EEPROM */
static volatile uint8_t eepromData;

/** Reset first 3 bytes of EEPROM to 0xFF */
static volatile bool eepromReset = false;

/* Local prototypes */
void eepromtestIRQInit(void);
void eepromtestUpdateLCD(uint8_t *data);

/**************************************************************************//**
 * @brief GPIO Interrupt handler
 * This interrupt handler is not an example of good design, as it will do
 * a lot of operations inside the interrupt handler.
 *****************************************************************************/
void GPIO_EVEN_IRQHandler(void)
{
  uint16_t joystick;
  uint16_t pb;

  /* Clear interrupt */
  BSP_InterruptFlagsClear(BC_INTEN_JOYSTICK);
  BSP_InterruptFlagsClear(BC_INTEN_PB);
  GPIO_IntClear(1 << GPIO_INT_PIN);

  /* LEDs on to indicate joystick used */
  BSP_LedsSet(0xffff);

  /* Read and store joystick activity - wait for key release */
  joystick = BSP_JoystickGet();
  while (BSP_JoystickGet());

  /* Read and store pushbutton activity - wait for key release */
  pb = BSP_PushButtonsGet();
  while (BSP_PushButtonsGet());

  /* LEDs off to indicate joystick release */
  BSP_LedsSet(0x0000);

  /* Up increases data to store in EEPROM */
  if (joystick & BC_JOYSTICK_UP)
  {
    eepromData++;
  }

  /* Down decreases data to store in EEPROM */
  if (joystick & BC_JOYSTICK_DOWN)
  {
    eepromData--;
  }

  /* Reset modified data to factory default */
  if (pb & BC_PUSHBUTTON_SW4)
  {
    eepromReset = true;
  }
}


/**************************************************************************//**
 * @brief Initialize GPIO interrupt for joystick (ie FPGA signal)
 *****************************************************************************/
void eepromtestIRQInit(void)
{
  /* Configure interrupt pin as input with pull-up */
  GPIO_PinModeSet(gpioPortC, GPIO_INT_PIN, gpioModeInputPull, 1);

  /* Set falling edge interrupt and clear/enable it */
  GPIO_IntConfig(gpioPortC, GPIO_INT_PIN, false, true, true);

  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
}


/**************************************************************************//**
 * @brief Update LCD with data stored
 * @param[in] data Data to dispaly in hex.
 *****************************************************************************/
void eepromtestUpdateLCD(uint8_t *data)
{
  char text[8];
  int i;
  int j;
  uint32_t tmp;

  /* Show Gecko if debugger is attached. Energy modes do not behave as */
  /* expected when using the debugger. */
  if (DBG_Connected())
  {
    SegmentLCD_Symbol(LCD_SYMBOL_GECKO, 1);
  }
  else
  {
    SegmentLCD_Symbol(LCD_SYMBOL_GECKO, 0);
  }

  memset(text, ' ', sizeof(text) - 1);
  text[sizeof(text) - 1] = 0;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 2; j++)
    {
      tmp = (data[i] >> (4 * (1 - j))) & 0xf;
      if (tmp > 9)
      {
        text[(i*2) + j] = 'A' + (char)tmp - 10;
      }
      else
      {
        text[(i*2) + j] = '0' + (char)tmp;
      }
    }
  }

  SegmentLCD_Write(text);
}


/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
  I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
  uint8_t data[3];

  /* Chip revision alignment and errata fixes */
  CHIP_Init();

  /* Initialize DVK board register access */
  BSP_Init(BSP_INIT_DEFAULT);

  /* If first word of user data page is non-zero, enable eA Profiler trace */
  BSP_TraceProfilerSetup();

  /* Initialize LCD controller without boost */
  SegmentLCD_Init(false);

  SegmentLCD_AllOff();

  /* Enable board control interrupts */
  BSP_InterruptDisable(0xffff);
  BSP_InterruptFlagsClear(0xffff);
  BSP_InterruptEnable(BC_INTEN_JOYSTICK);
  BSP_InterruptEnable(BC_INTEN_PB);
  eepromtestIRQInit();

  /* Initialize I2C driver, using standard rate. Devices on DVK itself */
  /* supports fast mode, but in case some slower devices are added on */
  /* prototype board, we use standard mode. */
  I2CDRV_Init(&i2cInit);

  /* Main loop - just read data and update LCD */
  while (1)
  {
    /* Should data be reset to factory default? */
    if (eepromReset)
    {
      eepromReset = false;

      /* Data changed by user? */
      data[0] = 0xFF;
      data[1] = 0xFF;
      data[2] = 0xFF;
      if (EEPROM_Write(I2C0, EEPROM_DVK_ADDR, 0, data, 3) < 0)
      {
        SegmentLCD_Write("RST ERR");
        /* Enter EM2, no wakeup scheduled */
        EMU_EnterEM2(true);
      }
    }

    if (EEPROM_Read(I2C0, EEPROM_DVK_ADDR, 0, data, 3) < 0)
    {
      SegmentLCD_Write("RD ERR");
      /* Enter EM2, no wakeup scheduled */
      EMU_EnterEM2(true);
    }

    eepromData = data[0];
    eepromtestUpdateLCD(data);

    /* Just enter EM2 until joystick pressed */
    EMU_EnterEM2(true);

    /* Data changed by user? */
    if (eepromData != data[0])
    {
      data[0] = eepromData;
      data[1] = eepromData + 1;
      data[2] = eepromData + 2;
      if (EEPROM_Write(I2C0, EEPROM_DVK_ADDR, 0, data, 3) < 0)
      {
        SegmentLCD_Write("WR ERR");
        /* Enter EM2, no wakeup scheduled */
        EMU_EnterEM2(true);
      }
    }
  }
}
