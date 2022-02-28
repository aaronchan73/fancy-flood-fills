/*
*  File: imageTileColorPicker.cpp
*  Implements the image tile color picker for CPSC 221 PA2.
*
*/

#include "imageTileColorPicker.h"

ImageTileColorPicker::ImageTileColorPicker(PNG& otherimage) {
  img_other = otherimage;
}

HSLAPixel ImageTileColorPicker::operator()(PixelPoint p) {
  // complete your implementation below
  return *img_other.getPixel((p.x % (img_other.width())), (p.y % (img_other.height())));
}