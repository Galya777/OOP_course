//
// Created by galya777 on 25.08.25 г..
//

#ifndef OOP_COURSE_EBOOK_H
#define OOP_COURSE_EBOOK_H

#include "Book.h"
class EBook: public Book{

public:


private:
    void init( const char* format, int length ){

    };

    void copy(const EBook& other){

    };
    void del(){
        delete[] format;
        format = nullptr;
    };

    double calculatePrice() const{
        return price +0.1 * length;
    }


private:
char* format;
int length;

};
#endif //OOP_COURSE_EBOOK_H
