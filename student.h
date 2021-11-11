#pragma once
#include "degree.h"
#include <string>
using namespace std;

class Student {
public:

	const static int daysArraySize = 3;

	Student();
	Student(string sID, string fNM, string lNM, string emAddr, int sAge, int daysArr[]);

	void SetStudentID(string idToSet);
	string GetStudentID();

	void SetFirstName(string fNameToSet);
	string GetFirstName();
	
	void SetLastName(string lNameToSet);
	string GetLastName();
	
	void SetEmailAddr(string emailAddrToSet);
	string GetEmailAddr();
	
	void SetStudentAge(int ageToSet);
	int GetStudentAge();
	
	void SetDaysToComplete(int daysArray[]);
	int* GetDaysToComplete() ;

	virtual void Print();
	virtual Degree GetDegreeProgram() = 0;

	~Student();

protected:
	string studentID;
	string fName;
	string lName;
	string emailAddr;
	int studentAge;
	int daysToComplete[daysArraySize];
	Degree degreeType;
};