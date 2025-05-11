#include "PGM.h"

PGM::PGM(int rows, int col)
{
	init(rows, cols);
}

PGM::PGM()
{
	init(0, 0);
}

PGM::PGM(const PGM& other)
{
	copy(other);
}

PGM& PGM::operator=(const PGM& other)
{
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
	// TODO: insert return statement here
}

PGM::~PGM()
{
	del();
}

std::string PGM::getType() const
{
    return "PGM";
}

std::string PGM::getFilename() const
{
    return fileName;
}

int PGM::getNumRows() const
{
	return rows;
}

int PGM::getNumCol() const
{
	return cols;
}

int PGM::getAtIndex(int row, int col) const
{
	return bitMap[row][col];
}

Color PGM::getAtIndex(int row, int col, int unused) const
{
	row++;
	col++;
	unused++;
	return { 0,0,0 }; ///returns a black colored pixel
}

void PGM::setAtIndex(int row, int col, char value)
{
	bitMap[row][col] = value;
}

void PGM::setFilname(const char* filename)
{
	fileName = filename;
}

void PGM::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << bitMap[i][j];
		}
		std::cout << std::endl;
	}
}

void PGM::grayscale()
{
	std::cout << "It is already a grayscale!\n";
}

void PGM::monochrome()
{
	if ((greyScale == 1) || (greyScale == 0))
	{
		std::cout << "Image is already monochrome!";
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (bitMap[i][j] < greyScale) //if grey convert to black
			{
				bitMap[i][j] = 0;
			}
		}
	}
}

void PGM::negative()
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (bitMap[i][j] == 0) {
				bitMap[i][j] = 1;
			}
			else if (bitMap[i][j] < greyScale) {
				bitMap[i][j] = greyScale - bitMap[i][j];
			}
			else {
				bitMap[i][j] = 0;
			}
		}
	}
}

BasicImage* PGM::rotate(const char* direction)
{
	PGM* newOne = new PGM(cols, rows);
	newOne->fileName = fileName;
	if (direction == "left") {
		int tmp = cols - 1;
		for (int i = 0; i < newOne->rows; i++)
		{
			for (int j = 0; j < newOne->cols; j++)
			{
				newOne->bitMap[i][j] = bitMap[j][tmp];
			}
			tmp--;
		}
		std::cout << "Succesfully left rotated image " << fileName << std::endl;
		return newOne;
	}
	else if (direction == "right") {
		int tmp;
		for (int i = 0; i < newOne->rows; i++)
		{
			tmp = rows - 1;
			for (int j = 0; j < newOne->cols; j++)
			{
				newOne->bitMap[i][j] = bitMap[tmp][j];
			}
			tmp--;
		}
		std::cout << "Succesfully right rotated image " << fileName << std::endl;
		return newOne;
	}
	else {
		std::cout << "The direction is not excisting!";
	}
	return this;
}

void PGM::writeToFile(std::ofstream& outfile)
{
	outfile << cols << " " << rows << " ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			outfile << bitMap[i][j];
		}
		outfile << std::endl;
	}
}

void PGM::init(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;

	fileName = "";
	greyScale = 0;

	bitMap = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		bitMap[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			bitMap[i][j] = 0;
		}
	}
}

void PGM::copy(const PGM& other)
{
	rows = other.rows;
	cols = other.cols;
	greyScale = other.greyScale;
	fileName = other.fileName;


	for (int i = 0; i < other.rows; ++i) {
		for (int j = 0; j < other.cols; ++j) {
			bitMap[i][j] = other.bitMap[i][j];
		}
	}
}

void PGM::del()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] bitMap[i];
	}
	delete[] bitMap;
}

PGM& readPGMFromFile(std::ifstream& infile)
{
	char newline;
	char space;
	int cols;
	int rows;
	int value;
	int grayScale;
	infile.get(newline);

	infile >> cols;
	infile >> rows;
	infile.get(newline);
	infile >> grayScale;
	infile.get(newline);

	PGM* image = new PGM(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			infile >> value;
			image->bitMap[i][j] = value;
		}
	}

	return *image;
	// TODO: insert return statement here
}
