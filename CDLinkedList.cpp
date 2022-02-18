// Implementation for Linked List Goes Here - Jonathan
// To enter the implementation, remember to add "CDLinkedList::<methodName>"

#include <iostream>

#include "CDLinkedList.h"
#include "Transaction.h"

// Class Instantiation
CDLinkedList::CDLinkedList() {
    this->head = NULL;
    this->tail = NULL;
}

// When user placed a new order which adds a new element to the Linked List
void CDLinkedList::insertTransaction(Transaction userTransaction) {
    // Declaring the new Transaction
    TransactionNode* newTransaction = new TransactionNode;
    newTransaction->data = userTransaction;

    // IF HEAD is empty...
    if(head == NULL){
        head = newTransaction;
        return;
    }

    // IF TAIL is empty...
    if(tail == NULL){
        tail = newTransaction;

        // Connecting HEAD to TAIL together like: -> HEAD <--> TAIL <-
        tail->nextNode = head;
        tail->previousNode = head;

        head->nextNode = tail;
        head->previousNode = tail;
        return;
    }

    // Else, HEAD and TAIL is not NULL.
    // 1. Setting nextNode[newTransaction] to point at HEAD
    newTransaction->nextNode = head;
    // 2. Setting previousNode[newTransaction] to point at TAIL
    newTransaction->previousNode = tail;
    // 3. Setting previousNode[HEAD] to point at newTransaction
    head->previousNode = newTransaction;
    // 4. Setting nextNode[TAIL] to point at newTransaction
    tail->nextNode = newTransaction;
    // 5. Updating newTransaction as the new TAIL
    tail = newTransaction;
}

// When user choose to see the intricate details of a transaction
Transaction CDLinkedList::searchTransaction(int index) {

}

// User wants to sort according to Total Price OR by ID
void CDLinkedList::sortTransaction() {

}

// System displays high-level details of each transaction which is indexed according
//  to the arrangement in the LinkedList
void CDLinkedList::displayAllTransaction() {
    // IF LinkedList is empty
    if(head == NULL){
        std::cout << "List is empty" << std::endl;
        return;
    }

    if(tail == NULL){
        std::cout << head->data.getMovieName() << std::endl;
        return;
    }

    TransactionNode* current = head;
    do{
        /*JONATHAN OWEN: WE CAN IMPLEMENT THE FORMATTED PRINTING FOR EACH
         * TRANSACTION DETAILS OVER HERE. MAKE SURE THE LAST LINE OF THIS BLOCK
         * IS CURRENT = CURRENT -> NEXT NODE;. THAT WILL BE ALL */
        std::cout << current->data.getMovieName() << " -> "; //REPLACEABLE STRING

        current = current->nextNode;
    }while(current != head);
}

