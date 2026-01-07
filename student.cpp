#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse1 = 0;
	this->daysInCourse2 = 0;
	this->daysInCourse3 = 0;
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
	this->degreeProgram = DegreeProgram::UNDECLARED;
}
Student::Student(string id, string first, string last, string email,int studentage, int days[], DegreeProgram degree) {
	this->studentID = id;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = email;
	this->age = studentage;
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = days[i];
	}
	this->degreeProgram = degree;
}

Student::~Student() {}

void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
}

string Student::GetStudentID() 
{
	return studentID;
}

void Student::SetFirstName(string firstName)
{
	this->firstName = firstName;
}

string Student::GetFirstName() 
{
	return firstName;
}

void Student::SetLastName(string lastName)
{
	this->lastName = lastName;
}

string Student::GetLastName() 
{
	return lastName;
}

void Student::SetEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

string Student::GetEmailAddress() 
{
	return emailAddress;
}

void Student::SetAge(int age)
{
	this->age = age;
}

int Student::GetAge() 
{
	return age;
}

void Student::SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
	this->daysInCourse1 = daysInCourse1;
	this->daysInCourse2 = daysInCourse2;
	this->daysInCourse3 = daysInCourse3;
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;

}

void Student::SetDaysInCourse(int days[3])
{
	this->daysInCourse[0] = days[0];
	this->daysInCourse[1] = days[1];
	this->daysInCourse[2] = days[2];
}

int* Student::GetDaysInCourse()
{
	return this->daysInCourse;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

DegreeProgram Student::GetDegreeProgram()
{
	return degreeProgram;
}

string Student::GetDegreeString() {
	string x;
	switch (GetDegreeProgram()) {
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
	return x;
}
void Student::Print() 
{	
	cout << GetStudentID() << "\t";
	cout << "First Name: " << GetFirstName() << "\t";
	cout << "Last Name: " << GetLastName() << "\t";
	cout << "Age: " << GetAge() << "\t";
	cout << "daysInCourse: {" << GetDaysInCourse()[0] << ", " << GetDaysInCourse()[1]<< ", " << GetDaysInCourse()[2] << "}\t";
	cout << "Degree Program: " << GetDegreeString();
	cout << endl;
}
