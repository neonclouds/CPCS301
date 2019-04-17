/*
Author: Brandon Le
Project: Assignment 2
Date: 2/26/19
*/
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;
class Person
{
private:
	string lastName;
	string firstName;
	float  payRate;
	float  hoursWorked;
public:
	Person(string fName, string lName, float rate, float hours);
	void setLastName(string lName);
	string getLastName();
	void setFirstName(string fName);
	string getFirstName();
	void setPayRate(float rate);
	float getPayRate();
	void setHoursWorked(float hours);
	float getHoursWorked();
	float totalPay();
	string fullName();
};
#endif // end person.h