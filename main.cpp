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

//banner displayed upon program shutdown
void banner()
{
    std::cout <<"\n\n\n\n\n\n\t  ________                         ._____________.__                 \n\t"
           " /  _____/___________    ____    __| _/\\______   \\  |   ____ ___  ___\n\t"
           "/   \\  __\\_  __ \\__  \\  /    \\  / __ |  |     ___/  | _/ __ \\\\  \\/  /\n\t"
           "\\    \\_\\  \\  | \\// __ \\|   |  \\/ /_/ |  |    |   |  |_\\  ___/ >    < \n\t"
           " \\______  /__|  (____  /___|  /\\____ |  |____|   |____/\\___  >__/\\_ \\\n\t"
           "        \\/           \\/     \\/      \\/                     \\/      \\/\n\n\n\n";
}

int main() {
    //main program starts here, for testing, call functions directly before this

    MovieList adminMovie;
    adminMovie.initializeList();

    TransactionList adminTransaction;
    adminTransaction.initializeTransactionList(adminMovie);

    bool flag = true;
    while (flag == true){
        std::cout << "\n\t---------------------------------------------------------\n"
                     "\t              Grandplex Movie Ticketing System           \n"
                     "\t-*-------------------------------------*-----------------\n"
                     "\t-|1. Inventory Management System       |-----------------\n"
                     "\t-|2. Transaction Management System     |-----------------\n"
                     "\t-|3. Exit Program                      |-----------------\n"
                     "\t-*-------------------------------------*-----------------\n"
                     "\t>> Enter your choice:";
        int userChoice = validateInt();

        switch (userChoice) {
            case 1:
                adminMovie.movieMenu();
                break;
            case 2:
                //accept inventory as parameter
                adminTransaction.transactionMenu(&adminMovie);
                break;
            case 3:
                std::cout << "\n\t>> Goodbye\n\t>> Enter any key to exit:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                flag = false;
                banner();
                break;
            case -999:
                std::cout << "\n\t>> ERROR: Please enter an index."
                             "\n\t>> Enter any key to continue:";

                // Wait for user Input and ignore up to 10,000 characters
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
