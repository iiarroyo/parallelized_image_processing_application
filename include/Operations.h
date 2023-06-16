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
    cimg_library::CImg<unsigned char> RGB2grayscale(
        cimg_library::CImg<unsigned char> &);
    std::vector<int> create_kernel(int);
    void display_image(cimg_library::CImg<unsigned char> &);
};

cimg_library::CImg<unsigned char> Operations::rotate(
    cimg_library::CImg<unsigned char> &img)
{
    cimg_library::CImg<unsigned char> new_img(img.height(),
                                              img.width(), 1, img.spectrum());

    for (int row = 0; row < img.height(); row++)
    {
        for (int col = 0; col < img.width(); col++)
        {
            int rot_col = new_img.width() - 1 - row;
            int rot_row = col;
            for (int dimension = 0; dimension < img.spectrum(); dimension++)
                new_img(rot_col, rot_row, 0, dimension) = img(col, row, 0, dimension);
        }
    }
    return new_img;
}

cimg_library::CImg<unsigned char> Operations::RGB2grayscale(
    cimg_library::CImg<unsigned char> &img)
{
    cimg_library::CImg<unsigned char> new_img(img.width(),
                                              img.height(), 1, 1);
    int g_value;
    for (int row = 0; row < img.width(); row++)
    {
        for (int col = 0; col < img.height(); col++)
        {
            g_value = (img(row, col, 0, 0) + img(row, col, 0, 1) + img(row, col, 0, 2)) / 3;
            new_img(row, col, 0, 0) = g_value;
        }
    }
    return new_img;
}

std::vector<int> Operations::create_kernel(int l)
{
    
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