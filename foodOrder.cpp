#include "foodOrder.h"
// Constructor: initializes FoodOrder with personal info and restaurant name
// Calls base class DeliveryOrder constructor
FoodOrder::FoodOrder(const string& name, const string& date, const string& phone, float miles, const string& restaurantName)
    : DeliveryOrder(name, date, phone, miles), restaurantName(restaurantName), foodCount(0) {}
// Destructor: prints message on destruction
FoodOrder::~FoodOrder() {
    cout << "FoodOrder destroyed.\n";
}
// receipt: calls base class receipt and adds food count
void FoodOrder::receipt() const {
    DeliveryOrder::receipt();
    cout << "\tFood Count: " << foodCount << endl;
}
// VIPdiscount: returns a discount multiplier based on total order balance
float FoodOrder::VIPdiscount() const {
    if (orderBalance > 50) return 0.8;
    if (orderBalance > 30) return 0.9;
    if (orderBalance > 20) return 0.95;
    return 1.0;
}
// addFood: adds specified food item with optional sides and soup
// Throws InvalidInput exception if food name is not recognized
void FoodOrder::addFood(const string& foodName, int sides, bool soup) {
    float price = 0;
    // Determine base price
    if (foodName == "Thick Cauliflower Steaks") price = 15;
    else if (foodName == "Rack of Lamb") price = 38;
    else if (foodName == "Organic Scottish Salmon") price = 23;
    else if (foodName == "Grilled Lobster Risotto") price = 46;
    else throw InvalidInput(foodName);
    // Add side and soup costs
    price += sides * 6;
    if (soup) price += 5;
    // Update total balance and item count
    orderBalance += price;
    foodCount++;
}