/*****************************************************************************
 * @file main_dac_signal_generator_gg.c
 * @brief Digital to Analog converter, signal generator example
 * @author Silicon Labs
 * @version 1.11
 * @note
 *   WARNING: Do not attach or use headphones with this example. Use small
 *   loadspeakers with built in amplification, ensuring volume is at an
 *   acceptable level. Exposure to loud noises from any source for extended
 *   periods of time may temporarily or permanently affect your hearing. The
 *   louder the volume sound level, the less time is required before your
 *   hearing could be affected. Hearing damage from loud noise is sometimes
 *   undetectable at first and can have a cumulative effect. 
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Silicon Labs has no
 * obligation to support this Software. Silicon Labs is providing the
 * Software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Silicon Labs will not be liable for any consequential, incidental, or
 * special damages, or any other relief, or for any claim by any third party,
 * arising from your use of this Software.
 *
 ******************************************************************************/


#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_dac.h"
#include "em_prs.h"
#include "em_timer.h"
#include "em_dma.h"
#include "dmactrl.h"
#include "bsp.h"


/* Signal tables */
const uint8_t sinewave[] = /* 256 values */
{
  0x80, 0x83, 0x86, 0x89, 0x8c, 0x8f, 0x92, 0x95, 0x98, 0x9c, 0x9f, 0xa2, 0xa5, 0xa8, 0xab, 0xae,
  0xb0, 0xb3, 0xb6, 0xb9, 0xbc, 0xbf, 0xc1, 0xc4, 0xc7, 0xc9, 0xcc, 0xce, 0xd1, 0xd3, 0xd5, 0xd8,
  0xda, 0xdc, 0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xed, 0xef, 0xf0, 0xf2, 0xf3, 0xf5,
  0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfc, 0xfd, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfd, 0xfc, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8, 0xf7,
  0xf6, 0xf5, 0xf3, 0xf2, 0xf0, 0xef, 0xed, 0xec, 0xea, 0xe8, 0xe6, 0xe4, 0xe2, 0xe0, 0xde, 0xdc,
  0xda, 0xd8, 0xd5, 0xd3, 0xd1, 0xce, 0xcc, 0xc9, 0xc7, 0xc4, 0xc1, 0xbf, 0xbc, 0xb9, 0xb6, 0xb3,
  0xb0, 0xae, 0xab, 0xa8, 0xa5, 0xa2, 0x9f, 0x9c, 0x98, 0x95, 0x92, 0x8f, 0x8c, 0x89, 0x86, 0x83,
  0x80, 0x7c, 0x79, 0x76, 0x73, 0x70, 0x6d, 0x6a, 0x67, 0x63, 0x60, 0x5d, 0x5a, 0x57, 0x54, 0x51,
  0x4f, 0x4c, 0x49, 0x46, 0x43, 0x40, 0x3e, 0x3b, 0x38, 0x36, 0x33, 0x31, 0x2e, 0x2c, 0x2a, 0x27,
  0x25, 0x23, 0x21, 0x1f, 0x1d, 0x1b, 0x19, 0x17, 0x15, 0x13, 0x12, 0x10, 0x0f, 0x0d, 0x0c, 0x0a,
  0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x03, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
  0x09, 0x0a, 0x0c, 0x0d, 0x0f, 0x10, 0x12, 0x13, 0x15, 0x17, 0x19, 0x1b, 0x1d, 0x1f, 0x21, 0x23,
  0x25, 0x27, 0x2a, 0x2c, 0x2e, 0x31, 0x33, 0x36, 0x38, 0x3b, 0x3e, 0x40, 0x43, 0x46, 0x49, 0x4c,
  0x4f, 0x51, 0x54, 0x57, 0x5a, 0x5d, 0x60, 0x63, 0x67, 0x6a, 0x6d, 0x70, 0x73, 0x76, 0x79, 0x7c
};
const uint8_t squarewave[] = /* square wave */
{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};
const uint8_t sawtoothwave[] =
{
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
  0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
  0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
  0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
  0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
  0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
  0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
  0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
  0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
  0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
const uint8_t rewsawtoothwave[] = /* reverse sawtooth wave */
{
  0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8, 0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0,
  0xef, 0xee, 0xed, 0xec, 0xeb, 0xea, 0xe9, 0xe8, 0xe7, 0xe6, 0xe5, 0xe4, 0xe3, 0xe2, 0xe1, 0xe0,
  0xdf, 0xde, 0xdd, 0xdc, 0xdb, 0xda, 0xd9, 0xd8, 0xd7, 0xd6, 0xd5, 0xd4, 0xd3, 0xd2, 0xd1, 0xd0,
  0xcf, 0xce, 0xcd, 0xcc, 0xcb, 0xca, 0xc9, 0xc8, 0xc7, 0xc6, 0xc5, 0xc4, 0xc3, 0xc2, 0xc1, 0xc0,
  0xbf, 0xbe, 0xbd, 0xbc, 0xbb, 0xba, 0xb9, 0xb8, 0xb7, 0xb6, 0xb5, 0xb4, 0xb3, 0xb2, 0xb1, 0xb0,
  0xaf, 0xae, 0xad, 0xac, 0xab, 0xaa, 0xa9, 0xa8, 0xa7, 0xa6, 0xa5, 0xa4, 0xa3, 0xa2, 0xa1, 0xa0,
  0x9f, 0x9e, 0x9d, 0x9c, 0x9b, 0x9a, 0x99, 0x98, 0x97, 0x96, 0x95, 0x94, 0x93, 0x92, 0x91, 0x90,
  0x8f, 0x8e, 0x8d, 0x8c, 0x8b, 0x8a, 0x89, 0x88, 0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81, 0x80,
  0x7f, 0x7e, 0x7d, 0x7c, 0x7b, 0x7a, 0x79, 0x78, 0x77, 0x76, 0x75, 0x74, 0x73, 0x72, 0x71, 0x70,
  0x6f, 0x6e, 0x6d, 0x6c, 0x6b, 0x6a, 0x69, 0x68, 0x67, 0x66, 0x65, 0x64, 0x63, 0x62, 0x61, 0x60,
  0x5f, 0x5e, 0x5d, 0x5c, 0x5b, 0x5a, 0x59, 0x58, 0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51, 0x50,
  0x4f, 0x4e, 0x4d, 0x4c, 0x4b, 0x4a, 0x49, 0x48, 0x47, 0x46, 0x45, 0x44, 0x43, 0x42, 0x41, 0x40,
  0x3f, 0x3e, 0x3d, 0x3c, 0x3b, 0x3a, 0x39, 0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31, 0x30,
  0x2f, 0x2e, 0x2d, 0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20,
  0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
  0x0f, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
};

const uint8_t trianglewave[] =
{
  0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
  0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e,
  0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e,
  0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e,
  0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e,
  0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe,
  0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde,
  0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe,
  0xff, 0xfd, 0xfb, 0xf9, 0xf7, 0xf5, 0xf3, 0xf1, 0xef, 0xef, 0xeb, 0xe9, 0xe7, 0xe5, 0xe3, 0xe1,
  0xdf, 0xdd, 0xdb, 0xd9, 0xd7, 0xd5, 0xd3, 0xd1, 0xcf, 0xcf, 0xcb, 0xc9, 0xc7, 0xc5, 0xc3, 0xc1,
  0xbf, 0xbd, 0xbb, 0xb9, 0xb7, 0xb5, 0xb3, 0xb1, 0xaf, 0xaf, 0xab, 0xa9, 0xa7, 0xa5, 0xa3, 0xa1,
  0x9f, 0x9d, 0x9b, 0x99, 0x97, 0x95, 0x93, 0x91, 0x8f, 0x8f, 0x8b, 0x89, 0x87, 0x85, 0x83, 0x81,
  0x7f, 0x7d, 0x7b, 0x79, 0x77, 0x75, 0x73, 0x71, 0x6f, 0x6f, 0x6b, 0x69, 0x67, 0x65, 0x63, 0x61,
  0x5f, 0x5d, 0x5b, 0x59, 0x57, 0x55, 0x53, 0x51, 0x4f, 0x4f, 0x4b, 0x49, 0x47, 0x45, 0x43, 0x41,
  0x3f, 0x3d, 0x3b, 0x39, 0x37, 0x35, 0x33, 0x31, 0x2f, 0x2f, 0x2b, 0x29, 0x27, 0x25, 0x23, 0x21,
  0x1f, 0x1d, 0x1b, 0x19, 0x17, 0x15, 0x13, 0x11, 0x0f, 0x0f, 0x0b, 0x09, 0x07, 0x05, 0x03, 0x01
};


/* Function prototypes */
void FillAndModifySignalBuffer(bool primary);
void PingPongTransferComplete(unsigned int channel, bool primary, void *user);
void ReadUserInput(void);

void DMA_setup(void);
void DAC_setup(void);
void TIMER_setup(void);

/* DMA callback structure */
DMA_CB_TypeDef DMAcallBack;

/* Ram buffers and global variables */
#define BUFFERSIZE    256

uint16_t SignalBuffer0[BUFFERSIZE];
uint16_t SignalBuffer1[BUFFERSIZE];

uint16_t frequency;
int16_t  amplitude;
int16_t  offset;

int8_t   waveform;

bool     FsFixed; /* Use fixed sampling frequency or not */
uint32_t SamplingFreq;

/**************************************************************************//**
 * @brief  Main function
 * This example uses the predefined signal tables and DMA-transfers to
 * generate different waveforms.
 * The signal generator can use both fixed and variable sampling
 * frequency. With variable frequency all the values in the table are used to
 * make the waveform output. The frequency is changed by changing the prs
 * triggering frequency of new samples.
 * With fixed frequency, new samples are triggered at a predefined frequency,
 * for example at the cd-audio rate of 44.1kHz. The signal frequency is changed
 * by changing the number of samples used from the waveform table to make one
 * period of the outputsignal.
 *
 * By using the buttons and joystick on the dvk, the frequency, amplitude,
 * offset and waveform type can be changed. Joystick right and left changes the
 * frequency. Up/down changes waveform type. Button 1 and 2 changes the
 * amplitude, while 3 and 4 changes the offset.
 * Pressing the joystick center button switches between fixed and variable
 * sample frequency.
 *****************************************************************************/
int main(void)
{
  /* Initialize chip */
  CHIP_Init();

  frequency    = 1000; /* Hz, should be between 200 and 1700 for variable Fs. */
  amplitude    = 50;   /* % Percent */
  offset       = 50;   /* 0-100, position of offset, 50 is center */
  waveform     = 0;    /* Sinewave */
  SamplingFreq = 44100;

  FsFixed = false;

  /* Use 32MHZ HFXO as core clock frequency */
  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);

  /* Initialize DVK board register access */
  BSP_Init(BSP_INIT_DEFAULT);

  /* Start clocks */
  CMU_ClockEnable(cmuClock_DMA, true);
  CMU_ClockEnable(cmuClock_DAC0, true);
  CMU_ClockEnable(cmuClock_TIMER0, true);
  CMU_ClockEnable(cmuClock_PRS, true);

  /* Fill both primary and alternate RAM-buffer before start */
  FillAndModifySignalBuffer(true);
  FillAndModifySignalBuffer(false);

  /* Setup DMA and peripherals */
  DMA_setup();
  TIMER_setup();
  DAC_setup();

  /* Enable DAC channel 0, located on pin PB11 */
  DAC_Enable(DAC0, 0, true);

  while (1)
  {
    /* Enter EM1 while the DAC, Timer, PRS and DMA is working */
    EMU_EnterEM1();
  }
}

