#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#pragma once

using namespace std;

class Course
{
public:
    Course(string, int, char, string);
    string getCourseCode();
    void printReport();
    void printReportFaculty();
    string getInstructor();
    int getCredits();
    int getGPV();
    void setGrade(char);

private:
    string courseCode,
        instructor;
    int gpv,
        credits;
    char letterGrade;
};

Course::Course(string code, int credit, char grade = 'N', string professor = "TBD")
{
    instructor = professor;
    courseCode = code;
    letterGrade = grade;
    credits = credit;
    switch (grade)
    {
    case 'A':
        gpv = 4 * credits;
        break;
    case 'B':
        gpv = 3 * credits;
        break;
    case 'C':
        gpv = 2 * credits;
        break;
    case 'D':
        gpv = 1 * credits;
        break;
    default:
        gpv = 0;
        break;
    }
};

string Course::getCourseCode()
{
    return courseCode;
};

string Course::getInstructor()
{
    return instructor;
};

int Course::getCredits()
{
    return credits;
};

int Course::getGPV()
{
    return gpv;
};

void Course::printReport()
{
    cout << courseCode << setw(15) << instructor << setw(15) << to_string(credits) << setw(15) << letterGrade << setw(5) << to_string(gpv) << endl;
}

void Course::printReportFaculty()
{
    cout << courseCode << endl;
}
void Course::setGrade(char grade)
{
    letterGrade = toupper(grade);
};
