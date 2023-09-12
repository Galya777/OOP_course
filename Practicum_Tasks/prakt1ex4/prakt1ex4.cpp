#include <iostream>
using namespace std;
struct Student {
	char singleName[64];
	double facultitynumber;
};
void read(Student& student) {
	cin >> student.singleName;
	cin >> student.facultitynumber;
} void output(const Student& student) {
	cout << student.singleName << "  ";
	cout << student.facultitynumber << endl;
}
int main()
{
	const char MAX = 5;
	char name[MAX];
	Student student[MAX];
	for (int i = 0; i < MAX; i++) {
		read(student[i]);
	}
	for (int i = 0; i < MAX; i++) {
		output(student[i]);
	}
	return 0;
}