/**************************************************************************//**
 * @brief  Used for filling up the memory buffers and modifying the signal
 *****************************************************************************/
void FillAndModifySignalBuffer(bool primary)
{
  int32_t       tempvalue;
  uint16_t      * buffer;
  const uint8_t * LookUpTable;
  int           i;

  /* Set buffer pointer correct ram buffer */
  if (primary)
  {
    buffer = SignalBuffer0;
  }
  else /* Alternate */
  {
    buffer = SignalBuffer1;
  }

  /* Change waveform */
  switch (waveform)
  {
  case 0:
    LookUpTable = sinewave;
    break;
  case 1:
    LookUpTable = squarewave;
    break;
  case 2:
    LookUpTable = sawtoothwave;
    break;
  case 3:
    LookUpTable = rewsawtoothwave;
    break;
  case 4:
    LookUpTable = trianglewave;
    break;
  }

  /* Modify samples according to amplitude and offset, fixed sampling frequency */
  if (FsFixed)
  {
    int samplesNeeded, increment, j;

    /* Find out how many samples from table that are needed */
    samplesNeeded = SamplingFreq / frequency;

    /* Find increment */
    increment = BUFFERSIZE / samplesNeeded;

    j = 0;
    for (i = 0; i < BUFFERSIZE; i++)
    {
      tempvalue = (((LookUpTable[j % BUFFERSIZE] - 127) * 16 * amplitude) / 100) + (offset - 50) * 41;
      j        += increment;

      if (tempvalue > 2048)
      {
        tempvalue = 2048;
      }
      if (tempvalue < -2047)
      {
        tempvalue = -2047;
      }

      buffer[i] = (int16_t) tempvalue + 2047;
    }
  }
  else
  {
    /* Modify samples according to amplitude and offset, variable sampling frequency */
    for (i = 0; i < BUFFERSIZE; i++)
    {
      tempvalue = (((LookUpTable[i] - 127) * 16 * amplitude) / 100) + (offset - 50) * 41;
      if (tempvalue > 2048)
      {
        tempvalue = 2048;
      }
      if (tempvalue < -2047)
      {
        tempvalue = -2047;
      }

      buffer[i] = (int16_t) tempvalue + 2047;
    }
  }
}

