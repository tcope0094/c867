#pragma once
#include "student.h"
#include "degree.h"
using std::string;
class SecurityStudent : public Student {
public:
	SecurityStudent();
	SecurityStudent(string sID, string fNM, string lNM, string emAddr, int sAge, int daysArr[]);

	Degree GetDegreeProgram();

	void Print();

	~SecurityStudent();

private:
	Degree degreeType;
};