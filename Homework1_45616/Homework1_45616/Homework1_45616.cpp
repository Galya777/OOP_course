#include <iostream>
#include "MyString.h"
#include "Garage.h"
#include "Vehicle.h"
const std::size_t MAX = 100;
using namespace std;
int main()
{
    size_t capacity;
    cout << "Enter the capacity of your garage: ";
    cin >> capacity;
    Garage garage = capacity;
    MyString registration;
    MyString description;
    char* descr=new (nothrow) char[MAX];
    char* reg= new (nothrow) char[MAX];
    size_t park;
    char* coomand = new(nothrow) char[MAX];
    cout << "Enter if you want to add or remove a car: ";
    cin.ignore(MAX, '\n');
    cin.getline(coomand, MAX);
    size_t counter = 0;
    while (strcmp(coomand, "ready") != 0) {
        if (strcmp(coomand, "add") == 0) {
            if (counter == capacity) {
                cout << "There is no more space! Try to remove a car.";
                cin.ignore(MAX, '\n');
                cin.getline(coomand, MAX);
            } else {
                cout << "Enter the description:  ";
                cin.getline(descr, MAX);
                cout << "Enter the registration:  ";
                cin.getline(reg, MAX);
                if (garage.find(reg) != nullptr) {
                    cout << "TThis registration is used!" << endl;
                    cin.getline(reg, MAX);
                }  cout << "Enter the number of park places:  "; 
                cin >> park;
                counter += park;
                if (counter > capacity) {
                    cout << "There is not enough space for this vehicle."<<endl;
                }else {
                    Vehicle vec = { reg, descr, park };
                    garage.insert(vec);
                }
                cout << "Enter if you want to add or remove a car: ";
                cin.ignore(MAX, '\n');
                cin.getline(coomand, MAX);
            }
        }
        else if (strcmp(coomand, "remove") == 0) {
            cout << "Please, enter the registration of the car you want to remove: ";
            cin.getline(reg, MAX);
            garage.erase(reg);
            cout << "Enter if you want to add or remove a car: ";
            cin.getline(coomand, MAX);
        }
        else if (strcmp(coomand, "print") == 0) {
            for (size_t i = 0; i < garage.size(); ++i) {
                cout << garage[i].description() << " " << garage[i].registration() << " " << garage[i].space() << endl;
            } cout << "Enter if you want to add or remove a car: "; 
            cin.getline(coomand, MAX);
        }else {
            cout << "Command not found! Try another one: ";
            cin.getline(coomand, MAX);
        }
    }
    delete[] descr;
    delete[] reg;
    delete[] coomand;
    return 0;
}

