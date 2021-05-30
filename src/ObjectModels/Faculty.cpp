#include "./User.cpp"
#include "./Course.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

class Faculty : public User
{
private:
    vector<Course> courses;

public:
    Faculty() {}
    Faculty(int, string, string, string, string, vector<Course>);

    void listClasses();
    void editGrades(vector<Student> studentRoster);
};

Faculty::Faculty(int id, string username, string name, string pass, string userRole, vector<Course> classList = {})
{
    this->userID = id;
    this->userName = username;
    this->fullName = name;
    this->password = pass;
    this->role = userRole;
    this->optionsList = {"Faculty Menus: ", "1   Print your course list", "2   Edit a students grade"};
    courses = classList;
};

void Faculty::listClasses()
{
    cout << "This is the list of courses you are instructing: " << endl;
    for (Course course : this->courses)
    {
        course.printReportFaculty();
    }
}

void Faculty::editGrades(vector<Student> studentRoster)
{
    string c, student;
    vector<Student> tempRoster = {};
    this->listClasses();
    cout << "\nPlease enter the course code of the class in which the students whos grade you would like to modify is enrolled" << endl;
    cin >> c;

    // Here we need to figure out how to read from the SIS.studentsRoster follow the code below

    for (Student student: studentRoster)
    {
      for (Course course: student.getClassList())
      {
        if(c == course.getCourseCode()) //try to find a match from the input
        {
          tempRoster.push_back(student);
          cout << "test" << endl;
        }
        else
          continue;        //for testing purposes | delete else if it works
      }
    }




    /*
    for(Student student: SIS.studentRoster){
          int indexOf = find(student.courses.begin(), student.courses.end(), course);
          if(indexOf != student.courses.end())
          {
              student.courses[indexOf].printreport();
          }
     }
     */
}
