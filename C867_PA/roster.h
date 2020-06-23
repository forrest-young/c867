#pragma once
#include "student.h"
using namespace std;

const int numOfStudents = 5;

class Roster {

private:

	Student* classRosterArray[numOfStudents] = { NULL };
	
public:

	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
		DegreeProgram degreeProgram);
	void remove(string);
	void printAll();
	void printAverageDaysInCourse(string);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram);

	~Roster();
};