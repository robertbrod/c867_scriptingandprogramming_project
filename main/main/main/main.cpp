#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"

void parseString(string stringToParse, string &id, string &fName, string &lName, string &email, int &age, int (&days)[3], Degree::DegreeProgram& deg);

int main()
{
	// <------------------------------------- Personal Information ----------------------------------------->

	std::cout << "        Scripting and Programming - Applications - C867        " << std::endl;
	std::cout << "                  Programming Language: C++                    " << std::endl;
	std::cout << "                 WGU Student ID: #001939918                    " << std::endl;
	std::cout << "                      Name: Robert Brod                        " << std::endl;
	std::cout << "===============================================================" << std::endl << std::endl;

	// <---------------- 'studentData' table with index[4] changed to personal information ----------------->

	const std::string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Robert,Brod,rbrod@wgu.edu,29,52,90,16,SOFTWARE"
	};

	// <--------------------------------- Creating instance of Roster class -------------------------------->

	Roster classRoster;

	// <---------------------------- Variables used by parseString() function ------------------------------>

	std::string id;
	std::string fName;
	std::string lName;
	std::string email;
	int age = 0;
	int days[3]{};
	Degree::DegreeProgram deg{};

	// <----------------------------- Adding all students to classRoster ----------------------------------->

	for (int i = 0; i < 5; ++i) {
		parseString(studentData[i], id, fName, lName, email, age, days, deg);
		classRoster.Add(id, fName, lName, email, age, days[0], days[1], days[2], deg);
	}

	// <------------------------------ Displaying all student information ---------------------------------->

	std::cout << "Displaying all students:" << std::endl;
	classRoster.PrintAll();
	std::cout << std::endl;

	// <------------------------------ Printing invalid e-mail addresses ----------------------------------->

	classRoster.PrintInvalidEmails();
	std::cout << std::endl;

	// <----------------------- Printing average days in course for each student --------------------------->

	string studentID;

	for (int i = 0; i < 5; ++i) {
		studentID = classRoster.classRosterArray[i]->GetStudentID();
		classRoster.PrintAverageDaysInCourse(studentID);
	}

	std::cout << std::endl;

	// <----------------------------- Printing students by degree program ---------------------------------->

	classRoster.PrintByDegreeProgram(Degree::DegreeProgram::SOFTWARE);
	std::cout << std::endl << std::endl;

	// <------- Removing A3, printing all student information, then attempting to remove A3 again ---------->

	std::cout << "Removing A3:" << std::endl;
	classRoster.Remove("A3");
	std::cout << std::endl;

	classRoster.PrintAll();
	std::cout << std::endl;

	std::cout << "Removing A3 again:" << std::endl << std::endl;
	classRoster.Remove("A3");
	std::cout << std::endl;

	// <----------------------------------------- End of main() -------------------------------------------->

	std::cout << "DONE" << std::endl << std::endl;
	return 0;
}

/*

Function to parse all studentData string information. The variables passed by reference into the function are populated
by searching for a demiliter (','), extracting a substring beginning at index 0 and ending at the delimiter, and then
erasing that substring from the initial string. The position variable is increased by 1 before erasing to accommodate for
the comma's position in the string.

*/
void parseString(std::string stringToParse, std::string& id, std::string& fName, std::string& lName, std::string& email, int& age, int(&days)[3], Degree::DegreeProgram& deg) {
	char delimiter = ',';
	int position = 0;

	position = stringToParse.find(delimiter);
	id = stringToParse.substr(0, position);
	position += 1;
	stringToParse.erase(0, position);

	position = stringToParse.find(delimiter);
	fName = stringToParse.substr(0, position);
	position += 1;
	stringToParse.erase(0, position);

	position = stringToParse.find(delimiter);
	lName = stringToParse.substr(0, position);
	position += 1;
	stringToParse.erase(0, position);

	position = stringToParse.find(delimiter);
	email = stringToParse.substr(0, position);
	position += 1;
	stringToParse.erase(0, position);

	position = stringToParse.find(delimiter);
	age = stoi(stringToParse.substr(0, position));
	position += 1;
	stringToParse.erase(0, position);

	for (int i = 0; i < 3; ++i) {
		position = stringToParse.find(delimiter);
		days[i] = stoi(stringToParse.substr(0, position));
		position += 1;
		stringToParse.erase(0, position);
	}

	string str;

	position = stringToParse.find(delimiter);
	str = stringToParse.substr(0, position);

	if (str == "SECURITY") {
		deg = Degree::SECURITY;
	}
	else if (str == "NETWORK") {
		deg = Degree::NETWORK;
	}
	else {
		deg = Degree::SOFTWARE;
	}
}