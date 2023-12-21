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

	//ВЕКТОР СТАТИЧНИХ ОБ'ЄКТІВ
	vector<Room<bool>> rooms_Static;
	for (int i = 1; i < 6; i++) {
		Room<bool> r(i, "Стандарт", i % 2 + 1, 500.0 * (i % 2 + 1), false);
		rooms_Static.push_back(r);
	}

	Room<bool> r1(4, "Люкс", 1, 1000.0, false);

	rooms_Static.pop_back();
	rooms_Static.emplace_back(r1);

	//ДЕК ДИНАМІЧНИХ ОБ'ЄКТІВ
    deque<Room<bool>*> rooms_Dynamic;
	for (int j = 6; j < 11; j++) {
		Room<bool>* r = new Room<bool>(j, "Стандарт", j % 3 + 1, 500.0 * (j % 3 + 1), false);
		if (j % 2 == 0) {
			rooms_Dynamic.push_back(r);
		}
		else {
			rooms_Dynamic.push_front(r);
		}
	}

	rooms_Dynamic.pop_front();

	//СТЕК КОРИСТУВАЧІВ
	stack<Customer> customers;

	customers.emplace(Customer("Василь", "Руденко", "vasyl@gmail.com", "vasyl", "parol", 500.0));
	customers.push(Customer("Іван", "Вовк", "ivan@gmail.com", "ivan", "password", 1000.0));

    std::cout << customers.top()[2] << endl;

    //АДМІН
	Admin admin("Адмін", "Адмін", "support@i.ua", "12345678");

	//ПОЛІМОРФНІ ВИКЛИКИ ФУНКЦІЙ
    //1 спосіб
	Person* pers;
    pers = new Person("Person", "Surname", "Contact");
    pers->displayInfo();
    delete pers;
    pers = new Admin("Адмін", "Адмін", "i@i.ua", "52123647");
    pers->displayInfo();
    delete pers;
    pers = new Customer("Петро", "Петрук", "petr@p.com", "petryk", "password", 500.0);
    pers->displayInfo();
    delete pers;

    //2 спосіб
    Person person2("Персона 1", "Прізвище", "Контакна інформація");
    pers = &person2;
    pers->displayInfo();
	pers = &admin;
	pers->displayInfo();
	pers = &customers.top();
	pers->displayInfo();

    //3 спосіб
    Admin administrator("Адмін2", "Адмін2", "контакт", "код доступу");
    Customer customer1("Користувач1", "Прізвище", "контакт", "username", "password", 0.0);
    Person person("Персона", "Прізвище", "контакт");
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
        std::cout << "Користувача з бюджетом 500 грн. знайдено." << std::endl;
    }
    else {
        std::cout << "Користувача з бюджетом 500 грн. не знайдено." << std::endl;
    }

    //ЧИСТО ВІРТУАЛЬНА ФУНКЦІЯ
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

    
	//ШАБЛОНИ
	Room<bool>* rb = new Room<bool>(12, "Люкс", 1, 1300.00, false);
	Room<string>* rs = new Room<string>(15, "Стандарт", 1, 600.00, "Ні");
	Room<int>* ri = new Room<int>(15, "Люкс", 2, 2000.00, 0);

	rb->displayInfo();
	rs->displayInfo();
	ri->displayInfo();

	//ПЕРЕВАНТАЖЕННЯ ОПЕРАТОРІВ
	customers.top()--;
	customers.top()++;
	customers.top().displayInfo();
    --customers.top();
    customers.top().displayInfo();

	//Функтори
	Functor<int> funct1;
	Functor<double> funct2;

	cout << funct1.add(2, 4) << endl;
	cout << funct2.substr(9.257, 3.731) << endl;

    vector<Room<bool>> rooms;
    vector<Booking> bookings;
    Room<bool> r2(101, "Стандарт", 1, 500.0, false);
    rooms_Static.push_back(r2);

    bool isRunning = true;

    while (isRunning) {
        cout << "\nСистема замовлення готелю" << endl;
        cout << "1. Показати доступні номери" << endl;
        cout << "2. Забронювати номер" << endl;
        cout << "3. Переглянути статус замовлення" << endl;
        cout << "4. Оплатити замовлення" << endl;
        cout << "5. Поповнити баланс" << endl;
        cout << "6. Меню Адміністратора" << endl;

        int choice;
        cout << "Оберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            cout << "Доступні номери: " << endl;
            for (Room<bool>& r : rooms) {
                r.displayInfo();
            }
            break;
        }
        case 2:
        {
            cout << "Оформлення бронювання: " << endl;
            string customerName, customerSurname, contact, username, pass;
            int roomNumber, time, count;
            cout << "Введіть Ваше ім'я: ";
            cin >> customerName;
            cout << "Введіть Ваше прізвище: ";
            cin >> customerSurname;
            cout << "Введіть Ваші контактні дані: ";
            cin >> contact;
            cout << "Введіть Ваше ім'я користувача: ";
            cin >> username;
            cout << "Введіть номер, який Ви бажаєте забронювати: ";
            cin >> roomNumber;
            cout << "Введіть час перебування (днів): ";
            cin >> time;
            cout << "Введіть кількість осіб у номері: ";
            cin >> count;

            Customer customer(customerName, customerSurname, contact, username, pass, 500.0);
            customers.push(customer);
            for (Room<bool>& r : rooms) {
                if (roomNumber == r.getNumber()) {
                    Booking b(r, customer, time, count);
                    bookings.push_back(b);
                }
            }
            cout << "Бронювання успішне!" << endl;
            break;
        }
        case 3:
        {
            cout << "Перегляд бронювання: " << endl;
            int id;
            cout << "Введіть ID замовлення: ";
            cin >> id;
            for (Booking& b : bookings) {
                if (id == b.getBookingId()) {

                }
            }
            break;
        }
        case 4:
        {
            cout << "Оплата бронювання: " << endl;
            int id;
            cout << "Введіть ID замовлення: ";
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
            cout << "Поповнення балансу: " << endl;
            string custName;
            string custlName;
            double summ;
            cout << "Введіть ім'я клієнта: ";
            cin >> custName;
            cout << "Введіть прізвище клієнта: ";
            cin >> custlName;
            cout << "Введіть суму, на яку бажаєте поповнити баланс: ";
            cin >> summ;
            for (Customer& c = customers.top();;) {
                if ((custName == c.getFirstName()) && (custlName == c.getLastName())) {
                    c.replBalance(summ);
                    bookings.back().getCustomer().replBalance(summ);
                    cout << custName << " " << custlName << ", Ваш баланс поповнено на " << summ << " гривень" << endl;
                        bookings.back().getCustomer().getBudget();
                }
            }
            if (bookings.size() == 0) {
                cout << "Ви не є нашим клієнтом!" << endl;
            }
            break;
        }
        case 6:
        {
            cout << "\nМеню Адміністратора" << endl;
            cout << "1. Переглянути бронювання" << endl;
            cout << "2. Підтвердити бронювання" << endl;
            cout << "3. Відхилити бронювання" << endl;
            cout << "4. Додати номер" << endl;

            int adminChoice;
            cout << "Оберіть опцію: ";
            cin >> adminChoice;

            switch (adminChoice) {
            case 1:
            {
                cout << "Перегляд бронювань: " << endl;
                for (Booking& bs : bookings) {
                    bs.getBookingId();
                }
                choice = 4;
                break;
            }
            case 2:
            {
                cout << "Підтвердження бронювання: " << endl;
                cout << "Введіть ID бронювання: ";
                int id;
                cin >> id;
                for (Booking& bs : bookings) {
                    if (id == bs.getBookingId()) {
                        bs.setApprovingState(true);
                        cout << "Бронювання № " << bs.getBookingId() << " підтверджено" << endl;
                    }
                }
                choice = 4;
                break;
            }
            case 3:
            {
                cout << "Введіть ID бронювання: ";
                int id;
                cin >> id;
                for (Booking& bs : bookings) {
                    if (id == bs.getBookingId()) {
                        bs.setApprovingState(false);
                        cout << "Бронювання № " << bs.getBookingId() << " відхилено" << endl;
                    }
                }
                choice = 4;
                break;
            }
            case 4:
            {
                cout << "Додавання номера: " << endl;
                int nr, cap;
                double prc;
                string tpr;
                cout << "Введіть номер кімнати: ";
                cin >> nr;
                cout << "Введіть клас комфортабельності номера: ";
                cin >> tpr;
                cout << "Введіть кількість місць у номері: ";
                cin >> cap;
                cout << "Введіть вартість проживання: ";
                cin >> prc;
                rooms.push_back(Room<bool>(nr, tpr, cap, prc, false));
                cout << "Номер додано" << endl;
                choice = 4;
                break;
            }
            default:
                cout << "Невірний вибір." << endl;
                choice = 4;
                break;
            }
        }
        }
    }
    return 0;
}