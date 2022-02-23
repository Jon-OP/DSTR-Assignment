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

//----------------------------------{ Helper Methods Starts}--------------------------------------//

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

// Swaps two node elements in an array
void MovieList::swapNode(MovieNode* elem1, MovieNode* elem2 ){
    MovieNode temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

// Partition for quickSort by quantity
int MovieList::partition2 (MovieNode* Node, int low, int high)
{
    // pivot
    MovieNode pivot = Node[high];
    // Index of smaller element and indicates the right position of pivot found so far
    int i = (low - 1);


    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (Node[j].ticketQuantity < pivot.ticketQuantity)
        {
            i++; // increment index of smaller element
            swapNode(&Node[i], &Node[j]);
        }
    }
    swapNode(&Node[i + 1], &Node[high]);
    return (i + 1);
}


// Partition for quickSort by ID
int MovieList::partition (MovieNode* Node, int low, int high)
{
    // pivot
    MovieNode pivot = Node[high];
    // Index of smaller element and indicates the right position of pivot found so far
    int i = (low - 1);


    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (Node[j].movieID < pivot.movieID)
        {
            i++; // increment index of smaller element
            swapNode(&Node[i], &Node[j]);
        }
    }
    swapNode(&Node[i + 1], &Node[high]);
    return (i + 1);
}
//----------------------------------{ Helper Methods Ends }--------------------------------------//
// Quick Sort method for ID
void MovieList::quickSort(MovieNode* Node, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(Node, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(Node, low, pi - 1);
        quickSort(Node, pi + 1, high);
    }
}

// Quick Sort method for Quantity
void MovieList::quickSort2(MovieNode* Node, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition2(Node, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(Node, low, pi - 1);
        quickSort(Node, pi + 1, high);
    }
}
//----------------------------------{ Functional Methods }--------------------------------------//
//-----------------------------------{ Movie handling methods starts } ------------------------//
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
MovieList::MovieNode* MovieList::searchMovie() {
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
        }
    }

    if(internalIndex != 0) {
        while (true) {
            // Print the list of search results
            for (int i = 0; i < internalIndex; i++) {
                std::cout << "\n\t" << std::setw(3) << i + 1 << ". " << this->movieList[foundIndex[i]].movieName;
            } //LINE 165 PHILIP @@@

            std::cout << "\n\t" << std::setw(3) << internalIndex+1 << ". Exit search."
                         "\n\n\t>> Enter the index of the movie you are seeking."
                         "\n\t>> Enter your choice:";

            int userChoice = validateInt();

            if(userChoice == internalIndex+1){
                std::cout << "\n\tReturning to Inventory Menu."
                          <<  "\n\tEnter any key to continue:";

                std::cin.ignore(10000, '\n');

                return nullptr;
            }else{
                if (userChoice > 0 && userChoice <= internalIndex) {
                    return &movieList[foundIndex[userChoice]];
                } else {
                    if (userChoice == -999) {
                        std::cout << "\n\n\t>> ERROR: Please enter digits only."
                                     "\n\t>> Enter any key to continue:";

                        // Wait for user Input and ignore up to 10,00 characters
                        std::cin.ignore(10000, '\n');
                    } else {
                        std::cout << "\n\n\t>> ERROR: Enter index from 1 to " << internalIndex+1
                                  << "\n\t>> Enter any key to continue:";

                        // Wait for user Input and ignore up to 10,00 characters
                        std::cin.ignore(10000, '\n');
                    }
                }
            }
        }
    }else{
        std::cout << "\n\tERROR: No Movie found with \"" <<searchParameter << "\""
                  <<  "\n\tReturning. Enter any key to continue:";

        // Ignore up to 10000 chars
        std::cin.ignore(10000, '\n');
    }
};

