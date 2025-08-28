//
// Created by galya777 on 24.08.25 г..
//
#include "Telephone.h"
#include "SmartPhone.h"
#include "Store.h"
int main(){

    double budget=15000.50;
    Store store= Store(budget);

    Telephone t1= Telephone("3320", "Nokia", 35.59);
    store.addPhone(t1);
    SmartPhone s1=SmartPhone("galaxy z fold 3", "Samsung", 1250.50, "android", 128);
    store.addPhone(s1);
    SmartPhone s2=SmartPhone(" 24 pro", "Apple", 1350.50, "ios", 256);
    store.addPhone(s2);

    store.removeCheapestSamsung();
    store.removePhone("galaxy z fold 3", "Samsung");

    return 0;
}