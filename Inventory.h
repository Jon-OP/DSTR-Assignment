// Attribute & Method Declaration for Inventory goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_INVENTORY_H
#define G8_TP060491_TP061069_TP055727_INVENTORY_H

#include <string>
#include <algorithm>
#include <iomanip>

class MovieList { //movieList

    /* Actual Object storing the information of each Movie */
    struct MovieNode{
        /* --- Movie Node: Attributes --------------------------------------------------------------------------------*/
        int movieID;
        std::string movieName;
        int moviePrice;
        int ticketQuantity;
        std::string movieCategory;
        std::string movieTime;

        /* --- Constructors for MovieNode ----------------------------------------------------------------------------*/
        // Default Constructor
        MovieNode();
        // Constructor for creating new Movies (Denoted as MovieNode)
        MovieNode(int movieID, std::string movieName, int moviePrice, std::string movieCategory,
                  std::string movieTime);
    };

/* --- MovieList: Attributes -----------------------------------------------------------------------------------------*/
    /* nodeCount records the number of nodes added to the Array. */
    int nodeCount;

    /* IDGenerator is used to generate the ID of newly created MovieNode. */
    int IDGenerator;

    /* Actual Array storing the collection of MovieNode. */
    MovieNode* movieList;

    /* Stores the list of available categories. */
    std::string categoryList[3] = {"Action","Comedy", "Horror"};

/* --- MovieList: Functional Methods [Private] -----------------------------------------------------------------------*/
    /* Method to prompt user to enter the details of a new movie and instantiates a new MovieNode.
     * Subsequently, this method calls the addMovie method to add the new Node into the Array. */
    void addMovie_prompt();
        /* Supportive Method to add new MovieNodes to the Array, movieList */
        void addMovie(MovieNode newNodes);

    /* Sort the List of Movies[Price, ID, Quantity]: QuickSort
     * sortMovie prompt user to choose a sorting method which will be passed as parameter into
     * quickSort, partition, swapNode */
    void sortMovie();
        // Support Method to swap the position of nodes or element in arrays
        void quickSort(MovieNode *IDs, int low, int high, int sortParameter);
        //
        int partition(MovieNode *IDs, int low, int high, int partitionType);
        void swapNode(MovieNode *elem1, MovieNode *elem2);
    //void addMovie(MovieNode newNodes);
    MovieNode* searchMovie();
    void deleteMovie();

    void updateMovie_prompt();
    void updateMovie(MovieNode* toUpdate);

    // Validation
    int validateInt();

public:
    /* Default Constructor for MovieList. */
    MovieList();

    /* Method to display Inventory Menu to users. This retains the ability to keep internal methods like sorting and
     * adding private. */
    void movieMenu();

    /* Method to exclusively list down *all* details pertaining to movie */
    void listMovies();

    /* Method to filter movie by its category.
     * Accepts a parameter called functionType which details whether this method is used to view all movies of a
     * category [Inventory] or to search and purchase movie based on its category [Transaction] */
    int filterMovie(std::string functionType);

    /* Method to deduct the quantity of movie based on user input on the index of Movie in MovieList. */
    void deductMovieQuantity(int index, int inputQuantity);

    /* Method to initialize the Inventory List. */
    void initializeList();

    /* Getters method to display movie information in Transaction when user is purchasing movie tickets. */
    int getMovieListNodeCount();
    std::string getMovieName(int index);
    int getMoviePrice(int index);
    int getTicketsLeft(int index);
    std::string getTime(int index);
};


#endif //G8_TP060491_TP061069_TP055727_INVENTORY_H
