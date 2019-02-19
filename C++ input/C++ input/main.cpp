#include <iostream>
#include <fstream>
#include <string>

using namespace std;

float displayRichest()
{

}

float deposit()
{

}

//char menu()
//{
//	char input;
//	cout << "[E]nter the data. Enter only 1 entry per [E]" << endl;		//The display menu selection screen.
//	cout << "[D]isplay all names and balances" << endl;
//	cout << "[Q]uit the program" << endl;
//	cin >> input;
//	return input;
//}

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
	float balance;
	char input;


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

	//do
	//{
	//	menu();
	//	if (input == )

	//} while (loop);

	for (int i = 0; i < 6; i++)
	{
		display(people[i].Name, people[i].Balance);
	}
	system("PAUSE");
	return 0;
}