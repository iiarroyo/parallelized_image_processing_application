#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#define cimg_use_jpeg
#include "CImg/CImg.h"

class Operations
{
public:
    cimg_library::CImg<unsigned char> rotate(
        cimg_library::CImg<unsigned char> &);
    void display_image(cimg_library::CImg<unsigned char> &);
};

cimg_library::CImg<unsigned char> Operations::rotate(
    cimg_library::CImg<unsigned char> &img)
{
    cimg_library::CImg<unsigned char> new_img(img.height(),
                                              img.width(), 1, 3);

    for (int row = 0; row < img.height(); row++)
    {
        for (int col = 0; col < img.width(); col++)
        {
            int rot_col = new_img.width() - 1 - row;
            int rot_row = col;
            new_img(rot_col, rot_row, 0, 0) = img(col, row, 0, 0);
            new_img(rot_col, rot_row, 0, 1) = img(col, row, 0, 1);
            new_img(rot_col, rot_row, 0, 2) = img(col, row, 0, 2);
        }
    }
    return new_img;
}
void Operations::display_image(cimg_library::CImg<unsigned char> &img)
{
    cimg_library::CImgDisplay display(img, "Image");
    // Wait for the display window to close
    while (!display.is_closed())
    {
        display.wait();
    }
}

#endif