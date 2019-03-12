#include "person.h"
#include <fstream>
#include <vector>



void Person::setFirstName(string fName)
{
	firstName = fName;
}

string Person::getFirstName() 
{
	return firstName;
}

void Person::setLastName(string lName)
{
	lastName = lName;
}

string Person::getLastName()
{
	return lastName;
}

void Person::setEmployeeId(int id)
{
	employeeID = id;
}

int Person::getEmployeeId()
{
	return employeeID;
}

void Person::setCompanyName(string coName)
{
	companyName = coName;
}

string Person::getCompanyName()
{
	return companyName;
}

void Person::setPayRate(float rate)
{
	payRate = rate;
}

float Person::getPayRate()
{
	return payRate;
}

void Person::setHoursWorked(float hours)
{
	hoursWorked = hours;
}

float Person::getHoursWorked()
{
	return hoursWorked;
}

float Person::totalPay()
{

}

string Person::fullName()
{

}

void readData(string text, vector<Person>* employees)
{
	ifstream inData;
	inData.open(text);
	string firstName;
	string lastName;
	string line;
	float hoursWorked;
	float payRate;
	char newLine;
	int n = 0;
	Person p;

	while (inData >> firstName >> lastName >> hoursWorked >> payRate)
	{
		p.setFirstName(firstName);

	}

	inData.close();

}