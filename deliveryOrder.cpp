#include "deliveryOrder.h"
#include <iomanip> // for fixed and setprecision
// Initialize static variable
int DeliveryOrder::orderCount = 0;

// Constructor: Initializes member variables and increments order count
DeliveryOrder::DeliveryOrder(const string& name, const string& date, const string& phone, float miles)
    : name(name), date(date), phone(phone), miles(miles), orderBalance(0) {
    ++orderCount;
}

// Destructor: Outputs message when DeliveryOrder is destroyed
DeliveryOrder::~DeliveryOrder() {
    cout << "DeliveryOrder destroyed.\n";
}

// Prints order receipt details
void DeliveryOrder::receipt() const {
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << fixed << setprecision(2) << orderBalance << endl;
}

// Calculates and returns the total balance including tax and delivery fees
float DeliveryOrder::getTotalBalance() const {
    return orderBalance * (1 + taxRate) + miles * deliveryRate;
}

// Returns the total number of orders placed
int DeliveryOrder::getOrderCount() {
    return orderCount;
}