// Attribute & Method Declaration for Inventory goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_INVENTORY_H
#define G8_TP060491_TP061069_TP055727_INVENTORY_H

#include <string>
#include <algorithm>

class Movie { //movieList

    struct MovieNode{
        // Attributes
        int movieID;
        std::string movieName;
        float moviePrice;
        int ticketQuantity;

        bool seatAllocation[25];
        int* seat;

        std::string* movieCategory;
        std::string movieDate;
        std::string movieTime;

        // Methods
        MovieNode();
        MovieNode(int movieID, std::string movieName, float moviePrice, int ticketQuantity, int* seat,
                  std::string* movieCategory, std::string movieDate, std::string movieTime);

    };

    // Attributes
    int nodeCount;
    int IDGenerator;
    MovieNode* movieList;

    // Methods
    //void addMovie(MovieNode newNodes);
    //MovieNode generateNewNodes();
    MovieNode searchMovie();
    void deleteMovie();
    void sortMovie();
    void updateMovie();

    // Validation
    int validateInt();
    float validateFloat();

public:
    void addMovie(MovieNode newNodes);
    MovieNode generateNewNodes();
    void listMovies();
    void viewMovie();
    // void decreaseQuantity();

    // User Interface
    void movieMenu();

    // Constructors
    Movie();

};


#endif //G8_TP060491_TP061069_TP055727_INVENTORY_H
