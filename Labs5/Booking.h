#pragma once
#include <iostream>
#include <string>
#include "Room.h"
#include "Customer.h"

class Booking
{
protected:
	int bookingId;
	Room<bool>* bookedRoom;
	Customer* booker;
	int personsCount;
	int duration;
	bool approvingState;
	bool waiting;
	bool paymentState;

public:
	static int idCounter;
	Booking();
	Booking(const Booking& book);
	Booking(Room<bool>& room, Customer& cust, int count, int time);

	~Booking();
	
	void setBookingId(int id);
	void setBookedRoom(Room<bool>& room);
	void setBooker(Customer& cust);
	void setPersonCount(int count);
	void setDuration(int time);
	void setApprovingState(bool state);
	void setWaiting(bool state);
	void setPaymentState(bool state);

	int getBookingId();
	Room<bool>& getRoom();
	Customer& getCustomer();
	int getPersonCount();
	int getDuration();
	bool getApprovingState();
	bool getWaiting();
	bool getPaymentState();

	double countCost();
};

