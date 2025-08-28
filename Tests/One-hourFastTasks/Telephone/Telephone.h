//
// Created by galya777 on 24.08.25 г..
//

#ifndef OOP_COURSE_TELEPHONE_H
#define OOP_COURSE_TELEPHONE_H
#include <cstring>
#include <iostream>

class Telephone {
public:
    Telephone(const char* model, const char* brand, double price){
        model = nullptr;
        brand = nullptr;
        init(model, brand, price);
    };
    Telephone(){
        model = nullptr;
        brand = nullptr;
        init("", "", 0.0);
    };
    Telephone(const Telephone& other){
        model = nullptr;
        brand = nullptr;
        copy(other);
    };
   Telephone& operator=(const Telephone& other){
       if(this!=&other){
           del();
           copy(other);
       }
       return *this;
   };
  virtual ~Telephone(){
       del();
   };
    virtual Telephone* clone() const { return new Telephone(*this); }

   //getters
   char* getModel() const{
       return this->model;
   };
   char* getBrand() const{
       return this->brand;
   };
    virtual double getPrice() const { return price; }

   //setters
   void setModel(const char * model){
       delete[] this->model;
       if (!model) model = "";
       this->model=new char[strlen(model)+1];
       strcpy(this->model, model);
   };
   void setBrand(const char* brand){
       delete[] this->brand;
       if (!brand) brand = "";
       this->brand=new char[strlen(brand)+1];
       strcpy(this->brand, brand);
   };
  void setPrice(double price){
       if(price>=0.0){
           this->price=price;
       }else{
           std::cout<<"Invalid price!";
       }
   };

private:
    void init(const char* model, const char* brand, double price){
        setModel(model);
        setBrand(brand);
        setPrice(price);
    };
void copy(const Telephone& other){
    setModel(other.model);
    setBrand(other.brand);
    setPrice(other.price);
};
void del(){
    delete[] model;
    delete[] brand;
    model = nullptr;
    brand = nullptr;
};

protected:
    char * model;
   char * brand;
   double price;
};


#endif //OOP_COURSE_TELEPHONE_H
