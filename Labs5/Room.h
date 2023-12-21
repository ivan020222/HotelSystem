#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Room
{
protected:
	int roomNumber;
	string type;
	int capacity;
	double cost;
	T isBooked;

public:
    Room() {}

    Room(const Room& room)
    {
        roomNumber = room.roomNumber;
        type = room.type;
        capacity = room.capacity;
        cost = room.cost;
        isBooked = room.isBooked;
    }

    Room(int num, string tpe, int cpc, double cst, T isB)
        :roomNumber(num), type(tpe), capacity(cpc), cost(cst), isBooked(isB) {}

    ~Room()
    {
        cout << "Кімнату номер " << roomNumber << " видалено." << endl;
    }

    void setNumber(int num)
    {
        roomNumber = num;
    }

    void setType(string tpe)
    {
        type = tpe;
    }

    void setCapacity(int cpc)
    {
        capacity = cpc;
    }

    void setCost(double cst)
    {
        cost = cst;
    }

    void setIsBooked(bool isB)
    {
        isBooked = isB;
    }

    int getNumber()
    {
        return roomNumber;
    }

    string getType()
    {
        return type;
    }

    int getCapacity()
    {
        return capacity;
    }

    double getCost()
    {
        return cost;
    }

    bool getIsBooked()
    {
        return isBooked;
    }

    void displayInfo()
    {
        cout << "Кімната номер " << roomNumber << endl;
        cout << "Тип номера: " << type << endl;
        cout << "Кількість місць: " << capacity << endl;
        cout << "Вартість: " << cost << " грн." << endl;
    }
};

