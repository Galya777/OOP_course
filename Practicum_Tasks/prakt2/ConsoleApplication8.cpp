#include <iostream>
#include "Beer1.h"
int main()
{
	Beer b1;
	b1.getBrand("Stella Artois");
	b1.getVolume(500);
	Beer b2;
	int volume = 250;
	b1.add(b1, b2, volume);
	b1.check(b1, b2);

	return 0;
}