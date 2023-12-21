#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string firstName;
	string lastName;
	string contactInfo;
public:
	Person();
	Person(const Person& pers);
	Person(string, string, string);

	virtual ~Person();

	void setFirstName(string name);
	void setLastName(string lName);
	void setContacts(string contact);

	string getFirstName();
	string getLastName();
	string getContacts();

	virtual void login() {};

	virtual void displayInfo();
};

