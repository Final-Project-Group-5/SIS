#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "grades_report.h"
#include "student.h"
#include "course.h"

using namespace std;

void open_input_file(ifstream& inFile);

const string filename = "grades_report.dat";
int main() {
    GradesReport gradesReport;

    ifstream inFile;
    open_input_file(inFile);

    string line;
    while(getline(inFile, line)) {
        string idStr, lname, fname, codeStr, creditsStr, gradeStr;

        stringstream lineStream(line);
        getline(lineStream, idStr, ' ');
        int id = stoi(idStr);
        getline(lineStream, lname, ' ');
        getline(lineStream, fname, ' ');
        string name = lname + " " + fname;
        getline(lineStream, codeStr, ' ');
        char code[Course::SIZE]; 
        for (int i=0; i < Course::SIZE; i++)
            code[i] = codeStr.c_str()[i];
        getline(lineStream, creditsStr, ' ');
        int credits = stoi(creditsStr);
        getline(lineStream, gradeStr, ' ');
        char grade = gradeStr.c_str()[0];

        Course course(code, credits, grade);
        Student* student = gradesReport.getStudent(id);

        if (student == NULL) {
            Student s(id, name);
            s.addCourse(course);    
            gradesReport.addStudent(s);        
        } else {            
            student->addCourse(course);
        }
    }

    gradesReport.print();

    return 0;
}

void open_input_file(ifstream& inFile) {
	inFile.open(filename.c_str());
	//if (inFile.fail()) throw filename;
    if (inFile.fail()) {
        cout << "File not found!!" << endl;
        exit(0);
    }
}