#pragma once
#include <fstream>
#include "Color.h"
#include "errorDiffusionAlgorithm.h"
#include "OrderedDitheringAlgorithm.h"
#include <vector>
#include <string>
/**
 * Abstract class for images
 * consists pure virtual methods which will be override in image file types
 * declares all common image methods:
 * getters and setters, methods which modify an image
 * and writing image to a file
 */
class BasicImage
{
public:

    //==getters
    /// return the type of image
    virtual std::string getType() const = 0;
    /// return filename from which the image was imported
    virtual std::string getFilename() const = 0;
    /// return the height of image
    virtual int getNumRows() const = 0;
    /// return the width of image
    virtual int getNumCol() const = 0;
    /// returns single color for images that are not RGB encoded
    virtual int getAtIndex(int row, int col) const = 0;
    /// returns colors for RGB encoded images
    virtual Color getAtIndex(int row, int col, int unused) const = 0;

  
    //==setters
    /// sets a color with given value at given coordinates
    virtual void setAtIndex(int row, int col, char value) = 0;
    /// renames an image's filename
    virtual void setFilname(const char* filename) = 0;
    /// prints image in console
    virtual void print() = 0;

    //===image methods
    ///applies greyscale to image
    virtual void grayscale() = 0;
    /// applies monochrome to image
    virtual void monochrome() = 0;
    /// makes an image negative
    virtual void negative() = 0;
    /// rotates an image at 90 degrees in given direction
    /// &returns: pointer to new rotated image
    virtual BasicImage* rotate(const char* direction) = 0;


    /// collages two images in given direction
   /// &returns: pointer to new collaged image
    virtual BasicImage* collage(const char* direction, BasicImage* second_image) = 0;
    ///make the image bigger
    virtual void enlargeImage(int value, BasicImage& oldImage)=0;
    ///make the image smaller
    virtual void shrinkImage(int value, BasicImage& oldImage)=0;
    ///get the reflection of an image. 
    ///Flips the image
    virtual void reflectImage(bool flag, BasicImage& oldImage)=0;
    ///crops the image
    virtual void crop(int x1, int y1, int x2, int y2) = 0;
    ///=Dither algorithm
      //! Dithers the image via ErrorDiffusionAlrogithm
    virtual void errorDiffusionDithering(ErrorDiffusionAlgorithm algorithm)=0;

    //! Dithers the image via OrderedDitheringAlgorithm
    virtual void orderedDithering(OrderedDitheringAlgorithm algorithm)=0;


    //==file methods
    /// writes image to binary format
    virtual void writeToFile(std::ofstream& outfile) = 0;

protected:
	///every image has numbers of rows and cols colored in different colors
	int rows;
	int cols;
};

