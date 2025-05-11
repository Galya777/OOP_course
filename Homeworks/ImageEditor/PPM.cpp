#include "PPM.h"
const float R_LUMINANCE = 0.2126; ///< perceived luminance for red colour
const float G_LUMINANCE = 0.7152; ///< perceived luminance for green colour
const float B_LUMINANCE = 0.0722; ///<perceived luminance for blue colour
PPM::PPM(int rows, int col)
{
	this->rows = rows;
	this->cols = cols;

	fileName = "";
	MaxColor = 1;
	colors[0].push_back(Color(0, 0, 0));
}

PPM::PPM()
{
	this->rows = rows;
	this->cols = cols;
	fileName = "";
	MaxColor = 0;
	colors[0].push_back(Color());
}

std::string PPM::getType() const
{
    return "PPM";
}

std::string PPM::getFilename() const
{
    return fileName;
}

int PPM::getNumRows() const
{
    return rows;
}

int PPM::getNumCol() const
{
    return cols;
}

int PPM::getAtIndex(int row, int col) const
{
	row++;
	col--;
	return 0;
}

Color PPM::getAtIndex(int row, int col, int unused) const
{
	row++;
	col++;
	unused++;
	return { 0,0,0 }; ///returns a black colored pixel
}

void PPM::setAtIndex(int row, int col, char value)
{
	row--;
	col++;
	value--;
}

void PPM::setFilname(const char* filename)
{
	fileName = filename;
}

void PPM::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << colors.at(i).at(j).getRed() << " "
                      << colors.at(i).at(j).getGren() << " "
                      << colors.at(i).at(j).getBlue() << "| ";
        }
        std::cout << std::endl;
    }
}

void PPM::grayscale()
{
    PPM* tmp = new PPM(rows, cols);
    tmp->MaxColor = this->MaxColor;

    int greyscale_pixels = 0;
    int all_pixels = 0;
    for (int i = 0; i < rows; i++) //checks if picture is already in greyscale
    {
        for (int j = 0; j < cols; j++)
        {
            all_pixels++;
            if (colors.at(i).at(j).isGrey())
            {
                greyscale_pixels++;
            }
        }
    }
    if (greyscale_pixels == (all_pixels))
    {
        std::cout << "Image is already in greyscale!\n";
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            float luminance = R_LUMINANCE * (colors.at(i).at(j).getRed()) 
                + G_LUMINANCE * (colors.at(i).at(j).getGren()) + B_LUMINANCE * (colors.at(i).at(j).getBlue());

            tmp->colors.at(i).at(j).setRED(luminance);
            tmp->colors.at(i).at(j).setGREEN(luminance);
            tmp->colors.at(i).at(j).setBLUE(luminance);
        }
    }
    *this = *tmp;
}

void PPM::monochrome()
{
    if ((MaxColor == 1) || (MaxColor == 0))
    {
        std::cout << "Image is already monochrome!";
        return;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (colors.at(i).at(j).isWhite() == false) {
                colors.at(i).at(j) = { 0,0,0 };
            }
        }
    }
}

void PPM::negative()
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            colors.at(i).at(j) = colors.at(i).at(j) - MaxColor;
        }
    }
}

BasicImage* PPM::rotate(const char* direction)
{
    PPM* newOne = new PPM(cols, rows);
    newOne->fileName = fileName;
    if (direction == "left") {
        int tmp = cols - 1;
        for (int i = 0; i < newOne->rows; i++)
        {
            for (int j = 0; j < newOne->cols; j++)
            {
                newOne->colors.at(i).at(j) = colors.at(j).at(tmp);
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
                newOne->colors.at(i).at(j) = colors.at(tmp).at(j);
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

BasicImage* PPM::collage(const char* direction, BasicImage* second_image)
{
    int first_image_num_rows = rows;
    int first_image_num_col = cols;
    int second_image_num_rows = second_image->getNumRows();
    int second_image_num_col = second_image->getNumCol();
    if ((first_image_num_rows != second_image_num_rows)                                                    //checks dimensions of images are the same
        || (first_image_num_col != second_image_num_col) || (strcmp("PPM", second_image->getType().c_str()) != 0)) //checks if types are the same
    {
        std::cout << "Unable to apply collage for images " <<" and " << second_image->getFilename() << " ."
            << "Collage images should be of the same type and dimensions!" << std::endl;
    }
    //==horizontal collage
    if (strcmp(direction, "horizontal") == 0)
    {
        int new_size = first_image_num_col + second_image_num_col;
        PPM* new_PPM = new PPM(first_image_num_rows, new_size);
        new_PPM->MaxColor = MaxColor;
        //==joining first table
        for (int i = 0; i < first_image_num_rows; i++)
        {
            for (int j = 0; j < first_image_num_col; j++)
            {
                new_PPM->colors[i][j] = colors[i][j];
            }
        }

        //==joining second table
        int col_num;
        for (int i = 0; i < second_image_num_rows; i++)
        {
            col_num = 0;
            for (int j = second_image_num_col; j < new_size; j++)
            {
                new_PPM->colors[i][j] = second_image->getAtIndex(i, col_num, 0);
                col_num++;
            }
        }
        std::cout << "Successfully completed horizontal collage" << std::endl;
        return new_PPM;
    }

    //==vertical collage
    if (strcmp(direction, "vertical") == 0)
    {
        int new_size = first_image_num_rows + second_image_num_rows;
        PPM* new_PPM = new PPM(new_size, first_image_num_col);
        new_PPM->MaxColor = MaxColor;
        //==joining first table
        for (int i = 0; i < first_image_num_rows; i++)
        {
            for (int j = 0; j < first_image_num_col; j++)
            {
                new_PPM->colors[i][j] = colors[i][j];
            }
        }

        //==joining second table
        int row_num = 0;
        for (int i = second_image_num_rows; i < new_size; i++)
        {
            for (int j = 0; j < second_image_num_col; j++)
            {
                new_PPM->colors[i][j] = second_image->getAtIndex(row_num, j, 0);
            }
            row_num++;
        }
        std::cout << "Successfully completed vertical collage" << std::endl;
        return new_PPM;
    }

    else
    {
        std::cout << "Invalid collage direction: options are \"horizontal\" and \"vertical\"." << std::endl;
        return this;
    }
}

void PPM::writeToFile(std::ofstream& outfile)
{
    outfile << cols << " " << rows << " ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            outfile << colors.at(i).at(j);
        }
        outfile << std::endl;
    }
}

PPM& readPPMFromFile(std::ifstream& infile)
{
    char newline;
    char space;
    int cols;
    int rows;
    int red;
    int green;
    int blue;
    int color;
    infile.get(newline);

    infile >> cols;
    infile >> rows;
    infile.get(newline);
    infile >> color;
    infile.get(newline);

    PPM* image = new PPM(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            infile >> red;
            infile >> green;
            infile >> blue;
            image->colors.at(i).at(j) = {red, green, blue};
        }
    }

    return *image;
    // TODO: insert return statement here
}
