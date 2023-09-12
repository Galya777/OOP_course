#pragma once
#include "BasicForStoreAndConfig.h"
#include "Configuration.h"
class Requirement: public BasicForStoreAndConfig
{
public:
	Requirement(Component comp);
	Requirement();
	bool hasSameTypes(Configuration& con);
	bool hasBetterCharacteristics(Configuration& con);
	void enterRequirement(int numberOfComponents);
private:
	virtual bool RepeatingTypes(Component comp);
};

