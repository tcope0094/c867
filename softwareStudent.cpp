#include "softwareStudent.h"
#include <iostream>

SoftwareStudent::SoftwareStudent():Student() {
	degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string sID, string fNM, string lNM, string emAddr, int sAge, int daysArr[])
	:Student(sID, fNM, lNM, emAddr, sAge, daysArr) {
	degreeType = SOFTWARE;
}

Degree SoftwareStudent::GetDegreeProgram() {
	return SOFTWARE;
}

void SoftwareStudent::Print() {

	this->Student::Print();
	std::cout << "DEGREE PROGRAM: SOFTWARE" << endl;

};

SoftwareStudent::~SoftwareStudent(){}