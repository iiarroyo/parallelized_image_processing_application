#include <iostream>
#include "Operations.h"
#define cimg_use_jpeg
#include "CImg/CImg.h"

using namespace std;

int main() {
    // Load and display an image using CImg
    cimg_library::CImg<unsigned char> originalImage("images/cat.jpg");
    cimg_library::CImg<unsigned char> newImage(originalImage.width(), originalImage.height(), 1, 3);
    cimg_library::CImgDisplay display(newImage, "Image");

    // Wait for the display window to close
    while (!display.is_closed()) {
        display.wait();
    }

    return 0;
}
