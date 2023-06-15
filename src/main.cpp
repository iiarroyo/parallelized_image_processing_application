#include <iostream>
#include "Operations.h"
#define cimg_use_jpeg
#include "CImg/CImg.h"

using namespace std;

int main()
{
    cimg_library::CImg<unsigned char> img("../images/person2.jpg");
    Operations op;
    img = op.rotate(img);
    op.display_image(img);

    return 0;
}
