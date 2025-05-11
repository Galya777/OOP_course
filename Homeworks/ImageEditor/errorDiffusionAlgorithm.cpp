#include "errorDiffusionAlgorithm.h"
#include <stdexcept>
#include <iostream>

ErrorDiffusionAlgorithm::ErrorDiffusionAlgorithm(BasicImage* image, int table[COEFFIIENT_TABLE_HEIGHT][COEFFIIENT_TABLE_WIDTH], bool isShiftable, int divisor)
{
    this->image = image;
    for (std::size_t i = 0; i < COEFFIIENT_TABLE_HEIGHT; ++i)
    {
        for (std::size_t j = 0; j < COEFFIIENT_TABLE_WIDTH; ++j)
        {
            this->table[i][j] = table[i][j];
        }
    }
    this->isShiftable = isShiftable;
    this->divisor = divisor;
    this->loadGrayscalePixels();
}

int ErrorDiffusionAlgorithm::RGBToGrayscale(Color color)
{
    int max = std::max(color.getRed(), std::max(color.getGren(), color.getBlue()));
    int min = std::min(color.getRed(), std::min(color.getGren(), color.getBlue()));

    return static_cast<int>((static_cast<double>(min) + static_cast<double>(max)) / 2);
}

void ErrorDiffusionAlgorithm::loadGrayscalePixels()
{
    unsigned int width = this->image->getNumRows();
    unsigned int height = this->image->getNumCol();

    for (std::size_t i = 0; i < width * height; ++i)
    {
        this->grayscalePixels.push_back(this->RGBToGrayscale((*this->image)[i]));
    }
}

bool ErrorDiffusionAlgorithm::isCloserToZero(int value, int maxValue)
{
    return value < (maxValue - value);
}

bool ErrorDiffusionAlgorithm::isInsideTheImage(std::size_t i, std::size_t j, unsigned int height, unsigned int width)
{
    return i < height&& j < width;
}

void ErrorDiffusionAlgorithm::addError(int& pixel, int error, int coefficient)
{
    if (this->isShiftable)
    {
        pixel += ((error * coefficient) >> this->divisor);
    }
    else
    {
        pixel += (error * coefficient / this->divisor);
    }
}

void ErrorDiffusionAlgorithm::spreadError(std::size_t currentI, std::size_t currentJ, unsigned int height,
    unsigned int width, int error)
{
    if (currentI >= height || currentJ >= width)
    {
        throw std::invalid_argument("Current pixel is outside the image");
    }

    for (std::size_t i = 0; i < COEFFIIENT_TABLE_HEIGHT; ++i)
    {
        for (std::size_t j = 0; j < COEFFIIENT_TABLE_WIDTH; ++j)
        {
            // 2 2
            if (this->table[i][j] > 0 && this->isInsideTheImage(currentI + i, currentJ + j - 2, height, width))
            {
                addError(this->grayscalePixels[(currentI + i) * width + currentJ + j - 2], error, this->table[i][j]);
            }
        }
    }
}

BasicImage* ErrorDiffusionAlgorithm::dither()
{
    std::vector<Color> newPixels;
    unsigned int width = this->image->getNumRows();
    unsigned int height = this->image->getNumCol();
    unsigned int maxValue = 255;

    for (std::size_t i = 0; i < height; ++i)
    {
        int error = 0;
        for (std::size_t j = 0; j < width; ++j)
        {
            int oldPixel = this->grayscalePixels[i * width + j];
            int newPixel;

            if (isCloserToZero(oldPixel, maxValue))
            {
                newPixel = 0;
            }
            else
            {
                newPixel = maxValue;
            }
            error = oldPixel - newPixel;

            spreadError(i, j, height, width, error);

            newPixels.push_back(Color(newPixel, newPixel, newPixel));
        }
    }
    return new BasicImage(width, height, maxValue, newPixels);
}