#include "Customer.h"

Customer::Customer(){}

Customer::Customer(const Customer& cust)
{
	firstName = cust.firstName;
	lastName = cust.lastName;
	contactInfo = cust.contactInfo;
	username = cust.username;
	password = cust.password;
	budget = cust.budget;
}

Customer::Customer(string name, string lname, string contact, string user, string pass, double budg)
	:username(user), password(pass), budget(budg)
{
	setFirstName(name);
	setLastName(lname);
	setContacts(contact);
}

Customer::~Customer(){
	cout << "����������� " << firstName << " " << lastName << " ��������." << endl;
}

void Customer::setUsername(string usname)
{
	username = usname;
}

void Customer::setPassword(string pass)
{
	password = pass;
}

void Customer::setBudget(double budg)
{
	budget = budg;
}

string Customer::getUsername()
{
	return username;
}

string Customer::getPassword()
{
	return password;
}

double Customer::getBudget()
{
	return budget;
}

void Customer::replBalance(double sum)
{
	if (sum > 0.0) {
		budget += sum;
		cout << "������ ����������� ������ " << budget << " ���." << endl;
	}
	else {
		cout << "���������� ���� ����������!" << endl;
	}
}

void Customer::login() {
	string pass;
	cout << firstName << ", ������ ������: ";
	cin >> pass;
	if (pass == password) {
		cout << "³����, " << firstName << endl;
	}
	else {
		cout << "������������ ������" << endl;
	}
}

void Customer::displayInfo() 
{
	cout << "�볺��: " << firstName << " " << lastName << endl;
	cout << "��������� ����������: " << contactInfo << endl;
	cout << "������: " << budget << " ���." << endl;
}


