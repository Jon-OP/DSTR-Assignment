// Implementation for Linked List Goes Here - Jonathan
// To enter the implementation, remember to add "CDLinkedList::<methodName>"

#include <iostream>

#include "CDLinkedList.h"
#include "Transaction.h"

// Class Instantiation
CDLinkedList::CDLinkedList() {
    this->head = NULL;
    this->tail = NULL;
    linkListSize = 0;
}

// When user placed a new order which adds a new element to the Linked List
void CDLinkedList::insertTransaction(Transaction userTransaction) {
    // Declaring the new Transaction
    TransactionNode* newTransaction = new TransactionNode;
    newTransaction->data = userTransaction;

    // IF HEAD is empty...
    if(head == NULL){
        head = newTransaction;

        // Record the curent size of Link List
        linkListSize++;
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

        // Record the size of Link List
        linkListSize++;
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

    // Record the current size of link list
    linkListSize++;
}

// When user choose to see the intricate details of a transaction
// No error validation here as everything is accessed by Index
Transaction CDLinkedList::searchTransaction(int index) {
    TransactionNode* current = head;
    // Iterate through the Link List until the desired
    //  Index is reached
    while(index-1 > 0){
        current = current->nextNode;
        index--;
    }

    // RETURN THE ACTUAL Transaction Object and NOT the
    //  Node Pointer
    return current->data;

}

//void CDLinkedList:: LEFT OUT FIRST

// System displays high-level details of each transaction which is indexed according
//  to the arrangement in the LinkedList
void CDLinkedList::displayAllTransaction() {
    // IF LinkedList is empty
    if(head == NULL){
        std::cout << "List is empty" << std::endl;
        return;
    }

    if(tail == NULL){
        std::cout << head->data.getTransactionID() << std::endl;
        return;
    }

    TransactionNode* current = head;
    do{
        /*JONATHAN OWEN: WE CAN IMPLEMENT THE FORMATTED PRINTING FOR EACH
         * TRANSACTION DETAILS OVER HERE. MAKE SURE THE LAST LINE OF THIS BLOCK
         * IS CURRENT = CURRENT -> NEXT NODE;. THAT WILL BE ALL */
        std::cout << current->data.getTotalPrice() << " -> "; //REPLACEABLE STRING

        current = current->nextNode;
    }while(current != head);
}

// User wants to sort according to Total Price OR by ID
// sortParameter = {ID, totalPrice}

TransactionNode* CDLinkedList::sortTransaction(std::string sortParameter) {
    // Break the Circular Link to prevent infinite recursion
    head->previousNode = NULL;
    tail->nextNode = NULL;

    // UPDATE the HEAD to point to the NEW FIRST NODE after sorting
    head = mergeSort_Transaction(head, sortParameter);

    // Restore the Circular Link to achieve Circular Doubly Linked List status
    head->previousNode = tail;
    tail->nextNode = head;

    return NULL;

}

TransactionNode* CDLinkedList::mergeSort_Transaction(TransactionNode *headNode, std::string sortParameter) {
    // IF headNode == NULL OR headNode-> nextNode == NULL, then return and end the recursion
    if(!headNode || !headNode->nextNode){
        return headNode;
    }

    // Split the Link List into two halves, and assign the right half to rightCDLL
    TransactionNode* rightCDLL = splittingProcess(headNode);

    // Recursion Calling of mergeSort_Transaction to further split CDLL into smaller nodes
    headNode = mergeSort_Transaction(headNode, sortParameter);
    rightCDLL = mergeSort_Transaction(rightCDLL, sortParameter);



    // Return the Linked List sorted using mergingProcess
    return mergingProcess(headNode, rightCDLL, sortParameter);

}

TransactionNode* CDLinkedList::splittingProcess(TransactionNode *headNode) {

    // Follow the Fast-Slow Pointer strategy to find Midpoint of Linked List
    TransactionNode* fastPointer = headNode;
    TransactionNode* slowPointer = headNode;

    while(fastPointer->nextNode && fastPointer->nextNode->nextNode){
        // slowPointer Traverse 1 Node at a time
        // fastPointer Traverse 2 Nodes at a time
        slowPointer = slowPointer->nextNode;
        fastPointer = fastPointer->nextNode->nextNode;
    }

    // The sub-LinkedList starts after the slowPointer
    TransactionNode* rightCDLL = slowPointer->nextNode;

    // Disconnect right sub-LinkedList from the head
    slowPointer->nextNode = NULL;

    return rightCDLL;


}

TransactionNode* CDLinkedList::mergingProcess(TransactionNode *firstCDLL, TransactionNode *secondCDLL,
                                              std::string sortParameter) {
    // IF firstCDLL is EMPTY, return secondCDLL
    if(!firstCDLL){
        return secondCDLL;
    }

    // IF secondCDLL is EMPTY, return firstCDLL
    if(!secondCDLL){
        return firstCDLL;
    }

    // Both firstCDLL and secondCDLL have values
    // User SORTS by ID
    if(sortParameter == "ID"){

        // Data value of firstCDLL is lesser than secondCDLL
        if(firstCDLL->data.getTransactionID() < secondCDLL->data.getTransactionID()){

            // RECURSIVELY call Merge to find the next value (Ascending order)
            firstCDLL->nextNode = mergingProcess(firstCDLL->nextNode, secondCDLL, sortParameter);

            // firstCDLL[nextNode] points to adjacentNode. But adjacentNode[previousNode] is not pointing to firstCDLL
            firstCDLL->nextNode->previousNode = firstCDLL;

            // firstCDLL[currentNode] is the current HEAD in this sub-linked list. Set firstCDLL[previousNode] to NULL
            firstCDLL->previousNode = NULL;

            while(tail->nextNode != NULL){
                tail = tail->nextNode;
            }

            return firstCDLL;

        }else{

            // Data value of secondCDLL is lesser than firstCDLL
            secondCDLL->nextNode = mergingProcess(firstCDLL, secondCDLL->nextNode, sortParameter);

            // secondCDLL[nextNode] points to adjacentNode. But adjacentNode[previousNode] is not pointing to secondCDLL
            secondCDLL->nextNode->previousNode = secondCDLL;

            // secondCDLL[currentNode] is the current HEAD of this sub-linked list. Set secondCDLL[previousNode] to NULL
            secondCDLL->previousNode = NULL;

            while(tail->nextNode != NULL){
                tail = tail->nextNode;
            }

            return secondCDLL;
        }
    }
    else{
        // User sort by Total Price
        if(sortParameter == "totalPrice"){
            // Data value of firstCDLL is lesser than secondCDLL
            if(firstCDLL->data.getTotalPrice() < secondCDLL->data.getTotalPrice()){

                // RECURSIVELY call Merge to find the next value (Ascending order)
                firstCDLL->nextNode = mergingProcess(firstCDLL->nextNode, secondCDLL, sortParameter);

                // firstCDLL[nextNode] points to adjacentNode. But adjacentNode[previousNode] is not pointing to firstCDLL
                firstCDLL->nextNode->previousNode = firstCDLL;

                // firstCDLL[currentNode] is the current HEAD in this sub-linked list. Set firstCDLL[previousNode] to NULL
                firstCDLL->previousNode = NULL;

                while(tail->nextNode != NULL){
                    tail = tail->nextNode;
                }

                return firstCDLL;

            }else{

                // Data value of secondCDLL is lesser than firstCDLL
                secondCDLL->nextNode = mergingProcess(firstCDLL, secondCDLL->nextNode, sortParameter);

                // secondCDLL[nextNode] points to adjacentNode. But adjacentNode[previousNode] is not pointing to secondCDLL
                secondCDLL->nextNode->previousNode = secondCDLL;

                // secondCDLL[currentNode] is the current HEAD of this sub-linked list. Set secondCDLL[previousNode] to NULL
                secondCDLL->previousNode = NULL;

                while(tail->nextNode != NULL){
                    tail = tail->nextNode;
                }

                return secondCDLL;
            }
        }
    }



}

/*
TransactionNode* CDLinkedList::sortTransaction(std::string sortParameter) {
    head->previousNode = NULL;
    tail->nextNode = NULL;
    head = mergeSort_Transaction(head, "aaa");

    if(head == NULL){
        std::cout << "WHY";
    }

    /*
    TransactionNode* current = head;
    do{
        std::cout << current->data.getTransactionID();
        current = current->nextNode;
    }while(current != NULL);

}

TransactionNode* CDLinkedList::mergeSort_Transaction(TransactionNode* headNode, std::string sortParameter){
    // IF the HEAD is not NULL OR next HEAD is not NULL, continue
    if(headNode == NULL || headNode->nextNode == NULL){
        std::cout << "A";
        return headNode;
    }

    // Split the Linked List
    TransactionNode* rightCDLL = splittingProcess(headNode);

    // Recursion to further decompose the CDLL
    // headNode = mergeSort_Transaction(headNode, sortParameter);
    rightCDLL = mergeSort_Transaction(rightCDLL, sortParameter);

    //std::cout << head->data.getTransactionID();


    //return NULL;
    return mergingProcess(headNode, rightCDLL, sortParameter);

}

TransactionNode* CDLinkedList::mergingProcess(TransactionNode* firstCDLL, TransactionNode* secondCDLL, std::string sortParameter){
    // First CDLL is empty
    if(firstCDLL == NULL){
        return secondCDLL;
    }

    // Second CDLL is empty
    if(secondCDLL == NULL){
        return firstCDLL;
    }

    // Both CDLL are not empty
    // Sorting Parameter = ID
    if(sortParameter == "ID"){
        // First CDLL is smaller
        if(firstCDLL->data.getTransactionID() < secondCDLL->data.getTransactionID()){
            // Recursive mergingProcess until 1:1 comparison / Individual Comparison
            firstCDLL->nextNode = mergingProcess(firstCDLL->nextNode, secondCDLL, sortParameter);

            // Set the 2nd Node previousNode value to firstCDLL
            firstCDLL->nextNode->previousNode = firstCDLL;

            // firstCDLL is the first element. Set the previous to NULL first
            firstCDLL->previousNode = NULL;

            return firstCDLL;
        }
        else{ // Second CDLL is smaller
            // Recursive mergingProcess until 1:1 comparison / Individual Comparison
            secondCDLL->nextNode = mergingProcess(firstCDLL, secondCDLL->nextNode, sortParameter);

            // Set the 2nd Node previousNode value to second CDLL
            secondCDLL->nextNode->previousNode = secondCDLL;

            // secondCDLL is the first element. Set the previous to NULL first
            secondCDLL->previousNode = NULL;

            return secondCDLL;
        }
    }


}

// Process of Splitting the Doubly Linked List to two Lists
TransactionNode* CDLinkedList::splittingProcess(TransactionNode* headNode) {
    // Splitting the Node using Fast-Slow pointer strategy
    TransactionNode* slowPointer = headNode;
    TransactionNode* fastPointer = headNode; //ERROR HERE

    // Continue Iteration until fastPointer -> nextNode AND fastPointer -> nextNode -> nextNode is NOT NULL
    while(fastPointer->nextNode && fastPointer->nextNode->nextNode){
        slowPointer = slowPointer->nextNode;
        fastPointer = fastPointer->nextNode->nextNode;
    }

    // Return the pointer for the second half which is the right side
    TransactionNode* rightCDLL = slowPointer->nextNode;

    // Disconnect the leftCDLL from the rightCDLL
    slowPointer->nextNode = NULL;
    //rightCDLL->previousNode = NULL;

    /*
    std::cout << "RIGHT CDLL: ";
    TransactionNode* cx = rightCDLL;
    do{
        std::cout << cx->data.getTransactionID();
        cx = cx->nextNode;
    }while(cx != NULL);
    std::cout << '\n';

    std::cout << "LEFT CDLL OR HEAD: ";
    cx = headNode;
    do{
        std::cout << cx->data.getTransactionID();
        cx = cx->nextNode;
    }while(cx != NULL);
    std::cout << '\n';
    return rightCDLL;
}
*/
