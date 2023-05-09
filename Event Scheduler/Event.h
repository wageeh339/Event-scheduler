#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

class Event

{

public:
	string Name;
	int id;
	int StartDay;
	string Place;
	int StartTime;
	int EndTime;
	int RemTime;
	bool Done;

	Event()
	{
		Done = 0;
	}

	

	void Event::calcRemTime(int date){
		RemTime = date - StartDay;
	}
};

