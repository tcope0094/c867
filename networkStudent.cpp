#include "networkStudent.h"
#include <iostream>

NetworkStudent::NetworkStudent() {
	degreeType = NETWORKING;
}

NetworkStudent::NetworkStudent(string sID, string fNM, string lNM, string emAddr, int sAge, int daysArr[])
	:Student(sID, fNM, lNM, emAddr, sAge, daysArr) {

}

Degree NetworkStudent::GetDegreeProgram() {
	return NETWORKING;
}

void NetworkStudent::Print() {

	this->Student::Print();
	std::cout << "DEGREE PROGRAM: NETWORKING" << endl;
};

NetworkStudent::~NetworkStudent(){}