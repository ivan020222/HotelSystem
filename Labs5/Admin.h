#pragma once
#include "Person.h"
#include "Booking.h"

class Admin :
    public Person
{
protected:
    string access_code;

public:
    Admin();
    Admin(const Admin& adm);
    Admin(string name, string lname, string contact, string code);

    ~Admin();

    void setAccessCode(string code);

    string getAccessCode();

    void login();

    void rejectBooking(Booking& book);
    void approveBooking(Booking& book);
};

