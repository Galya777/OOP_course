#pragma once
const int MAX = 128;
class Beer 
{
public:
	Beer();
	Beer(const char* br, int vol);
	void setBrand(const char* brand);
	void setVolume(int vol);
	const char* getBrand();
	int getVolume();
	void add(Beer beer1, int volume);
	bool check(Beer beer1);
private:
	char brand[MAX];
	int volume;
};

