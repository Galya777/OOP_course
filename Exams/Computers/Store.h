#pragma once
#include <vector>
#include"Component.h"
#include "Cpu.h"
#include "Hdd.h"
#include "Ram.h"
#include "BasicForStoreAndConfig.h"
#include <iostream>
class Store: public BasicForStoreAndConfig
{
public:
	Store();
	virtual void addComponent(Component& com);
	virtual void removeComponent(int i);
	
protected:
	Cpu cpu;
	Ram ram;
	Hdd hdd;
	
	
	
};

