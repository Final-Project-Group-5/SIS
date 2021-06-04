#include "./User.cpp"

class Staff : public User
{
private:


public:
    Staff() {}
    Staff(int, string, string, string, string);

    void printStudentReport();
    void addInstructorToCourse();
    void addCourseToCatalog();
    void runCommandCode(int);

};

Staff::Staff(int id, string username, string name, string pass, string userRole)
{
    this->userID = id;
    this->userName = username;
    this->fullName = name;
    this->password = pass;
    this->role = userRole;
    this->optionsList = {"Staff Options: ", "1   Print Student Report", "2    Add an instructor to a course", "3    Add a course w/o an instructor"};

};
void Staff::addCourseToCatalog()
{
    cout << "Add Course"<<endl;
}
void Staff::addInstructorToCourse(){
    cout << "Add instructor"<<endl;
}
void Staff::printStudentReport(){
        cout << "Print Student report"<<endl;
}


void Staff::runCommandCode(int command)
{
    switch(command){
      case 1:
        // this->printStudentReport();
        break;
    case 2:
        // this->addInstructorToCourse();
        break;
      case 3:
        // this->addCourseToCatalog();
        break;
    case 9:
        // this-> showOptions();
        break;
    default:
        cout << "Invalid command, please eneter another command code." << endl;
        // this->showOptions();
    }
  
}

