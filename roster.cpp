#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

Roster::Roster() {};
Roster::~Roster() {};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, 
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int index)
{
	int daysInCourse[3];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	Student * student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	classRosterArray[index] = student;

}

void Roster::parse(string studentToAdd, int index)
{
	size_t far = studentToAdd.find(",");
	string studentID = studentToAdd.substr(0, far);

	size_t near = far + 1;
	far = studentToAdd.find(",", near);
	string firstName = studentToAdd.substr(near, far - near);

	near = far + 1; 
	far = studentToAdd.find(",", near);
	string lastName = studentToAdd.substr(near, far - near);

	near = far + 1;
	far = studentToAdd.find(",", near);
	string email = studentToAdd.substr(near, far - near);

	near = far + 1;
	far = studentToAdd.find(",", near);
	string age = studentToAdd.substr(near, far - near);
	int int_age = stoi(age);

	near = far + 1;
	far = studentToAdd.find(",", near);
	string days1 = studentToAdd.substr(near, far - near);
	int int_days1 = stoi(days1);

	near = far + 1;
	far = studentToAdd.find(",", near);
	string days2 = studentToAdd.substr(near, far - near);
	int int_days2 = stoi(days2);

	near = far + 1;
	far = studentToAdd.find(",", near);
	string days3 = studentToAdd.substr(near, far - near);
	int int_days3 = stoi(days3);

	near = far + 1;
	far = studentToAdd.find(",", near);
	string degree = studentToAdd.substr(near, far - near);
	
	DegreeProgram degreeProgram = DegreeProgram::HISTORY;
	if (degree == "ENGLISH") {
		degreeProgram = DegreeProgram::ENGLISH;
	} else if (degree == "HISTORY") { 
		degreeProgram = DegreeProgram::HISTORY;
	} else if (degree == "PHILOSOPHY") {
		degreeProgram = DegreeProgram::PHILOSOPHY;
	} else if (degree == "UNDECLARED") {
		degreeProgram = DegreeProgram::UNDECLARED;
	}
	
	add(studentID, firstName, lastName, email, int_age, int_days1, int_days2, int_days3, degreeProgram, index);
}
void Roster::remove(string studentID)
{
	bool studentExists = false;
	int rosterSize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	for (int i = 0; i < rosterSize; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			studentExists = true;
			cout << "Removing student " << studentID << "..." << endl;
			Student* nullStudent = new Student();
			classRosterArray[i] = nullStudent;
			break;
		}
	} 
	if (!studentExists) {
		cout << "Student " << studentID << " not found.";
	}
	
}
void Roster::printAll() {
	int rosterSize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	for (int i = 0; i < rosterSize; i++) {
		classRosterArray[i]->Print();
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	bool studentExists = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			studentExists = true;
			int daysSum = classRosterArray[i]->GetDaysInCourse()[0] + classRosterArray[i]->GetDaysInCourse()[1] + classRosterArray[i]->GetDaysInCourse()[2];
			cout << "Average days in course for student " << studentID << ": " << daysSum / 3.0 << endl;
			break;
		}
	}
	if (!studentExists) {
		cout << "Student ID not found.";
	} else if (studentExists) {
	}
}

void Roster::printInvalidEmails()
{	
	bool invalidEmail = false;
	for (int i = 0; i < 5; i++) {
		string email = classRosterArray[i]->GetEmailAddress();
		size_t at_sign = email.find("@");
		size_t period = email.find(".");
		size_t space = email.find(" ");
		if ((at_sign == string::npos) || (period == string::npos) || (space != string::npos)) {
			cout << "Invalid email: " << email << endl;
			invalidEmail = true;
		}
	} 
	if (!invalidEmail) {
		cout << "No invalid emails found." << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	string x;
	switch (degreeProgram) {
	case 0:
		x = "ENGLISH";
		break;
	case 1:
		x = "HISTORY";
		break;
	case 2:
		x = "PHILOSOPHY";
		break;
	case 3:
		x = "THEATER";
		break;
	case 4:
		x = "UNDECLARED";
		break;
	}
	cout << "Printing list of students in " << x << ":" << endl;
	bool studentsInDP = false;
	for (int i = 0; i < 5; i++) {
		DegreeProgram dp = classRosterArray[i]->GetDegreeProgram();
		if (dp == degreeProgram) {
			studentsInDP = true;
			classRosterArray[i]->Print();
		}
	}
	if (!studentsInDP) { cout << "There are no students in that degree program."; }
}





