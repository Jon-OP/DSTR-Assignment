#ifndef G8_TP060491_TP061069_TP055727_TRANSACTION_H
#define G8_TP060491_TP061069_TP055727_TRANSACTION_H

#include <string>
#include "Inventory.h"
#include <iostream>

class Transaction{
/* --- Transaction: Attributes ---------------------------------------------------------------------------------------*/
    int transactionID;
    std::string movieName;
    int totalPrice;
    int quantity;
    std::string movieTime;

public:
/* --- Transaction: Linked List Attributes ---------------------------------------------------------------------------*/
    Transaction* nextNode = NULL;
    Transaction* previousNode = NULL;

/* --- Transaction: Functional Methods -------------------------------------------------------------------------------*/
    void printAllDetails(int index);

/* --- Transaction: Getters ------------------------------------------------------------------------------------------*/
    int getTransactionID();
    int getTransactionTotalPrice();

/* --- Transaction: Constructor --------------------------------------------------------------------------------------*/
    // Default Constructor
    Transaction();
    // Constructor for creating new transactions
    Transaction(int transactionID, std::string movieName, int totalPrice, int quantity, std::string movieTime);

};

/* TransactionList is a Circular Doubly Linked List that stores Transactions as nodes of a Linked List  */
class TransactionList {
/* --- Transaction List: Private Attributes --------------------------------------------------------------------------*/
    /* Linked List Attributes utilized locally for each instantiation of Transaction List */
    Transaction* head;
    Transaction* tail;

    /* Attribute used to generate ID incrementally for every addition of Transaction to TransactionList */
    int transactionIDGenerator = 1;

/* --- Transaction List: Functional Methods --------------------------------------------------------------------------*/
    /* Method to prompt users to choose their desired Movie and instantiating a new Transaction object that is passed
     *  to the supportive function, insertTransactionToList
     * This method has a Time Complexity of 0(1) as it appends Nodes to the end of Transaction List*/
    void newPurchaseMenu(MovieList* movieList);
        /* Supportive Function to add Transaction to Transaction List*/
        void insertTransactionToList(Transaction* transactionNode); // COMPLETED !!!

    /* Method to delete a Transaction Object from the by traversing the until the pointer reaches the desired index.
     * This Operation has a Time Complexity of a 0(n) */
    void deleteTransaction(int index);

    /* Method to Display all Transactions stored in the Transaction List and to return the Number of Nodes + 1 */
    int displayAllTransaction();


    /* Prompt user to choose a method to sort Transaction Information. */
    void sortTransaction_prompt();

    // Sort the List of Transaction[TotalPrice]: MergeSort
    /* Method to Sort the List according to the parameter (sortParameter). Users are able to sort by TransactionID and
     * by totalPrice of each transaction. The sorting algorithm employed is the MergeSort algorithm which has a Time
     * Complexity of 0(n log(n)) */
    void sortTransaction(std::string sortParameter);

        //Supporting Method to recursively call splitList and returns a mergeList
        Transaction* mergeSort(Transaction* headNode, std::string sortParameter);

        // Support Method to split the linked list into half
        Transaction* splitList(Transaction* headNode);

        // Compare the value of two nodes, arranging the nodes according to ascending value, then return the merged list
        Transaction* mergeList(Transaction* firstList, Transaction* secondList, std::string sortParameter);

    /* Prompt user to select and delete a Transaction. */
    void deleteTransaction_prompt();

    /* Method to validate integers by reading user input as a string, then iterate the string while checking for
     * non-digit values. If user input does not consist of only digits, the function returns -999. Else, the
     * method parses the string to integer and returns to the user. */
    int validateInt();

public:
    /* Default Constructor for TransactionList. */
    TransactionList();

    /* Method to display Transaction Menu to users. This retains the ability to keep internal methods like
     * sorting and adding private. Additionally, this method requires the list of Movies as an argument.*/
    void transactionMenu(MovieList* movieList);

    /* Method to initialize the transaction list. Each transaction in this method deducts the quantity from
     * movieList. */
    void initializeTransactionList(MovieList movieList);
};


#endif //G8_TP060491_TP061069_TP055727_TRANSACTION_H
