#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

class GradesReport {
  private:
    vector<Student> students;

  public:
    GradesReport(){};       //Was missing {}
    GradesReport(vector<Student> students) {this->students = students;}
    
    Student* getStudent(int id);
    vector<Student> getStudents() {return students;}
    
    void addStudent(Student student) {students.push_back(student);}
    void print();
};