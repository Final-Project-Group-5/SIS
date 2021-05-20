#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

class Course {
  public:
    const static int SIZE = 6;

  private:
    char code[SIZE];
    int credits;
    char grade;

    int get_numeric_grade(char letter_grade);

  public:
    Course(char code[], int credits, char grade);
    char* getCode() {return code;};
    int getCredits() {return credits;}
    char getGrade() {return grade;}

    void setCode(char code[]);
    void setCredits(int credits) {this->credits = credits;}
    void setGrade(char grade) {this->grade = grade;}

    double calculatePoints();
    void print();
};

#endif