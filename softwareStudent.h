#pragma once
#include "student.h"
#include "degree.h"
using std::string;
class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	SoftwareStudent(string sID, string fNM, string lNM, string emAddr, int sAge, int daysArr[]);

	Degree GetDegreeProgram();

	void Print();

	~SoftwareStudent();

private:
	Degree degreeType;
};