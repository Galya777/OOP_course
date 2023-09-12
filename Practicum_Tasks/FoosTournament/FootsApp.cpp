#pragma warning(disable:4996)
#include <iostream>
#include "SoftwareEngineer.h"
#include "GradeConstants.h"
#include "FoosballTournament.h"

void testTournaments();
int main()
{
	testTournaments();

	int x = 5;
	int y = x;
	int z(x);



	return 0;
}

void testTournaments()
{
	SoftwareEngineer peshe("Peshe", Grade::JuniorDev, 999999);
	SoftwareEngineer goshe("Goshe", Grade::JuniorDev, 799999);
	Team pesheGoshe = Team(peshe, goshe);

	SoftwareEngineer yasen("Krasen", Grade::JuniorDev, 6000);
	SoftwareEngineer krasen("Yasen", Grade::JuniorDev, 6001);
	Team yasenKrasen = Team(yasen, krasen);

	Team pesheYasen = Team(peshe, yasen);
	Team gosheKrasen = Team(goshe, krasen);

	FoosballTournament tournament2019;
	tournament2019.registerTeam(pesheGoshe);
	tournament2019.registerTeam(yasenKrasen);
	tournament2019.registerTeam(pesheYasen);
	tournament2019.registerTeam(gosheKrasen);

	tournament2019.begin();

	
}