#include "account.h" //include account header file

// Constructor: Initializes username and status using initializer list
Account::Account(const string& username, const string& status) 
    : username(username), status(status) {}

// Destructor: Prints message when an Account object is destroyed
Account::~Account() { 
    cout << "Account removed.\n";
}

// Accessor: Returns the status of the account ("Owner", "VIP", "Regular")
string Account::getStatus() const {
    return status;
}