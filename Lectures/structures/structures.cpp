#include <iostream>
using namespace std;
const int MAX = 100;
struct Book {
	char name[MAX];
	char author[MAX];
	char genre[MAX];
	double prize;
	int countofsolds;
};
void initialize(Book& b) {
	cin >> b.name;
	cin >> b.author;
	cin >> b.genre;
	cin >> b.prize;
	cin >> b.countofsolds;
}
void printlower(Book* books, size_t count) {
	double lower = books[0].prize;
	int bookswithlow = 0;
	for (int i = 0; i < count; ++i) {
		if (books[i].prize < lower) {
			lower = books[i].prize;
			bookswithlow = i;
		}
	}
}
int main()
{
	Book b;
	for (int i = 0; i < 10; i++) {
		initialize(b);
	}
	return 0;
}
