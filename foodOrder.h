#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

#include "deliveryOrder.h"
#include "invalidInput.h" //include delivery and invalidinput header files

// FoodOrder class derived from DeliveryOrder
class FoodOrder : public DeliveryOrder {
    private:
        string restaurantName;
        int foodCount; // Number of food items added
    public:
         // Constructor: initializes delivery details and restaurant name
        FoodOrder(const string& name, const string& date, const string& phone, float miles, const string& restaurantName);
        ~FoodOrder(); // Destructor: prints message on destruction

    void receipt() const override;  // Prints the receipt (overrides base class)
    float VIPdiscount() const override; // Calculates VIP discount based on order balance
    // Adds food item to the order, with optional sides and soup
    void addFood(const string& foodName, int sides = 0, bool soup = false);
    // Throws InvalidInput if foodName is not recognized
};

#endif