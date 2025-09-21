#ifndef INVALID_INPUT_H
#define INVALID_INPUT_H

#include <string>
#include <iostream>
using namespace std;
// Custom exception class for handling invalid inputs
class InvalidInput : public exception {
    private:
        const string message; // Error message to describe the invalid input
    public:
        // Constructor: builds a custom message using the invalid input string
        InvalidInput(const string& input) : message("Invalid input \"" + input + "\".\n") {}
        // Displays the reason for the exception
        void reason() const {
        cout << message;
        }
};

#endif