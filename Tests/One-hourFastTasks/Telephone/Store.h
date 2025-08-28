//
// Created by galya777 on 24.08.25 г..
//

#ifndef OOP_COURSE_STORE_H
#define OOP_COURSE_STORE_H

#endif //OOP_COURSE_STORE_H
#include"Telephone.h"
#include "SmartPhone.h"
class Store{

public:
    Store(double budget){
        this->budget=budget;
        this->currentBudget=budget;

        this->phoneCapacity=2;
        this->phoneSize=0;
        phones = new Telephone*[phoneCapacity];
    };

    ~Store(){
        for (int i = 0; i < phoneSize; ++i) {
            delete phones[i];
        }
        delete[] phones;
    };

    void addPhone(const Telephone& phone){
        Telephone* heapCopy = phone.clone();
        double price = heapCopy->getPrice();

        if (currentBudget - price >= 0) {
            if (phoneSize >= phoneCapacity) resize();
            phones[phoneSize++] = heapCopy;
            currentBudget -= price;
        } else {
            std::cout << "Not enough budget!\n";
            delete heapCopy;
        }
    };

    void removePhone(const char* model, const char* brand){
        int idx = foundPhoneHere(model, brand);
        if (idx == -1) {
            std::cout << "Phone not found here!\n";
            return;
        }

        currentBudget += phones[idx]->getPrice();

        delete phones[idx]; // FIX: реално изтриваме телефона

        // FIX: изместваме елементите наляво и намаляваме размера
        for (int i = idx; i < phoneSize - 1; ++i) {
            phones[i] = phones[i + 1];
        }
        --phoneSize;
    };

    void removeCheapestSamsung(){
        int idx = -1;
        double minPrice = 1e18;

        for (int i = 0; i < phoneSize; ++i) {
            if (std::strcmp(phones[i]->getBrand(), "Samsung") == 0) {
                double p = phones[i]->getPrice();
                if (p < minPrice) {
                    minPrice = p;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            std::cout << "No Samsung phones found!\n";
            return;
        }

        currentBudget += phones[idx]->getPrice();
        delete phones[idx];

        for (int i = idx; i < phoneSize - 1; ++i) {
            phones[i] = phones[i + 1];
        }
        --phoneSize;
    };

    int foundPhoneHere(const char* model, const char* brand){
        for (int i = 0; i < phoneSize; ++i) {
            if(strcmp(phones[i]->getModel(), model)==0 && strcmp(phones[i]->getBrand(), brand)==0){
                return i;
            }
        }

       return -1;
    };

private:
    Telephone** phones;
    int phoneSize;
    int phoneCapacity;

    double currentBudget;
    double budget;

    void resize(){
        phoneCapacity *= 2;
        Telephone** tmp = new Telephone*[phoneCapacity];
        for (int i = 0; i < phoneSize; ++i) tmp[i] = phones[i];
        delete[] phones;
        phones = tmp;
    };
};