// Lecture13.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Date.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Date d1(3, 2021, 24);
	Date d3;
	d1.showDate();
	
	string s1 = d1.isLeapYear() ? " is Leap Year" : " is Not Leap Year";		//Using tertiary conditional operator ?:
	cout << d1.getYear() << s1.c_str() << endl;

	Date d2(3, 2021, 25);
	string s2 = (d1 == d2) ? "Yes" : "No";
	cout << "Is d1 equal to d2? " << s2.c_str() << endl;

	cout << d1.convert() << endl;

	string s3 = (d1 > d2) ? "Yes" : "No";
	cout << "Is d1 larger than d2? " << s3.c_str() << endl;
	cout << "Day of the Week: " << d2.dayOfWeek() << endl;
	cout << "Name of the day: " << d2.nameOfDay() << endl;
	cout << "Is D2 a weekday: " << d2.isWeekDay() << endl;
	cout << "I O capabilities" << endl;
	cout << "Please enter Date #1: (MM/DD/YYYY)" << endl;
	cin >> d3;
	cout << d3 <<  "Was succesfuly inserted into the outstream" << endl;




	d2.nextDay();

	cout << "D2 incremented +1 day: " << d2.convert()<< " " << d2.dayOfWeek() << " " << d2.nameOfDay() << endl;
}
