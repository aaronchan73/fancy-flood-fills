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
  // img_main contains pixelpoint p parameter, calls imagetile
  // x y x y img_main x = 2, img_other width = 2, 2 % 2 = 0
  // w z w z  img main y = 2; img other height = 2; 2%2=0
  // x o o o
  // o o o o

  // x y img_other 
  // w z
  return *img_other.getPixel((p.x % (img_other.width())), (p.y % (img_other.height())));
}