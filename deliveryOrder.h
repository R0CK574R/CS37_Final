#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include <string>
#include <iostream>
using namespace std;
//Abstract base class for all delivery orders.
//Handles common order information such as name, date, phone, and mileage.
class DeliveryOrder {
    private:
        string name; // Customer name
        string date; // Order date
        string phone;  // Customer phone number
        float miles; // Delivery distance in miles

    protected:
        float orderBalance; // Cost of items before tax and delivery

    public:
        static int orderCount; // Total number of orders
        static constexpr float taxRate = 0.09; // Sales tax rate (9%)
        static constexpr float deliveryRate = 2.0; // Delivery cost per mile

        // Constructor: Initializes order details and increments order count
        DeliveryOrder(const string& name, const string& date, const string& phone, float miles);
        virtual ~DeliveryOrder();   // Virtual destructor

        virtual void receipt() const;  // Displays receipt with basic order details
        float getTotalBalance() const; // Returns total order cost including tax and delivery
        static int getOrderCount();  // Returns total number of orders placed
        virtual float VIPdiscount() const = 0; // pure virtual
};

#endif