// Implementation for Transaction Goes Here - Jonathan
// To enter the implementation, remember to add "Transaction::<methodName>"

#include "Transaction.h"
#include <iostream>
#include "CDLinkedList.h"

int userChoice;

// Constructor Methods
Transaction::Transaction() {};

Transaction::Transaction(int movieName, float x) {
    this->transactionID = movieName;
    this->totalPrice = x;
    //this -> seats = y;
}

Transaction::Transaction(int transID, int movID, std::string movName) {
    this->transactionID = transID;
    this->movieName = movName;
    this->totalPrice = x;
    //this -> seats = y;
}


// Getter and Setter Methods (most likely obsolete)
//std::string Transaction::getMovieName(){
//    return movieName;
//}
//
//int Transaction::getTransactionID() {
//    return transactionID;
//}
//
//float Transaction::getTotalPrice(){
//    return totalPrice;
//}
//void Transaction::setTotalPrice(float totalPrice){
//    this->totalPrice = totalPrice;
//};


// Transaction menu landing page implementation - Philip
void Transaction::transactionMenu(){

    //stdlib::system ("CLS"); was testing with clearing screen

//Code section with reused input validation component
    std::string transactionMenuMsg = "\tTransaction Management Menu\n"
                                   "\t---------------------------\n"
                                   "\t1. Place a new purchase\n"
                                   "\t2. View All Purchases\n"
                                   "\t3. Sort Purchases\n"
                                   "\t4. View Purchase Details\n"
                                   "\t5. Return to Main Menu\n"
                                   "\n\t>> Enter your choice:";
    int userChoice;
    while (true){
        userChoice = validateInteger(transactionMenuMsg);
        switch (userChoice) {
            case 1:
                newPurchaseMenu(); //call function for creation of new purchase
                break;
            case 2:
                viewPurchase();
                break;
            case 3:
                //placeholder for sort purchase
                break;
            case 4:
                //placeholder for view purchase details
                break;
            case 5:
                return;
            default:
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 5\n\t>> Enter any Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore(10000, '\n');
                break;
        }
    }
}

void viewPurchases()
{
    CDLinkedList cd = CDLinkedList();
    cd.displayAllTransaction();
}

void Transaction::newPurchaseMenu()
{
    std::string newPurchaseMenuMsg = "\tCreating new purchase\n"
                                     "\t---------------------\n"
                                     "\t1. View All Product\n"
                                     "\t2. Search Product by Category\n"
                                     "\t3. Checkout cart\n"
                                     "\t4. Return to previous menu\n"
                                     "\n\t>> Enter your choice:";

    int userChoice;
    while (true){
        userChoice = validateInteger(newPurchaseMenuMsg);
        switch (userChoice) {
            case 1:
                //placeholder for View All Product
                break;
            case 2:
                // placeholder for Search Product by Category
                break;
            case 3:
                //placeholder for Checkout cart
                break;
            case 4:
                return;
            default:
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 7\n\t>> Enter any Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
        }
    }

}
void newTransaction()
{
    CDLinkedList cd = CDLinkedList();
    Transaction userTransaction = Transaction(); //include user input details on purchase as parameters
    cd.insertTransaction(userTransaction);
}



// Error Validation Method
int Transaction::validateInteger(std::string message){
    bool inputFlag;
    std::string userInput;
    int sanitizedInput;
    while(true){
        // Display message <- I want to change. IDW USE STD::COUT
        std::cout << std::string(3, '\n') << message;

        // Get User Input as String
        std::getline(std::cin, userInput);

        // User entered newLine which is consumed by getLine(). Hence, length = 0
        if(!(userInput.length() == 0)){
            // Flag to check if non-digit exists
            bool isDigit = true;

            for(int i = 0; i < userInput.length(); i++){
                if( !(isdigit(userInput[i])) ){
                    isDigit = false;
                }
            }

            // True = all char in string is digit.
            if(isDigit){
                return std::stoi(userInput);
            }
        }

        // Print error message and prompt user to enter any key to continue
        std::cout << "\n\t>> ERROR: Invalid Input\n\t>> Please enter numbers.\n\t>> Enter a Key to continue:";

        // Wait for user Input and ignore up to 10,00 characters
        std::cin.ignore( 10000, '\n');
    }
}



//getter to display all transactions
std::string Transaction::getDetails()
{
    std::string transID = std::to_string(this->transactionID);
    std::string totalPrice = std::to_string(this->totalPrice);
    std::string quantity = std::to_string(this->quantity);
    std::string seats = std::to_string(this->seats);

    return transID +"\t"+movieName+ "\t"+ quantity + "\t"+ totalPrice + "\t"+ seats;
}


//functions to add
    //function to check last transaction ID -> so we can add it into the userTransaction object
    //





