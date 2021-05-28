#include <iostream>
#include <algorithm>
#include "course.h"
#include "student.h"
#include "grades_report.h"

void GradesReport::print() {
    for (Student &student : students) {     //for each example
        student.print();
        cout << endl << endl;
    }

    /*
    for (auto student = students.begin(); student != students.end(); ++student)
    {
        student->print();
        cout << endl << endl;
    }
    */
}

Student* GradesReport::getStudent(int id) {
    //for (auto student = students.begin(); student != students.end(); ++student)
    for (vector<Student>::iterator student = students.begin(); student != students.end(); ++student)
    {
        if (student->getId() == id)
            return &*student;
    }

    return NULL;
}
