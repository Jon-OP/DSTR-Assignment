// Implementation for Transaction Goes Here - Jonathan
// To enter the implementation, remember to add "Transaction::<methodName>"

#include "Transaction.h"
#include <iostream>


// Constructor Methods
Transaction::Transaction() {};

Transaction::Transaction(int movieName, float x) {
    this->transactionID = movieName;
    this->totalPrice = x;
}


// Functional Methods
void Transaction::greetings(){
    std::cout << "This is a Test from Transaction." << std::endl;
}






// Getter and Setter Methods
std::string Transaction::getMovieName(){
    return movieName;
}

int Transaction::getTransactionID() {
    return transactionID;
}

float Transaction::getTotalPrice(){
    return totalPrice;
}
void Transaction::setTotalPrice(float totalPrice){
    this->totalPrice = totalPrice;
};