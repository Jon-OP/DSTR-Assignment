// Attribute & Method Declaration for Transaction goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_TRANSACTION_H
#define G8_TP060491_TP061069_TP055727_TRANSACTION_H

#include <string>
#include "Inventory.h"

class Transaction{
    // Transaction Attributes
    int transactionID;
    std::string movieName;
    float totalPrice;
    int quantity;
    int seats;
    // Date and Time, do we include here ? - Jonathan

public:
    // Linked List implementation
    Transaction* nextNode = NULL;
    Transaction* previousNode = NULL;

    int getTransactionID();
    float getTransactionTotalPrice();

    void printAllDetails(int index);

    Transaction();
    Transaction(int ID, float totalPrice); // THIS WILL BE INSTANTIATION OF TRANSACTION WITH ALL ATTRIBUTES
    // Transaction Constructor with Param
    //Transaction()
};

// Transaction: will be the linked list
class TransactionList {
/* --- Linked List Attribute Implementation ------------------------------------------------------------------------- */
    Transaction* head;
    Transaction* tail; // Think about it

/* --- Private Linked List Implementation Methods ------------------------------------------------------------------- */

    // Inserting new transaction at the end
    //void insertTransactionToList(Transaction* transactionNode); // COMPLETED !!!

    // Return a transaction at the selected index
    void deleteTransaction(int index);

    // Delete a Transaction Detail
    Transaction* deleteTransaction();

    // Display the details of all Transaction and return the final index + 1
    int displayAllTransaction();

    // Sort the List of Transaction[TotalPrice]: MergeSort
    //void sortTransaction(std::string sortParameter); // COMPLETED !!!

        Transaction* mergeSort(Transaction* headNode, std::string sortParameter);

        // Split the List into Half
        Transaction* splitList(Transaction* headNode);

        // Merging two list
        Transaction* mergeList(Transaction* firstList, Transaction* secondList, std::string sortParameter);

/* --- Transaction Functions ---------------------------------------------------------------------------------------- */

    // Placing a new order
    void newPurchaseMenu(MovieList* movieList); // Prompt user to choose movie, ETC

        // Multiple Sub functions pertaining to newPurchase
        void newTransaction();

    // Sort all transaction
    void sortTransaction_prompt();

    // Prompt to Delete Transaction
    void deleteTransaction_prompt();

    // Prompt user to choose a transaction to view in detail
    void promptTransactionDetails();


    // Error validation
    int validateInteger(std::string msg);

    // TEST FUNCTION JONATHAN
    int validateInt();

public:
    // Constructor
    TransactionList();
    void transactionMenu(MovieList* movieList);

    void insertTransactionToList(Transaction* transactionNode);
    //void displayAllTransaction();
    void sortTransaction(std::string sortParameter);
};


#endif //G8_TP060491_TP061069_TP055727_TRANSACTION_H
