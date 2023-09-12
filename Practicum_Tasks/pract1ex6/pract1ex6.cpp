#include <iostream>
using namespace std;
struct TimePeriod {
	int hours;
	int minutes;
	int seconds;
};
void print(TimePeriod &time) {
	if (time.seconds >= 60) {
		time.minutes++;
		time.seconds -= 60;
	} if (time.minutes >= 60) {
		time.hours++;
		time.minutes -= 60;
	}
	cout << time.hours << ":" << time.minutes << ":" << time.seconds<<endl;
}
void difference(TimePeriod& time1, TimePeriod& time2) {
	int hours = time1.hours - time2.hours;
	int minutes = time1.minutes - time2.minutes;
	int seconds = time1.seconds - time2.seconds;
	if (seconds >= 60) {
		minutes++;
		seconds -= 60;
	} if (minutes >= 60) {
		hours++;
		minutes -= 60;
	} if (minutes < 0) {
		hours--;
		minutes += 60;
	} if (seconds < 0) {
		minutes--;
		seconds += 60;
	}
	cout << hours << ":" << minutes << ":" << seconds;
}
int main()
{
	TimePeriod time1 = { 3,15,45 };
	TimePeriod time2 = { 2,30,15 };
	print(time1);
	print(time2);
	difference(time1,time2);

	return 0;
}