/**************************************************************************//**
 * @brief  Called When DAC PingPong Transfer is Complete
 *****************************************************************************/
void PingPongTransferComplete(unsigned int channel, bool primary, void *user)
{
  (void) channel;
  (void) user;
  
  ReadUserInput();

  FillAndModifySignalBuffer(primary);

  /* Refresh the DMA control structure */
  DMA_RefreshPingPong(0,
                      primary,
                      false,
                      NULL,
                      NULL,
                      BUFFERSIZE - 1,
                      false);
}

/**************************************************************************//**
 * @brief  Reads the dvk-joystick and buttons and changes global variables
 *****************************************************************************/
void ReadUserInput(void)
{
  static int joystick = 0;
  int        joystickReadValue;

  static int pushButton = 0;
  int        pushButtonReadValue;

  /* Read buttons/joystick */

  joystickReadValue   = BSP_JoystickGet();
  pushButtonReadValue = BSP_PushButtonsGet();

  if (joystick != joystickReadValue)
  {
    joystick = joystickReadValue;

    /* Change waveform/frequency */
    switch (joystick)
    {
    case BC_UIF_JOYSTICK_UP:
      waveform++;
      if (waveform > 4)
      {
        waveform = 0;
      }
      break;
    case BC_UIF_JOYSTICK_DOWN:
      waveform--;
      if (waveform < 0)
      {
        waveform = 4;
      }
      break;
    case BC_UIF_JOYSTICK_RIGHT:
      if (FsFixed)
      {
        frequency += 200;
        if (frequency > 20000)
        {
          frequency = 20000;
        }
      }
      else
      {
        frequency += 50;
        if (frequency > 1700 && !FsFixed)
        {
          frequency = 1700;
        }
      }
      break;
    case BC_UIF_JOYSTICK_LEFT:
      if (FsFixed)
      {
        frequency -= 200;
        if (frequency < 200)
        {
          frequency = 200;
        }
      }
      else
      {
        frequency -= 50;
        if (frequency < 50)
        {
          frequency = 50;
        }
      }

      break;
    case BC_UIF_JOYSTICK_CENTER:
      FsFixed = !FsFixed;
      if (!FsFixed)
      {
        frequency = 1000;   /* Reduce frequency to avoid timertopvalue of 0 */
      }
      break;
    }

    if (!FsFixed)
    {
      /* Write topValue */
      TIMER_TopBufSet(TIMER0, CMU_ClockFreqGet(cmuClock_TIMER0) / BUFFERSIZE / frequency);
    }
  }

  if (pushButton != pushButtonReadValue)
  {
    pushButton = pushButtonReadValue;

    /* Change Amplitude/Offset */
    switch (pushButton)
    {
    case BC_UIF_PB1:
      amplitude -= 2;
      if (amplitude < 0)
      {
        amplitude = 0;
      }
      break;
    case BC_UIF_PB2:
      amplitude += 2;
      if (amplitude > 100)
      {
        amplitude = 100;
      }
      break;
    case BC_UIF_PB4:
      offset += 2;
      if (offset > 100)
      {
        offset = 100;
      }
      break;
    case BC_UIF_PB3:
      offset -= 2;
      if (offset < 0)
      {
        offset = 0;
      }
      break;
    }
  }
}

