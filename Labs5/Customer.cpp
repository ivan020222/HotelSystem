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
	cout << "Користувача " << firstName << " " << lastName << " видалено." << endl;
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
		cout << "Бюджет користувача складає " << budget << " грн." << endl;
	}
	else {
		cout << "Некоректна сума поповнення!" << endl;
	}
}

void Customer::login() {
	string pass;
	cout << firstName << ", введіть пароль: ";
	cin >> pass;
	if (pass == password) {
		cout << "Вітаємо, " << firstName << endl;
	}
	else {
		cout << "Неправильний пароль" << endl;
	}
}

void Customer::displayInfo() 
{
	cout << "Клієнт: " << firstName << " " << lastName << endl;
	cout << "Контактна інформація: " << contactInfo << endl;
	cout << "Бюджет: " << budget << " грн." << endl;
}


