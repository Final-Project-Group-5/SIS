#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
	Solution to Exercise 8.5-4
*/
void display_report(ifstream&);
void write_file();
int get_numeric_grade(char);
void open_input(ifstream&);

const string filename = "grades_report.dat";

int main2() {
	try {
		write_file();		//write data to file

		ifstream inFile;
		open_input(inFile);

		cout << setprecision(2) << fixed;		//Display only 2 digits after decimal
		display_report(inFile);		//display the report
	}
	catch (string fn) {
		cout << "Could not open " << fn.c_str() << endl;
		return -1;
	}
	catch (int e) {

	}

	return 0;
}

void display_summary(int total_units, int total_unitsgrade) {	//No prototype needed since it will not be called any where else. Created separate functions since this could runs twice
	double gpa = (double)total_unitsgrade / total_units;
	cout << "\nTotal Semester Course Credits Completed: " << total_units << "\nSemester GPA: " << gpa << "\n\n" << endl;
}

void display_report(ifstream& inFile) {
	int current_id = 0, total_units = 0, total_unitsgrade = 0;

	while (true) {
		int id, course_credits;
		char fname[25], lname[5], course_code[10], course_grade;

		inFile >> id;
		if (inFile.eof()) {	
			//print summary for last student and exit the loop
			display_summary(total_units, total_unitsgrade);
			break;		//finish displaying the report
		}

		inFile >> fname >> lname >> course_code >> course_credits >> course_grade;

		if (id != current_id) {
			//execute for first iteration as well as when student id changes from previous line in data file
			if (total_units > 0) {
				//execute only when stuent id changes from previous line in data file - we are processing data for new student now
				display_summary(total_units, total_unitsgrade);
				total_units = 0;
				total_unitsgrade = 0;
			}

			cout << "Student Name: " << fname << " " << lname << endl
				<< "Student ID Number : " << id << "\n" << endl
				<< "Course Code\tCourse Credits\tCourse Grade" << endl
				<< "--------------------------------------------" << endl;
			current_id = id;	//Make sure to update our current student id
		}

		cout << course_code << "\t\t" << course_credits << "\t\t" << course_grade << endl;	//print for every iteration
		total_units += course_credits;
		total_unitsgrade += course_credits * get_numeric_grade(course_grade);
	}
}

void write_file() {
	ofstream outFile;
	outFile.open(filename.c_str());
	if (outFile.fail()) throw filename;

	outFile << "2333021 BOKOW, R. NS201 3 A" << endl
		<< "2333021 BOKOW, R. MG342 3 A" << endl
		<< "2333021 BOKOW, R. FA302 1 A" << endl
		<< "2574063 FALLIN, D. MK106 3 C" << endl
		<< "2574063 FALLIN, D. MA208 3 B" << endl
		<< "2574063 FALLIN, D. CM201 3 C" << endl
		<< "2574063 FALLIN, D. CP101 2 B" << endl
		<< "2663628 KINGSLEY, M. QA140 3 A" << endl
		<< "2663628 KINGSLEY, M. CM245 3 B" << endl
		<< "2663628 KINGSLEY, M. EQ521 3 A" << endl
		<< "2663628 KINGSLEY, M. MK341 3 A" << endl
		<< "2663628 KINGSLEY, M. CP101 2 B" << endl;

	outFile.close();
}

int get_numeric_grade(char letter_grade) {
	if (letter_grade == 'A')
		return 4;
	else if (letter_grade == 'B')
		return 3;
	else if (letter_grade == 'C')
		return 2;
	else if (letter_grade == 'D')
		return 1;
	else
		return 0;
}

void open_input(ifstream& inFile) {
	inFile.open(filename.c_str());
	if (inFile.fail()) throw filename;
}