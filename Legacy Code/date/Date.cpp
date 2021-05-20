//Implementation of Date Class 6,7,9,10, 11
#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Date::showDate() {
	//Display format is: yyyy-MM-dd e.g. 2021-01-15
	cout << setfill('0') << setw(4) << year << "-" << setw(2) << month << "-" << setw(2) << day << endl;
}																//accessor method

//Utility methods
bool Date::isLeapYear() {
	// Divisible by 400 OR Divisible by 4 but not divisible by 100, Use modulus or remainder operator (returns remainder of integer division)
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int Date::convert() const {
	return year * 10000 + month * 100 + day;
}

int Date::dayOfWeek() {
	int m = 0, y = 0;																		/* Algorithm from book */
	if (month < 3) {																		//If the month is less than 3
		m = month + 12;																		//month = month + 12
		y = year - 1;																		//year = year - 1
	}																						//EndIf

	int century = int(y / 100);																//Set century = int(year / 100)
	y = y % 100;																			//Set year = year % 100
	int T = day + int(26 * (m + 1) / 10) + y + int(y / 4) + int(century / 4) - 2 * century; //Set variable T = day + int(26 �(month + 1) / 10) + year + int(year / 4) + int(century / 4) - 2 � century
	int dd = T % 7;																			//Set dd = T % 7
	if (dd < 0) {																			//If dd is less than 0
		dd = dd + 7;																		//Set dd = dd + 7
	}																						//EndIf

	return dd;
}

bool Date::operator==(const Date& date2) {
	return (this->year == date2.year) && (this->month == date2.month) && (this->day == date2.day);
}

bool Date::operator>(const Date& date2) {
	int d1 = this->convert();
	int d2 = date2.convert();
	return d1 > d2;
}

string Date::nameOfDay(){
	switch(dayOfWeek()){
        case 1:
            return "Sunday";
        case 2:
            return "Monday";
        case 3:
            return "Tuesday";
        case 4:
            return "Wednesday";
		case 5:
            return "thursday";
		case 6:
            return "Friday";
        default:
            return "Saturday";
    }
};

bool Date::isWeekDay(){
	int day = dayOfWeek();
	return day > 1 && day < 7;
};

void Date::nextDay(){
	int newDay = this -> day + 1,
		newMonth = this -> month,
		newYear = this -> year;

	if(newDay > 30){
		newDay -= 30;
		newMonth++;
	};
	if(this -> month > 12){
		newYear++;
	};

	setDate(newMonth, newYear, newDay);
};

void Date::priorDay(){
	int newDay = this -> day - 1,
		newMonth = this -> month,
		newYear = this -> year;

	if(newDay < 1){
		newDay += 30;
		newMonth--;
	};
	if(this -> month < 1){
		newYear--;
	};

	setDate(newMonth, newYear, newDay);
};

Date Date::operator+(int nDays){
	Date* newDate = new Date(*this);
	newDate -> day += nDays;
	while(newDate -> day > 30){
		newDate -> day -=30;
		newDate -> month +=1;
		if(newDate -> month > 12){
			newDate -> year++;
			newDate -> month = 1;
		}; 	
	}; 
	return *newDate;
};




