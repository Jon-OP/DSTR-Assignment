// Attribute & Method Declaration for Inventory goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_INVENTORY_H
#define G8_TP060491_TP061069_TP055727_INVENTORY_H

#include <string>
#include <algorithm>

class Movie {

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
    Movie* addMovie(Movie movieList[], Movie newMovie);
    Movie searchMovie(Movie *movieList, std::string criteria);




    // Error Validation Method
    int validateInteger(std::string message);

public:

    // Constructor Methods
    Movie();
    Movie(std::string movieName, float moviePrice, std::string movieCategory,
              std::string movieTime, std::string movieDate);

    // CONSOLE DISPLAY Methods
    void inventoryConsoleMenu();

};


#endif //G8_TP060491_TP061069_TP055727_INVENTORY_H
