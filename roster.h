#pragma once
#include "degree.h"
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include <string>


using namespace std;

class Roster {
private:
	int lastIndex;
	int capacity;

public:

	Student** classRosterArray;
	Roster();
	Roster(int capacity); 

	void parseThenAdd(string row);
	void Add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		Degree degreeProgram
	);

	void Remove(string studentID);
	void PrintAll();
	void PrintDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(int degreeProgram);
	
	~Roster();

};