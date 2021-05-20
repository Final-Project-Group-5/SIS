# Final Project



---

## **Goal**: 
Produce a fully functional interactive School Managment Application within the console in C++ that students can personally use throughout their educations or to add to their portfolios/resumes.

### **Base Concept**:
This will be a School Managment System(SMS) built as a console application in C++ that is built on a REPL granting access as well as exception handling for the user to input commands. The user will be able to add students to the roster, query and select a specified student or vector of students by ID for students or Family name or course for vectors of students allowing the system access to member functions of the selected objects or vector elements. The user will also be able to perform full CRUD(create read update delete) functionality for any relevant data. Exception and error handling should be addressed on a unit level printing a user confirmation message on success or failure of the input command. Any arguments that the user will need to provide such as query strings, or data to be assigned/overwritten will be separated by a single space in the order the arguments are expected to be recieved. All of the data stored and modified can be saved to a file and on initialization can be read from the file as well. 



---
## **Implementation details:**


### **Basic REPL implementation example:**
```CPP
        string commandCode;

        int appRunning = 1;
        printInstructionList();


        while(appRunning){
            cout << "Please enter a command";
            cin >> commandCode;

            if(commandCodeInCommandList()){
                    runCommand(commandCode);
            } else{
                cout << "Input error, please re-enter command"
            }

```

### **Example main.cpp**
```cpp
    int Main(){
        SMS system = SMS()
        return 1
    }
```
### **Object Models**:


    SMS:
        Methods:
            |_ Constructor(){ **Print instructions & Initialize REPL** } -> Void
            |_ readRosterFromFile(**Reads all data from file and constructs a roster of students**)
            |_ overWriteSavedRoster(){**Overwrites the saved file with the new updated roster data**}
            |_ printInstructions(){ **Print out a useful list of commands and instructions for use** } -> Void
            |_ readCommand(string) { **Recieves the user command input as well as any arguments to relevant commands seperated by spaces.}
            |_ runCommand(commandCode){ ** Master switch case handler and user command error handlingthat will invoke or trigger the mapped commands to their relevant object and member function **}
            |_ addToRoster( Student ){ **Add student to roster** } -> Void
            |_ searchByStudentID( int ){** deselcte the prior data andQuery roster and assign to selectedStudent and return "Selected" or "Student not found"**} -> Void
            |_ searchByFamilyName( String familyName ){** deselcte the prior data and Query roster and assign to selectedStudents and print user confirmation **} -> Void
            |_ searchByCourse(string courseCode){ ** deselcte the prior data and Query roster and assign to selectedStudents print user confirmation** } -> Void
            |_ printselectedStudentReport(){ **Print selectedStudent report to console** } -> Void
            |_ printselectedStudentsReports(){ **Print selectedStudents report to console** }
            |_ printAllReports(){**Print reports for all students on roster**} -> Void
            |_ selectSingleStudentCourse(String courseCode){ ** Query the selected students courses and assign the relevant course to selectedStudentCourse**}
            |_ updateSelectedStudent( Overload ){** Update specified data members of selectedStudents by overloading  and print user confirmation**}
            |_ updateSelectedFamily( Overload ){** Update specified data members of selectedStudents and print user confirmation**}
            |_ updateSelectedStudentSelectedCourse(){** Update specified data members of selectedStudentSelectedCourse and print user confirmation**}
            |_ deselectAll(){ **Clear all selected objects & print user confirmation** }
            |_ deselect(Overload){ **Clear specified selected object & print user confimation** }_
            |_ Exit(){**Ask if user would like to save session data to file, or exit without saving clean up streams, run deconstructors, and terminate repl exiting the SMS**}

        Data Fields:
            |_ <vector>{Student} roster
            |_ <vector> SMSCommandList {** Master list of all recognizable commands that a user can issue the SMS}
            |_ <vector> studentCommandList{ **List of commands that map to Student member functions**}
            |_ <vector> studentVectorCommandList{ **list of commands that map to student member functions that are implemented with in a dynamic loop to invoke the function on all vector elements**
            |_ <vector> courseCommandList{ **list of commands that map to Course member functions  that are implemented with in a dynamic loop to invoke the function on all vector elements**}
            |_ <vector> selectedStudents
            |_ Student selectedStudent
            |_ Course selectedStudentCourse

~~~
    IOHandler:
        Methods:
            |_ Constructor();
            |_ openStreams();
            |_ cleanUp();
            |_ seedGradeFile();
            |_ readFromFile();
            |_ writeToFile();

        Data Fields:
            |_ inFile
            |_ outFile
~~~

~~~
    Student:
        Methods:
            |_ Student(firstName, lastName, id, course) (**Overload to accept no courses, 1 course, or a vector of coursees**)
            |_ getFullName()
            |_ getLastName()
            |_ getFirstName()
            |_ updateName()
            |_ addCourse(Course) {**overload to accept Vectors also}
            |_ calculateGPA()
            |_ printReport()

        Data Fields:
            |_ fullName
            |_ ID
            |_ <vector> classes

~~~

~~~
    Course:
        Methods:
            |_ Constructor(courseCode, Credits, Grade, Status )
            |_ getCourseCode()
            |_ getGrade()
            |_ updateGrade()
            |_ getStatus()
            |_ updateStatus()
            |_ updateGrade()
            |_ print()

        Data Fields:
            |_ status
            |_ courseCode
            |_ credits
            |_ gradePointValue
            |_ grade
 ~~~        