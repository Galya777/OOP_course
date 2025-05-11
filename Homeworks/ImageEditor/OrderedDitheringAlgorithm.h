#pragma once
#include <cstddef>
#include <vector>
#include "BasicImage.h"
/**
 * @class OrderedDitheringAlgorithm
 */
class OrderedDitheringAlgorithm
{
protected:
    static const std::size_t MAX_TABLE_SIDE = 8; //!< a const for the max side of the table

    BasicImage* image; //!< stores a pointer to the image which will be dithered
    std::vector<int> grayscalePixels; //!< stores the pixels of the image converted into grayscale
    int table[MAX_TABLE_SIDE][MAX_TABLE_SIDE]; //!< stores the table with the values which with the pixels will be compared
    int tableSide; //!< stores the side of the table
    int divisor; //!< stores the divisor (it is always a power of 2, so we are storing the power)


    //! Helper function for converting RGB values into grayscale
    int RGBToGrayscale(Color color);

    //! Function for loading the vector of grayscale pixels from the image using the helper function
    void loadGrayscalePixels();

    //! Constructor with parametrs
    OrderedDitheringAlgorithm(BasicImage* image, int table[MAX_TABLE_SIDE][MAX_TABLE_SIDE], int tableSide, int divisor);

public:
    //! Main function for dithering an image via ordered dithering
    BasicImage* dither();
};

