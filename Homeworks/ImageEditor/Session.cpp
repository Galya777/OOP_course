#include "Session.h"
const int MAX_SESSION = 1000;
Session::Session()
{
	images.push_back(new BasicImage*[MAX_SESSION]);
	command.push_back("");
	ID = THIS_ID;
	THIS_ID++;
}

BasicImage** Session::getImage(int index)
{
    return images.at(index);

}
BasicImage** Session::getImageByName(std::string name)
{
	return images[getIndexByName(name.c_str())];
}
BasicImage* Session::load(std::string fileName)
{
    std::ifstream infile;
    infile.open(fileName);
    if (infile)
    {
        char imgType[4];
        infile >> imgType;
        if (strcmp(imgType, "PBM") == 0)
        {
            BasicImage* new_PBM = &readPBMFromFile(infile);
            new_PBM->setFilname(fileName.c_str());
            images.push_back(&new_PBM);
            infile.close();
            std::cout << "Image \"" << fileName << "\" added.\n";
            return new_PBM;
        }
        if (strcmp(imgType, "PGM") == 0)
        {
            BasicImage* new_PGM = &readPGMFromFile(infile);
            new_PGM->setFilname(fileName.c_str());
            images.push_back(&new_PGM);
            infile.close();
            std::cout << "Image \"" << fileName << "\" added.\n";
            return new_PGM;
        }
        if (strcmp(imgType, "P3") == 0)
        {
            BasicImage* new_PPM = &readPPMFromFile(infile);
            new_PPM->setFilname(fileName.c_str());
            images.push_back(&new_PPM);
            infile.close();
            std::cout << "Image \"" << fileName << "\" added.\n";
            return new_PPM;
        }
    }
    else
    { //creates a new empty file
        std::ofstream tmpfile;
        tmpfile.open(fileName);
        infile.open(fileName);
        std::cout << "Error in reading " << fileName << ". A new filename with this name was generated\n";
        if (infile)
        {
            infile.close();
            PBM* null_PBM = new PBM();
            return null_PBM;
        }
        else
        {
            std::cout << "Error:can't read from newly generated file.\n";
            PBM* null_PBM = new PBM();
            return null_PBM;
        }
    }
    std::cout << "Error in loading file\n";
    PBM* null_PBM = new PBM();
    return null_PBM;
}
int Session::getId() const
{
    return ID;
}
void Session::close()
{
    std::ifstream infile;
    infile.close();
	std::cout << "File successfully closed!" << std::endl;
}

void Session::save()
{
    for (int i = 0; i < images.size(); i++)
    {
        const char* filename = images.at(i)[i]->getFilename().c_str();
        std::ofstream outfile;
        outfile.open(filename);
        if (outfile)
        {
            images.at(i)[i]->writeToFile(outfile);
        }
        else
        {
            std::cout << "Unable to save " << filename << std::endl;
        }
        outfile.close();
    }
	std::cout << "File successfully saved!" << std::endl;
}

void Session::saveAs(const char* image_file, std::string filename)
{
    std::ofstream outfile;
    outfile.open(filename);
    if (outfile)
    {
        int index = getIndexByName(image_file);
        if (index >= 0)
        {
           images.at(index)[index]->writeToFile(outfile);
        }
    }
    else
    {
        std::cout << "Unable to save ";
    }
    outfile.close();
}

void Session::grayscale()
{
    command.push_back("grayscale");
}

void Session::monochrome()
{
    command.push_back("monochrome");
}

void Session::negative()
{
    command.push_back("negative");
}

void Session::rotate(std::string direction)
{
    const char* rotate = "rotate";
    command.push_back(rotate+direction);
}

void Session::undo()
{
    command.pop_back();
}

void Session::sessionInfo()
{
    std::cout << "Name of images: \n";
    for (int i = 0; i < images.size(); ++i) {
        std::cout << images.at(i)[i]->getFilename()<<std::endl;
    }
    std::cout << std::endl;

    std::cout << "Commands: \n";
    for (int i = 0; i < images.size(); ++i) {
        std::cout << command.at(i) << std::endl;
    }
    std::cout << std::endl;
}


int Session::getIndexByName(const char* filename)
{
	for (int i = 0; i < images.size(); ++i) {
		if (images.at(i)[i]->getFilename()==filename) {
			return i;
		}
	}
	return -1;
}
