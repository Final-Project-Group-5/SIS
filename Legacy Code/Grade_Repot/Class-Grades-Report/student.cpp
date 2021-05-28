#include <iostream>
#include <iomanip>
#include "course.h"
#include "student.h"

using namespace std;

Student::Student(int id, string name, char code[], int credits, char grade) {
    this->id = id;
    this->name = name;
    Course course(code, credits, grade);
    courses.push_back(course);
}

void Student::addCourse(Course course) {
    courses.push_back(course);
}
double Student::calcualteGPA() {
    double gpaNumerator = 0.0;
    for (auto course = courses.begin(); course != courses.end(); ++course)
	{
        gpaNumerator += course->calculatePoints();
	}

    return gpaNumerator/totalCredits();
}

int Student::totalCredits() {
    int totalCredits = 0;
    for (auto course = courses.begin(); course != courses.end(); ++course)
	{
        totalCredits += course->getCredits();
	}

    return totalCredits;
}

void Student::print() {
    cout << "Student Name: " << name << endl
        << "Student ID Number: " << id << endl << endl
        << setw(15) << left << "Course Code" << setw(15) << left << "Course Credits" << setw(15) << left <<"Course Grade" << endl
        << "------------------------------------------" << endl;
        for (auto course = courses.begin(); course != courses.end(); ++course)
        {
            course->print();
        }

    cout << "\nTotal Semester Credits Completed: " << totalCredits() << endl;
    cout << "Semester GPA: " << fixed << setprecision(2) << calcualteGPA() << endl; //Added fixed & setprecision
}