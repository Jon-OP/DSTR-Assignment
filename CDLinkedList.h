// Attribute & Method Declaration for Linked Lists goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_CDLINKEDLIST_H
#define G8_TP060491_TP061069_TP055727_CDLINKEDLIST_H

// Import Transaction Class
#include "Transaction.h"

// Transactional Nodes
struct TransactionNode{
    Transaction data;
    TransactionNode* nextNode;
    TransactionNode* previousNode;
};

// The Link List
class CDLinkedList {
    TransactionNode* head;

    // Initialization of Linked List
    CDLinkedList();

    // New Transaction
    // Inserting new transaction at the end
    void insertTransaction(Transaction userData);

    // Show Transaction Details
    // Searching transaction -> Returns one Transaction
    Transaction searchTransaction(int index);

    // Sorting the List of Transaction: MergeSort
    void sortTransaction();

    // Print all Transaction
    void displayAllTransaction();

};


#endif //G8_TP060491_TP061069_TP055727_CDLINKEDLIST_H
