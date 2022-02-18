// Attribute & Method Declaration for Transaction goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_TRANSACTION_H
#define G8_TP060491_TP061069_TP055727_TRANSACTION_H

#include <string>

class Transaction {
    // Transaction Class Variables
    int transactionID;

    int movieID;
    std::string movieName;
    float totalPrice;
    int quantity;
    //int seats[2]; //Store Seat by Index... DECLARING ARRAY WITHOUT INITIALIZING SIZE REQUIRES VECTOR LIBRARY

    // Date and Time, do we include here ? - Jonathan


public:
    // Constructor Method
    Transaction();
    Transaction(std::string movieName);

    // Functional Methods
    void greetings();

    // Getters and Setters
    int getMovieID();
    void setMovieID();

    std::string getMovieName();
    void setMovieName(std::string movieName);
};


#endif //G8_TP060491_TP061069_TP055727_TRANSACTION_H
