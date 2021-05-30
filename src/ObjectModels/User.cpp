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
    void showName();
    void showID();
    int getUserID();
    void showOptions();

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

void User::showID()
{
    cout << userID << endl;
}

int User::getUserID()
{
    return userID;
}
