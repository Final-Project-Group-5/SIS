#include "./User.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

class Student : public User {    // Sub class
private:
    vector<string>& st;
    string fullName;
    
public:
    static const int PrintWidth = 10;           // Spacing of text in print report
    Student(vector<string>& arr) : st(arr){}    // Initialized vector contructor
    
    void printStReport(vector <string>);          // Prints current courses
    friend void registerForCourse();            // Friend of SIS
};

void Student::printStReport(vector <string>) {
    // Header for report
    cout << "Report for " << fullName << " ." << endl;
    cout << "Course" << setw(PrintWidth) << "Faculty" << setw(PrintWidth) << "Credits" << setw(PrintWidth) << "Grade" << endl;
    cout << setw(40) << setfill('_') << "\n" << endl;
    
    // For loop prints report from vector
    for(int i = 0; i < st.size(); i++) {
        cout << st[i] << setw(PrintWidth) << endl;
    }

}

void registerForCourse (Student student) {
    string courseCode;
    cout << "Here are the avalible courses to take this semester: " << endl; // show list of courses SIS.availCourses
    cout << "Please enter in the course code you wish to registar for: ";// cin int for course ID
    getline(cin, courseCode);
    cout << "You entered: " << courseCode << endl;
    // add course to student course vector
    // if course not avalible send fail
    
}
/*
void registerForCourse() {
    // Show list of courses avalible to take
    // Enter course to register for, while loop
    // Search for course
        // If exists, Check for D/F
            // If D/F, Register
            // Else, "unable to take course, you got a C/better"
        // Else, "Course does not exist"
    // Exit Loop?
}
*/
