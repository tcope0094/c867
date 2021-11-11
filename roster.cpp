#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "degree.h"
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

using namespace std;

int main() {

    cout << "Course:\t\tScripting and Programming - Applications - C867" << endl;
    cout << "Language:\tC++" << endl;
    cout << "Student ID:\t000998155" << endl;
    cout << "Name:\t\tTyler Cope" << endl << endl;

    int numStudents = 5;
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Tyler,Cope,tcope0094@gmail.com,28,50,45,32,SOFTWARE" };

    Roster* classRoster = new Roster(numStudents);
    
    for (int i = 0; i < numStudents; ++i) {
        classRoster->parseThenAdd(studentData[i]);
    }

    classRoster->PrintAll();

    classRoster->PrintInvalidEmails();

    for (int i = 0; i < numStudents; ++i) {
        string tempID = "";
        tempID = classRoster->classRosterArray[i]->GetStudentID();
        classRoster->PrintDaysInCourse(tempID);
    }

    classRoster->PrintByDegreeProgram(SOFTWARE);

    classRoster->Remove("A3");
    classRoster->Remove("A3");

    classRoster->~Roster();

    return 0;
}

Roster::Roster() {

    this->capacity = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;

}

Roster::Roster(int capacity) {

    this->capacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student*[capacity];
}

void Roster::parseThenAdd(string row) {

    if (lastIndex < capacity) {
        lastIndex++;

        int rightSide = row.find(",");
        string tempID = row.substr(0, rightSide);

        int leftSide = rightSide + 1;
        rightSide = row.find(",", leftSide);
        string tempFName = row.substr(leftSide, (rightSide - leftSide));

        leftSide = rightSide + 1;
        rightSide = row.find(",", leftSide);
        string tempLName = row.substr(leftSide, (rightSide - leftSide));

        leftSide = rightSide + 1;
        rightSide = row.find(",", leftSide);
        string tempEmail = row.substr(leftSide, (rightSide - leftSide));
        
        leftSide = rightSide + 1;
        rightSide = row.find(",", leftSide);
        int tempAge = stoi(row.substr(leftSide, (rightSide - leftSide)));

        leftSide = rightSide + 1;
        rightSide = row.find(",", leftSide);
        int tempDays1 = stoi(row.substr(leftSide, (rightSide - leftSide)));

        leftSide = rightSide + 1;
        rightSide = row.find(",", leftSide);
        int tempDays2 = stoi(row.substr(leftSide, (rightSide - leftSide)));

        leftSide = rightSide + 1;
        rightSide = row.find(",", leftSide);
        int tempDays3 = stoi(row.substr(leftSide, (rightSide - leftSide)));
    
        leftSide = rightSide + 1;
        rightSide = row.find(",", leftSide);
        string degreeString = row.substr(leftSide, (rightSide - leftSide));
        
        Degree tempDegree = SOFTWARE;

        if (degreeString[2] == 'F') {
            tempDegree = SOFTWARE;
        }
        else if (degreeString[2] == 'T') {
            tempDegree = NETWORKING;
        }
        else if (degreeString[2] == 'C') {
            tempDegree = SECURITY;
        }
        else {
            cout << "INVALID DEGREE TYPE" << endl;
        }
        this->Add(tempID, tempFName, tempLName, tempEmail, tempAge, tempDays1, tempDays2, tempDays3, tempDegree);

        /*
        string singleRecord;
        int vecSize = 8;
        vector<string> resultVector(vecSize);
        stringstream recordStream(singleRecord);

        while (recordStream.good()) {
            string recordSubStr;
            getline(recordStream, recordSubStr, ',');
            resultVector.push_back(recordSubStr);
        }

        Degree tempDegree = SOFTWARE;
        if (resultVector.at(8) == "SOFTWARE") {
            tempDegree = SOFTWARE;
        }
    
        string tempID =    resultVector.at(0);
        cout << "TEMP ID: " << resultVector.at(0) << endl;
        string tempFName = resultVector.at(1);
        string tempLName = resultVector.at(2);
        string tempEmail = resultVector.at(3);
        string tempAge =   resultVector.at(4);
        string tempDays1 = resultVector.at(5);
        string tempDays2 = resultVector.at(6);
        string tempDays3 = resultVector.at(7);
        */
    }

}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
    int days[Student::daysArraySize];
    days[0] = daysInCourse1;
    days[1] = daysInCourse2;
    days[2] = daysInCourse3;
    
    if(degreeProgram == 0){
        classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, days);
    }
    else if (degreeProgram == 1){
        classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, days);
    }
    else if (degreeProgram == 2){
        classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, days);
    }
    else {
        cout << "INVALID DEGREE PROGRAM" << endl;
    }

    return;
}

void Roster::Remove(string studentID) {
    
    string tempID = "";
    bool idFound = false;

    for (int i = 0; i <= lastIndex; ++i) {

        tempID = classRosterArray[i]->GetStudentID();
        
        if (tempID == studentID) {
            
            delete classRosterArray[i];
            idFound = true;
            
            for (int j = i; j < lastIndex; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }

            lastIndex--;

        }
    }
    if (idFound == false) {
        cout << "STUDENT ID |" << studentID << "| NOT FOUND" << endl << endl;
    }
}

void Roster::PrintAll() {
    
    for(int i = 0; i <= lastIndex; ++i ){
        classRosterArray[i]->Print();
    }
    cout << endl;
}

void Roster::PrintDaysInCourse(string studentID) {

    string tempID = "";
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int avgNum = 0;

    for (int i = 0; i <= lastIndex; ++i) {

        tempID = classRosterArray[i]->GetStudentID();

        if (tempID == studentID) {
                num1 = classRosterArray[i]->GetDaysToComplete()[0];
                num2 = classRosterArray[i]->GetDaysToComplete()[1];
                num3 = classRosterArray[i]->GetDaysToComplete()[2];

                avgNum = ((num1 + num2 + num3) / 3);

                cout << "AVERAGE DAYS IN EACH COURSE FOR STUDENT |" << studentID << "| : " << avgNum << endl << endl;
        }
    }
}

void Roster::PrintInvalidEmails() {

    string spaceChar = " ";
    string atChar = "@";
    string periodChar = ".";

    string tempEmail = "";

    cout << "INVALID STUDENT EMAIL ADDRESSES: " << endl;
    
    for (int i = 0; i <= lastIndex; ++i) {
        tempEmail = classRosterArray[i]->GetEmailAddr();
        
        if (tempEmail.find(spaceChar) != string::npos) {
            cout << "INVALID EMAIL FOUND: " << tempEmail << endl;
            }
        else if (tempEmail.find(atChar) == string::npos) {
            cout << "INVALID EMAIL FOUND: " << tempEmail << endl;
            }
        else if (tempEmail.find(periodChar) == string::npos) {
            cout << "INVALID EMAIL FOUND: " << tempEmail << endl;
        }
    }
    cout << endl;
}

void Roster::PrintByDegreeProgram(int degreeProgram) {
    int tempDeg = 0;
    
    cout << "STUDENTS IN THE " << degreeTypeStrings[degreeProgram] << " DEGREE PROGRAM: " <<   endl;

    for (int i = 0; i <= lastIndex; ++i) {

        tempDeg = classRosterArray[i]->GetDegreeProgram();

        if (tempDeg == degreeProgram) {

            classRosterArray[i]->Print();

        }
    }
    cout << endl;
}
Roster::~Roster() {}