#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;


class Roster {
public:
    Roster();
    ~Roster();
    void add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram, int index);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void parse(string studentToAdd, int index);
    Student* classRosterArray[5]; //arr of pointers to Student objects

private:
    
    
};