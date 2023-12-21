#include "Booking.h"

Booking::Booking(){}

Booking::Booking(const Booking& book)
{
    //idCounter = book.idCounter;
    bookingId = book.bookingId;
    bookedRoom = book.bookedRoom;
    booker = book.booker;
    personsCount = book.personsCount;
    duration = book.duration;
    approvingState = book.approvingState;
    waiting = book.waiting;
    paymentState = book.paymentState;
}

Booking::Booking(Room<bool>& room, Customer& cust, int count, int time)
    :bookedRoom(&room), booker(&cust), personsCount(count), duration(time), waiting(true), paymentState(false)
{
    bookingId = idCounter++;
}

Booking::~Booking()
{
    cout << "Заявку з ідентифікатором " << bookingId << " видалено." << endl;
}

void Booking::setBookingId(int id)
{
    bookingId = id;
}

void Booking::setBookedRoom(Room<bool>& room)
{
    bookedRoom = &room;
}

void Booking::setBooker(Customer& cust)
{
    booker = &cust;
}

void Booking::setPersonCount(int count)
{
    personsCount = count;
}

void Booking::setDuration(int time)
{
    duration = time;
}

void Booking::setApprovingState(bool state)
{
    approvingState = state;
}

void Booking::setWaiting(bool state)
{
    waiting = state;
}

void Booking::setPaymentState(bool state)
{
    paymentState = state;
}

int Booking::getBookingId()
{
    return bookingId;
}

Room<bool>& Booking::getRoom()
{
    try {
        return *bookedRoom;
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
}

Customer& Booking::getCustomer()
{
    try {
        return *booker;
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
}

int Booking::getPersonCount()
{
    return personsCount;
}

int Booking::getDuration()
{
    return duration;
}

bool Booking::getApprovingState()
{
    return approvingState;
}

bool Booking::getWaiting()
{
    return waiting;
}

bool Booking::getPaymentState()
{
    return paymentState;
}

double Booking::countCost() {
    return ((bookedRoom->getCost()) * personsCount);
}