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
        cout << line << endl;
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
        //    cout << arg << endl;
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

void SIS::authenticate()
{
    cout << "Login" << endl;
    string username = "";
    string password = "";
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;
    
    for (Staff s : staffRoster)
    {
        if (s.getUserName() == username)
        {
            if (s.getPass() == password)
            {
                cout << "Login successful." << endl;
            }
            else
            {
                cout << "Failed to authenticate" << endl;
            }
            
        }
        
    }
    for (Faculty f : facultyRoster)
    {
        if (f.getUserName() == username)
        {
            if (f.getPass() == password)
            {
                cout << "Login successful." << endl;
            }
            else
            {
                cout << "Failed to authenticate" << endl;
            }
        }
        
    }
    for (Student s : studentRoster)
    {
        if (s.getUserName() == username)
        {
            if (s.getPass() == password)
            {
                cout << "Login successful." << endl;
            }
            else
            {
                cout << "Failed to authenticate" << endl;
            }
        }
        
    }
    
    //  Search through our list of users in memory. Once we find the right user and confirmatching password, assign this object that we are looking at to the current user




/*
    if (find(argVector.begin(), argVector.end(), username) != argVector.end()) // Find username loaded from argVector
    {  
        int userIndex = find(argVector.begin(), argVector.end(), username) - argVector.begin(); // Finds index of username
        if (find(argVector.begin(), argVector.end(), password) != argVector.end())  // Find password loaded from argVector
        {
            int passIndex = find(argVector.begin(), argVector.end(), password) - argVector.begin(); // Finds index of password
            // cout << userIndex << " " << passIndex << endl;
            if ((passIndex - userIndex) == 2)   // Checks if username and password are part of the same user
            {
                 // Assign to currentUser
                cout << "User |" << username << "|, with password |" << password << "| found." << endl;
                return true;
            }
        }
    }
    else
    {
         cout << "User not found." << endl;   // User not found
        return false;
    }
    */
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

    cout << "rawr28" << endl;

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
