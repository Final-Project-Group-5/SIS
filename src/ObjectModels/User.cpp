#include <string>
#include <vector>
#pragma once

using namespace std;

class User{
public:
    User(){}
    User(int, string, string, string, string);
    string getName();
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

User::User(int id, string username, string name, string pass, string userRole){
    userID = id;
    userName = username;
    fullName = name;
    password = pass;
    role = userRole;
}

void User::showOptions()
{
    for(string option: this->optionsList){
            cout << option << endl;
        };
    
}

string User::getName()
{
    return fullName;
}

int User::getUserID()
{
    return userID;
}