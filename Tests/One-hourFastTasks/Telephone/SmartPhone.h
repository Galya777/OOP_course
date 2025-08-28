//
// Created by galya777 on 24.08.25 г..
//

#ifndef OOP_COURSE_SMARTPHONE_H
#define OOP_COURSE_SMARTPHONE_H

#endif //OOP_COURSE_SMARTPHONE_H

#include "Telephone.h"

class SmartPhone: public Telephone{

public:
    SmartPhone(const char* model, const char* brand, double price,const char* os, int memory ){
        os = nullptr;
        init(model, brand, price, os, memory);
    };
    SmartPhone(){
        os = nullptr;
        init("", "", 0.0, "", 0);
    };
    SmartPhone(const SmartPhone& other){
        copy(other);
    };
    SmartPhone& operator=(const SmartPhone& other){
        if(this!=&other){
            del();
            copy(other);
        }
        return *this;
    };
    ~SmartPhone() override {
        del();
    };
    Telephone* clone() const override { return new SmartPhone(*this); }
    //getters
    char* getOs() const{
        return this->os;
    };
    int getMemory() const{
        return this->memory;
    };
    double getPrice() const override{
      return calculatePrice();
    };

    //setters
    void setOs(const char* os){
        os = nullptr;
        this->os=new char[strlen(os)+1];
        strcpy(this->os, os);
    };
    void setMemory(int memory){
        if(memory>=0){
            this->memory=memory;
        }else{
            std::cout<<"Invalid memory!";
        }
    };

private:
    void init(const char* model, const char* brand, double price,const char* os, int memory ){
        setModel(model);
        setBrand(brand);
        setOs(os);
        setMemory(memory);
    };

    void copy(const SmartPhone& other){
        setModel(other.model);
        setBrand(other.brand);
        setOs(other.os);
        setMemory(other.memory);
    };
    void del(){
        delete[] os;
        os = nullptr;
    };

    double calculatePrice() const{
        return price +1.0 * memory;
    }

    char* os{};
    int memory{};

};