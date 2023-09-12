//Галя Георгиева Додова 45616
//Visual C++
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Store_Builder.h"
#include "Conrfigurator.h"
#pragma warning(disable:4996)
using namespace std;
int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++) {
        cout << "argv" << i << ": " << argv[i] << endl;
    }
    if (argc < 2) {
        std::cout << "Usage: prog.exe <imput file>" << std::endl;
    }
    Store_Builder build;
    build.readFromFile(argv[2]);
    int requirements;
    std::cout << "Enter the number of requirements: ";
    std::cin >> requirements;
    Requirement req;  
    for (int i = 0; i < requirements; ++i) {
        int number;
        std::cout << "How many configurations will you have it your requirement?";
        std::cin >> number;
        req.enterRequirement(number);
        Conrfigurator configurator(build.ReturnStore(), req);
        configurator.createConfig();
        if (configurator.isEmpty() == true) {
            std::cout << "Sorry, we cannot make a configuration based on this store and this require.";
        }  else {
            time_t t = time(0);
            struct tm* now = localtime(&t);
             char name[100];
            strftime(name, 80, "%Y-%m-%d.", now);
            std::fstream configSave;
            configSave.open(name, std::ios::app);
            configurator.returnConfig().writeToFile(configSave);
            std::cout << "Your configuration is created successfully!";
            configurator.returnConfig().printComponents();

        }
    }
    build.save(argv[2]);
    return 0;
}
