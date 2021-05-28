#include "./ObjectModels/Course.cpp"
#include "./ObjectModels/User.cpp"
#include "./ObjectModels/Student.cpp"
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
    void test();

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
    ofstream outFile;

    char outFilename[21] = "./Data/tempdata.txt";
    outFile.open(outFilename);
    cout << "Opening data file to save" << endl;
    if (outFile.fail())
    {
        cout << "Failed to open the output file" << endl;
        std::exit(1);
    };
    outFile.close();
    cout << "Data successfuly saved" << endl;
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

    this->test();
    cout << "Welcome to SIS." << endl;
    this->loadData();
    this->authenticate();
    // this->currentUser.printOptions()
    this->runREPL();
    this->exit();
};

void SIS::test()
{
    cout << setfill(' ') << setw(25) << "This is a test\n\n\n\n\n\n\n"
        << endl;

    // vector<string> st;
    //     st.push_back("Aaron");
    // Student objFA(st);
    // objFA.printStReport(st);

    // registerForCourse(objFA);

    // User user1 = User(1,"rsmith","Robert Smith","password1","student");
    // user1.showOptions();
    Course c1 = Course("calc2", 5, 'A', "M.Hubbard");
    Course c2 = Course("calc3", 5, 'A', "M.Hubbard");
    vector<Course> v1 = {c1,c2};
    Student s1 = Student(1,"rsmith","Robert Smith","password1","student", v1);
    s1.printReport();
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
