/*
Author: Brandon Le
Project: Assignment 2
Date: 2/26/19
*/
#include "person.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void readData(string text, vector <Person> &p)
{
	ifstream inData;
	inData.open(text);
	string firstname;
	string lastname;
	float hoursworked;
	float payrate;

	while (inData >> firstname >> lastname >> hoursworked >> payrate)
	{
		p.emplace_back(firstname, lastname, hoursworked, payrate);
	}

	inData.close();

}

void writeData(string text, vector <Person> &p)
{
	ofstream outData;
	outData.open(text);
	for (int i = 0; i < p.size(); i++)
	{
		outData << p.at(i).fullName() << "  " << p.at(i).totalPay() << endl;

	}
	outData.close();

}


int main()
{
	vector <Person> person;
	readData("input.txt", person);
	writeData("output.txt", person);
	return 0;
}