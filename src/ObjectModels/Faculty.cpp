#include "./User.cpp"
#include "./Course.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

class Faculty : public User
{
private:
    vector<Course*> courses;

public:
    Faculty() {}
    Faculty(int, string, string, string, string, vector<Course*>);
    ~Faculty();

    void listClasses();
    void editGrades();
    void runCommandCode(int);
};

Faculty::Faculty(int id, string username, string name, string pass, string userRole, vector<Course*> classList = {})
{
    this->userID = id;
    this->userName = username;
    this->fullName = name;
    this->password = pass;
    this->role = userRole;
    this->optionsList = {"Faculty Menus: ", "1   Print your course list", "2   Edit a students grade"};
    courses = classList;
};

Faculty::~Faculty()
{
    for(Course* c: this->courses){
        delete c;
    }
}


void Faculty::listClasses()
{
    cout << "This is the list of courses you are instructing: \n\n"
         << endl;
    for (Course* course : this->courses)
    {
        (*course).printReportFaculty();
    }
}

void Faculty::editGrades()
{
    // string courseCode;
    // int studentID;
    // char letterGrade;
    // vector<Student> tempRoster = {};

    // this->listClasses();
    // cout << endl;
    // cout << "\nPlease select the course in which the student whos grade you would like to modify is enrolled: ";
    // cin >> courseCode;
    // cout << endl;

    // // Here we need to figure out how to read from the SIS.studentsRoster follow the code below

    // for (Student student : studentRoster)
    // {
    //     for (Course course : student.getClassList())
    //     {
    //         if (courseCode == course.getCourseCode()) //try to find a match from the input
    //         {
    //             tempRoster.push_back(student);
    //         }
    //         continue;
    //     }
    // }

    // cout << courseCode << " Student Roster" << endl;
    // for (Student s : tempRoster)
    // {
    //     cout << s.getName() << " " << s.getUserID() << endl;
    // }
    // cout << "\nPlease Select the student ID number of with the grade you would like to modify: ";
    // cin >> studentID;
    // cout << endl;
    // for (Student s : tempRoster)
    // {
    //     if (studentID == s.getUserID())
    //     {
    //         for (Course course : s.getClassList())
    //         {
    //             if (courseCode == course.getCourseCode()) //try to find a match from the input
    //             {
    //                 course.printReport();
    //                 cout << "Please enter the Letter grade that you would like to give this student: ";
    //                 cin >> letterGrade;
    //                 course.setGrade(letterGrade);
    //                 course.printReport();
    //             }
    //         }
    //     }
    // }

    // /*
    // for(Student student: SIS.studentRoster){
    //       int indexOf = find(student.courses.begin(), student.courses.end(), course);
    //       if(indexOf != student.courses.end())
    //       {
    //           student.courses[indexOf].printreport();
    //       }
    //  }
    //  */
}
void Faculty::runCommandCode(int command)
{
        switch(command){
        case 1:
            this->listClasses();
            break;
        case 2:
             this->editGrades(); 
            break;
        case 9:
            this-> showOptions();
            break;
        default:
            cout << "Invalid command, please eneter another command code." << endl;
            // this->showOptions();
        };
    
}
