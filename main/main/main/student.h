#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

class Student {
	public:
		Student(string id, string fName, string lName, string email, int num, int days[3], Degree::DegreeProgram deg);
		void SetStudentID(string id);
		void SetFirstName(string fName);
		void SetLastName(string lName);
		void SetEmailAddress(string email);
		void SetAge(int num);
		void SetDegreeProgram(Degree::DegreeProgram deg);
		void SetDaysToCompleteCourses(int days[3]);
		string GetStudentID() const;
		string GetFirstName() const;
		string GetLastName() const;
		string GetEmailAddress() const;
		int* GetDaysToCompleteCourses();
		Degree::DegreeProgram GetDegreeProgram() const;
		int GetAge() const;
		void Print() const;

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		Degree::DegreeProgram degree;
		int daysToCompleteCourses [3];
};

#endif