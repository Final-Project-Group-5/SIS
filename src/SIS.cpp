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
    // auto needs to be initialized at the time of declaration
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
    int pass = 1;
    bool userFound = 0;
    cout << "Login" << endl;

    while(!userFound){
        string username = "";
        string password = "";

        cout << "\nPlease enter your username: ";
        cin >> username;
       
        for (Staff s: staffRoster)
            {   
                if (s.getUserName() == username)
                {
                    cout << "User Found." << endl;
                    userFound = 1;
                    cout << "Please enter your password: ";
                    cin >> password;
                    while(password != s.getPass()){
                        cout << "Sorry that password was incorrect, please re-enter the password: ";
                        cin >> password;
                    }
                    cout << "Login Successful!" << endl;
                    continue;
                }
            }
        for (Faculty f: facultyRoster)
            {   
                if (f.getUserName() == username)
                {
                    cout << "User .ound." << endl;
                    userFound = 1;
                    cout << "Please enter your password: ";
                    cin >> password;
                    while(password != f.getPass()){
                        cout << "Sorry that password was incorrect, please re-enter the password: ";
                        cin >> password;
                    }
                    cout << "Login Successful!" << endl;
                    continue;
                }
            }
        for (Student s: studentRoster)
            {
                if (s.getUserName() == username)
                {
                    cout << "User Found." << endl;
                    userFound = 1;
                    cout << "Please enter your password: ";
                    cin >> password;
                    while(password != s.getPass()){
                        cout << "Sorry that password was incorrect, please re-enter the password: ";
                        cin >> password;
                    }
                    cout << "Login Successful!" << endl;
                    continue;
                
                }
            }
            if(!userFound) cout << "No user with that username was found please re-enter your username." << endl;         
    }
   
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
