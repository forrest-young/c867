#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

const int numOfFields = 9;

int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Forrest,Young,csssucks@gmail.com,29,10,50,42,SOFTWARE"
	};

	cout << "C867 - Scripting and Programming" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "WGU Student ID: #000833199" << endl;
	cout << "Written by: Forrest Young" << endl;

	Roster *classRoster = new Roster;

	string input;
	string tmp[numOfFields];
	DegreeProgram degree;

	for (int i = 0; i < numOfStudents; i++) {

		input = studentData[i];

		if (input[(input.length() - 1)] == 'Y') {

			degree = SECURITY;
		}
		else if (input[(input.length() - 1)] == 'K') {

			degree = NETWORK;
		}
		else if (input[(input.length() - 1)] == 'E') {

			degree = SOFTWARE;
		}
		else {

			degree = SOFTWARE;
		}

		for (int j = 0; j < numOfFields; j++) {

			int c = input.find(',');

			tmp[j] = input.substr(0, c);
			input.erase(0, (c + 1));
		}

		classRoster->add(tmp[0], tmp[1], tmp[2], tmp[3], stoi(tmp[4]), stoi(tmp[5]),
			stoi(tmp[6]), stoi(tmp[7]), degree);
	}

	classRoster->printAll();
	classRoster->printInvalidEmails();
	for (int i = 0; i < numOfStudents; i++) {

		string tmp = "A";
		tmp.append(to_string(i));

		classRoster->printAverageDaysInCourse(tmp);
	}
	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");

	classRoster->~Roster();

	return 0;
}