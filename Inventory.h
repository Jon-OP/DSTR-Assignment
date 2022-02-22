// Attribute & Method Declaration for Inventory goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_INVENTORY_H
#define G8_TP060491_TP061069_TP055727_INVENTORY_H

#include <string>
#include <algorithm>
#include <iomanip>

class MovieList { //movieList

    struct MovieNode{
        // Attributes
        int movieID;
        std::string movieName;
        float moviePrice;
        int ticketQuantity;

        std::string movieCategory;
        std::string movieTime;

        // Methods
        MovieNode();
        MovieNode(int movieID, std::string movieName, float moviePrice, std::string movieCategory,
                  std::string movieTime);

    };

    // Attributes
    int nodeCount;
    int IDGenerator;
    MovieNode* movieList;
    std::string categoryList[3] = {"Action","Comedy", "Horror"};

    // Methods
    //void addMovie(MovieNode newNodes);
    //MovieNode generateNewNodes();
    MovieNode* searchMovie();
    void deleteMovie();
    void sortMovie();
    void updateMovie_prompt();
    void updateMovie(MovieNode* toUpdate);

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
    MovieList();

    // List initializer: To initialize list with dummy data
    void initializeList();

    //Getters and setters
    int getMovieListNodeCount();
    std::string getMovieName(int index);
    std::string getMovieCategory(int index);
    int getSeatsLeft(int index);
    std::string getTime(int index);
    void deductMovieQuantity(int inputQuantity);

};


#endif //G8_TP060491_TP061069_TP055727_INVENTORY_H
