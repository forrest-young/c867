#include <iostream>
#include <regex>
#include "roster.h"
#include "student.h"
using namespace std;

const regex emailAddress ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeProgram degreeProgram) {

	Student *student;
	int a[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	student = new Student(studentID, firstName, lastName, emailAddress, age, a,
		degreeProgram);

	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i] == nullptr) {

			classRosterArray[i] = student;
			break;
		}
	}
}

void Roster::remove(string studentID) {

	for (int i = 0; i < numOfStudents; i++) {

		if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentID)) {

			classRosterArray[i] = nullptr;

			cout << studentID << " has successfully been removed from the roster." << endl;
		}
		else if (classRosterArray[i] == nullptr){

			cout << studentID << " does not exist, please try again." << endl;
		}
	}
}

void Roster::printAll() {

	cout << endl;
	cout << "Printing class roster:";
	cout << endl << endl;

	for (int i = 0; i < numOfStudents; i++) {

		if (classRosterArray[i] != nullptr) {

			classRosterArray[i]->print();
		}
		else {

			cout << "ID: -\tFirst Name: -\tLast Name: -\tAge: -\tDaysInCourse: -\tDegree Program: -" << endl;
		}

		cout << endl;
	}

	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {

	for (int i = 0; i < numOfStudents; i++) {

		if (classRosterArray[i]->getStudentID() == studentID) {

			int avg = 0;
			int* a = classRosterArray[i]->getDaysToComplete();
			
			for (int j = 0; j < numOfClasses; j++) {

				avg += (classRosterArray[i]->getDaysToComplete())[j];
			}

			avg = avg / numOfClasses;

			cout << "Average days left in {";

			for (int k = 0; k < numOfClasses; k++) {
				
				if (k != (numOfClasses - 1)) {

					cout << a[k] << ",";
				}
				else {

					cout << a[k];
				}
			}
			cout << "}: " << avg << " days" << endl;
		}
	}

	cout << endl;
}

void Roster::printInvalidEmails() {

	bool valid = false;

	cout << "The following email addresses are invalid: " << endl;

	for (int i = 0; i < numOfStudents; i++) {

		if (classRosterArray[i] != nullptr) {

			if (regex_match(classRosterArray[i]->getEmailAddress(), emailAddress) == false) {

				cout << classRosterArray[i]->getEmailAddress() << endl;
			}
		}

	}

	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	cout << "Printing information for students in a(n) ";

	if (degreeProgram == 0) {

		cout << "Security degree program:" << endl;
	}
	else if (degreeProgram == 1) {

		cout << "Network degree program:" << endl;
	}
	else if (degreeProgram == 2){

		cout << "Software degree program:" << endl;
	}
	else {

		cout << "Undefined degree program:" << endl;
	}

	for (int i = 0; i < numOfStudents; i++) {

		if (classRosterArray[i] != nullptr) {

			if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {

				classRosterArray[i]->print();
			}
		}
	}

	cout << endl;
}

Roster::~Roster()
{
	for (int i = 0; i < numOfStudents; i++)
	{
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}

	// Unable to delete the Roster, throws exception
	//delete this;
}