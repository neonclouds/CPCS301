/*************************************
Brandon Le
Homework 1: C++ Input
Date Due : 2/21/2019
Visual Studio 2015
*************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


float deposit(string person, string a, float balance, float deposit)
{
	if (person == a)
	{
		return balance + deposit;
	}
}


void display(string a, float balance)
{
	cout << a + ' ';
	cout << balance << endl;

}

struct PERSON {
	char Name[20];
	float Balance;
} people[5];

int main()
{
	ifstream inData;
	inData.open("data.txt");
	bool loop = true;
	string firstName;
	string lastName;
	string fullName;
	char cFullName[20];
	float balance = 0;
	float richestBalance = 0;
	string richestPerson;
	string personDeposit;
	float depositAmount;
	float tempBalance = 0;
	int input;


	for (int i = 0; i < 6; i++)
	{
		inData >> firstName >> lastName >> balance;
		
		fullName = firstName + ' ' + lastName;
		strcpy_s(cFullName, fullName.c_str());


		

		for (int n = 0; n < strlen(cFullName); n++)
		{
			people[i].Name[n] = cFullName[n];
		}
	
		people[i].Balance = balance;
	}

	do {

		cout << "1. Display all names and balances." << endl;
		cout << "2. Display richest person and balance." << endl;
		cout << "3. Deposit money." << endl;
		cout << "4. Quit" << endl;
		cout << "Please enter a number.";
		cin >> input;
		cout << endl;
		if (input == 1)
		{
			for (int i = 0; i < 6; i++)
			{
				display(people[i].Name, people[i].Balance);
			}
		}
		if (input == 2)
		{
			for (int i = 0; i < 6; i++)
			{
				tempBalance = people[i].Balance;
				if (tempBalance > richestBalance)
				{
					richestBalance = tempBalance;
					richestPerson = people[i].Name;
				}
			}
			cout << richestPerson + " ";
			cout << richestBalance << endl << endl;
		}
		if (input == 3)
		{
			cout << "Enter your full name to deposit money: ";
			cin.ignore();
			getline(cin, personDeposit);
			cout << endl << personDeposit << ", how much would you like to deposit?";
			cin >> depositAmount;

			for (int i = 0; i < 6; i++)
			{
				if (personDeposit == people[i].Name)
				{
					people[i].Balance = deposit(personDeposit, people[i].Name, people[i].Balance, depositAmount);
					cout << "Now your new balance is ";
					cout << people[i].Balance << endl << endl;
				}
				
			}

		}
		if (input == 4)
		{
			cout << "Thank you.";
			loop = false;
		}

	} while (loop);

	return 0;
}