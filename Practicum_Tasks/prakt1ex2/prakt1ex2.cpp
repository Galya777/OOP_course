#include <iostream>
using namespace std;
struct Distance {
	double inches;
	double feet;
};
void distance(Distance num) {
	cout << num.feet << "'" << num.inches << "''";
}
int main()
{
	Distance num = { 10,5 };
	distance(num);
	return 0;
}