#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"

Student::Student(string id, string fName, string lName, string email, int num, int days[3], Degree::DegreeProgram deg) {
	studentID = id;
	firstName = fName;
	lastName = lName;
	emailAddress = email;
	age = num;

	for (int i = 0; i < 3; ++i) {
		daysToCompleteCourses[i] = days[i];
	}

	degree = deg;
}

void Student::SetStudentID(string id) {
	studentID = id;
}

void Student::SetFirstName(string fName) {
	firstName = fName;
}

void Student::SetLastName(string lName) {
	lastName = lName;
}

void Student::SetEmailAddress(string email) {
	emailAddress = email;
}

void Student::SetAge(int num) {
	age = num;
}

void Student::SetDegreeProgram(Degree::DegreeProgram deg) {
	degree = deg;
}

void Student::SetDaysToCompleteCourses(int days[3]) {
	for (int i = 0; i < 3; ++i) {
		daysToCompleteCourses[i] = days[i];
	}
}

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}
Degree::DegreeProgram Student::GetDegreeProgram() const {
	return degree;               				
}

int* Student::GetDaysToCompleteCourses() {
	return daysToCompleteCourses;
}

void Student::Print() const{
	std::cout << studentID << '\t';
	std::cout << "First Name: " << firstName << '\t';
	std::cout << "Last Name: " << lastName << '\t';
	std::cout << "Age: " << age << '\t';
	std::cout << "daysInCourse: {" << daysToCompleteCourses[0] << ", " << daysToCompleteCourses[1] << ", " << daysToCompleteCourses[2] << "} " << '\t';
	std::cout << "Degree Program: ";

	switch (degree) {
		case Degree::DegreeProgram::SECURITY: 
			std::cout << "SECURITY" << std::endl;
			break;
		case Degree::DegreeProgram::NETWORK:
			std::cout << "NETWORK" << std::endl;
			break;
		case Degree::DegreeProgram::SOFTWARE:
			std::cout << "SOFTWARE" << std::endl;
	}
}