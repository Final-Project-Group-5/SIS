# SIS
This is the primary Repo holding the source code for a School Information System which our team will design and build.


This project is a C++ console application which provides basic functionality of a student information system. The three main user roles are students, faculty and staff.

Class User - This is the parent class. This class has following data members: id, name, isAuthenticated. All users are authenticated against a username/password file (this file also has role information) and that functionality is implemented in this class.

Class Student - inherited from User class. Add necessary data members and methods.
Students can take multiple courses per semester. They can reregister a course if they received a D or F in a previous semester.
A student can generate only his report but can not add/edit any data.

Class Faculty - inherited from User class. Add necessary data members and methods.
Faculty can teach multiple courses per semester.
A faculty can add/edit data for any student for the courses he/she teaches.

Class Staff - inherited from User class. Add necessary data members and methods.
A staff can generate report for any student but can not add/edit any data.
For sake of simplicity, assume there is only one class/section for a given course per semester.


Your program should allow users to login and based on their role present them various options:
Students:
1. List the courses the student is currently registered in.
2. Register for a course. Display a list of all courses available in current semester and allow to register for any of these courses.
3. Generate a grades report for current semester.

Faculty:
1. List the courses faculty is teaching in current semester.
2. Updating the grades - As for a course and iterate over the registered students in the course and ask for grade and update.

Staff:
1. Add a course to a Faculty.
2. Generate a grades report for a given student.

Notes:

    All other classes, e.g. Course, GradesReport etc should be created as needed.
    All the data should be stored in plain text files (csv, tsv files are allowed). These files should be store in project directory.
    You can review the concepts implemented in previous assignments including the object oriented implementation of "Grades Report" in class available at https://replit.com/join/idzgmogx-zrafique (Links to an external site.). You can may choose to reuse code from any of the work done in class.

Submission:

Create a zip file of only your .h & .cpp files and upload. DO NOT include any IDE specific files.
