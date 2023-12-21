#include "Admin.h"

Admin::Admin(){}

Admin::Admin(const Admin& adm)
{
    firstName = adm.firstName;
    lastName = adm.lastName;
    contactInfo = adm.contactInfo;
    access_code = adm.access_code;
}

Admin::Admin(string name, string lname, string contact, string code)
    :access_code(code)
{
    setFirstName(name);
    setLastName(lname);
    setContacts(contact);
}

Admin::~Admin()
{
    cout << "������������ " << firstName << " " << lastName << " ��������." << endl;
}

void Admin::setAccessCode(string code)
{
    access_code = code;
}

string Admin::getAccessCode()
{
    return access_code;
}

void Admin::rejectBooking(Booking& book)
{
    book.setApprovingState(false);
    book.setWaiting(false);
}

void Admin::approveBooking(Booking& book)
{
    book.setApprovingState(true);
    book.setWaiting(false);
}

void Admin::login() {
    string code;
    cout << "������ ��� �������: ";
    cin >> code;
    if (code == access_code) {
        cout << "�� ������ �� ����" << endl;
    }
    else {
        cout << "������������ ���� ��� ������" << endl;
    }
}
