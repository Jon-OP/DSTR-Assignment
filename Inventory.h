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
        int moviePrice;
        int ticketQuantity;

        std::string movieCategory;
        std::string movieTime;

        // Methods
        MovieNode();
        MovieNode(int movieID, std::string movieName, int moviePrice, std::string movieCategory,
                  std::string movieTime);

    };

    // Attributes
    int nodeCount;
    int IDGenerator;
    MovieNode* movieList;
    std::string categoryList[3] = {"Action","Comedy", "Horror"};

    // Methods

    //Support Methods
    void quickSort(MovieNode *IDs, int low, int high, int sortParameter);
    int partition(MovieNode *IDs, int low, int high, int partitionType);

    //void addMovie(MovieNode newNodes);
    MovieNode* searchMovie();
    void deleteMovie();
    void sortMovie();
    void addMovie_prompt();
    void updateMovie_prompt();
    void updateMovie(MovieNode* toUpdate);

    // Validation
    int validateInt();

public:
    void addMovie(MovieNode newNodes);
    MovieNode generateNewNodes();
    void listMovies();

    // User Interface
    void movieMenu();

    // Constructors
    MovieList();

    // List initializer: To initialize list with dummy data
    void initializeList();

    void swapNode(MovieNode *elem1, MovieNode *elem2);

    //Getters and setters
    int getMovieListNodeCount();
    std::string getMovieName(int index);
    int getMoviePrice(int index);
    int getTicketsLeft(int index);
    std::string getTime(int index);
    void deductMovieQuantity(int index, int inputQuantity);

};


#endif //G8_TP060491_TP061069_TP055727_INVENTORY_H
