#include <iostream>
#include "Operations.h"
#define cimg_use_jpeg
#include "CImg/CImg.h"

using namespace std;

int main()
{
    cimg_library::CImg<unsigned char> img("../images/cat.jpg");
    Operations op;
    img = op.RGB2grayscale(img);
    img = op.rotate(img);

    op.display_image(img);

    return 0;
}
