#include <iostream>
using namespace std;
struct Distance {
	double feet;
	double inche;
};
void distance(Distance num, Distance num1) {
	double feets = num.feet + num1.feet;
	double inches = num.inche + num1.inche;
	if (inches >= 12) {
		inches = inches - 12;
		feets++;
	}
	cout << feets << "'" << inches << "''";
}
int main()
{
	Distance num = { 4,9 };
	Distance num1 = { 2,7 };
	distance(num, num1);

	return 0;
}
