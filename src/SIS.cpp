#include "./ObjectModels/Course.cpp"
#include "./ObjectModels/Student.cpp"
#include "./ObjectModels/Staff.cpp"
#include "./ObjectModels/Faculty.cpp"
#include <algorithm>
#include <sstream>

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
    friend void Student::registerForCourse(SIS& x); // Friend function with Student

private:
    // static auto currentUser;
    vector<Course> availableCourses;
    vector<Course> allCourses;
    vector<Student> studentRoster;
    vector<Faculty> facultyRoster;
    vector<Staff> staffRoster;
};

SIS::SIS()
{
}

void SIS::loadData()
{
    ofstream outFile;
    ifstream inFile;
    string line;

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
        stringstream s_stream(line); //create string stream from the string

        vector<string> argVector;

        int tempID;

        string tempUserName,
            tempUserFullName,
            tempUserPassword,
            tempUserRole;

        while (s_stream.good())
        {
            string arg;
            getline(s_stream, arg, ','); //get first string delimited by comma
            argVector.push_back(arg);
        };

        tempID = stoi(argVector[0]);
        tempUserName = argVector[1];
        tempUserFullName = argVector[2];
        tempUserPassword = argVector[3];
        tempUserRole = argVector[4];

        // for (string arg : argVector)
        // {
        //     cout << arg << endl;
        // };

        if (tempUserRole == "student")
        {
            Student tempStudent = Student(tempID, tempUserName, tempUserFullName, tempUserPassword, tempUserRole);
            this->studentRoster.push_back(tempStudent);
        }
        else if (tempUserRole == "faculty")
        {
            Faculty tempFaculty = Faculty(tempID, tempUserName, tempUserFullName, tempUserPassword, tempUserRole);
            this->facultyRoster.push_back(tempFaculty); 
        }
        else
        {
            Staff tempStaff = Staff(tempID, tempUserName, tempUserFullName, tempUserPassword, tempUserRole);
            this->staffRoster.push_back(tempStaff);
        };
    };

    inFile.close();
    cout << "System data loaded" << endl;
    // cout << full;
}

void Student::registerForCourse(SIS& x) 
{
    string courseCode;
    cout << "Here are the avalible courses to take this semester: " << endl;
    // We must populate avalibleCourses vector
    for (Course course : this->courses)     // shows list of courses
    {
        course.printReport();
    }
    cout << "Please enter in the course code you wish to registar for: ";
    getline(cin, courseCode);
    cout << "You entered: " << courseCode << endl;
    if (find(availableCourses.begin(), availableCourses.end(), courseCode) != availableCourses.end())   // Find course entered in avalibleCourses
        // If found, add course to student course vector
    cout << "Course " << courseCode << " added";
    else
    cout << "Course not found.";   // Course not found
}
/*
void SIS::authenticate()
{
    cout << "Login" << endl;
    string username = "";
    string password = "";
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;
    
        //  Search through our list of users in memory. Once we find the right user and confirmatching password, assign this object that we are looking at to the current user

    if (find(argVector.begin(), argVector.end(), username) != argVector.end())   // Find username loaded from argVector
        if (find(argVector.begin(), argVector.end(), password) != argVector.end())  // Find password loaded from argVector
            // Assign to currentUser
            cout << "User |" << username << "|, with password |" << password << "| found.";
    else
        cout << "User not found.";   // User not found
}
*/

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
    cout << "Data successfully saved" << endl;
}

void SIS::runREPL()
{
    int commandCode;

    int REPLRunning = 1;
    // this -> currentUser.showOptions();
    cout << "You can exit the command loop by entering option 0." << endl;
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
        //     cout << "Input error, please re-enter a valid command";
        // }
    };
}
void SIS::run()
{

    cout << "Welcome to SIS." << endl;
    this->loadData();
    this->test();
    this->authenticate();
    // this->currentUser.printOptions()
    this->runREPL();
    this->exit();
};

void SIS::test()
{
    cout << setfill(' ') << setw(25) << "This is a test\n\n"
         << endl;

    

    cout << "\n\n"
         << "Test Over"
         << "\n\n"
         << endl;
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
