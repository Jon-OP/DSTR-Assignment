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
// Main Implementation - Jonathan
void mainMenu(){


}

int main() {

    // Initialize Movie Array which is our database
    //Movie* adminMovie = new Movie[0];

    // Declaration of Transaction Object -> to access public Transaction methods
    TransactionList adminTransaction;

    // TEST SITE FOR MOVIE
    //adding pre-defined data into Inventory of movie
    //Movie newMovie = Movie("John Wick", 12.2, "Action, Fight", "12.00 pm", "February");
   // Movie newMovie1 = Movie("Spiderman", 12.2, "Action, Fight", "12.00 pm", "February");
   // Movie newMovie2 = Movie("John Weak", 12.2, "Action, Fight", "12.00 pm", "February");

    //Movie databaseList[0];
    Movie adminInventory;

    //moviePointers
   // Movie* adminMoviePtr = adminInventory.addMovie(databaseList, newMovie);
    //adminInventory.addMovie();


    //adminMovie->addMovie(adminMovie, newMovie);

//place holder code to test update and viewmovie
    //newMovie.updateMovie(&newMovie);
   // newMovie.viewMovie(newMovie);


    //TEST SITE BELOW ONWARDS
    Transaction testTransaction1 = Transaction(1,12.5);
    Transaction testTransaction2 = Transaction(2, 13.2);
    Transaction testTransaction3 = Transaction(3, 10.0);
    Transaction testTransaction4 = Transaction(4, 11);
    Transaction testTransaction5 = Transaction(8, 17);
    Transaction testTransaction6 = Transaction(7, 21.2);
    Transaction testTransaction7 = Transaction(6, 82.1);
    Transaction testTransaction8 = Transaction(5, 9.2);

    adminTransaction.insertTransactionToList(&testTransaction1);
    adminTransaction.insertTransactionToList(&testTransaction2);
    adminTransaction.insertTransactionToList(&testTransaction3);
    adminTransaction.insertTransactionToList(&testTransaction4);
    adminTransaction.insertTransactionToList(&testTransaction5);
    adminTransaction.insertTransactionToList(&testTransaction6);
    adminTransaction.insertTransactionToList(&testTransaction7);
    adminTransaction.insertTransactionToList(&testTransaction8);






    //main program starts here, for testing, call functions directly before this
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
                //adminInventory.inventoryConsoleMenu();
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
