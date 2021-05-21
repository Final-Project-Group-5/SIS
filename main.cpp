#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class User {    // Base class
    
public:
    void getUser();             // User and password input
    bool authenticateUser();    // Return a letter that can be used in a case statement
                                // s = staff, f = faculty, u = student
    void printUser();           // Show user data
protected:
  struct user {
        string username, password;
        char role;              // role = s = staff, f = faculty, u = student
    } userInfo;
};

// Utility for class User
void User::getUser() {
    cout << "Enter Username: ";
    cin >> userInfo.username;
    cout << "Enter Password: ";
    cin >> userInfo.password;
}

void User::printUser() {
    cout << "Your username is: " << userInfo.username << endl;
    cout << "Your password is: " << userInfo.password << endl;
    cout << "Your role is: " << userInfo.role << endl;
}

bool User::authenticateUser() {     // authenticate against users.csv
    char role;
    // Find username
        // If username found, compare password
            // If valid password, set role = s / f / u
                // return true
            // Else not valid password,cout << "User not authenticated";
            // return false
        // Else not found, cout << "User not authenticated";
        // return false
    bool authorized;
    return authorized;    // role is: s = staff, f = faculty, u = student
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Student : public User {    // Sub class
private:
    // Vecotor to hold courses
    
public:
    void printCourses();    // Show courses currently taking
    void registerCourse();  // Register for a course (display list of courses avalible to take) (If D/F allow retake)
    void printGrades();     // Generate grades report
};

void Student::printCourses() {
    // pull data from vector and print
}

void Student::registerCourse() {
    // Show list of courses avalible to take
    // Enter course to register for
    // Search for course
        // If exists, Register, exit loop
            // Else, Invalid
    
}

void Student::printGrades() {
    // pull only grades/gpa from vector and print
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int main() {
    User person;
    person.getUser();
    person.printUser();
    
    
    return 1;
}
