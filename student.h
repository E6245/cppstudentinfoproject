#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
    Student();
    Student(string id, string first, string last, string email, int studentage, int days[], DegreeProgram degree);
    ~Student();
    void SetStudentID(string studentID);
    string GetStudentID();
    void SetFirstName(string firstName);
    string GetFirstName();
    void SetLastName(string lastName);
    string GetLastName();
    void SetEmailAddress(string emailAddress);
    string GetEmailAddress();
    void SetAge(int age);
    int GetAge();
    void SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void SetDaysInCourse(int days[3]);
    int* GetDaysInCourse();
    void SetDegreeProgram(DegreeProgram degreeprogram);
    DegreeProgram GetDegreeProgram();
    string GetDegreeString();
    void Print();


private:
    string studentID;
    string firstName;
    string lastName; 
    string emailAddress;
    int age;
    int daysInCourse1;
    int daysInCourse2;
    int daysInCourse3;
    int daysInCourse[3]; 
    DegreeProgram degreeProgram;

};