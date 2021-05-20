#include <iostream>
#include <iomanip>
#include "course.h"

using namespace std;

const int Course::SIZE;
Course::Course(char code[], int credits, char grade) {
    for (int i=0; i < SIZE; i++)
        this->code[i] = code[i];
        this->credits = credits;
        this->grade = grade;
}

void Course::setCode(char code[]) {
    for (int i=0; i < SIZE; i++)
        this->code[i] = code[i];
}

double Course::calculatePoints() {
    return credits * get_numeric_grade(grade);
}

void Course::print() {
    cout << setw(15) << left << code  << setw(15) << left << credits << setw(15) << left << grade << endl;
}

int Course::get_numeric_grade(char letter_grade) {
	if (letter_grade == 'A')
		return 4;
	else if (letter_grade == 'B')
		return 3;
	else if (letter_grade == 'C')
		return 2;
	else if (letter_grade == 'D')
		return 1;
	else
		return 0;
}