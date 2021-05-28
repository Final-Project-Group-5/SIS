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
    void exit();
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

    char inFilename[17] = "./Data/data.txt";
    inFile.open(inFilename);
    if (inFile.fail())
    {
        cout << "Failed to open the input file" << endl;
        std::exit(1);
    };

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

void SIS::saveData()
{
    cout << "data saving placeholder" << endl;
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
        if (commandCode == 0)
        {
            REPLRunning = 0;
        }
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
    this->exit();
};

void SIS::exit()
{
    int trigger;

    cout << "Would you like to save all of the changes made during this session? (1 = Yes, 0=No): ";
    cin >> trigger;
    if (trigger)
    {
        saveData();
    }
    cout << "Thank you for using SIS." << endl;
};
