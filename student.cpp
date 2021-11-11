#pragma once
#include <iostream>
#include "student.h"
#include "degree.h"

Student::Student() {
	this->studentID = "none";
	this->fName = "none";
	this->lName = "none";
	this->emailAddr = "none";
	this->studentAge = 0;
	for (int i = 0; i < daysArraySize; ++i) {
		daysToComplete[i] = 0;
	}
	
}

Student::Student(string sID, string fNM, string lNM, string emAddr, int sAge, int daysArr[]) {

	this->studentID = sID;
	this->fName = fNM;
	this->lName = lNM;
	this->emailAddr = emAddr;
	this->studentAge = sAge;
	for (int i = 0; i < daysArraySize; ++i) {
		this->daysToComplete[i] = daysArr[i];
	}

}

void Student::SetStudentID(string idToSet) {
	this->studentID = idToSet;
	return;
}

string Student::GetStudentID() {
	return studentID;
}

void Student::SetFirstName(string fNameToSet) {
	this->fName = fNameToSet;
	return;
}

string Student::GetFirstName() {
	return fName;
}

void Student::SetLastName(string lNameToSet) {
	this->lName = lNameToSet;
	return;
}

string Student::GetLastName() {
	return lName;
}

void Student::SetEmailAddr(string emailAddrToSet) {
	this->emailAddr = emailAddrToSet;
	return;
}

string Student::GetEmailAddr() {
	return emailAddr;
}

void Student::SetStudentAge(int ageToSet) {
	this->studentAge = ageToSet;
	return;
}

int Student::GetStudentAge() {
	return studentAge;
}

void Student::SetDaysToComplete(int daysArray[]) {
	for (int i = 0; i < daysArraySize; ++i) {
		this->daysToComplete[i] = daysArray[i];
	}
	return;
}

int* Student::GetDaysToComplete()  {
	return daysToComplete;
}

void Student::Print() {
	cout << "Student ID: " << studentID << " \t" ;
	cout << "First Name: " << fName << " \t";
	cout << "Last Name: " << lName << " \t";
	cout << "Email Address: " << emailAddr << "  \t";
	cout << "Student Age: " << studentAge << " \t";
	cout << "Days to Complete Courses: " << "{ " << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << " }" << "\t\t";
	return;
}

Student::~Student() {}