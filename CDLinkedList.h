// Attribute & Method Declaration for Linked Lists goes here - Jonathan
// This is the Class Definition containing Method Prototypes/Interfaces

#ifndef G8_TP060491_TP061069_TP055727_CDLINKEDLIST_H
#define G8_TP060491_TP061069_TP055727_CDLINKEDLIST_H

// Import Transaction Class
#include "Transaction.h"

// Transactional Nodes
struct TransactionNode{
    Transaction data;
    TransactionNode* nextNode = NULL;
    TransactionNode* previousNode = NULL;
};

// The Link List
class CDLinkedList {
    TransactionNode* head;
    TransactionNode* tail;


public:
    int linkListSize;
    // Initialization of Linked List
    CDLinkedList();

    // New Transaction
    // Inserting new transaction at the end
    void insertTransaction(Transaction userData);

    // Show Transaction Details
    // Searching transaction -> Returns one Transaction
    Transaction searchTransaction(int index);

    //### This will be called in the Transaction CLASS ###
    // ### SUPPORTIVE FUNCTION TO MERGE SORT TRANSACTION LIST ### //
    // Sorting the List of Transaction[TotalPrice]: MergeSort
    TransactionNode* sortTransaction(std::string sortParameter);

    TransactionNode* mergeSort_Transaction(TransactionNode* headNode, std::string sortParameter);
    // Splitting the Linked List
    TransactionNode* splittingProcess(TransactionNode* headNode);//TransactionNode* head
    // firstNode = LEFT CDLL || secondNode = RIGHT CDLL
    TransactionNode* mergingProcess(TransactionNode* firstCDLL, TransactionNode* secondCDLL, std::string sortParameter);
    // ### END SUPPORTIVE FUNCTION TO MERGE SORT TRANSACTION LIST ### //


    // Print all Transaction
    void displayAllTransaction();

};


#endif //G8_TP060491_TP061069_TP055727_CDLINKEDLIST_H
