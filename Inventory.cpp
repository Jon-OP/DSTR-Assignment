// Implementation for Inventory Goes Here - Jonathan
// To enter the implementation, remember to add "Inventory::<methodName>"

#include "Inventory.h"
#include <iostream>

// Constructor Methods
MovieList::MovieList() {
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

// Done
void MovieList::addMovie(MovieNode newNode) {
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

// Done
void MovieList::deleteMovie() {
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

// Search and Return ONE MovieNode
MovieList::MovieNode MovieList::searchMovie() {
    // Prompt user to enter search parameter
    std::cout << "\n\t>> Enter search parameter:";
    std::string searchParameter;
    std::getline(std::cin, searchParameter);

    // Initialize a temporary array to store search results
    int foundIndex[nodeCount];
    int internalIndex = 0;

    for(int i = 0; i < nodeCount; i++){
        // Input and comparison sanitation to allow case-insensitive searches
            // Search Parameter set to LOWER CASE
        std::transform(searchParameter.begin(),searchParameter.end(),searchParameter.begin(),::tolower);

            // Movie Name set to LOWER CASE
        std::string currentName = this->movieList[i].movieName;
        std::transform(currentName.begin(), currentName.end(), currentName.begin(), ::tolower);

        if( currentName.find(searchParameter) != std::string::npos ){
            foundIndex[internalIndex] = i;
            internalIndex++;
            //std::cout << "Found;";
        }
    }

    if(internalIndex != 0) {
        while (true) {
            // Print the list of search results
            for (int i = 0; i < internalIndex; i++) {
                std::cout << "\n\t" << i + 1 << ".\t" << this->movieList[foundIndex[i]].movieName;
            } //LINE 165 PHILIP @@@
            std::cout << "\n\n\t>> Enter the index of the movie you are seeking."
                         "\n\t>> Enter your choice:";

            int userChoice = validateInt();

            if (userChoice > 0 && userChoice < internalIndex) {
                return movieList[foundIndex[userChoice]];
            } else {
                if (userChoice == -999) {
                    std::cout << "\n\n\t>> ERROR: Please enter digits only."
                                 "\n\t>> Enter any key to continue:";

                    // Wait for user Input and ignore up to 10,00 characters
                    std::cin.ignore(10000, '\n');
                } else {
                    std::cout << "\n\n\t>> ERROR: Enter index from 1 to " << internalIndex
                              << "\n\t>> Enter any key to continue:";

                    // Wait for user Input and ignore up to 10,00 characters
                    std::cin.ignore(10000, '\n');
                }
            }
        }
    }
};

// Sort will be done by Eugene
void MovieList::sortMovie(){

}

// Update the Details
void MovieList::updateMovie(){
    while(true){
        std::cout << "\n\t0.\tSearch movie by Name.";






    }
}

// View specific details of a movie
void MovieList::viewMovie() {

    // List is empty
    if(movieList == NULL){
        std::cout << "\n\t>> ERROR: List is empty. Returning to Movie Menu."
                     "\n\t>> Enter any key to continue:";

        // Wait for user Input and ignore up to 10,000 characters
        std::cin.ignore( 10000, '\n');
    }else{
        // Atleast one item in the list
        std::cout << std::setw(10) << "Index"
                  << std::setw(10) << "Movie ID"
                  << std::setw(20) << "Movie Name"
                  << std::setw(10) << "Category"
                  << std::setw(10) << "Seats Left"
                  << std::setw(10) << "Time";

        for(int i = 0; i < nodeCount; i++){
            std::cout << movieList[i].movieName;
        }
    }


}

// List out the movie, price, and quantity - DONE
void MovieList::listMovies(){
    std::cout << "\n\tIndex\tMovie Name\tPrice\tAvailable Quantity";
    for(int i = 0; i < this->nodeCount; i++){
        std::cout << "\n\t" << i+1 << "\t" << this->movieList[i].movieName
                  << "\t" << this->movieList[i].moviePrice << "\t"
                  << this->movieList[i].ticketQuantity;
    }
}

// MovieList::MovieNode >> Returns movieNode
MovieList::MovieNode MovieList::generateNewNodes() {
    int id = 1, quantity = 25;
    float price = 10;
    std::string name, time = "12PM";
    std::string category = "Taste";
    int seat[] = { 1, 2};

    std::cout << "Name:";
    std::cin >> name;

    MovieNode newNode = MovieNode(id, name,price, category, time);
    return newNode;
}

MovieList::MovieNode::MovieNode() {
    this->movieName = "";
};

MovieList::MovieNode::MovieNode(int movieID, std::string movieName, float moviePrice, std::string movieCategory,
                            std::string movieTime){
    this->movieID = movieID;
    this->movieName = movieName;
    this->moviePrice = moviePrice;
    this->movieCategory = movieCategory;
    this->movieTime = movieTime;

    this->ticketQuantity = 25;
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

void MovieList::movieMenu(){
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
                searchMovie();
                //std::cout << "\n>> We should call searchMovie Method\n";
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
int MovieList::validateInt() {
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

float MovieList::validateFloat(){
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

// Initialize List
void MovieList::initializeList() {
    MovieNode movie_1 = MovieNode(IDGenerator, "John Wick", 12.5, "Action", "2300");
    IDGenerator;
    MovieNode movie_2 = MovieNode(IDGenerator, "Spiderman", 15.5, "Action", "2330");
    IDGenerator;
    MovieNode movie_3 = MovieNode(IDGenerator, "Human Centipede", 20.5, "Comedy", "1140");
    IDGenerator;
    MovieNode movie_4 = MovieNode(IDGenerator, "Naruto", 10.0, "Action", "2100");
    IDGenerator;
    MovieNode movie_5 = MovieNode(IDGenerator, "Gordon Ramsay", 15.0, "Horror", "1500");
    IDGenerator;
    MovieNode movie_6 = MovieNode(IDGenerator, "Bronze Man", 32.5, "Action", "1315");
    IDGenerator;
    MovieNode movie_7 = MovieNode(IDGenerator, "Pengu: Retribution", 25.0, "Comedy", "1145");
    IDGenerator;
    MovieNode movie_8 = MovieNode(IDGenerator, "Spiderwoman", 27.5, "Horror", "1200");
    IDGenerator;
    MovieNode movie_9 = MovieNode(IDGenerator, "My Dilemma", 23.5, "Comedy", "0000");
    IDGenerator++;
    MovieNode movie_10 = MovieNode(IDGenerator, "A+ in DSTR", 21.0, "Horror", "0115");
    IDGenerator++;


    addMovie(movie_1);
    addMovie(movie_2);
    addMovie(movie_3);
    addMovie(movie_4);
    addMovie(movie_5);
    addMovie(movie_6);
    addMovie(movie_7);
    addMovie(movie_8);
    addMovie(movie_9);
    addMovie(movie_10);
}