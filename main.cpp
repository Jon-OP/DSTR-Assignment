#include <iostream>
#include "Inventory.h"      // Allow the calling of Inventory Attributes & Methods
#include "Transaction.h"    // Allow the calling of Transaction Attributes & Methods

int validateInt() {
    // Read userInput
    std::string userInput;
    std::getline(std::cin, userInput);

    // Iterate and set hasChar to true if there is char in msg
    if(userInput.length() != 0){
        bool hasChar = false;
        for(int i = 0; i < userInput.length(); i++){
            if( !(std::isdigit(userInput[i]))){
                hasChar = true;
            }
        }
        // hasChar = true, return -99 to signify error
        if(hasChar){
            return -999;
        }else{
            // hasChar = false, convert msg to int and return
            return std::stoi(userInput);
        }
    }else{
        return -999;
    }
}

int main() {
    //main program starts here, for testing, call functions directly before this

    MovieList adminMovie;
    TransactionList adminTransaction;
    adminMovie.initializeList();

    bool flag = true;
    while (flag == true){
        std::cout << "\n\t---------------------------------------------------------\n"
                     "\t              Grandplex Movie Ticketing System           \n"
                     "\t-*-------------------------------------*-----------------\n"
                     "\t-|1. Inventory Management System       |-----------------\n"
                     "\t-|2. Transaction Management System     |-----------------\n"
                     "\t-|3. Exit Program                      |-----------------\n"
                     "\t-*-------------------------------------*-----------------\n"
                     "\n\t>> Enter your choice:";
        int userChoice = validateInt();

        switch (userChoice) {
            case 1:
                adminMovie.movieMenu();
                break;
            case 2:
                //accept inventory as parameter
                adminTransaction.transactionMenu(&adminMovie);
                std::cout << "You entered 2\n";
                break;
            case 3:
                std::cout << "\n\t>> Goodbye\n\t>> Enter any key to exit:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                flag = false;
                break;
            case -999:
                std::cout << "\n\t>> ERROR: Please enter an index."
                             "\n\t>> Enter any key to continue:";

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
    }
}
