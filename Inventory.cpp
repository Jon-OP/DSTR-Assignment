// Implementation for Inventory Goes Here - Jonathan
// To enter the implementation, remember to add "Inventory::<methodName>"

#include "Inventory.h"
#include <iostream>

// Counter to keep track of number of Movies -> For movieID
int Movie::inventoryCount = 0;

// Constructor Methods
Movie::Movie() {}

Movie::Movie(std::string movieName, float moviePrice, std::string movieCategory,
                     std::string movieTime, std::string movieDate) {
    this->movieID = inventoryCount+1;
    this->movieName = movieName;
    this->moviePrice = moviePrice;
    this->movieCategory = movieCategory;
    this->movieTime = movieTime;
    this->movieDate = movieDate;


    // Initialize all seatAllocation indices to FALSE (Available for Reservation)
    for(int i = 0; i < 25; i++){
        this->seatAllocation[i] = false;
    }

}

// ADD Inventory Product
void Movie::addMovie(std::string name, float price, std::string category, std::string time, std::string date) {
    Movie product1 = Movie(name, price, category, time, date);

}


// CONSOLE DISPLAY Methods
void Movie::inventoryConsoleMenu() {
    std::string inventoryMenuMsg = "\tMovie Management System\n"
                                   "\t-----------------------\n"
                                   "\t1. Add New Movie\n"
                                   "\t2. View Movie Details\n"
                                   "\t3. Search Movie by Name\n"
                                   "\t4. Update Movie Details\n"
                                   "\t5. Sort Movie\n"
                                   "\t6. Delete Movie Details\n"
                                   "\t7. Back to Main Menu\n"
                                   "\n\t>> Enter your choice:";

    int userChoice;
    do{
        userChoice = validateInteger(inventoryMenuMsg);

        switch(userChoice){
            case 1:
                std::cout << "\n>> We should CALL newMovie Method\n";
                break;

            case 2:
                std::cout << "\n>> We should call listMovieDetails Method\n";
                break;

            case 3:
                std::cout << "\n>> We should call searchMovie Method\n";
                break;

            case 4:
                std::cout << "\n>> We should call updateMovie Method\n";
                break;

            case 5:
                std::cout << "\n>> We should call sortMovie Method\n";
                break;

            case 6:
                std::cout << "\n>> We should call deleteMovie Method\n";
                break;

            case 7:
                std::cout << "\n\t>> Returning to Main Menu.\n\t>> Enter any key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;

            default:
                //std::cout << "Invalid Input. Try again.\nEnter any key to continue:";
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> ERROR: Invalid Input\n\t>> Please enter from 1 to 7.\n\t>> Enter a Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
        }


    }while(userChoice != 7);

};



void Movie::greetings(){
    std::cout << "This is a Test from Inventory" << std::endl;
}

// Error Validation Method
int Movie::validateInteger(std::string message){
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
