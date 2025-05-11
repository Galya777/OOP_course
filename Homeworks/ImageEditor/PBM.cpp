#include "PBM.h"

void PBM::writeToFile(std::ofstream& outfile)
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

void PBM::init(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;

	fileName = "";

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

void PBM::copy(const PBM& other)
{
	rows=other.rows;
	cols = other.cols;
	fileName = other.fileName;

	
	for (int i = 0; i < other.rows; ++i) {
		for (int j = 0; j < other.cols; ++j) {
			bitMap[i][j] = other.bitMap[i][j];
		}
	}
}

void PBM::del()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] bitMap[i];
	}
	delete[] bitMap;
}

PBM::PBM(int rows, int col)
{
	init(rows, cols);
}

PBM::PBM()
{
	init(1, 1);
}

PBM::PBM(const PBM& other)
{
	copy(other);
}

PBM& PBM::operator=(const PBM& other)
{
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
	// TODO: insert return statement here
}

PBM::~PBM()
{
	del();
}

std::string PBM::getType() const
{
	return "PBM";
}

std::string PBM::getFilename() const
{
	return fileName;
}

int PBM::getNumRows() const
{
	return rows;
}

int PBM::getNumCol() const
{
	return cols;
}

int PBM::getAtIndex(int row, int col) const
{
	return bitMap[row][col];
}

Color PBM::getAtIndex(int row, int col, int unused) const
{
	row++;
	col++;
	unused++;
	return { 0,0,0 }; ///returns a black colored pixel
}

void PBM::setAtIndex(int row, int col, char value)
{
	bitMap[row][col] = value;
}

void PBM::setFilname(const char* filename)
{
	fileName = filename;
}

void PBM::print()
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

void PBM::grayscale()
{
	std::cout << "Imposible to grayscale a .pbm image!\n";
}

void PBM::monochrome()
{
	std::cout << "Imposible to monochrome a .pbm image!\n";
}

void PBM::negative()
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (bitMap[i][j] == 0) {
				bitMap[i][j] = 1;
			}
			else {
				bitMap[i][j] = 0;
			}
		}
	}
}

BasicImage* PBM::rotate(const char* direction)
{
	///in order to keep the information for the original image, 
	///I will create a new one which is a copy of the old and rotate it 
	/// The copy is with inversed dimentions
	/// 
	/// This idea is given to me from a ready code I saw on StackOverflow 
	/// The perpouse was different, so I just copied the idea, not the code
	/// 
	
	PBM* newOne = new PBM(cols, rows);
	newOne->fileName = fileName;
	if (direction=="left") {
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
	} else if (direction == "right") {
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

PBM& readPBMFromFile(std::ifstream& infile)
{
	char newline;
	char space;
	int cols;
	int rows;
	int value;
	infile.get(newline);

	infile >> cols;
	infile >> rows;
	infile.get(newline);

	PBM* image = new PBM(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			infile >> value;
			image->bitMap[i][j] = value;
		}
	}
	
		return *image;
	// TODO: insert return statement here
}