/**************************************************************************//**
 * @brief Setup DAC
 * Configures the DAC
 *****************************************************************************/
void DAC_setup(void)
{
  /* Use default settings */
  DAC_Init_TypeDef        init        = DAC_INIT_DEFAULT;
  DAC_InitChannel_TypeDef initChannel = DAC_INITCHANNEL_DEFAULT;

  /* Set reference voltage to 2.5V */
  init.reference = dacRef2V5;

  /* Calculate the DAC clock prescaler value that will result in a DAC clock
   * close to 1 MHz. Second parameter is zero, if the HFPERCLK value is 0, the
   * function will check what the HFPERCLK actually is. */
  init.prescale = DAC_PrescaleCalc(1000000, 0);

  /* Initialize the DAC. */
  DAC_Init(DAC0, &init);

  /* Enable prs to trigger samples at the right time with the timer */
  initChannel.prsEnable = true;
  initChannel.prsSel    = dacPRSSELCh0;

  /* Both channels can be configured the same
   * and be triggered by the same prs-signal. */
  DAC_InitChannel(DAC0, &initChannel, 0);
}

/**************************************************************************//**
 * @brief  Setup TIMER for prs triggering of DAC conversion
 *****************************************************************************/
void TIMER_setup(void)
{
  uint32_t timerTopValue;

  /* Use default timer configuration, overflow on counter top and start counting
   * from 0 again. */
  TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;

  TIMER_Init(TIMER0, &timerInit);

  /* PRS setup */
  /* Select TIMER0 as source and TIMER0OF (Timer0 overflow) as signal */
  PRS_SourceSignalSet(0, PRS_CH_CTRL_SOURCESEL_TIMER0, PRS_CH_CTRL_SIGSEL_TIMER0OF, prsEdgeOff);

  if (FsFixed)
  {
    timerTopValue = CMU_ClockFreqGet(cmuClock_TIMER0) / SamplingFreq;
  }
  else
  {
    timerTopValue = CMU_ClockFreqGet(cmuClock_TIMER0) / BUFFERSIZE / frequency;
  }

  /* Write topValue */
  TIMER_TopBufSet(TIMER0, timerTopValue);
}


