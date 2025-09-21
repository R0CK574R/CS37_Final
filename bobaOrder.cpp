#include "bobaOrder.h"
// Constructor: Initializes shop name, sets drinksCount to 0, and calls DeliveryOrder constructor
BobaOrder::BobaOrder(const string& name, const string& date, const string& phone, float miles, const string& shopName)
    : DeliveryOrder(name, date, phone, miles), shopName(shopName), drinksCount(0) {}
// Destructor: Outputs destruction message
BobaOrder::~BobaOrder() {
    cout << "BobaOrder destroyed.\n";
}

// Prints receipt with base class receipt info plus drinks count
void BobaOrder::receipt() const {
    DeliveryOrder::receipt();
    cout << "\tDrinks Count: " << drinksCount << endl;
}

// Calculates discount multiplier based on number of drinks
float BobaOrder::VIPdiscount() const {
    if (drinksCount > 10) return 0.8;
    if (drinksCount > 5) return 0.9;
    if (drinksCount > 2) return 0.95;
    return 1.0;
}

// Adds drink to the order; updates balance and count; throws exception if drink is invalid
void BobaOrder::addDrink(const string& drinkName, bool addBoba, int count) {
    float price = 0;
     // Determine base price of the drink
    if (drinkName == "Green Tea Latte") price = 5.8;
    else if (drinkName == "Brown Sugar Boba Milk") price = 7.8;
    else if (drinkName == "Brown Sugar Pearl Milk") price = 9.8;
    else throw InvalidInput(drinkName); // Invalid drink name throws exception
    // Add cost of boba topping if selected
    if (addBoba) price += 1.0;
    
    // Update order total and drink count
    orderBalance += price * count;
    drinksCount += count;
}