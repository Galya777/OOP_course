#include <iostream>
#include "Vector.h"
#include "Vector.cpp"
using namespace std;
Vector vec;
void add(int num) {
	
 vec.push_back(num);
}
void del(int num) {
	std::cin >> num;
	for (int i = 0; i < vec.size; i++) {
		if (vec.at(i) == num) {
			vec.erase(i--);
		}
	}
}void find(int number) {
	int ind = -1;
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i) == number) {
			ind = i;
			break;
		}
	}
	cout << ind << endl;
} int get(int index){
	return vec.at(index);
} 
int main()
{
	
	vec.push_back(5);
	vec.push_back(8);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(9);

	// Since at(..) returns int&, which gives us
	// the actual element wihout copying it, we
	// can change the element in the array like this:
	vec.at(2) = -5; // Changes the element at index 2

	// Printing each element
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec.at(i) << ' ';

	std::cout << std::endl;

	// What about a lot more elements?
	Vector vec2;  // Calling the default constructor

	// We can easily add a lot of elements
	for (int i = 0; i <= 100; i++)
		vec2.push_back(2 * i);  // adding all the 

	// And printing each one
	for (int i = 0; i < vec2.size(); i++)
		std::cout << vec2.at(i) << ' ';
   
	return 0;
}
