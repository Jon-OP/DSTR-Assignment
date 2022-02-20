// Attribute & Method Declaration for Transaction goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_TRANSACTION_H
#define G8_TP060491_TP061069_TP055727_TRANSACTION_H

#include <string>
#include "CDLinkedList.h"

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
    int getTransactionTotalPrice();

    void printSummaryDetails();
    void printAllDetails();

    Transaction();
    // Transaction Constructor with Param
};

// Transaction: will be the linked list
class TransactionList {
/* --- Linked List Attribute Implementation ------------------------------------------------------------------------- */
    Transaction* head;
    Transaction* tail; // Think about it

/* --- Private Linked List Implementation Methods ------------------------------------------------------------------- */

    // Link List Manipulation
        // Inserting new transaction at the end
    void insertTransactionToList(Transaction* transactionNode);

        // Return a transaction at the selected index
    Transaction* getTransaction(int index);

        // Display the high-level details of all transaction
    void displayAllTransaction();

        // Sort the List of Transaction[TotalPrice]: MergeSort
    void sortTransaction(std::string sortParameter);

        Transaction* mergeSort(Transaction* headNode, std::string sortParameter);

            // Split the List into Half
        Transaction* splitList(Transaction* headNode);

            // Merging two list
        Transaction* mergeList(Transaction* firstList, Transaction* secondList, std::string sortParameter);

/* --- Transaction Functions ---------------------------------------------------------------------------------------- */

    // Placing a new order
    void newPurchaseMenu(); // Prompt user to choose movie, ETC

        // Multiple Sub functions pertaining to newPurchase
        // HERE

    // Display high-level details of each transaction
    void listAllTransaction();

    // Sort all transaction
    void sortTransaction_prompt();


    // Error validation
    int validateInteger(std::string msg);

public:
    // Constructor
    TransactionList();

    void transactionMenu();

};


#endif //G8_TP060491_TP061069_TP055727_TRANSACTION_H
