#include "Store.h"

Store::Store()
{
	components.push_back(Component());
	size++;
}
void Store::addComponent(Component& com)
{
	components.push_back(com);
	++size;
} void Store::removeComponent(int i)
{
	components.erase(components.begin() + i);
}


