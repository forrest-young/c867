#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

//  Accessors

string Student::getStudentID() {

	return studentID;
}
string Student::getFirstName() {

	return firstName;
}
string Student::getLastName() {

	return lastName;
}
string Student::getEmailAddress() {

	return emailAddress;
}
int Student::getAge() {

	return age;
}
int* Student::getDaysToComplete() {

	return daysToComplete;
}
DegreeProgram Student::getDegreeProgram() {

	return degreeProgram;
}

//  Mutators

void Student::setStudentID(string studentID) {

	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {

	this->firstName = firstName;
}
void Student::setLastName(string lastName) {

	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {

	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {

	this->age = age;
}
void Student::setDaysToComplete(int* daysToComplete) {

	for (int i = 0; i < 3; i++) {

		this->daysToComplete[i] = daysToComplete[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {

	this->degreeProgram = degreeProgram;
}

//  Default Constructor

Student::Student() {

	this->studentID = "Student ID";
	this->firstName = "First Name";
	this->lastName = "Last Name";
	this->emailAddress = "email@address.com";
	this->age = 0;
	for (int i = 0; i < numOfClasses; i++) {

		this->daysToComplete[i] = 0;
	}
	this->degreeProgram = SECURITY;
	
}

// Main Constructor

Student::Student(string studentID, string firstName, string lastName,
	string emailAddress, int age, int* daysToComplete, DegreeProgram degreeProgram) {

	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDaysToComplete(daysToComplete);
	setDegreeProgram(degreeProgram);
}

// Functions

void Student::print() {

	int* a = this->getDaysToComplete();

	cout <<"ID: " << this->getStudentID() << "\tFirst Name: " << this->getFirstName() << "\tLast Name: " << this->getLastName() << "\tAge: " <<
		this->getAge() << "\tDaysInCourse: {";
		
		for (int i = 0; i < numOfClasses; i++) {

			if (i != (numOfClasses - 1)) {

				cout << a[i] << ",";
			}
			else {

				cout << a[i];
			}
		}
		
		cout<< "\tDegree Program: ";

	switch (degreeProgram) {

		case 0:
			cout << "Security" << endl;
			break;
		case 1:
			cout << "Network" << endl;
			break;
		case 2:
			cout << "Software" << endl;
			break;
		default:
			cout << "Invalid degree program." << endl;
	}
}