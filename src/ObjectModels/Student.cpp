#include "./User.cpp"
#include "./Course.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

class Student : public User
{ // Sub class
private:
    vector<Course> courses;

public:
    Student() {}
    Student(int, string, string, string, string, vector<Course>);

    void printReport();              // Prints current courses
    void registerForCourse(SIS&); // Friend of SIS
};

Student::Student(int id, string username, string name, string pass, string userRole, vector<Course> classList = {})
{
    this->userID = id;
    this->userName = username;
    this->fullName = name;
    this->password = pass;
    this->role = userRole;
    this->optionsList = {"Students Menu:", "1   Print Grade Report", "2   Register for Classes"};
    courses = classList;
};

void Student::printReport()
{
    // Header for report
    cout << "Report for " << this->getName() << ".\nID number: " << this->getUserID() << endl;
    cout << "Course" << setw(15) << "Instructor" << setw(15) << "Credits" << setw(15) << "Grade" << endl;
    cout << setw(60) << setfill('_') << "\n"
         << setfill(' ') << endl;

    // For loop prints report from vector
    for (Course course : this->courses)
    {
        course.printReport();
    }
}

/*                           *Moved to SIS obj*
            To run, type this in main: Student.registerForCourse(_);

void registerForCourse()
{
    string courseCode;
    cout << "Here are the avalible courses to take this semester: " << endl;
    // show list of courses SIS.availCourses
    cout << "Please enter in the course code you wish to registar for: ";
    // cin int for course ID
    cin >> courseCode;
    cout << "You entered: " << courseCode << endl;
    // add course to student course vector
    // if course not avalible send fail
}
*/
