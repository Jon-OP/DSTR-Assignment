// Attribute & Method Declaration for Transaction goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_TRANSACTION_H
#define G8_TP060491_TP061069_TP055727_TRANSACTION_H

#include <iostream>
#include <string>
#include "CDLinkedList.h"

class Transaction {
    // Transaction Class Variables

    int transactionID;
    std::string movieName;
    float totalPrice;
    int quantity;
    int seats;
    //int seats[];
    // Date and Time, do we include here ? - Jonathan

    void newTransaction();
    void newPurchaseMenu();
    void viewPurchase();
    std::string getDetails();
    int validateInteger(std::string msg);


public:


/* ------------------------------------------------------ CONSTRUCTOR METHODS ------------------------------------------------------ */
    // Default Constructor
    Transaction();

    // Constructor to add new Transaction
    //Transaction(int movieName, float totalPrice);

    // Constructor for Admin
    //Transaction(CDLinkedList cx);

/* -------------------------------------------------------------- END -------------------------------------------------------------- */

/* ------------------------------------------------------- FUNCTIONAL METHODS ------------------------------------------------------ */

    // Display Transaction Menu
    void transactionMenu();

    // Printing High-Level details of the selected transaction
    void printBasicTransactionDetails(int index);



    int getTotalPrice();
    int getTransactionID();

/* -------------------------------------------------------------- END -------------------------------------------------------------- */

};


#endif //G8_TP060491_TP061069_TP055727_TRANSACTION_H
