#include "person.h"


Person::Person(int Cardid2, bool Active2, string Fname, string Lname) {
	cardid = Cardid2;
	active = Active2;
	firstName = Fname;
	lastName = Lname;

}

int Person::getCardID() {
	return 0;
}
void Person::setActive(bool active2) {
	active = active2;
}
bool Person::isActive() {
	return true;
}
string Person::getFirstName() 
{
	return firstName;
}
string Person::getLastName() {
	return lastName;
}
string Person::fullName() {
	return firstName + " " + lastName;
}
