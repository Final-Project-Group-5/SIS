#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "course.h"

using namespace std;

class Student {
  private:
    int id;
    string name;
    vector<Course> courses;

  public:
    Student(int id, string name) {this->id = id; this->name = name;};
    Student(int id, string name, char code[], int credits, char grade);

    int getId() {return id;}
    string getName() {return name;}
    vector<Course> getCourses() {return courses;}

    void setId(int id) {this->id = id;}
    void setName(string name) {this->name = name;}

    void addCourse(Course course);
    double calcualteGPA();
    int totalCredits();
    void print();

    bool operator==(const Student& s) {return this->id == s.id;};
};

#endif