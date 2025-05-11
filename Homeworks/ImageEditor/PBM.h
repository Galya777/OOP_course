#pragma once
#include "BasicImage.h"
/**
 * This class implements portable bitmap format (PBM) images
 * They are black and white as each pixel of it is a single bit
 * 1 - black 
 * 0 - white 
*/
class PBM:public BasicImage
{
public:	
	///the big 4
	///We need it because of the two-dimentional array of integers 
	PBM(int rows, int col);
	PBM();
	PBM(const PBM& other);
	PBM& operator=(const PBM& other);
	~PBM();

	//==getters

	virtual std::string getType() const override;
	virtual std::string getFilename() const override;
	virtual int getNumRows() const override;
	virtual int getNumCol() const override;
	virtual int getAtIndex(int row, int col) const override;
	///if not encoded in RGB, returns a black colored pixel
	virtual Color getAtIndex(int row, int col, int unused) const override;

	//==setters

	virtual void setAtIndex(int row, int col, char value) override;
	virtual void setFilname(const char* filename) override;
	virtual void print() override;

	//==images methods

	/// method not defined for PBM images
	virtual void grayscale() override;
	/// method not defined for PBM images
	virtual void monochrome() override;
	/// inverses color values
	virtual void negative() override;
	virtual BasicImage* rotate(const char* direction) override;

	/// collages two images in given direction
 /// &returns: pointer to new collaged image
	virtual BasicImage* collage(const char* direction, BasicImage* second_image);
	///make the image bigger
	virtual void enlargeImage(int value, BasicImage& oldImage);
	///make the image smaller
	virtual void shrinkImage(int value, BasicImage& oldImage);
	///get the reflection of an image. 
	///Flips the image
	virtual void reflectImage(bool flag, BasicImage& oldImage);
	///crops the image
	virtual void crop(int x1, int y1, int x2, int y2);
	///=Dither algorithm
	  //! Dithers the image via ErrorDiffusionAlrogithm
	virtual void errorDiffusionDithering(ErrorDiffusionAlgorithm algorithm);

	//! Dithers the image via OrderedDitheringAlgorithm
	virtual void orderedDithering(OrderedDitheringAlgorithm algorithm);

	//==files methods

	/// reads PBM from file
	/// & returns: newly read PBM image
	friend PBM& readPBMFromFile(std::ifstream& infile);
	virtual void writeToFile(std::ofstream& outfile) override;

private:

	void init(int rows, int cols);
	void copy(const PBM& other);
	void del();


	std::string fileName;
	int** bitMap; ///< stores the bits of the image in a two-dimentional array of integers which are representing values
};

PBM& readPBMFromFile(std::ifstream& infile);
