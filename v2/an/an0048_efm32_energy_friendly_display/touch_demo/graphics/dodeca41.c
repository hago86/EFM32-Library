/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap converter for emWin V5.16.                           *
*        Compiled Jun  4 2012, 15:48:30                              *
*        (C) 1998 - 2010 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: dodeca41                                              *
* Dimensions:  128 * 128                                             *
* NumColors:   2                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

/*   Palette
The following are the entries of the palette table.
Every entry is a 32-bit value (of which 24 bits are actually used)
the lower   8 bits represent the Red component,
the middle  8 bits represent the Green component,
the highest 8 bits (of the 24 bits used) represent the Blue component
as follows:   0xBBGGRR
*/

static GUI_CONST_STORAGE GUI_COLOR Colorsdodeca41[] = {
     0xFFFFFF,0x000000
};

static GUI_CONST_STORAGE GUI_LOGPALETTE Paldodeca41 = {
  2,	/* number of entries */
  0, 	/* No transparency */
  &Colorsdodeca41[0]
};

static GUI_CONST_STORAGE unsigned char acdodeca41[] = {
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX____, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X______X, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _X____XX, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX____XX, X___XXXX, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, __XXXXX_, ___XXXXX, XXX__XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX____X, XXXX____, _XXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ___XXXXX, X_____XX, __XXXXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX____, XXXXXX__, ___XXXXX, X__XXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, XXX_____, _XXXXXXX, XX__XXXX, XXXXXXX_, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, ___XXXXX, _____XXX, XXXXXXXX, XX__XXXX, XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX___X, XX_XX___, ___XXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XX_XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, XX______, XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXX_XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXX_, _____XXX, XXXXXXXX, XXXXXXXX, XXXXX__X, XXXXXXXX, XXXX_XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX___X, XXXX____, __X_XXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXX_XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, X______X, XXX_XXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXX__, ____XXXX, XXXX_XXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXXXXX_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX___X, XXX_____, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, __XXXXXX, XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, ______XX, XXXXXXXX, XXXX_XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__XXXXX, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXX_, ________, ___XXXXX, XXXXXXXX, XXXXX_XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, XXXXXXXX, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXX___, ________, XXXXXXXX, XXXXXXXX, XXXXX_XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX___XXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXX_XX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXX_XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXX_XXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX__X, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXX_XXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXX_XXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXX_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _XXXXXXX, XXXXXXX_, __XXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXX_XXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXXXXX_, __XXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXX_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, __XXXXXX, XXXXXX__, XX_XXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__XXXXX, XXXXX__X, XX_XXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXX_XXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, XXXX__XX, XXX_XXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXX_XXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX___XXX, XXX__XXX, XXX_XXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXX_XXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXX_XXXX, XXXX_XXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXX_XXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX__XX, XX_XXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX__XXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX__X, X__XXXXX, XXXXX_XX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX__XXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX_XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, __XXXXXX, XXXXX__X, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX_XXXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX____XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _XXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX_XXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_XXXX__, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXXXXX_, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX_XXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, _XXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXXXX_X, __XXXXXX, XXXXXXX_, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX_XXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXX_, XXXXXXXX, XXXXX___, XXXXXXXX, XXXXXXXX, XXXXX_XX, X__XXXXX, XXXXXXXX, _XXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X__XXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXX_, XXXXXXXX, XXXXXXXX, ____XXXX, XXXXXXXX, XXXX_XXX, XX__XXXX, XXXXXXXX, __XXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX, XXXX_X_X, XXXXXXXX, XXX__XXX, XX____XX, XXXXXXXX, X_XXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXX_XX, XXXXXXXX, XXXXXXXX, XXXXXXX_, __XXXXXX, XXXXXXXX, X_______, _XXXXXXX, X__XXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXX_XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX___XX, XX_XXXXX, ___XXX__, ___XXXXX, XX_XXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXX_XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, __XXXXX_, __XXXXXX, _____XXX, XXX_XXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXX_XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_XXXXX_, _XXXXXXX, XX_____X, XXX_XXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, __XXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XX_XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_XXXX__, _XXXXXXX, XXXX____, _XXX_XXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_XXX___, XXXXXXXX, XXXXXXX_, ______XX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_XX___X, XXXXXXXX, XXXXXXXX, X_____XX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_XX__XX, XXXXXXXX, XXXXXXXX, XXX____X, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXX_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_X___XX, XXXXXXXX, XXXXXXXX, XXXXX__X, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXX__XX, XXXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X____XXX, XXXXXXXX, XXXXXXXX, XXXXX_XX, XXXXXXXX,
  XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXX__XX, XXXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXXXX,
  XXXXXXXX, XXXXXXX_, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXX_XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXXXX,
  XXXXXXXX, XXXXXXX_, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXX_XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXX_XXX, XXXXXXXX,
  XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXX__XX, XXXXXXXX, XXX_XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, __XXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX,
  XXXXXXXX, XXXXXXX_, _____XXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, __XXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX,
  XXXXXXXX, XXXXXXX_, XX______, _XXX__XX, XXXXXXXX, XX_XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, __XXXXXX, XXXXXXXX, XXXXXXXX, XXX_XXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXX_, XXXXXXX_, ______XX, XXXXXXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, X_XXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXX_, XXXXXXXX, XXX_____, _XXXXXXX, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX__X, X_XXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXX__XX, X____XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX__XX, X_XXXXXX, XXXXXXXX, XXXXXXXX, XX_XXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXX__XX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX___XX, X_XXXXXX, XXXXXXXX, XXXXXXXX, X__XXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXX__XX, XXXXXXX_, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX___XXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, X__XXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXX__XX, XXXXXXXX, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, X_XXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXX_____, XXXXXXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, __XXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XXX_____, ___XXXXX, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ___XXXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, __XXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XX___XXX, ______XX, XX_XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, __XXXXXX, X_XXXXXX, XXXXXXXX, XXXXXXXX, _XXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, _XXXXXXX, XX__XXXX, XXX_____, _XX_XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, X_XXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, __XXXXXX, X___XXXX, XXXXXX__, _____XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _XXXXXXX, X__XXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, __XXXXXX, X__XXXXX, XXXXXXXX, X_______, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXXXX_, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXXXX, ___XXXXX, XXXXXXXX, XXXX____, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX__X, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXXXX_, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXXXX, __XXXXXX, XXXXXXXX, XXXXX___, ______XX, XXXXXXXX, XXXXXXXX, XXXX___X, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXXX_, _XXXXXXX, XXXXXXXX, XXXXXX__, XX______, _XXXXXXX, XXXXXXXX, XXX___XX, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXXX_, _XXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXX__, _____XXX, XXXXXXXX, XXX__XXX, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXXX__, XXXXXXXX, XXXXXXXX, XXXXXXX_, __XXXXXX, X_______, XXXXXXXX, XX__XXXX, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXX__X, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X_XXX___, XXXXXXXX, XXXXXXXX, XXXXXXXX, __XXXXXX, XXXX____, ___XXXXX, X___XXXX, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXX_XX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X__XX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__XXXXX, XXXXXXX_, ______XX, ___XXXXX, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXX_XX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, X__X___X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, XXXXXXXX, XX______, __XXXXXX, XXXXXX__, _____XXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX_X__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, XXXXXXXX, XXXXXX__, __XXXXXX, XXX_____, _X_____X, XXXXXXXX, XXXX_XXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX____XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXXXXX_, __XXXXXX, ______XX, XXXXX___, __XXXXXX, XXXX_XXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, __XXX___, ___XXXXX, XXXXXXX_, ____XXXX, XXX__XXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX___X, XXXXXXXX, XXXXXXXX, ________, XXXXXXXX, XXXXXXXX, X_____XX, XXX_XXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX__X, XXXXXXXX, XXXXXXX_, _____XXX, XXXXXXXX, XXXXXXXX, XXXX____, _XX_XXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXX____, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ____XXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, X______X, X___XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ___XXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXX___, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXX__, ____XXXX, X___XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ___XXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, __X_____, _XXXXXXX, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X_____XX, XXXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXXX___, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__XXXXX, XXXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, __XXXXXX, XXXXXXXX, XXX__XXX, XXXXXXXX, XXXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX___X, XXXXXXXX, XXXXXXXX, XXXXXXX_, __XXXXXX, XXXXXXXX, XXX___XX, XXXXXXXX, XXXXXXXX, X___XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XXXXXXXX, XXX___XX, XXXXXXXX, XXXXXXXX, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, __XXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXXX__, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXX___X, XXXXXXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX___XXX, XXXXXXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXX__X, XXXXXXXX, XXX___XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXX__X, XXXXXXXX, XXXXXXXX, XXXXX__X, XXXXXXXX, XX___XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX__X, XXXXXXXX, XXXX__XX, XXXXXXXX, XXXXXXXX, XXXXX___, XXXXXXXX, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _XXXXXXX, XXX__XXX, XXXXXXXX, XXXXXXXX, XXXXX___, XXXXXXX_, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, __XXXXXX, XXX__XXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, X___XXXX, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _XXX___X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX__XXX, XX__XXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _XX___XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX___X, X__XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _X__XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, ________, ________, ________, ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX
};

GUI_CONST_STORAGE GUI_BITMAP bmdodeca41 = {
  128, /* XSize */
  128, /* YSize */
  16, /* BytesPerLine */
  1, /* BitsPerPixel */
  acdodeca41,  /* Pointer to picture data (indices) */
  &Paldodeca41,   /* Pointer to palette */
  NULL
};

/* *** End of file *** */