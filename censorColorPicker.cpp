/*
*  File: censorColorPicker.cpp
*  Implements the censor color picker for CPSC 221 PA2.
*
*/

#include "censorColorPicker.h"

#include <math.h> // gives access to sqrt function

/*
*  Useful function for computing the Euclidean distance between two PixelPoints
*/
double PointDistance(PixelPoint a, PixelPoint b) {
  unsigned int diff_x, diff_y;
  if (a.x > b.x)
    diff_x = a.x - b.x;
  else
    diff_x = b.x - a.x;
  if (a.y > b.y)
    diff_y = a.y - b.y;
  else
    diff_y = b.y - a.y;
  return sqrt(diff_x * diff_x + diff_y * diff_y);
}

HSLAPixel CensorColorPicker::computeAvg(PNG& image, unsigned int xStart, unsigned int yStart) {
  double hue = 0;
  double sat = 0;
  double lum = 0;
  double alp = 0;
  for (unsigned int x = xStart; x < xStart + blockwidth; x++) {
    for (unsigned int y = yStart; y < yStart + blockwidth; y++) {
      hue += image.getPixel(x, y)->h;
      sat += image.getPixel(x, y)->s;
      lum += image.getPixel(x, y)->l;
      alp += image.getPixel(x, y)->a;
    }
  }
  hue = hue / (blockwidth * blockwidth);
  sat = sat / (blockwidth * blockwidth);
  lum = lum / (blockwidth * blockwidth);
  alp = alp / (blockwidth * blockwidth);

  HSLAPixel *pixel = new HSLAPixel(hue, sat, lum, alp);
  HSLAPixel temp;
  temp = *pixel;
  delete pixel;
  return temp;

}

void CensorColorPicker::mosaic(PNG& image) {
  PNG *mosaic = new PNG(image.width(), image.height());
  for (unsigned int x = 0; x < image.width(); x++) {
    for (unsigned int y = 0; y < image.height(); y++) {
      int xStart = x - (x % blockwidth);
      int yStart = y - (y % blockwidth);
      *(*mosaic).getPixel(x, y) = computeAvg(image, xStart, yStart);
    }
  }
  blockyimg = *mosaic;
  delete mosaic;
}

CensorColorPicker::CensorColorPicker(unsigned int b_width, PixelPoint ctr, unsigned int rad, PNG& inputimage)
{
  // complete your implementation below
  blockwidth = b_width;
  center = ctr;
  radius = rad;
  img = inputimage;
  newimg = inputimage;
  mosaic(newimg);
}

HSLAPixel CensorColorPicker::operator()(PixelPoint p)
{
  // complete your implementation below
  if (PointDistance(center, p) <= radius) {
    return *blockyimg.getPixel(p.x, p.y);
  } else {
    return *img.getPixel(p.x, p.y);
 }
}
