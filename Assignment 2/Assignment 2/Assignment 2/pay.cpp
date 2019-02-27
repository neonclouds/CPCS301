#include "person.h"
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

Person::Person()
{
	string lastName = " ";
	string firstName = " ";
	float  payRate = 0;
	float  hoursWorked = 0;
}

string Person::getFirstName() {

	return firstName;
}

string Person::getLastName()
{
	return lastName;
}

float Person::getHoursWorked()
{
	return hoursWorked;
}

float Person::getPayRate()
{
	return payRate;
}

void Person::setFirstName(string fName)
{
	firstName = fName;
}

void Person::setLastName(string lName)
{
	lastName = lName;
}

void Person::setHoursWorked(float hours)
{
	hoursWorked = hours;
}

void Person::setPayRate(float pay)
{
	payRate = pay;
}

float Person::totalPay()
{
	return payRate * hoursWorked;
}

string Person::fullName()
{
	return firstName + " " + lastName;
}

int readData(string text, Person people[])
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
	for (int i = 0; i < 20; i++)
	{
		
		inData >> firstName >> lastName >> hoursWorked >> payRate;


		people[i].setFirstName(firstName);
		people[i].setLastName(lastName);
		people[i].setHoursWorked(hoursWorked);
		people[i].setPayRate(payRate);

		if (inData.eof())
		{
			n = i;
			i = 19;
		}

	}

	inData.close();
	return n;

}

void writeData(string text, Person people[], int n)
{
	ofstream outData;
	outData.open(text);
	for (int i = 0; i < n; i++)
	{
		outData << people[i].fullName() << "  " << people[i].totalPay() << endl;

	}
	outData.close();
}

int main()
{
	Person people[19];
	int numberOfEmployees = readData("input.txt", people);
	readData("input.txt", people);
	writeData("output.txt", people, numberOfEmployees);
	return 0;
}