/**************************************************************************//**
 * @brief  Setup DMA in ping pong mode
 *****************************************************************************/
void DMA_setup(void)
{
  /* DMA configuration structs */
  DMA_Init_TypeDef       dmaInit;
  DMA_CfgChannel_TypeDef chnlCfg;
  DMA_CfgDescr_TypeDef   descrCfg;

  /* Initializing the DMA */
  dmaInit.hprot        = 0;
  dmaInit.controlBlock = dmaControlBlock;
  DMA_Init(&dmaInit);

  /* Set the interrupt callback routine */
  DMAcallBack.cbFunc = PingPongTransferComplete;

  /* Callback doesn't need userpointer */
  DMAcallBack.userPtr = NULL;

  /* Setting up channel */
  chnlCfg.highPri   = false; /* Can't use with peripherals */
  chnlCfg.enableInt = true;  /* Interrupt needed when buffers are used */

  /* channel 0 and 1 will need data at the same time,
   * can use channel 0 as trigger */
  chnlCfg.select = DMAREQ_DAC0_CH0;
  chnlCfg.cb     = &DMAcallBack;
  DMA_CfgChannel(0, &chnlCfg);

  /* Setting up channel descriptor */
  /* Destination is DAC register and doesn't move */
  descrCfg.dstInc = dmaDataIncNone;

  /* Transfer 16 bit each time to CH0DATA register*/
  descrCfg.srcInc = dmaDataInc2;
  descrCfg.size   = dmaDataSize2;

  /* We have time to arbitrate again for each sample */
  descrCfg.arbRate = dmaArbitrate1;

  descrCfg.hprot = 0; /* No need to have high priority */

  /* Configure both primary and secondary descriptor alike */
  DMA_CfgDescr(0, true, &descrCfg);
  DMA_CfgDescr(0, false, &descrCfg);


  /* Enabling PingPong Transfer*/
  DMA_ActivatePingPong(0,
                       false,
                       (void *) &(DAC0->CH0DATA),
                       (void *) &SignalBuffer0,
                       BUFFERSIZE - 1,
                       (void *) &(DAC0->CH0DATA),
                       (void *) &SignalBuffer1,
                       BUFFERSIZE - 1);
}