// Sort will be done by Eugene
void MovieList::sortMovie(){

    std::cout << "\n\t1. Sort by ID"
              << "\n\t2. Sort by Price"
              << "\n\n\t Enter your choice: ";
    int userChoice = validateInt();

        if (userChoice == 1) {
            //Sort the array by ID
            quickSort(movieList, 0, nodeCount - 1);
            std::cout << "Quicksort function called \n";

        } else if (userChoice == 2) {
            //Sort the array by price
            quickSort2(movieList, 0, nodeCount - 1);
            std::cout << "Quicksort2 function called \n";
        }
}

// Update the Details
void MovieList::updateMovie_prompt(){
    // This section ask users to choose an item to update
    MovieNode* toUpdate = NULL;
    while(true){
        std::cout << "\n0. Search Movie By Name";
        listMovies();
        std::cout << "\n" << nodeCount+1 << " Return to Inventory Menu.";

        int userChoice = validateInt();

        if(userChoice == 0){
            toUpdate = searchMovie();
            if(toUpdate != NULL){
            }
        }else{
            if(userChoice == nodeCount+1){
                std::cout << "\n\n\t>> Returning to Main Menu"
                             "\n\t>> Enter any key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore(10000, '\n');
                return;
            }

            if(userChoice > 0 && userChoice < this->nodeCount){
                toUpdate = &movieList[userChoice-1];
            }else{
                if(userChoice == -999){
                    std::cout << "\n\n\tERROR: Please enter a viable index."
                                 "\n\t>> Enter any key to continue:";

                    // Wait for user Input and ignore up to 10,00 characters
                    std::cin.ignore(10000, '\n');
                }
            }
        }
        if(toUpdate != NULL){
            updateMovie(toUpdate);
            return;
        }
    }
}

// View specific details of a movie
/*
void MovieList::viewMovie() {

    // List is empty
    if(this->movieList == NULL){
        std::cout << "\n\t>> ERROR: List is empty. Returning to Movie Menu."
                     "\n\t>> Enter any key to continue:";

        // Wait for user Input and ignore up to 10,000 characters
        std::cin.ignore( 10000, '\n');
    }else{
        // Atleast one item in the list
        std::cout << std::setw(10) << "Index"
                  << std::setw(10) << "Movie ID"
                  << std::setw(20) << "Movie Name"
                  << std::setw(15) << "Category"
                  << std::setw(20) << "Seats Left"
                  << std::setw(10) << "Time";

        for(int i = 0; i < nodeCount; i++){
            std::cout << movieList[i].movieName ;// @PHILIP PRINT ALL DETAILS
        }
    }
}*/

