#pragma once
#include "Store.h"
#include "Requirement.h"
#include "Configuration.h"
#include "Store_Builder.h"
class Conrfigurator: public Store, Configuration
{
public:
	Conrfigurator(const Store& store, Requirement& req);
	Conrfigurator();
	Configuration createConfig();
	bool isEmpty();
	Configuration returnConfig();
	
private:
	Store store;
	Requirement req;
	Configuration con;
};

