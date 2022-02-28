/*
*  File: negativeColorPicker.cpp
*  Implements the negative color picker for CPSC 221 PA2.
*
*/

#include "negativeColorPicker.h"

NegativeColorPicker::NegativeColorPicker(PNG& inputimg)
{
  // complete your implementation below
  img = inputimg;
}
// pixelpoint is a point on the image
HSLAPixel NegativeColorPicker::operator()(PixelPoint p)
{
  // complete your implementation below
  HSLAPixel pixel;
  pixel.h = p.color.h;
  pixel.s = p.color.s;
  pixel.l = 1 - p.color.l;
  pixel.a = p.color.a;
  return pixel;
}
