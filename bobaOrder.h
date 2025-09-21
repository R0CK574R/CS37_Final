#ifndef BOBA_ORDER_H
#define BOBA_ORDER_H

#include "deliveryOrder.h"
#include "invalidInput.h"
// BobaOrder class inherits from DeliveryOrder
// Manages drink orders and applies VIP discounts based on number of drinks
class BobaOrder : public DeliveryOrder {
    private:
        string shopName;
        int drinksCount; // Total number of drinks ordered
    public:
        // Constructor: initializes boba order details and shop name
        BobaOrder(const string& name, const string& date, const string& phone, float miles, const string& shopName); 
        ~BobaOrder(); //Destructor
    
    void receipt() const override;// Prints receipt including drink count
    float VIPdiscount() const override; // Returns discount multiplier based on number of drinks
    void addDrink(const string& drinkName, bool addBoba = true, int count = 1); // Adds a drink to the order
    // Throws InvalidInput if drink name is not recognized; Parameters: drink name, optional boba (default: true), and quantity (default: 1)
};

#endif