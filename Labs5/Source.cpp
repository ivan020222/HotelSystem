#pragma once
#include <iostream>
#include <vector>
//#include <deque>
#include <stack>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include "Person.h"
#include "Admin.h"
#include "Customer.h"
#include "Room.h"
#include "Booking.h"

using namespace std;

template <typename X>
class Functor {
public:
	X add(X x, X y) {
		return x + y;
	}

    X substr(X x, X y) {
        return x - y;
    }
};

int Booking::idCounter = 1;

int main() {
	SetConsoleCP(1521);
	SetConsoleOutputCP(1251);

	//������ ��������� ��'��Ҳ�
	vector<Room<bool>> rooms_Static;
	for (int i = 1; i < 6; i++) {
		Room<bool> r(i, "��������", i % 2 + 1, 500.0 * (i % 2 + 1), false);
		rooms_Static.push_back(r);
	}

	Room<bool> r1(4, "����", 1, 1000.0, false);

	rooms_Static.pop_back();
	rooms_Static.emplace_back(r1);

	//��� ����̲���� ��'��Ҳ�
    deque<Room<bool>*> rooms_Dynamic;
	for (int j = 6; j < 11; j++) {
		Room<bool>* r = new Room<bool>(j, "��������", j % 3 + 1, 500.0 * (j % 3 + 1), false);
		if (j % 2 == 0) {
			rooms_Dynamic.push_back(r);
		}
		else {
			rooms_Dynamic.push_front(r);
		}
	}

	rooms_Dynamic.pop_front();

	//���� ���������ײ�
	stack<Customer> customers;

	customers.emplace(Customer("������", "�������", "vasyl@gmail.com", "vasyl", "parol", 500.0));
	customers.push(Customer("����", "����", "ivan@gmail.com", "ivan", "password", 1000.0));

    std::cout << customers.top()[2] << endl;

    //��̲�
	Admin admin("����", "����", "support@i.ua", "12345678");

	//��˲����Ͳ ������� ����ֲ�
    //1 �����
	Person* pers;
    pers = new Person("Person", "Surname", "Contact");
    pers->displayInfo();
    delete pers;
    pers = new Admin("����", "����", "i@i.ua", "52123647");
    pers->displayInfo();
    delete pers;
    pers = new Customer("�����", "������", "petr@p.com", "petryk", "password", 500.0);
    pers->displayInfo();
    delete pers;

    //2 �����
    Person person2("������� 1", "�������", "�������� ����������");
    pers = &person2;
    pers->displayInfo();
	pers = &admin;
	pers->displayInfo();
	pers = &customers.top();
	pers->displayInfo();

    //3 �����
    Admin administrator("����2", "����2", "�������", "��� �������");
    Customer customer1("����������1", "�������", "�������", "username", "password", 0.0);
    Person person("�������", "�������", "�������");
    pers = &person;
    pers->displayInfo();
    pers = (Person*)&administrator;
    pers->displayInfo();
    pers = (Person*)&customer1;
    pers->displayInfo();

    vector<Customer> customers_St;
    for (int i = 0; i < 5; i++)
        customers_St.push_back(Customer());

    std::sort(customers_St.begin(), customers_St.end(), [](Customer& r1, Customer& r2) {
        return r1.getBudget() < r2.getBudget();
    });

    std::for_each(customers_St.begin(), customers_St.end(), [](Customer& obj) {
        std::cout << obj.getBudget() << " ";
    });
    std::cout << std::endl;

   vector<Customer> transformed_Vector;
    std::transform(customers_St.begin(), customers_St.end(), std::back_inserter(transformed_Vector), [](Customer& obj) {
        return obj.setBudget(obj.getBudget() * 2);
        });

    vector<Customer> copiedCustom;
    std::copy(customers_St.begin(), customers_St.end(), std::back_inserter(copiedCustom));

    auto it = std::find_if(customers_St.begin(), customers_St.end(), [](Customer& obj) {
        return obj.getBudget() == 500.0;
    });

    if (it != customers_St.end()) {
        std::cout << "����������� � �������� 500 ���. ��������." << std::endl;
    }
    else {
        std::cout << "����������� � �������� 500 ���. �� ��������." << std::endl;
    }

    //����� ²�������� ����ֲ�
    stack<Customer> customs;
    customs.push(customers.top());
    customers.pop();
    customs.push(customers.top());
    customers.pop();
    customs.top().login();
    admin.login();

    pers->login();
    pers = &admin;
    pers->login();

    
	//�������
	Room<bool>* rb = new Room<bool>(12, "����", 1, 1300.00, false);
	Room<string>* rs = new Room<string>(15, "��������", 1, 600.00, "ͳ");
	Room<int>* ri = new Room<int>(15, "����", 2, 2000.00, 0);

	rb->displayInfo();
	rs->displayInfo();
	ri->displayInfo();

	//�������������� �������в�
	customers.top()--;
	customers.top()++;
	customers.top().displayInfo();
    --customers.top();
    customers.top().displayInfo();

	//��������
	Functor<int> funct1;
	Functor<double> funct2;

	cout << funct1.add(2, 4) << endl;
	cout << funct2.substr(9.257, 3.731) << endl;

    vector<Room<bool>> rooms;
    vector<Booking> bookings;
    Room<bool> r2(101, "��������", 1, 500.0, false);
    rooms_Static.push_back(r2);

    bool isRunning = true;

    while (isRunning) {
        cout << "\n������� ���������� ������" << endl;
        cout << "1. �������� ������� ������" << endl;
        cout << "2. ����������� �����" << endl;
        cout << "3. ����������� ������ ����������" << endl;
        cout << "4. �������� ����������" << endl;
        cout << "5. ��������� ������" << endl;
        cout << "6. ���� ������������" << endl;

        int choice;
        cout << "������ �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            cout << "������� ������: " << endl;
            for (Room<bool>& r : rooms) {
                r.displayInfo();
            }
            break;
        }
        case 2:
        {
            cout << "���������� ����������: " << endl;
            string customerName, customerSurname, contact, username, pass;
            int roomNumber, time, count;
            cout << "������ ���� ��'�: ";
            cin >> customerName;
            cout << "������ ���� �������: ";
            cin >> customerSurname;
            cout << "������ ���� �������� ���: ";
            cin >> contact;
            cout << "������ ���� ��'� �����������: ";
            cin >> username;
            cout << "������ �����, ���� �� ������ �����������: ";
            cin >> roomNumber;
            cout << "������ ��� ����������� (���): ";
            cin >> time;
            cout << "������ ������� ��� � �����: ";
            cin >> count;

            Customer customer(customerName, customerSurname, contact, username, pass, 500.0);
            customers.push(customer);
            for (Room<bool>& r : rooms) {
                if (roomNumber == r.getNumber()) {
                    Booking b(r, customer, time, count);
                    bookings.push_back(b);
                }
            }
            cout << "���������� ������!" << endl;
            break;
        }
        case 3:
        {
            cout << "�������� ����������: " << endl;
            int id;
            cout << "������ ID ����������: ";
            cin >> id;
            for (Booking& b : bookings) {
                if (id == b.getBookingId()) {

                }
            }
            break;
        }
        case 4:
        {
            cout << "������ ����������: " << endl;
            int id;
            cout << "������ ID ����������: ";
            cin >> id;
            for (Booking& b : bookings) {
                if (id == b.getBookingId() && b.getApprovingState() == true) {
                    b.getCustomer().getBudget();
                }
            }
            break;
        }
        case 5:
        {
            cout << "���������� �������: " << endl;
            string custName;
            string custlName;
            double summ;
            cout << "������ ��'� �볺���: ";
            cin >> custName;
            cout << "������ ������� �볺���: ";
            cin >> custlName;
            cout << "������ ����, �� ��� ������ ��������� ������: ";
            cin >> summ;
            for (Customer& c = customers.top();;) {
                if ((custName == c.getFirstName()) && (custlName == c.getLastName())) {
                    c.replBalance(summ);
                    bookings.back().getCustomer().replBalance(summ);
                    cout << custName << " " << custlName << ", ��� ������ ��������� �� " << summ << " �������" << endl;
                        bookings.back().getCustomer().getBudget();
                }
            }
            if (bookings.size() == 0) {
                cout << "�� �� � ����� �볺����!" << endl;
            }
            break;
        }
        case 6:
        {
            cout << "\n���� ������������" << endl;
            cout << "1. ����������� ����������" << endl;
            cout << "2. ϳ��������� ����������" << endl;
            cout << "3. ³������� ����������" << endl;
            cout << "4. ������ �����" << endl;

            int adminChoice;
            cout << "������ �����: ";
            cin >> adminChoice;

            switch (adminChoice) {
            case 1:
            {
                cout << "�������� ���������: " << endl;
                for (Booking& bs : bookings) {
                    bs.getBookingId();
                }
                choice = 4;
                break;
            }
            case 2:
            {
                cout << "ϳ����������� ����������: " << endl;
                cout << "������ ID ����������: ";
                int id;
                cin >> id;
                for (Booking& bs : bookings) {
                    if (id == bs.getBookingId()) {
                        bs.setApprovingState(true);
                        cout << "���������� � " << bs.getBookingId() << " �����������" << endl;
                    }
                }
                choice = 4;
                break;
            }
            case 3:
            {
                cout << "������ ID ����������: ";
                int id;
                cin >> id;
                for (Booking& bs : bookings) {
                    if (id == bs.getBookingId()) {
                        bs.setApprovingState(false);
                        cout << "���������� � " << bs.getBookingId() << " ��������" << endl;
                    }
                }
                choice = 4;
                break;
            }
            case 4:
            {
                cout << "��������� ������: " << endl;
                int nr, cap;
                double prc;
                string tpr;
                cout << "������ ����� ������: ";
                cin >> nr;
                cout << "������ ���� ���������������� ������: ";
                cin >> tpr;
                cout << "������ ������� ���� � �����: ";
                cin >> cap;
                cout << "������ ������� ����������: ";
                cin >> prc;
                rooms.push_back(Room<bool>(nr, tpr, cap, prc, false));
                cout << "����� ������" << endl;
                choice = 4;
                break;
            }
            default:
                cout << "������� ����." << endl;
                choice = 4;
                break;
            }
        }
        }
    }
    return 0;
}