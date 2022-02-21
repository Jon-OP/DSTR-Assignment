#include <iostream>
#include "Inventory.h"      // Allow the calling of Inventory Attributes & Methods
#include "Transaction.h"    // Allow the calling of Transaction Attributes & Methods

int validateInteger(std::string message){
    bool inputFlag;
    std::string userInput;
    int sanitizedInput;
    while(true){
        // Display message <- I want to change. IDW USE STD::COUT
        std::cout << std::string(3, '\n') << message;

        // Get User Input as String
        std::getline(std::cin, userInput);

        // User entered newLine which is consumed by getLine(). Hence, length = 0
        if( ! (userInput.length() == 0)){
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
        std::cout << "\n\t>> Invalid Input\n\t>> Please Enter only numbers\n\t>> Enter any key to continue:";

        // Wait for user Input and ignore up to 10,00 characters
        std::cin.ignore( 10000, '\n');

    }
}

// Main Implementation - Jonathan
void mainMenu(){

    Movie adminInventory;
    TransactionList adminTransaction = TransactionList();

    std::string mainMenuMsg = "\t---------------------------------------------------------\n"
                              "\t              Grandplex Movie Ticketing System           \n"
                              "\t-*-------------------------------------*-----------------\n"
                              "\t-|1. Inventory Management System       |-----------------\n"
                              "\t-|2. Transaction Management System     |-----------------\n"
                              "\t-|3. Exit Program                      |-----------------\n"
                              "\t-*-------------------------------------*-----------------\n"
                              "\n\t>> Enter your choice:";

    int userChoice;
    do{
        userChoice = validateInteger(mainMenuMsg);

        switch (userChoice) {
            case 1:
                adminInventory.inventoryConsoleMenu();
                break;
            case 2:
                //accept inventory as parameter
                adminTransaction.transactionMenu();
                std::cout << "You entered 2\n";
                break;
            case 3:
                std::cout << "\n\t>> Goodbye\n\t>> Enter any key to exit:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');

                break;
            default:
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 3\n\t>> Enter any Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
        }
    }while(userChoice != 3);
}




int main() {
    // Initialize Movie Array
    Movie* movieArray = new Movie[0];

    // Declaration of Inventory Object
    Movie testInventory;

    // Declaration of Transaction Object
    // Transaction testTransaction;
    // testTransaction.transactionMenu();
    TransactionList adminTransaction;

    //TEST SITE BELOW ONWARDS
    Transaction testTransaction1 = Transaction(2,12.5);
    Transaction testTransaction2 = Transaction(5, 13.2);
    Transaction testTransaction3 = Transaction(3, 10.0);
    Transaction testTransaction4 = Transaction(4, 11);
    Transaction testTransaction5 = Transaction(2, 17);
    Transaction testTransaction6 = Transaction(7, 21.2);
    Transaction testTransaction7 = Transaction(2, 82.1);
    Transaction testTransaction8 = Transaction(3, 9.2);

    adminTransaction.insertTransactionToList(&testTransaction1);
    adminTransaction.insertTransactionToList(&testTransaction2);
    adminTransaction.insertTransactionToList(&testTransaction3);
    adminTransaction.insertTransactionToList(&testTransaction4);
    adminTransaction.insertTransactionToList(&testTransaction5);
    adminTransaction.insertTransactionToList(&testTransaction6);
    adminTransaction.insertTransactionToList(&testTransaction7);
    adminTransaction.insertTransactionToList(&testTransaction8);

    adminTransaction.transactionMenu();

    //adminTransaction.sortTransaction("TOTALPRICE");

    return 0;
}
