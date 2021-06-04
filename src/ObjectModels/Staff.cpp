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
    void recieveCommandCode();
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
