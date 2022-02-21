// Attribute & Method Declaration for Inventory goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_INVENTORY_H
#define G8_TP060491_TP061069_TP055727_INVENTORY_H

#include <string>
#include <algorithm>

class Movie {

    Movie* movieList = NULL;
    // Counter for movieID
    static int inventoryCount;

    // Attributes of Inventory Class which will be kept Private
    int movieID;
    std::string movieName;
    float moviePrice;

    // Ticket Quantity = 25
    int ticketQuantity = 25;
    bool seatAllocation[25];

    std::string movieCategory;
    std::string movieTime; // HOUR, MINUTE, AM/PM
    std::string movieDate; // DAY, MONTH, YEAR

    // Functional Methods
//    Movie* addMovie(Movie movieList[], Movie newMovie);
    Movie searchMovie(Movie *movieList, std::string criteria);
    Movie* deleteMovie(Movie *movieList, Movie movieToDelete);
    Movie* sortMovie(Movie *movieList);

//    void updateMovie(Movie toUpdate);
//    void viewMovie(Movie selectedMovie);

    //UI methods
    void listMovieDetails();


    // Error Validation Method
    int validateInteger(std::string message);

    int validateInt();
    float validateFloat();

public:

    // Constructor Methods
    Movie();
    Movie(std::string movieName, float moviePrice, std::string movieCategory,
              std::string movieTime, std::string movieDate);

    // CONSOLE DISPLAY Methods
    void inventoryConsoleMenu(Movie* movieList);

    //test method - PHILIP
    void inventoryShowDetails();
    void viewMovie(Movie selectedMovie);

    Movie* addMovie(Movie movieList[], Movie newMovie);
    void updateMovie(Movie* toUpdate);

};


#endif //G8_TP060491_TP061069_TP055727_INVENTORY_H
