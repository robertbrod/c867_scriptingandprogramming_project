#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>

Roster::Roster() {
}

Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeprogram) {
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* student = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram);

	classRosterArray[studentCount] = student;

	// Keeping track of classRosterArray index. studentCount begins at 0 before any student is added.
	studentCount += 1; 
}

void Roster::Remove(string studentID) {
	bool studentFound = false;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				studentFound = true;
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
			}
		}
	}

	if (studentFound == false) {
		std::cout << "The student with ID: " << studentID << ", was not found." << std::endl;
	}
}

void Roster::PrintAll() {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
		else {
			continue;
		}
			
	}
}

void Roster::PrintAverageDaysInCourse(string studentID) {
	int days[3]{};
	int sum = 0;
	int average = 0;

	bool studentFound = false;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			studentFound = true;
			for (int j = 0; j < 3; ++j) {
				days[j] = classRosterArray[i]->GetDaysToCompleteCourses()[j];
			}
			
			break;
		}
	}

	if (studentFound) {
		int sum = days[0] + days[1] + days[2];
		average = sum / 3;
		std::cout << "Student ID: " << studentID << ", average days in course is: ";
		std::cout << average << std::endl;
	}

	if (studentFound == false) {
		std::cout << "Student not found." << std::endl;
	}
}

void Roster::PrintInvalidEmails() {
	string email;
	char atSign = '@';
	char period = '.';
	char space = ' ';

	std::cout << "Displaying invalid emails:" << std::endl << std::endl;

	for (int i = 0; i < 5; ++i) {
		email = classRosterArray[i]->GetEmailAddress();

		if (email.find(atSign) == -1 || email.find(period) == -1 || email.find(space) != -1) {
			std::cout << classRosterArray[i]->GetEmailAddress() << " - is invalid." << std::endl;
		}
	}
}

void Roster::PrintByDegreeProgram(Degree::DegreeProgram degreeProgram) {
	std::cout << "Showing students in degree program: ";
	if (degreeProgram == Degree::DegreeProgram::NETWORK) {
		std::cout << "NETWORK";
	}
	else if(degreeProgram == Degree::DegreeProgram::SECURITY) {
		std::cout << "SECURITY";
	}
	else{
		std::cout << "SOFTWARE";
	}

	std::cout << std::endl << std::endl;

	bool studentFound = false;

	for (int i = 0; i < 5; ++i) {	
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
			studentFound = true;
		}
	}
	if (studentFound == false) {
		std::cout << "No students found." << std::endl;
	}
}