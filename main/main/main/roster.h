#include <string>
#include "degree.h"
#include "student.h"
#ifndef ROSTER_H
#define ROSTER_H

class Roster {
	public:
		Student* classRosterArray[5];
		int studentCount = 0;

		Roster();
		~Roster();
		void Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeprogram);
		void Remove(std::string studentID);
		void PrintAll();
		void PrintAverageDaysInCourse(std::string studentID);
		void PrintInvalidEmails();
		void PrintByDegreeProgram(Degree::DegreeProgram degreeProgram);
};

#endif