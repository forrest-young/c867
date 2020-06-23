#pragma once
#include "degree.h"
#include <string>
using namespace std;

const int numOfClasses = 3;

class Student {

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[numOfClasses];
	DegreeProgram degreeProgram;

public:

	//  Accessors

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	//  Mutators

	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmailAddress(string);
	void setAge(int);
	void setDaysToComplete(int*);
	void setDegreeProgram(DegreeProgram);

	//  Constructors

	Student();
	Student(string, string, string, string, int, int*, DegreeProgram);

	//  Functions

	void print();
};