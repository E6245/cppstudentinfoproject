#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main()
{
    cout << "Project: C++ Student Roster Project" << endl;
    cout << "Language: C++" << endl;
    cout << "Description: a simple program to manage and view information about students enrolled in a hypothetical course of study." << endl;
    cout << endl;
    
    string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,ENGLISH",
        "A2,Huyen,Nguyen,knguyen_1990@gmailcom,19,50,30,40,HISTORY",
        "A3,Valentina,Napoli,The_lawyer99yahoo.com,19,20,40,33,PHILOSOPHY",
        "A4,Priya,Pamut,priya.pamut@comcast.net,22,50,58,40,THEATER",
        "A5,Said,Adani,sadani@gmail.com,44,10,20,30,PHILOSOPHY"
    };
    // Demo: Create Roster object
    Roster roster;
    for (int i = 0; i < 5; i++) {
        roster.parse(studentData[i], i);
    }
    // Demo: prints Roster using Roster print method
    roster.printAll();
    cout << endl;

    // Demo: shows simple Roster method to check for invalid emails and displays emails that match criteria    
    roster.printInvalidEmails();
    cout << endl;

    // Demo: uses student id field to retrieve and print the output of the printAverageDaysInCourse method
    for (int i = 0; i < 5; i++) {
        string std_id = roster.classRosterArray[i]->GetStudentID();
        roster.printAverageDaysInCourse(std_id);
    }
    cout << endl;

    // Demo: shows output of printByDegreeProgram method for degree = Philosophy
    roster.printByDegreeProgram(PHILOSOPHY);
    cout << endl;

    // Demo: removes student from roster and performs a validity check to verify the student was removed
    roster.remove("A3");
    cout << endl;

    roster.remove("A3");
    cout << endl;

    // Garbage collector for Roster object used in demos
    roster.~Roster();

};
