#include <string>
#include <vector>
#pragma once

using namespace std;

class User{
public:
    User(int, string, string, string, string);
    void showOptions();

private:
    int userID;
    string userName,
        password,
        fullName;
    string role;
    vector<string> optionsList;

};

User::User(int id, string username, string name, string pass, string userRole){
    userID = id;
    userName = username;
    fullName = name;
    password = pass;
    role = userRole;

    
    vector<string> studentOptions = {"1   Print Grade Report", "2    Register for Classes"};
    vector<string> staffOptions = {"1   Print Student Report", "2    Add an instructor to a course", "3    Add a course w/o an instructor"};
    vector<string> facultyOptions = {"1   Print your course list", "2    Edit a students grade"};


        role == "student"
            ? optionsList = studentOptions
            :role == "faculty"
                ? optionsList = facultyOptions
            : optionsList = staffOptions;


}

void User::showOptions()
{
    for(string option: this->optionsList){
            cout << option << endl;
        };
    
}