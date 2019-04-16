#include "person.h"

void readData(string text, vector<Person>* employees)
{
	ifstream inData;
	inData.open(text);
	string firstName;
	string lastName;
	int ID;
	string companyName;
	float hoursWorked;
	float payRate;
	Person p;

	while (inData >> firstName >> lastName >> ID >> companyName >> hoursWorked >> payRate)
	{
		p.setFirstName(firstName);
		p.setLastName(lastName);
		p.setEmployeeId(ID);
		p.setCompanyName(companyName);
		p.setHoursWorked(hoursWorked);
		p.setPayRate(payRate);

		employees->push_back(p);

	}

	inData.close();
}


void printHighestPaid(vector<Person>* employees)
{
	float highestpaid = 0.0;
	string highestname;
	int employeeid;
	string employer;
	float totalpay = 0.0;
	int index = 0;
	for (int i = 0; i < employees->size(); i++)
	{
		if (highestpaid < employees->at(i).getPayRate()) {
			highestpaid = employees->at(i).getPayRate();
			highestname = employees->at(i).fullName();
			employeeid = employees->at(i).getEmployeeId();
			totalpay = employees->at(i).totalPay();
			employer = employees->at(i).getCompanyName();
		}
	}

	cout << "Highest Paid: " << highestname << endl;
	cout << "Employee ID: " << employeeid << endl;
	cout << "Employer: " << employer << endl;
	cout << "Total pay: " << totalpay << endl;

}

void getCompanies(vector<string>* companyNames, vector<Person>* employees)
{
	string companyName;

	for (int i = 0; i < employees->size(); i++) {
		companyName = employees->at(i).getCompanyName();
		companyNames->push_back(companyName);
	}
}

void separateAndSave(vector<Person>* employees)
{
	ofstream outfile;
	string boeing = "Boeing";
	outfile.open("Boeing.txt");
	float boeingtotal = 0.00;
	for (int i = 0; i < employees->size(); i++)
	{
		if (boeing == employees->at(i).getCompanyName()) {
			outfile << employees->at(i).fullName() << " ";
			outfile << employees->at(i).getEmployeeId() << " ";
			outfile << employees->at(i).getCompanyName() << " ";
			outfile << employees->at(i).totalPay() << endl;
			boeingtotal += employees->at(i).totalPay();
		}
	}
	outfile << "Total: " << boeingtotal << endl;
	outfile.close();

	outfile.open("Intel.txt");
	string intel = "Intel";
	float inteltotal = 0.00;
	for (int i = 0; i < employees->size(); i++)
	{
		if (intel == employees->at(i).getCompanyName()) {
			outfile << employees->at(i).fullName() << " ";
			outfile << employees->at(i).getEmployeeId() << " ";
			outfile << employees->at(i).getCompanyName() << " ";
			outfile << employees->at(i).totalPay() << endl;
			inteltotal += employees->at(i).totalPay();
		}
	}
	outfile << "Total: " << inteltotal << endl;
	outfile.close();

	outfile.open("Douglas.txt");
	string douglas = "Douglas";
	float douglastotal = 0.00;
	for (int i = 0; i < employees->size(); i++)
	{
		if (douglas == employees->at(i).getCompanyName()) {
			outfile << employees->at(i).fullName() << " ";
			outfile << employees->at(i).getEmployeeId() << " ";
			outfile << employees->at(i).getCompanyName() << " ";
			outfile << employees->at(i).totalPay() << endl;
			douglastotal += employees->at(i).totalPay();
		}
	}
	outfile << "Total: " << douglastotal << endl;
	outfile.close();

	outfile.open("Raytheon.txt");
	string raytheon = "Raytheon";
	float raytheontotal = 0.00;
	for (int i = 0; i < employees->size(); i++)
	{
		if (raytheon == employees->at(i).getCompanyName()) {
			outfile << employees->at(i).fullName() << " ";
			outfile << employees->at(i).getEmployeeId() << " ";
			outfile << employees->at(i).getCompanyName() << " ";
			outfile << employees->at(i).totalPay() << endl;
			raytheontotal += employees->at(i).totalPay();
		}
	}
	outfile << "Total: " << raytheontotal << endl;
	outfile.close();

	outfile.open("HealthTech.txt");
	string healthtech = "HealthTech";
	float healthtechtotal = 0.00;
	for (int i = 0; i < employees->size(); i++)
	{
		if (healthtech == employees->at(i).getCompanyName()) {
			outfile << employees->at(i).fullName() << " ";
			outfile << employees->at(i).getEmployeeId() << " ";
			outfile << employees->at(i).getCompanyName() << " ";
			outfile << employees->at(i).totalPay() << endl;
			healthtechtotal += employees->at(i).totalPay();
		}
	}
	outfile << "Total: " << healthtechtotal << endl;
	outfile.close();
}

int main()
{
	vector<Person> employees;
	vector<string> companyNames;
	readData("input.txt", &employees);
	printHighestPaid(&employees);
	separateAndSave(&employees);
}