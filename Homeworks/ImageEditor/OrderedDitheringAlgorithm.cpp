#include "OrderedDitheringAlgorithm.h"

#include <iostream>

OrderedDitheringAlgorithm::OrderedDitheringAlgorithm(BasicImage* image, int table[MAX_TABLE_SIDE][MAX_TABLE_SIDE], int tableSide, int divisor)
{
    this->image = image;
    for (std::size_t i = 0; i < MAX_TABLE_SIDE; ++i)
    {
        for (std::size_t j = 0; j < MAX_TABLE_SIDE; ++j)
        {
            this->table[i][j] = table[i][j];
        }
    }
    this->tableSide = tableSide;
    this->divisor = divisor;
    this->loadGrayscalePixels();
}

int OrderedDitheringAlgorithm::RGBToGrayscale(Color color)
{
    int max = std::max(color.getRed(), std::max(color.getGren(), color.getBlue()));
    int min = std::min(color.getRed(), std::min(color.getGren(), color.getBlue()));

    return static_cast<int>((static_cast<double>(min) + static_cast<double>(max)) / 2);
}

void OrderedDitheringAlgorithm::loadGrayscalePixels()
{
    unsigned int width = this->image->getNumRows();
    unsigned int height = this->image->getNumCol();

    for (std::size_t i = 0; i < width * height; ++i)
    {
        this->grayscalePixels.push_back(this->RGBToGrayscale((*this->image)[i]));
    }
}

BasicImage* OrderedDitheringAlgorithm::dither()
{
    std::vector<Color> newPixels;
    unsigned int width = this->image->getNumRows();
    unsigned int height = this->image->getNumCol();
    unsigned int maxValue = 255;

    for (std::size_t i = 0; i < height; ++i)
    {
        int row = i % this->tableSide;
        for (std::size_t j = 0; j < width; ++j)
        {
            int column = j % this->tableSide;
            int oldPixel = this->grayscalePixels[i * width + j];
            int newPixel;

            if ((oldPixel >> this->divisor) < this->table[row][column])
            {
                newPixel = 0;
            }
            else
            {
                newPixel = maxValue;
            }

            newPixels.push_back(Color(newPixel, newPixel, newPixel));
        }
    }

    return new BasicImage(width, height, maxValue, newPixels);
}