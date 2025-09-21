#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
using namespace std;

// Account class represents a user with a username, account status
class Account {
    private:
        string username;
        string status; // Account status: "Owner", "VIP", or "Regular"
    public:
        Account(const string& username, const string& status = "Regular"); // Constructor: Initializes username and status (defaults to "Regular")
        ~Account(); // Destructor: Cleans up Account object

        string getStatus() const; // Accessor: Returns the status of the account
};

#endif