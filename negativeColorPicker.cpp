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
  pixel.h = fmod((img.getPixel(p.x, p.y)->h + 180), 360);
  pixel.s = img.getPixel(p.x, p.y)->s;
  pixel.l = 1 - img.getPixel(p.x, p.y)->l;
  pixel.a = img.getPixel(p.x, p.y)->a;
  return pixel;
}
