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

//----------------------------------{ Support Methods }--------------------------------------//

// Checks if string is float
bool isFloat(std::string str) {
    try {
        float checker = stof(str);
        return true;
    }
    catch (...) {
        return false;
    }
}

// Checks if string is integer
bool isInt(std::string str) {
    try {
        int checker = stoi(str);
        return true;
    }
    catch (...) {
        return false;
    }
}

// Swaps two movie elements in an array
void swap(Movie* elem1, Movie* elem2 ){
    Movie temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

//----------------------------------{ Functional Methods }--------------------------------------//
//ADD movie to Movie Array
Movie * Movie::addMovie(Movie movieList[], Movie newMovie){

    //Element counter
    int counter = 0;

    //Define new array with size +1
    Movie* newMovieList = new Movie[(sizeof(movieList)/sizeof(movieList[0])) + 1];

    //Copy elements to new array
    for (int i=0; i < sizeof(newMovieList)/sizeof(newMovieList[0]) ; i++){
        newMovieList[i] = movieList[i];
        counter++;
    }

    //Append new movie to new array
    newMovieList[counter] = newMovie;

    //Delete old array
    delete[] movieList;

    return newMovieList;
}

//SEARCH for a movie in Movie Array
Movie Movie::searchMovie(Movie movieList[], std::string criteria){

    // Loop for each item in movie list
    for (int i=0; i < sizeof(movieList)/sizeof(movieList[0]); i++){

        // If criteria is part of movie name, return movie. Else, return error.
        if (movieList[i].movieName.find(criteria) != std::string::npos){
            return movieList[i];
        } else {
            std::cout << "Movie not found, please search for another movie." << '\n';
        }
    }
}

//DELETE a movie from Movie Array
Movie * Movie::deleteMovie(Movie movieList[], Movie movieToDelete){

    // Counter for new array
    int counter = 0;

    // Declare size of new array (-1 from original)
    int size = (sizeof(movieList)/sizeof(movieList[0]) - 1);

    // Define new array with size - 1
    Movie* newMovieList = new Movie[size];

    // For each element in movieList
    for (int i = 0; i < sizeof(movieList)/sizeof(movieList[0]); i++){
        if (movieList[i].movieID != movieToDelete.movieID) {
            newMovieList[counter] = movieList[i];
            counter++;
        }
    }

    //Delete old array
    delete[] movieList;

    return newMovieList;
}

// VIEW movie details
void Movie::viewMovie(Movie selectedMovie){
    std::cout << "Movie ID: " << selectedMovie.movieID;
    std::cout << "Movie Name: " << selectedMovie.movieName;
    std::cout << "Movie Price: " << selectedMovie.moviePrice;
    std::cout << "Movie Category: " << selectedMovie.movieCategory;
    std::cout << "Movie Date: " << selectedMovie.movieDate;
    std::cout << "Movie Time: " << selectedMovie.movieTime;
}

// UPDATE movie details
void Movie::updateMovie(Movie* toUpdate){

    while(true){
        std::cout << "\n\tUpdate Menu"
                     "\n\t-----------------------"
                     "\n\t1. Change Movie Name"
                     "\n\t2. Change Movie Price"
                     "\n\t3. Change Movie Category"
                     "\n\t4. Return to Movie Menu\n"
                     "\n\t>> Enter your choice:";

        int userChoice = validateInt();
        std::string userInput;

        switch(userChoice){
            case 1:
                // Get user input
                std::cout << "\n\t>> Enter new movie name: ";
                std::getline(std::cin, userInput);

                // Replace movie name with input
                toUpdate->movieName = userInput;

                // Print success message
                std::cout << "\n\tMovie Name successfully updated.";
                break;

            case 2:
                while(true){
                    std::cout << "\n\t>> Enter the new movie price:";

                    float newPrice = validateFloat();

                    if(newPrice == -999){
                        std::cout << "\n\t>> ERROR: Please enter a number."
                                     "\n\t>> Enter any key to continue:";

                        // Wait for user Input and ignore up to 10,00 characters
                        std::cin.ignore( 10000, '\n');

                    }else{
                        if(newPrice > 0){
                            toUpdate->moviePrice = newPrice;
                            std::cout << "\n\tMovie Price successfully updated.";
                            break;
                        }else{
                            std::cout << "\n\t>> ERROR: Please enter a positive number."
                                         "\n\t>> Enter any key to continue:";

                            // Wait for user Input and ignore up to 10,00 characters
                            std::cin.ignore( 10000, '\n');

                        }
                    }
                }
                break;
            case 3:
                // Get user input
                std::cout << "Enter new movie category: ";
                std::getline(std::cin, userInput);

                // Replace movie name with input
                toUpdate->movieCategory = userInput;

                // Print success message
                std::cout << "\n\tMovie Category successfully updated.";
                break;
            case 4:
                std::cout << "\n\tReturning to Inventory Menu."
                             "\n\tEnter any key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');

                return;
            case -999:
                std::cout << "\n\t>> ERROR: Please enter an index."
                             "\n\t>> Enter any key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');

                break;
            default:
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 4\n\t>> Enter any Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;

        }
    }
}

// SORT movie array in ascending order
Movie * Movie::sortMovie(Movie movieList[]){

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
                // PROMPT MOVIE


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

//Philip testting, paiseh
void Movie::inventoryShowDetails(){}


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

int Movie::validateInt() {
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

float Movie::validateFloat(){
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
            return std::stof(userInput);
        }
    }else{
        return -999;
    }
}
