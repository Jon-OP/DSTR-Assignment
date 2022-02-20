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
    //std::string transactionMenuMsg = "\tTransaction Management Menu\n"
                                   "\t---------------------------\n"
                                   "\t1. Place a new purchase\n"
                                   "\t2. View All Purchases\n"
                                   "\t3. Sort Purchases\n"
                                   "\t4. View Purchase Details\n"
                                   "\t5. Return to Main Menu\n"
                                   "\t6. Exit Program\n"
                                   "\n\t>> Enter your choice:";
    //int userChoice;
    //do{
        //insert validation

    //}
//Code section with reused input validation component

    std::cout << "\tTransaction Management Menu" << std::endl;
    std::cout << "\t---------------------------" << std::endl;
    std::cout << "\t1. Place a new purchase" << std::endl;
    std::cout << "\t2. View All Purchases" << std::endl;
    std::cout << "\t3. Sort Purchases" << std::endl;
    std::cout << "\t4. View Purchase Details" << std::endl;
    std::cout << "\t5. Return to Main Menu" << std::endl;
    std::cout << "\t6. Exit Program" << std::endl;
    std::cout << "\t Enter your choice:   " << std::endl;
    std::cin >> userChoice;

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
            //returns to main menu
            return;
        case 6:
            std::cout << "\n\t>> Goodbye\n\t>> Enter any key to exit:";

            // Wait for user Input and ignore up to 10,00 characters
            std::cin.ignore( 10000, '\n');

            break;
        default:
            // Print error message and prompt user to enter any key to continue
            std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 6\n\t>> Enter any Key to continue:";

            // Wait for user Input and ignore up to 10,00 characters
            std::cin.ignore( 10000, '\n');
            break;
    }

}
void Transaction::newPurchaseMenu()
{

    std::cout << "\tCreating new purchase" << std::endl;
    std::cout << "\t---------------------" << std::endl;
    std::cout << "\t1. View All Product" << std::endl;
    std::cout << "\t2. Search Product by Category" << std::endl;
    std::cout << "\t3. Remove product from cart" << std::endl;
    std::cout << "\t4. Update cart" << std::endl;
    std::cout << "\t5. View Cart" << std::endl;
    std::cout << "\t6. Checkout cart" << std::endl;
    std::cout << "\t7. Cancel Purchase" << std::endl;
    std::cout << "\t Enter your choice [Any irrelevant key to return]:   " << std::endl;
    std::cin >> userChoice;
    switch (userChoice) {
        case 1:
            //placeholder for View All Product
            break;
        case 2:
            // placeholder for Search Product by Category
            break;
        case 3:
            //placeholder for Remove product
            break;
        case 4:
            //placeholder for Update cart
            break;
        case 5:
            //placeholder for view cart
            break;
        case 6:
            //placeholder for checkout cart
            break;
        case 7:
            //placeholder for cancel purchase
            break;
        default:
            // Print error message and prompt user to enter any key to continue
            std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 7\n\t>> Enter any Key to continue:";

            // Wait for user Input and ignore up to 10,00 characters
            std::cin.ignore( 10000, '\n');
            break;
    }

}
void newTransaction()
{
    CDLinkedList cd = CDLinkedList();
    Transaction userTransaction = Transaction(); //include user input details on purchase as parameters
    cd.insertTransaction(userTransaction);
}

void viewPurchases()
{
    CDLinkedList cd = CDLinkedList();
    cd.displayAllTransaction();
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

//getters for displayTransaction method in CDLinkedlist
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





