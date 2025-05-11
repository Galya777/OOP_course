#pragma once
#include <vector>
#include "BasicImage.h"
#include "PBM.h"
#include "PGM.h"
#include "PPM.h"
static int THIS_ID = 0;
/**
 * This class is representing a session
 * holding current images
 * has unique number
*/
class Session
{
public:
	/// default constructor creating a session with no images 
   /// sets a unique session ID
	Session();

	///returns the image by index
	BasicImage** getImage(int index);

	///returns the image by name
	BasicImage** getImageByName(std::string name);

	///loads image in the session
	BasicImage* load(std::string fileName);

	int getId() const;

	void close(); //closes the image
	void save(); //saves the same file
	void saveAs(const char* image_file, std::string filename); //saves another file with same content

	void grayscale();/// grayscale
	void monochrome();///monochrome
	
	void negative();///negative
	void rotate(std::string direction);///rotates the image

	void undo();///undo
	void sessionInfo();///Info for the current session
private:
	int getIndexByName(const char* filename);
	std::vector<std::string> command;///in order to make the undo command, we have to collect commands in a vector
	

	std::vector<BasicImage**> images;
    int ID; ///makes unique session

};

