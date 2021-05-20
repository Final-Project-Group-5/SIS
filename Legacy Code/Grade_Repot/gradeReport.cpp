#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Course{
    public:
        Course(string, int, char);
        string getCourseCode();
        string printReport();
        int getCredits();
        int getGPV();

    protected:
        string courseCode;
        int gpv,
            credits;
        char letterGrade;

};

Course::Course(string code, int credit, char grade){
    courseCode = code;
    letterGrade = grade;
    credits = credit;
    switch(grade){
        case 'A':
            gpv = 4 * credits;
            break;
        case 'B':
            gpv = 3 * credits;
            break;
        case 'C':
            gpv = 2 * credits;
            break;
        case 'D':
            gpv = 1 * credits;
            break;
        default:
            gpv = 0;
            break;
    }
};


string Course::getCourseCode(){
    return courseCode;
};

int Course::getCredits(){
    return credits;
};

int Course::getGPV(){
    return gpv;
};

string Course::printReport(){
    return courseCode + "            "  + to_string(credits) + "        "  +  letterGrade + "     " + to_string(gpv);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Student{
    public:
        Student(string, int);
        string getName();
        string getID();
        void printReportCard();
        void addClasses(vector <Course>);
        void listClasses();
        vector<Course> classes;

    protected:
        string fullName;
        int id;

};

Student::Student( string name, int studentID){
    fullName = name;
    id = studentID;
};

string Student::getName(){
    return fullName;
};

string Student::getID(){
    return to_string(id);
};

void Student::addClasses(vector <Course> courses){
    classes.insert(classes.end(), courses.begin(), courses.end());
};

void Student::listClasses(){
    for( int i = 0; i < classes.size(); i++)
        cout << classes[i].printReport() << endl;
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


class IOStreamHandler{
    public:
        IOStreamHandler();
        void openStreams();
        void cleanUp();
        void seedGradeFile();
        string readFromFile();
        void writeToFile(Student);
        void writeToFile(string);
    private:
        ofstream outFile;
        ifstream inFile;
};

IOStreamHandler::IOStreamHandler(){

};

void IOStreamHandler::openStreams(){
    char outFilename[11] = "grades.dat";
    outFile.open(outFilename);
    if (outFile.fail()) {
        cout << "Failed to open the output file" << endl;
        exit(1);
    };

    char inFilename[11] = "grades.dat";
    inFile.open(inFilename);
    if (inFile.fail()) {
        cout << "Failed to open the input file" <<endl;
        exit(1);
    };
}


string IOStreamHandler::readFromFile(){
    string line;
    string full;
    while(getline(inFile, line)){
        // cout << line << endl;
        full += line + "\n";
    };
    
    return full;
};

void IOStreamHandler::writeToFile(string input){
    outFile << input << endl;
}

void IOStreamHandler::writeToFile(Student student){
    outFile << "\nStudent Name: " + student.getName() + "\nStudent ID: " + student.getID() + "\n" << endl;
    outFile << "\033[4mCourse Code         " << "Credits   " << "Grade\033[0m" << endl;

    int creditTotal = 0;
    double totalGPV=0;
    
    for (int i = 0; i < student.classes.size(); i++){
        creditTotal += student.classes[i].getCredits();
        totalGPV += student.classes[i].getGPV();
        outFile << student.classes[i].printReport() << endl;
    }; 

    outFile << "\nTotal Course Credits Attempted: " << creditTotal << "\nGPA: " << (totalGPV/creditTotal) << endl;
};

void IOStreamHandler::seedGradeFile(){
    Student s1 = Student("Omar S.", 33697);
    Course Geo = Course("Geo-109    ", 3, 'F');
    Course PoliSci = Course("PoliSci-150", 3, 'C');
    Course Hlth = Course("Hlth-100   ", 3, 'B');
    Course Coms = Course("Coms-246   ", 3, 'F');
    Course Psych = Course("Psych-109  ", 3, 'A');
    Course Hist = Course("Hist-111   ", 3, 'A');
    Course Eng1 = Course("Eng-101    ", 4, 'A');
    Course Soci1 = Course("Soci-101   ", 3, 'A');
    Course Chem1 = Course("Chem-151   ", 4, 'A');
    Course Music = Course("Music-105  ", 3, 'A');
    Course Phil = Course("Philo-120  ", 3, 'A');
    Course Math1 = Course("Calc-1     ", 5, 'B');
    Course CS1 = Course("CmpSci-235 ", 3, 'A');
    Course Eng2 = Course("Eng-103    ", 3, 'A');

    Course Math2 = Course("Calc-2     ", 5, 'A');
    Course Soci2 = Course("Soci-102   ", 3, 'A');
    Course CmpSci2 = Course("CmpSci-236 ", 3, 'A');
    Course Bio = Course("Bio-106    ", 4, 'A');
        

    s1.addClasses({Geo, PoliSci, Hlth, Coms, Psych, Hist, Eng1, Soci1, Soci2, Chem1, Music, Phil, Math1, CS1, Eng2, Math2, Soci2, CmpSci2, Bio});



    IOStreamHandler::writeToFile(s1);
};

void IOStreamHandler::cleanUp(){
    inFile.close();
    outFile.close();
};

int main() {
    IOStreamHandler iostream = IOStreamHandler();

    iostream.openStreams();
    iostream.seedGradeFile();

    
    cout << iostream.readFromFile();
    
    iostream.cleanUp();
    return 0;
};
