/*************************************
Brandon Le
Project: Redo Assignment 1 
Date Due : 4/16/19
Visual Studio 2017
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
};

PERSON * readData(int &N)
{
	PERSON* P = new PERSON[N];
	ifstream inData;
	inData.open("data.txt");
	string firstName;
	string lastName;
	float balance;
	string fullName;
	int i = 0;

	while (inData && i < N)
	{
		inData >> firstName >> lastName >> P[i].Balance;
		fullName = firstName + ' ' + lastName;
		strcpy_s(P[i].Name, fullName.c_str());
		cout << firstName << P[i].Balance << endl;
		i++;
	}

	inData.close();
	return P;
}

int main()
{
	ofstream outData;
	bool loop = true;
	int size = 6;
	float balance = 0;
	float richestBalance = 0;
	string richestPerson;
	string personDeposit;
	float depositAmount;
	float tempBalance = 0;
	int input;
	PERSON* p = new PERSON[size];
	p = readData(size);


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
			for (int i = 0; i < size; i++)
			{
				display(p[i].Name, p[i].Balance);
			}
		}
		if (input == 2)
		{
			for (int i = 0; i < 6; i++)
			{
				tempBalance = p[i].Balance;
				if (tempBalance > richestBalance)
				{
					richestBalance = tempBalance;
					richestPerson = p[i].Name;
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

			int count = 0;
			for (int i = 0; i < size; i++)
			{
				if (personDeposit == p[i].Name)
				{
					p[i].Balance = deposit(personDeposit, p[i].Name, p[i].Balance, depositAmount);
					cout << "Now your new balance is ";
					cout << p[i].Balance << endl << endl;
				}
				if (personDeposit != p[i].Name)
				{
					count++;
				}
				if (count == 5)
				{
					cout << "Record not found." << endl;
				}
				
			}

		}
		if (input == 4)
		{
			cout << "Thank you.";
			loop = false;
		}

	} while (loop);

	outData.open("newData.txt");
	for (int i = 0; i < 6; i++)
	{
		outData << p[i].Name << "  " << p[i].Balance << endl;
	}

	return 0;
}