//Function to display all the movies in the movieList
// List out the movie, price, and quantity - DONE
void MovieList::listMovies() {

    // Checks if movieList is empty
    if(this->movieList == NULL){
        std::cout << "\n\t>> ERROR: List is empty. Returning to Movie Menu."
                     "\n\t>> Enter any key to continue:";

        // Wait for user Input and ignore up to 10,000 characters
        std::cin.ignore( 10000, '\n');
    }else{
        //Executes if at least one item(movie) is in the movieList
        std::cout << "\tIndex"
                  << std::left<<std::setw(10) << "\tMovie ID"
                  << std::right<<std::setw(16)  << "Movie Name"
                  << std::left<<"\t       Price"
                  << std::left<< "\tCategory"
                  << std::left<< "\tSeats Left"
                  << std::left<< "\tTime";

        for(int i = 0; i < nodeCount; i++){
            std::cout   <<"\n\t"<< i+1
                    << std::left << std::setw(2) <<"\t" << movieList[i].movieID
                    << std::left <<std::setw(8)<<"\t"<< movieList[i].movieName;

            if (movieList[i].movieName.length()<8)
            {
                std::cout  <<std::setw(16)<<"\t "<< movieList[i].moviePrice;
            }else if (movieList[i].movieName.length()>8 && movieList[i].movieName.length()<16)
            {
                std::cout << std::setw(8) << "\t " <<movieList[i].moviePrice;
            }else
            {
                std::cout<< "\t" << movieList[i].moviePrice;
            }
            std::cout
                    << std::left<<"\t" << movieList[i].movieCategory
                    << std::left<<"\t\t" << movieList[i].ticketQuantity
                    << std::left<<"\t\t" << movieList[i].movieTime;
        }
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

MovieList::MovieNode::MovieNode(int movieID, std::string movieName, int moviePrice, std::string movieCategory,
                            std::string movieTime){
    this->movieID = movieID;
    this->movieName = movieName;
    this->moviePrice = moviePrice;
    this->movieCategory = movieCategory;
    this->movieTime = movieTime;

    this->ticketQuantity = 25;
}

//--------------------------------------------{ Movie handling methods ends } --------------------------//

//---------------------------------------------{ UI methods starts }------------------------------------//


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
                addMovie_prompt();
                std::cout << "\n>> We should CALL newMovie Method [Pending]\n";
                break;

            case 2:
                std::cout << "\n\t-----------------------------------------------------------------------------------------------------\n"
                             "\t                                         Displaying all movies                                        \n"
                             "\t------------------------------------------------------------------------------------------------------\n";
                listMovies();
                std::cout<< "\n\t-----------------------------------------------------------------------------------------------------\n"
                            "\tPress any key to continue:";
                std::cin.ignore( 10000, '\n');
                break;
            case 3:
                searchMovie();
                //std::cout << "\n>> We should call searchMovie Method\n";
                break;

            case 4:
                updateMovie_prompt();
                //std::cout << "\n>> We should call updateMovie Method\n";
                break;

            case 5:
                std::cout << "\n>> We should call sortMovie Method\n";
                sortMovie();
                std::cout <<"\n called sort function.";
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
void MovieList::addMovie_prompt(){
    std::string movieName, movieCategory, movieTime, tempString;
    int moviePrice;
    int movieID, tempTime;
    std::cout << "\n\t-*----------------------------------------------*-"
                 "\n\t-|               Adding New Movie               |-"
                 "\n\t-*----------------------------------------------*-\n"
                 "\n\t>> Movie Name [Maximum of 20 characters]"
                 "\n\t>> Enter the new movie name:";;

    // Getting Movie Name and validating their input
    while(true){
        std::getline(std::cin, movieName);
        if(movieName.length() < 21 && movieName.length() != 0){
            std::cout << "\n\t>> [ Movie Name: " << movieName << " ] - User input accepted...";
            break;
        }else{
            std::cout << "\n\t>> ERROR: Movie name has to be lesser than 20 characters long"
                         "\n\t>> Enter the Movie Name:";
        }
    }

    // Getting Movie Price and validating their input
    std::cout << "\n\n\t>> Movie Price [In Ringgit Malaysia, must be more than RM 0]"
                 "\n\t>> Enter the Movie Price: RM";
    while(true){
        moviePrice = validateInt();
        // User enters a valid price for movie
        if(moviePrice > 0 && moviePrice < 1000){
            std::cout << "\n\t>> [ Price: RM" << moviePrice << " ] - User input accepted...";
            break;
        }else{
            // User entered < 0 OR validateInt returns -999 which is an error code
            std::cout << "\n\t>> ERROR: Invalid Input."
                         "\n\t>> Price must be a positive integer [More than RM 0]."
                         "\n\t>> Please re-enter the new movie price:";
        }
    }

    // Getting Category from user
    while(true){
        std::cout << "\n\n\t-*--------------*-"
                     "\n\t-| Category List |-"
                     "\n\t-*---------------*-";
        for(int i = 0; i < (sizeof (categoryList)/sizeof (categoryList[0])); i++ ){
            std::cout << "\n\t-| " << i+1 << ". " << std::left << std::setw(10) << categoryList[i] << " |-";
        }
        std::cout << "\n\t-*---------------*-"
                     "\n\n\t>> [Enter the index between 1 to 3]"
                     "\n\t>> Choose a category for the new movie:";

        int userChoice = validateInt();

        if(userChoice > 0 && userChoice <= (sizeof(categoryList)/sizeof (categoryList[0]))){
            movieCategory = categoryList[userChoice-1];
            std::cout << "\n\t>> [ Movie Category: " << movieCategory << " ] - User input accepted...";
            break;
        }else{
            std::cout << "\n\t>> ERROR: Invalid Input detected."
                         "\n\t>> Please choose an appropriate index."
                         "\n\t>> Enter any key to continue:";
            std::cin.ignore(10000,'\n');
        }
    }

    // Get HOURS from user
    std::cout << "\n\n\t>> Selecting the start time for Movie in HOURS [0 - 23]"
                 "\n\t>> Enter the movie start time:";
    while(true){
        tempTime = validateInt();
        if(tempTime >= 0 && tempTime < 24){
            movieTime = std::to_string(tempTime);

            // Time entered by user is less than 10 so its 1, 2, 3, ...
            // Convert to 24 hour representation like 01, 02, 03, ...
            if(tempTime < 10){
                movieTime = "0" + movieTime;
            }
            std::cout << "\n\n\t>> [ Time(Hours): " << movieTime << " ] - User input accepted...";
            break;
        }else{
            std::cout << "\n\tERROR: Invalid HOURS value detected."
                         "\n\t>> Please enter the HOURS from [0 - 23]."
                         "\n\t>> Enter the movie start time:";
        }
    }

    // Get MINUTES from user
    std::cout << "\n\n\t>> Selecting the starting for Movie in MINUTES [0 - 59]"
                 "\n\t>> Enter the movie start time:";
    while(true){
        tempTime = validateInt();
        if(tempTime >= 0 && tempTime < 60){
            tempString = std::to_string(tempTime);
            // Format string to print 9 like 09
            if(tempTime < 10){
                tempString = "0" + tempString;
            }
            std::cout << "\n\n\t>> [ Movie Time [MINUTES]: " << tempString << " ] - User input accepted...";
            // Concatenate movieTime and tempString to get the appropriate 24 HOURS time format
            movieTime = movieTime + tempString;
            break;
        }else{
            std::cout << "\n\tERROR: Invalid MINUTES value detected."
                         "\n\t>> Please enter the MINUTES from [0 - 59]."
                         "\n\t>> Enter the movie start time:";
        }
    }

    // FINAL CONFIRMATION TO ADD NEW MOVIE
    while(true){
        std::cout << "\n\n\t-*-----------------------------------------------------*-"
                  <<   "\n\t-|                  New Movie Details                  |-"
                  <<   "\n\t-*-----------------------------------------------------*-"
                  <<   "\n\t-| Movie Name     : " << std::left << std::setw(21) << movieName << " |------------|-"
                  <<   "\n\t-| Movie Price    : RM " << std::left << std::setw(18) <<moviePrice << " |------------|-"
                  <<   "\n\t-| Movie Category : " << std::left << std::setw(21) << movieCategory << " |------------|-"
                  <<   "\n\t-| Movie Time     : " << std::left << std::setw(21) << movieTime << " |------------|-"
                  <<   "\n\t-*------------------------------------------------------*";
        std::cout << "\n\n\t>> [ 1 = Yes , 2 = No ]"
                     "\n\t>> Confirm adding this movie?"
                     "\n\t>> Enter your choice:";
        int userChoice = validateInt();
        if(userChoice == 1){
            IDGenerator++;
            movieID = this->IDGenerator;
            MovieNode newMovie = MovieNode(movieID, movieName, moviePrice, movieCategory, movieTime);
            this->addMovie(newMovie);
            std::cout << "\n\t>> New Movie has been added to the list."
                         "\n\t>> Returning to Inventory menu."
                         "\n\t>> Enter any key to continue:";
            std::cin.ignore(10000, '\n');
            break;
        }else{
            if(userChoice == 2) {
                std::cout << "\n\tAdding New Movie process has been cancelled."
                             "\n\tCurrent Movie details have been discarded."
                             "\n\tReturning to Inventory Menu."
                             "\n\tEnter any key to continue:";
                std::cin.ignore(10000, '\n');
                break;
            } else{
                std::cout << "\n\tERROR: Invalid Input."
                             "\n\tEnter any key to continue:";
                std::cin.ignore(10000,'\n');
            }
        }
    }
    return;
}


void MovieList::updateMovie(MovieNode *toUpdate) {
    while (true){
        std::cout << "\n\t---------------------------------------------------------"
                     "\n\t                      Updating movie                      "
                     "\n\t-*----------------------------*---------------------------"
                     "\n\t-|  1. Name     ->" << std::setw(20) << toUpdate->movieName << " |------------------"
                     "\n\t-|  2. Price    ->" << std::setw(20) << toUpdate->moviePrice << " |------------------"
                     "\n\t-|  3. Category ->" << std::setw(20) << toUpdate->movieCategory << " |------------------"
                     "\n\t-|  4. Time     ->" << std::setw(20) << toUpdate->movieTime << " |------------------"
                     "\n\t-|  5. Finalize updating details       |------------------"
                     "\n\t-*--------------------------------------------------------"
                     "\n\n\t>> Enter your choice:";
        int userChoice = validateInt();
        std::string userInput;
        std::string userInputTime;
        int userChoiceInternal;
        int userPrice;
        switch(userChoice){
            case 1:
                // Prompt and read user input regarding name
                std::cout << "\n\t>> Enter the new Name:";
                std::getline(std::cin, userInput);

                // Replace the movie name with input
                if(userInput.length() < 21){
                    toUpdate->movieName = userInput;
                    std::cout << "\n\t>> Movie Name successfully updated."
                                 "\n\t>> Enter any key to return to Update Menu:";

                    // Wait for user Input and ignore up to 10,00 characters
                    std::cin.ignore(10000, '\n');

                }else{
                    std::cout << "\n\t>> ERROR: New Name too long."
                                 "\n\t>> Enter name less than 21 characters."
                                 "\n\t>> Movie Name failed to update."
                                 "\n\t>> Returning to Update Menu. Enter any key to continue:";
                    // Wait for user Input and ignore up to 10,00 characters
                    std::cin.ignore(10000, '\n');
                }

                break;

            case 2:
                // Prompt and read user input regarding price
                std::cout << "\n\n\t>> Enter the new price: RM";
                userPrice = validateInt();

                // Update the movie price with input
                if(userPrice > 0){
                    toUpdate->moviePrice = userPrice;

                    std::cout << "\n\t>> Movie Price successfully updated."
                                 "\n\t>> Enter any key to return to Update Menu";

                    // Wait for user Input and ignore up to 10,00 characters
                    std::cin.ignore(10000, '\n');
                }else{
                    std::cout << "\n\t>> ERROR: Invalid Input."
                                 "\n\t>> Movie Price failed to update."
                                 "\n\t>> Returning to Update Menu. Enter any key to continue:";

                    // Wait for user Input and ignore up to 10,000 characters
                    std::cin.ignore(10000,'\n');

                }
                break;

            case 3:
                std::cout << "\n\tIndex\tCategories\n";
                for(int i = 0; i < 3; i++){
                    std::cout << i+1 << "\t" <<categoryList[i] << "\n";
                }

                userChoiceInternal = validateInt();

                if(userChoiceInternal > 0 && userChoiceInternal < 4){

                    toUpdate->movieCategory = categoryList[userChoiceInternal-1];

                    std::cout << "\n\t>> Movie Category successfully updated."
                                 "\n\t>> Returning to Update Menu."
                                 "\n\t>> Enter any key to Continue:";

                    // Wait for user Input and ignore up to 10,000 characters
                    std::cin.ignore(10000, '\n');
                }else{
                    std::cout << "\n\t>> ERROR: Invalid Input."
                                 "\n\t>> Movie Category failed to update."
                                 "\n\t>> Returning to Update Menu."
                                 "\n\t>> Enter any key to continue:";

                    // Wait for user Input and ignore up to 10,000 characters
                    std::cin.ignore(10000,'\n');
                }
                break;
            case 4:
                std::cout << "\n\t>> NOTE: Time is stored in 24-hour format"
                             "\n\t>> Enter the HOUR [0 - 23] for the movie:";

                userChoiceInternal = validateInt();

                if(userChoiceInternal >= 0 && userChoiceInternal < 24){
                    userInput = std::to_string(userChoiceInternal);
                    if (userInput.length() != 2){
                        userInput = "0"+userInput;
                    }
                }else{
                    std::cout << "\n\t>> ERROR: Invalid Input."
                                 "\n\t>> Movie Time failed to update."
                                 "\n\t>> Returning to Update Menu."
                                 "\n\t>> Enter any key to continue:";

                    // Wait for user Input and ignore up to 10,000 characters
                    std::cin.ignore(10000,'\n');
                    break;
                }

                std::cout << "\n\t>> NOTE: Time is stored in 24-hour format"
                             "\n\t>> Enter the MINUTES [0 - 59] for the movie:";

                userChoiceInternal = validateInt();

                if(userChoiceInternal >= 0 && userChoiceInternal < 60){
                    userInputTime = std::to_string(userChoiceInternal);
                    if(userInputTime.length() != 2){
                        userInputTime = "0" + userInputTime;
                    }
                    userInput = userInput + userInputTime;
                }else{
                    std::cout << "\n\t>> ERROR: Invalid Input."
                                 "\n\t>> Movie Time failed to update."
                                 "\n\t>> Returning to Update Menu."
                                 "\n\t>> Enter any key to continue:";

                    // Wait for user Input and ignore up to 10,000 characters
                    std::cin.ignore(10000,'\n');
                    break;
                }

                toUpdate->movieTime = userInput;
                std::cout << "\n\t>> Movie Category successfully updated."
                             "\n\t>> Returning to Update Menu."
                             "\n\t>> Enter any key to continue:";

                // Wait for user Input and ignore up to 10,000 characters
                std::cin.ignore(10000, '\n');
                break;
            case 5:
                std::cout << "\n\t>> Returning to Inventory Menu."
                             "\n\t>> Enter any key to continue:";

                // Wait for user Input and ignore up to 10,000 characters
                std::cin.ignore(10000, '\n');
                return;
            default:
                std::cout << "\n\t>> ERROR: Invalid Input."
                             "\n\t>> Returning to Update Menu."
                             "\n\t>> Enter any key to continue:";

                // Wait for user Input and ignore up to 10,000 characters
                std::cin.ignore(10000,'\n');
                break;
        }
    }
}
//Getters and setters
int MovieList::getMovieListNodeCount()
{
    return nodeCount;
}
std::string MovieList::getMovieName(int index)
{
    return movieList[index].movieName;
}
std::string MovieList::getMovieCategory(int index)
{
    return movieList[index].movieCategory;
}
int MovieList::getMoviePrice(int index)
{
    return movieList[index].moviePrice;
}
int MovieList::getTicketsLeft(int index)
{
    return movieList[index].ticketQuantity;
}
std::string MovieList::getTime(int index)
{
    return movieList[index].movieTime;
}
void MovieList::deductMovieQuantity(int index,int inputQuantity)
{

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
    IDGenerator++;
    MovieNode movie_2 = MovieNode(IDGenerator, "Spiderman", 15.5, "Action", "2330");
    IDGenerator++;;
    MovieNode movie_3 = MovieNode(IDGenerator, "Human Centipede", 20.5, "Comedy", "1140");
    IDGenerator++;;
    MovieNode movie_4 = MovieNode(IDGenerator, "Naruto", 10.0, "Action", "2100");
    IDGenerator++;;
    MovieNode movie_5 = MovieNode(IDGenerator, "Gordon Ramsay", 15.0, "Horror", "1500");
    IDGenerator++;;
    MovieNode movie_6 = MovieNode(IDGenerator, "Bronze Man", 32.5, "Action", "1315");
    IDGenerator++;;
    MovieNode movie_7 = MovieNode(IDGenerator, "Pengu: Retribution", 25.0, "Comedy", "1145");
    IDGenerator++;;
    MovieNode movie_8 = MovieNode(IDGenerator, "Spiderwoman", 27.5, "Horror", "1200");
    IDGenerator++;;
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


