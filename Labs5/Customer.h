#pragma once
#include "Person.h"

class Customer :
    public Person
{
protected:
    string username;
    string password;
    double budget;

public:
    Customer();
    Customer(const Customer& cust);
    Customer(string, string, string, string, string, double);

    ~Customer();

    void setUsername(string usname);
    void setPassword(string pass);
    void setBudget(double budg);

    string getUsername();
    string getPassword();
    double getBudget();

    void login();

    void replBalance(double sum);

    void displayInfo();

    Customer& operator --() {
        if (budget >= 500) {
            budget -= 500;
        }
        return *this;
    }

    Customer& operator --(int) {
        Customer& temp = *this;
        if (budget >= 500) {
            budget -= 500;
        }
        return temp;
    }

    Customer& operator ++() {
        budget += 500;
        return *this;
    }

    Customer& operator++(int) {
        Customer& temp = *this;
        budget += 500;
        return temp;
    }

    Customer operator+(Customer& other) {
        double result = budget + other.budget;

        return Customer("", "", "", "", "", result);
    }

    Customer operator-(Customer& other) {
        double result;
        if (budget >= other.budget) result = budget - other.budget;
        else result = 0.0;

        return Customer("", "", "", "", "", result);
    }

    string& operator[](int p) {
        switch(p) {
        case 1:
            return this->firstName;
            break;
        case 2:
            return this->lastName;
            break;
        case 3:
            return this->contactInfo;
            break;
        case 4:
            return this->username;
            break;
        case 5:
            return this->password;
            break;
        }
    }

    Customer operator*(Customer& other) {
        double result = budget * other.budget;
        return Customer("", "", "", "", "", result);
    }
};

