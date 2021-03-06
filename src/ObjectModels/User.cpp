#include <string>
#include <vector>
#pragma once

using namespace std;

class User
{
public:
    User() {}
    User(int, string, string, string, string);
    string getName();
    string getUserName();
    string getPass();
    string getRole();
    void showID();
    void showName();
    int getUserID();
    void showOptions();
    void runCommandCode(int);
    friend ostream& operator<<(ostream&, User&);

protected:
    int userID;
    string userName,
        password,
        fullName;
    string role;
    vector<string> optionsList;
};

User::User(int id, string username, string name, string pass, string userRole)
{
    userID = id;
    userName = username;
    fullName = name;
    password = pass;
    role = userRole;
}

void User::showOptions()
{
    for (string option : this->optionsList)
    {
        cout << option << endl;
    };
}

string User::getName()
{
    return fullName;
}

void User::showName()
{
    cout << fullName << endl;
}

string User::getUserName()
{
    return userName;
}

string User::getPass()
{
    return password;
}

int User::getUserID()
{
    return userID;
}

string User::getRole()
{
    return role;
}

ostream& operator<<(ostream& out, User& u) {

    out << u.getUserID() <<"," << u.getUserName() <<"," << u.getName() <<"," << u.getPass() <<"," << u.getRole() <<",";

    return out;
}