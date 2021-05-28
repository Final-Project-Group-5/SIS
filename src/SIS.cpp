#include "./ObjectModels/Course.cpp"
#include <algorithm>
#include <iostream>

using namespace std;

class SIS
{
public:
    SIS();
    void authenticate();
    void loadData();
    void saveData();
    void run();
    void runREPL();

private:
    // auto currentUser;
    vector<Course> availableCourses;
    vector<Course> allCourses;
    // vector<Faculty> facultyRoster;
    // vector<Student> studentRoster;
    // vector<Staff> staffRoster;
};

SIS::SIS()
{
}

void SIS::loadData()
{
    ofstream outFile;
    ifstream inFile;
    string line;
    string full;

    cout << "Please hold while system data is loaded." << endl;

    //  Open data streams, read from file constructing all of the user and course objects needed while storing them to the SIS vectors
    cout << "Opening file" << endl;
    char inFilename[17] = "./Data/data.txt";
    inFile.open(inFilename);
    if (inFile.fail())
    {
        cout << "Failed to open the input file" << endl;
        exit(1);
    };
    cout << "File opened" << endl;
    while (getline(inFile, line))
    {
        // cout << line << endl;
        full += line + "\n";
    };
    inFile.close();
    cout << "System data loaded" << endl;
    cout << full;
}
void SIS::authenticate()
{
    cout << "Login" << endl;
    string username = "";
    string password = "";
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;
    cout << username << " " << password << endl;
}

void SIS::runREPL()
{
    int commandCode;

    int REPLRunning = 1;
    // this -> currentUser.showOptions();

    while (REPLRunning)
    {
        cout << "Please enter a command: ";
        cin >> commandCode;
        // if (count(this->currentUser.commandList.begin(), this->currentUser.commandList.end(), commandCode))
        // {
        //     // this ->currentUser.runCommand(commandCode);
        // }
        // else
        // {
        //     cout << "Input error, please re-enter command"
        // }
    };
}
void SIS::run()
{
    cout << "Welcome to SIS." << endl;
    this->loadData();
    this->authenticate();
    // this->currentUser.printOptions()
    this->runREPL();
};
