#include "deliveryOrder.h"
#include "bobaOrder.h"
#include "foodOrder.h"
#include "account.h"
#include "invalidInput.h" //include all the header files

#include <iomanip> // for set precision
// Applies discount based on account status
float applyDiscount(DeliveryOrder* order, const Account& account) {
    if (account.getStatus() == "Owner")
        return order->getTotalBalance() * 0.1f; //90% discount
    else if (account.getStatus() == "VIP")
        return order->getTotalBalance() * order->VIPdiscount(); // Custom VIP discount
    else
        return order->getTotalBalance(); //NO Discount
}


int main() { //main
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    // Create account instances with different statuses
    const Account stuart("Stuart", "Owner"); // Owner account
    Account kevin("Kevin", "VIP"); // VIP account
    Account bob("Bob"); // Regular account (default status)

    DeliveryOrder* order = nullptr; // Pointer used to handle different types of orders

    // Kevin's order
    cout << "Kevin is placing order.\n";
    BobaOrder kevinOrder("Kevin", "04/20/2024", "123-456-0000", 10.4, "M Tea");

    try {
        kevinOrder.addDrink("Green Tea Latte"); //VALID 
        kevinOrder.addDrink("Brown Sugar Pearl Milk", false); //VALID
        kevinOrder.addDrink("Brown Sugar Boba Milk", false, 2); //VALID
        kevinOrder.addDrink("Iron Goddess"); //INVALID (Should Throw)
    } catch (const InvalidInput& e) {
        e.reason(); // print the exception's reason
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }

    kevinOrder.receipt(); //print the receipt
    cout << "Balance: $" << kevinOrder.getTotalBalance() << endl;
    order = &kevinOrder;
    cout << "Discounted Balance: $" << applyDiscount(order, kevin) << "\n\n";

    // Stuart's order
    cout << "Stuart is placing order.\n";
    FoodOrder stuartOrder("Stuart", "04/20/2024", "123-456-1111", 25.5, "Tavern Green");

    try {
        stuartOrder.addFood("Thick Cauliflower Steaks", 1, true); //VALID
        stuartOrder.addFood("Organic Scottish Salmon"); //VALID
        stuartOrder.addFood("Rack of Lamb", 0, true); //INVALID (Should Throw)
    } catch (const InvalidInput& e) {
        e.reason(); // Print the exception's reason
        cout << "Not serving requested food. Food order ignored.\n\n";
    }

    stuartOrder.receipt(); // Print the receipt
    cout << "Balance: $" << stuartOrder.getTotalBalance() << endl;
    order = &stuartOrder;
    cout << "Discounted Balance: $" << applyDiscount(order, stuart) << "\n\n";

    // Bob tries to copy the order
    cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";
    stuartOrder.receipt(); //Print receipt again
    cout << "Balance: $" << stuartOrder.getTotalBalance() << endl;
    cout << "Discounted Balance: $" << applyDiscount(&stuartOrder, bob) << endl;
    cout << "Bob upset, cancelling order :(\n\n"; //upset bob (NOT BUYING)
    // Total number of delivery orders placed
    cout << "Total order placed: " << DeliveryOrder::getOrderCount() << "\n\n";

    return 0;
}