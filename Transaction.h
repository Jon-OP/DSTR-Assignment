// Attribute & Method Declaration for Transaction goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_TRANSACTION_H
#define G8_TP060491_TP061069_TP055727_TRANSACTION_H

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

    // Constructor Method
    Transaction();
    Transaction(CDLinkList list); // THIS IS THE ADMIN TRANSACTION
    Transaction(int movieName, float totalPrice);


    // Functional Methods
    [[noreturn]] void transactionMenu();



//    // Getters and Setters (Possibly obsolete)
//        // movieID
//    int getMovieID();
//    void setMovieID();
//        // movieName
//    std::string getMovieName();
//    void setMovieName(std::string movieName);
//        // transactionID
//    int getTransactionID();
//    void setTransactionID(int ID);
//        //totalPrice
//    float getTotalPrice();
//    void setTotalPrice(float totalPrice);
};


#endif //G8_TP060491_TP061069_TP055727_TRANSACTION_H
