
#undef cimg_display
#define cimg_display 0
#include "cimg/cimg.h"

using namespace cimg_library;

int main(int argc,char **argv)
{
  const char *const file_i = cimg_option("-i",(char*)0,"Input image");

  // Init fonts
  CImg<> img;
  img.assign(file_i);

  cimg_forY(img,y)
  {
    cimg_forX(img,x)
    {
      std::fprintf(stdout,"%f\n", img(x,y));
    }
  }

  return 0;
}
