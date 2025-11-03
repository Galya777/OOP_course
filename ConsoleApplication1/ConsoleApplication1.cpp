#include <iostream>
using namespace std;
struct Complex {
	double real;
	double imag;
};
void ComplexNumber(Complex num) {
	double realpart = num.real;
	double imagpart = num.imag;
	cout << realpart << '+' << 'i' << '*' << imagpart;
}
int main()
{
	Complex num = { 5,6 };
	ComplexNumber(num);
	return 0;
}
