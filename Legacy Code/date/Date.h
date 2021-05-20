//Decleration of Date Class
#include <string>
#include <iostream>
using namespace std;


class Date {
private:
	int year;
	int month;
	int day;

public:
	Date(int m = 1, int y = 1, int d = 1) { month = m; year = y; day = d; }			//inline constructor method
	void setDate(int m = 1, int y = 1, int d = 1) { month = m; year = y; day = d; }	//inline mutator method

	//accessor methods
	void showDate(),
		nextDay(),
		priorDay();																
	int getYear() { return year; }

	//Utility methods
	bool isLeapYear(),
		isWeekDay();
	int convert() const;
	int dayOfWeek();
	string nameOfDay();

	bool operator==(const Date&);
	bool operator>(const Date&);
	Date operator+(int);
	
	friend ostream& operator<<(ostream& out, Date& d){
		out << d.day <<"/"<<d.month<<"/"<<d.year<<endl;
		return out;
	}

	friend istream& operator>>(istream& in, Date& d){
		char ch;
		in>> d.day;
		in>> ch;
		in>> d.month;
		in>> ch;
		in>> d.year;
		return in;
	}

};

