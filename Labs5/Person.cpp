#include "Person.h"

Person::Person(){}

Person::Person(const Person& pers)
{
    firstName = pers.firstName;
    lastName = pers.lastName;
    contactInfo = pers.contactInfo;
}

Person::Person(string name, string lname, string contact)
    : firstName(name), lastName(lname), contactInfo(contact){}

Person::~Person(){
    cout << "Персону " << firstName << " " << lastName << " видалено." << endl;
}

void Person::setFirstName(string name)
{
    firstName = name;
}

void Person::setLastName(string lName)
{
    lastName = lName;
}

void Person::setContacts(string contact)
{
    contactInfo = contact;
}

string Person::getFirstName()
{
    return firstName;
}

string Person::getLastName()
{
    return lastName;
}

string Person::getContacts()
{
    return contactInfo;
}

void Person::displayInfo()
{
    cout << "Персона: " << firstName << " " << lastName << endl;
    cout << "Контактна інформація: " << contactInfo << endl;
}
