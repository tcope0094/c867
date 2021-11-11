#pragma once
#include "student.h"
#include "degree.h"
using std::string;
class NetworkStudent : public Student {
public:
	NetworkStudent();
	NetworkStudent(string sID, string fNM, string lNM, string emAddr, int sAge, int daysArr[]);

	Degree GetDegreeProgram();
	
	void Print();

	~NetworkStudent();

private:
	Degree degreeType;
};
