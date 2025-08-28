//
// Created by galya777 on 25.08.25 г..
//

#ifndef OOP_COURSE_BOOK_H
#define OOP_COURSE_BOOK_H

#include <cstring>

class Book{

public:
    Book(const char* title, const char* author, double price){
        init(title, author, price);
    };
    Book(){
        init("", "", 0.0);
    };
    Book(const Book& other){
        copy(other);
    };
    Book& operator=(const Book& other){
        if(this!=&other){
            del();
            copy(other);
        }
        return *this;
    };

    virtual ~Book(){
        del();
    };

    virtual Book* clone() { return new Book (*this);};


    //getters
    const char* getTitle() const{return this->title;};
    const char* getAuthor() const{return this->author;};
    const double getPrice() const{return this->price;};
    //setters
    void setTitle(const char* title) {
        this->title=new char[strlen(title)+1];
        strcpy(this->title, title);
        ; };
    void setAuthor(const char* author){
        this->author=new char[strlen(author)+1];
        strcpy(this->author, author);

    };

    virtual void setPrice(double price){
        this->price=price;
    };

protected:
    char* title;
char* author;
double price;

private:

void init(const char* title, const char* author, double price){
    setTitle(title);
    setAuthor(author);
    setPrice(price);
};
void copy(const Book& other){
    init(other.title, other.author, other.price);
};
void del(){
    delete[] title;
    delete[] author;
    title= nullptr;
    author= nullptr;
};

};


#endif //OOP_COURSE_BOOK_H
