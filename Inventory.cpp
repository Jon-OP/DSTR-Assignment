// Implementation for Inventory Goes Here - Jonathan
// To enter the implementation, remember to add "Inventory::<methodName>"

#include "Inventory.h"
#include <iostream>

// Constructor Methods
Movie::Movie() {
    this->nodeCount = 0;
    this->IDGenerator = 1;
    this->movieList = NULL;
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
void swap(std::string* elem1, std::string* elem2 ){
    std::string temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

// String partition for QuickSwap method (sortMovie())
int partition (std::string names[], int low, int high)
{
    std::string pivot = names[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (names[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&names[i], &names[j]);
        }
    }
    swap(&names[i + 1], &names[high]);
    return (i + 1);
}

//----------------------------------{ Functional Methods }--------------------------------------//

void Movie::addMovie(MovieNode newNode) {
    if(movieList == NULL){
        movieList = new MovieNode[1];
        movieList[0] = newNode;
        nodeCount++;
    }else{

        // Create a static List to copy with size+1
        MovieNode copyList[nodeCount+1];
        for(int i = 0; i < nodeCount; i++){
            copyList[i] = movieList[i];
        }
        // Add the new Movie to end of the copyList
        copyList[nodeCount] = newNode;

        // Delete the movieList content
        delete[] movieList;
        movieList = NULL;

        movieList = new MovieNode[nodeCount+1];
        for(int i = 0; i < nodeCount+1 ; i++){
            movieList[i] = copyList[i];
        }

        //movieList = copyList;
        nodeCount++;
    }
}

Movie::MovieNode Movie::searchMovie() {

};

void Movie::deleteMovie() {
    int indexToDelete;
    listMovies();
    std::cout << "\n\t>> Which movie would you like to delete?"
                 "\n\t>> Enter your choice:";
    std::cin >> indexToDelete;
    indexToDelete = indexToDelete - 1;
    nodeCount; // Reduce nodeCount before resizing array

    if(nodeCount == 0){
        delete[] movieList;
        movieList = NULL;
    }else{
        MovieNode copyList[nodeCount];

        movieList[indexToDelete] = MovieNode();

        // Copy the list
        int copyListCount = 0;
        for(int i = 0; i < nodeCount; i++){
            if(movieList[i].movieName != ""){
                copyList[copyListCount] = movieList[i];
                copyListCount++;
            }
        }

        delete[] movieList;
        movieList = NULL;

        nodeCount--;

        movieList = new MovieNode[nodeCount];
        for(int i = 0; i < nodeCount; i++){
            movieList[i] = copyList[i];
        }
    }
}

void Movie::sortMovie(){

}

void Movie::updateMovie(){

}

// View specific details of a movie
void Movie::viewMovie() {
    for(int i = 0; i < nodeCount; i++){
        std::cout << movieList[i].movieName;
    }

}

// List out the movie, price, and quantity - DONE
void Movie::listMovies(){
    std::cout << "\n\tIndex\tMovie Name\tPrice\tAvailable Quantity";
    for(int i = 0; i < this->nodeCount; i++){
        std::cout << "\n\t" << i+1 << "\t" << movieList[i].movieName
                  << "\t" << movieList[i].moviePrice << "\t"
                  << movieList[i].ticketQuantity;
    }
}

Movie::MovieNode Movie::generateNewNodes() {
    int id = 1, quantity = 25;
    float price = 10;
    std::string name, time = "12PM", date = "FEB";
    std::string category[] = {"Valbo", "Testa"};
    int seat[] = { 1, 2};

    std::cout << "Name:";
    std::cin >> name;

    MovieNode newNode = MovieNode(id, name,price, quantity, seat, category, date, time);
    return newNode;
}








Movie::MovieNode::MovieNode() {
    this->movieName = "";
};

Movie::MovieNode::MovieNode(int movieID, std::string movieName, float moviePrice, int ticketQuantity, int* seat,
                            std::string* movieCategory, std::string movieDate, std::string movieTime){
    this->movieID = movieID;
    this->movieName = movieName;
    this->moviePrice = moviePrice;
    this->ticketQuantity = ticketQuantity;
    this->seat = seat;
    this->movieCategory = movieCategory;
    this->movieDate = movieDate;
    this->movieTime = movieTime;
}

/*
//ADD movie to Movie Array
Movie* Movie::addMovie(Movie* movieList, Movie newMovie){


    if(movieList == NULL){
        movieList = new Movie[1];
        movieList[0] = newMovie;
        movieCount++;
    }else{
        Movie* copyList = new Movie[this->movieCount+1];
        for(int i = 0; i < this->movieCount; i++){
            copyList[i] = movieList [i];
        }

        copyList[this->movieCount] = newMovie;

        delete[] movieList[];
        movieList = copyList;
        nodeCount++'
        return movieList;
    }
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
// PHILIP - fix formating
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
        // include selected movie
        std::cout << "\n\t---------------------------------------------------------\n"
                     "\t                      Updating movie                      \n"
                     "\t-*----------------------------*---------------------------\n"
                     "\t-|1. Change Movie Name        |---------------------------\n"
                     "\t-|2. Change Movie Price       |---------------------------\n"
                     "\t-|3. Change Movie Category    |---------------------------\n"
                     "\t-|4. Return to Movie Menu     |---------------------------\n"
                     "\t-*----------------------------*---------------------------\n"
                     "\t>> Enter your choice:";

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
void Movie::inventoryConsoleMenu(Movie* movieListParam) {
    Movie* movieList = movieListParam;
    std::string inventoryMenuMsg = "\n\t---------------------------------------------------------\n"
                                   "\t                    Movie Management Menu                 \n"
                                   "\t-*--------------------------*-----------------------------\n"
                                   "\t-|1. Add New Movie          |-----------------------------\n"
                                   "\t-|2. View Movie Details     |-----------------------------\n"
                                   "\t-|3. Search Movie by Name   |-----------------------------\n"
                                   "\t-|4. Update Movie Details   |-----------------------------\n"
                                   "\t-|5. Sort Movie             |-----------------------------\n"
                                   "\t-|6. Delete Movie Details   |-----------------------------\n"
                                   "\t-|7. Back to Main Menu      |-----------------------------\n"
                                   "\t-*--------------------------*-----------------------------\n"
                                   "\n\t>> Enter your choice:";

    int userChoice;
    do{
        userChoice = validateInteger(inventoryMenuMsg);

        switch(userChoice){
            case 1:
                // PROMPT MOVIE

                std::cout << "\n>> We should CALL newMovie Method [Pending]\n";
                break;

            case 2:
                std::cout << "\n>> We should call listMovieDetails Method\n";
                std::cout << "\n\t---------------------------------------------------------\n"
                             "\t                 Select a movie to be updated             \n"
                             "\t----------------------------------------------------------\n";
                void listMovieDetails();

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

void Movie::listMovieDetails(Movie* movieList)
{
    for(int i=0;i<sizeof(movieList)/sizeof(movieList[0]);i++)
    {
        viewMovie(movieList[i]);
        std:: cout << std::endl;
    }
}

//Philip testting, paiseh
void Movie::inventoryShowDetails()
{
    std::cout<< movieName + std::to_string(moviePrice) +movieCategory;
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
*/

void Movie::movieMenu(){
    while(true){
        std::cout << "\n\t---------------------------------------------------------\n"
                     "\t                    Movie Management Menu                 \n"
                     "\t-*--------------------------*-----------------------------\n"
                     "\t-|1. Add New Movie          |-----------------------------\n"
                     "\t-|2. View Movie Details     |-----------------------------\n"
                     "\t-|3. Search Movie by Name   |-----------------------------\n"
                     "\t-|4. Update Movie Details   |-----------------------------\n"
                     "\t-|5. Sort Movie             |-----------------------------\n"
                     "\t-|6. Delete Movie Details   |-----------------------------\n"
                     "\t-|7. Back to Main Menu      |-----------------------------\n"
                     "\t-*--------------------------*-----------------------------\n"
                     "\n\t>> Enter your choice:";

        int userChoice = validateInt();
        switch(userChoice){
            case 1:
                // PROMPT MOVIE

                std::cout << "\n>> We should CALL newMovie Method [Pending]\n";
                break;

            case 2:
                std::cout << "\n>> We should call listMovieDetails Method\n";
                std::cout << "\n\t---------------------------------------------------------\n"
                             "\t                 Select a movie to be updated             \n"
                             "\t----------------------------------------------------------\n";
                void listMovieDetails();

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
                return;

            default:
                //std::cout << "Invalid Input. Try again.\nEnter any key to continue:";
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> ERROR: Invalid Input\n\t>> Please enter from 1 to 7.\n\t>> Enter a Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
        }
    }
}

// Error Validation
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