#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void readBooks(vector<book *> & myBooks)
{
	int bookID;
	string titlebook;
	string authorbook;
	string categorybook;
	string whitespace; //this reads the blank line in the books.txt file that you dont need

	fstream infile;
	infile.open("books.txt");

	while (infile >> bookID) //if you dont use this operator it wont work because
	//it is an integer. You can only use getline for strings

	{
		getline(infile, whitespace);
		getline(infile, titlebook);
		getline(infile, authorbook);
		getline(infile, categorybook);
		getline(infile, whitespace);
		myBooks.push_back(new book(booksid, titlebook, authorbook, categorybook));
	}
	//int m = myBooks.size(); used this to get the vector size, just to make sure everything was properly
	//placed inside

}

int readPersons(vector<person *> & myCardholders) {

	int cardidperson;
	bool actperson;
	string firstn;
	string lastn;

	fstream inFile;
	inFile.open("persons.txt");

	while (inFile >> cardidperson >> actperson >> firstn >> lastn)
	{
		myCardholders.push_back(new person(cardidperson, actperson, firstn, lastn));

	}
	return 0;
}

void readRentals(vector<book *> & myBooks, vector<person *> myCardholders) {
	return;
}



void openCard(vector<person *> & myCardholders, int nextID) {
	return;
}

book * searchBook(vector<book *> myBooks, int id) {
	return nullptr;
}


int main()
{
	vector<book *> books;
	vector<person *> cardholders;

	readBooks(books);
	readPersons(cardholders);

	int option;
	do
	{
		cout << "----------Library Book Rental System----------" << endl;
		cout << "1.  Book checkout" << endl;
		cout << "2.  Book return" << endl;
		cout << "3.  View all available books" << endl;
		cout << "4.  View all outstanding rentals" << endl;
		cout << "5.  View outstanding rentals for a cardholder" << endl;
		cout << "6.  Open new library card" << endl;
		cout << "7.  Close library card" << endl;
		cout << "8.  Exit system" << endl;
		cout << "Please enter a choice: ";
		cin >> option;
		switch (option)
		{
		case 1:
			int answer2;
			int answer;
			int tempcardid;
			string name = cardholders.at(0)->fullname();
			int cardID = cardholders.at(0)->getcardid();
			int booksid = books.at(0)->getbookid();
			string titles = books.at(0)->gettitle();

			cout << "Please enter the card ID: ";
			cin >> answer;

			for (int i = 0; i < cardholders.size(); i++) {

				if (answer == cardholders.at(i)->getcardid()) {
					cardID = cardholders.at(i)->getcardid();
					name = cardholders.at(i)->fullname();
					cout << "Cardholder: " << name << endl;
					cout << "Please enter the Book ID: ";
					cin >> answer2;
				}
				else {
					cout << "invalid card id" << endl;
					break;
				}

			}
			for (int i = 0; i < books.size(); i++) {
				if (answer2 == books.at(i)->getbookid()) {
					booksid = books.at(i)->getbookid();
					titles = books.at(i)->gettitle();
					cout << "Title: " << titles << endl;
					cout << "Rental complete." << endl;
				}
				else {
					cout << "invalid book id." << endl;
					break;
				}
			}
		}

	} while (option != 8);
	return 0;

}
/*
			case 2:
				// Book return
				break;

			case 3:
				// View all available books
				break;

			case 4:
				// View all outstanding rentals
				break;

			case 5:
				// View outstanding rentals for a cardholder
				break;

			case 6:
				// Open new library card
				break;

			case 7:
				// Close library card
				break;

			case 8:
				// Must update records in files here before exiting the program
				break;
*/
/*default:
	cout << "Invalid entry" << endl;
	break;*/