#include "securityStudent.h"
#include <iostream>

SecurityStudent::SecurityStudent() {
	degreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string sID, string fNM, string lNM, string emAddr, int sAge, int daysArr[])
	:Student(sID, fNM, lNM, emAddr, sAge, daysArr) {

}

Degree SecurityStudent::GetDegreeProgram() {
	return SECURITY;
}

void SecurityStudent::Print() {

	this->Student::Print();
	std::cout << "DEGREE PROGRAM: SECURITY" << endl;

};

SecurityStudent::~SecurityStudent(){}