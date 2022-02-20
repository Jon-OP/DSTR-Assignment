// Implementation for Transaction Goes Here - Jonathan
// To enter the implementation, remember to add "Transaction::<methodName>"

#include "Transaction.h"
#include <iostream>

int userChoice;

/* --- Transaction: METHODS ------------------------------------------------------------------------------------------*/

// Methods: CONSTRUCTOR
    // Default Constructor
Transaction::Transaction() {};

    // Primary Constructor
Transaction::Transaction(int ID, int TOTALPRICE) {

};

// Methods: FUNCTIONAL
    // Print some basic details regarding one Transaction
void Transaction::printSummaryDetails(int index) {
    std::cout << index << "\t|  ID:" << transactionID << "\t|  Price:" << totalPrice << std::endl;
}// PRINT MOVIE NAME ALSO !! @PHILIP

// Methods: GETTERS
    // Get the Transaction ID
int Transaction::getTransactionID() {
    return  this->transactionID;
}

    // Get the Total Price
float Transaction::getTransactionTotalPrice() {
    return this->totalPrice;
}

/* --- TransactionList: METHODS --------------------------------------------------------------------------------------*/





/* --- Linked List Functions ---------------------------------------------------------------------------------------- */

// Methods: CONSTRUCTOR
    // Default Constructor
TransactionList::TransactionList() {
    head = NULL;
    tail = NULL;
};


// Methods: LINK LIST MANIPULATION

    // Inserting new transaction at the end
void TransactionList::insertTransactionToList(Transaction* newTransaction){
    // HEAD Node is EMPTY . . .
    if(head == NULL){
        head = newTransaction;

        return;
    }

    // TAIL Node is EMPTY . . .
    if(tail == NULL){
        tail = newTransaction;

        // Connecting HEAD to TAIL like: -> HEAD <--> TAIL <-
        tail->nextNode = head;
        tail->previousNode = head;

        head->nextNode = tail;
        head->previousNode = tail;
        return;
    }

    // HEAD and TAIL is not NULL
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
    // No error validation here as everything is accessed by Index
    // Return a transaction at the selected index
Transaction* TransactionList::getTransaction(int index) {
    Transaction* current = head;

    // Iterate through the Link List until the desired Index is obtained
    while(index - 1 < 0){
        current = current->nextNode;
        index--;
    }

    // Return the Transaction
    return current;
}

    // Display the high-level details of all transaction
void TransactionList::displayAllTransaction() {
    // IF LinkedList is empty
    if(head == NULL){
        std::cout << "List is empty" << std::endl;
        return;
    }

    // There is only one Item in LinkedList
    if(tail == NULL){
        head->printSummaryDetails(1);
        return;
    }

    Transaction* current = head;
    int index = 1;
    do{
        // Print the details
        current->printSummaryDetails(index);

        // Move to the next node
        current = current->nextNode;
        index++;
    }while(current != head);
}

    // Sort the List of Transaction[TotalPrice]: MergeSort
    // sortParameter = { "ID", "TOTALPRICE" }
void TransactionList::sortTransaction(std::string sortParameter) {
    // Convert Circular Doubly Linked List to Doubly Linked List
    head->previousNode = NULL;
    tail->nextNode = NULL;

    // Call the Merge-Sort Algorithm
    // UPDATE the HEAD to point at the NEW FIRST NODE after sorting
    head = mergeSort(head, sortParameter);

    // Restore the Circular Link
    head->previousNode = tail;
    tail->nextNode = head;
}

    // Implementation of Merge Sort
    Transaction* TransactionList::mergeSort(Transaction *headNode, std::string sortParameter) {
        // IF headNode == NULL OR headNode->nextNode == NULL, then END the recursion
        if(!headNode || !headNode->nextNode){
            return headNode;
        }

        // Split the Link List into two halves, and assign the right half to rightCDLL
        Transaction* rightCDLL = splitList(headNode);

        // Recursion Calling of mergeSort to further split CDLL into smaller list
        headNode = mergeSort(headNode, sortParameter);
        rightCDLL = mergeSort(rightCDLL, sortParameter);

        // Return the Linked List sorted using mergeList
        return mergeList(headNode, rightCDLL, sortParameter);
    }

    // Split the List into Half
    Transaction* TransactionList::splitList(Transaction *headNode) {
        // Follow the Fast-Slow Pointer Strategy and find the Midpoint of the List
        Transaction* slowPointer = headNode;
        Transaction* fastPointer = headNode;

        while(fastPointer->nextNode && fastPointer->nextNode->nextNode){
            // slowPointer Traverse 1 Node at a time
            // fastPointer Traverse 2 Nodes at a time
            slowPointer = slowPointer->nextNode;
            fastPointer = fastPointer->nextNode->nextNode;
        }

        // The Second Linked-List starts after the slowPointer
        Transaction* rightCDLL = slowPointer->nextNode;

        // Disconnect the Second Link List from the head
        slowPointer->nextNode = NULL;

        return rightCDLL;
    }

    // Merging two list
    Transaction* TransactionList::mergeList(Transaction *firstList, Transaction *secondList, std::string sortParameter) {
    // IF firstList is empty, then return secondList
    if(!firstList){
        return secondList;
    }

    // IF secondList is empty, then return firstList
    if(!secondList){
        return firstList;
    }

    // BOTH firstList and secondList have values
    // User Sorts by ID:
    if(sortParameter == "ID"){

        // ID of firstList is LESSER than secondList
        if(firstList->getTransactionID() < secondList->getTransactionID()){

            // RECURSIVELY call mergeList to find next value (ASCENDING ORDER)
            firstList->nextNode = mergeList(firstList->nextNode, secondList, sortParameter);

            // firstList[nextNode] points to adjacentNode. But adjacentNode[previousNode] is not pointing at firstList
            firstList->nextNode->previousNode = firstList;

            // firstList[currentNode] is the current HEAD in this sub-linked list. Set firstList[previousNode] to NULL
            firstList->previousNode = NULL;

            // Updating the value of TAIL
            while (tail->nextNode != NULL){
                tail = tail->nextNode;
            }

            return firstList;

        }else{

            // Data value of secondList is lesser than firstList
            secondList->nextNode = mergeList(firstList, secondList->nextNode, sortParameter);

            // secondList[nextNode] points to adjacentNode. But adjacentNode[previousNode] is not pointing to secondList
            secondList->nextNode->previousNode = secondList;

            // secondList[currentNode] is the current HEAD of this sub-linked list. Set secondList[previousNode] to NULL
            secondList->previousNode = NULL;

            // Updating the value of TAIL
            while(tail->nextNode != NULL){
                tail = tail->nextNode;
            }
            return secondList;
        }
    }else{

        // User sort by TOTALPRICE
        if(sortParameter == "TOTALPRICE"){
            // Total Price of firstList is lesser than secondList

            //if(firstList->getTransactionTotalPrice() < secondList->getTransactionTotalPrice()){
            if(firstList->getTransactionTotalPrice() < secondList->getTransactionTotalPrice()){

                // RECURSIVELY call mergeList to find the next value (ASCENDING ORDER)
                firstList->nextNode = mergeList(firstList->nextNode, secondList, sortParameter);

                // firstList[nextNode] points to adjacentNode. But adjacentNode[previousNode] is not pointing at firstList
                firstList->nextNode->previousNode = firstList;

                // firstList[currentNode] is the current HEAD in this sub-linked list. Set firstList[previousNode] to NULL
                firstList->previousNode = NULL;

                // Update the value of TAIL
                while(tail->nextNode != NULL){
                    tail = tail->nextNode;
                }
                return firstList;
            }else{

                // Total Price of secondList is lesser than firstList
                secondList->nextNode = mergeList(firstList, secondList->nextNode, sortParameter);

                // secondList[nextNode] point to adjacentNode
                // But adjacentNode[previousNode] is not pointing at secondList
                secondList->nextNode->previousNode = secondList;

                // secondList[currentNode] is the current HEAD if this sub-linked list
                // Set secondList[previousNode] to NULL
                secondList->previousNode = NULL;

                // Update the value of TAIL
                while(tail->nextNode != NULL){
                    tail = tail->nextNode;
                }
                return secondList;
            }
        }
    }
}

// METHODS: FUNCTIONAL


/*
// Transaction menu landing page implementation - Philip
void TransactionList::transactionMenu(){

    //stdlib::system ("CLS"); was testing with clearing screen

//Code section with reused input validation component
    std::string transactionMenuMsg = "\tTransaction Management Menu\n"
                                   "\t---------------------------\n"
                                   "\t1. Place a new purchase\n"
                                   "\t2. View All Purchases\n"
                                   "\t3. Sort Purchases\n"
                                   "\t4. View Purchase Details\n" // remove
                                   "\t5. Return to Main Menu\n"
                                   "\n\t>> Enter your choice:";
    int userChoice;
    while (true){
        userChoice = validateInteger(transactionMenuMsg);
        switch (userChoice) {
            case 1:
                newPurchaseMenu(); //call function for creation of new purchase
                break;
            case 2:
                viewPurchase();
                break;
            case 3:
                //placeholder for sort purchase
                break;
            case 4:
                //placeholder for view purchase details
                break;
            case 5:
                return;
            default:
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 5\n\t>> Enter any Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore(10000, '\n');
                break;
        }
    }
}

void viewPurchases()
{
    CDLinkedList cd = CDLinkedList();
    cd.displayAllTransaction();
}

void Transaction::newPurchaseMenu()
{
    std::string newPurchaseMenuMsg = "\tCreating new purchase\n"
                                     "\t---------------------\n"
                                     "\t1. View All Product\n"
                                     "\t2. Search Product by Category\n"
                                     "\t3. Checkout cart\n"
                                     "\t4. Return to previous menu\n"
                                     "\n\t>> Enter your choice:";

    int userChoice;
    while (true){
        userChoice = validateInteger(newPurchaseMenuMsg);
        switch (userChoice) {
            case 1:
                //placeholder for View All Product(CALL FROM - I) > WHICH MOVIE DO YOU WANT() > WHICH SEAT YOU WANT > CONFIRM > CREATE PURCHASE(TRANS OBJ) > ADD TO LINKED LIST
                break;
            case 2:
                // placeholder for Search Product by Category
                break;
            case 3:
                //placeholder for Checkout cart
                break;
            case 4:
                return;
            default:
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 7\n\t>> Enter any Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
        }
    }

}
void newTransaction()
{
    CDLinkedList cd = CDLinkedList();
    Transaction userTransaction = Transaction(); //include user input details on purchase as parameters
    cd.insertTransaction(userTransaction);
}



// Error Validation Method
int TransactionList::validateInteger(std::string message){
    bool inputFlag;
    std::string userInput;
    int sanitizedInput;
    while(true){
        // Display message <- I want to change. IDW USE STD::COUT
        std::cout << std::string(3, '\n') << message;

        // Get User Input as String
        std::getline(std::cin, userInput);

        // User entered newLine which is consumed by getLine(). Hence, length = 0
        if(!(userInput.length() == 0)){
            // Flag to check if non-digit exists
            bool isDigit = true;

            for(int i = 0; i < userInput.length(); i++){
                if( !(isdigit(userInput[i])) ){
                    isDigit = false;
                }
            }

            // True = all char in string is digit.
            if(isDigit){
                return std::stoi(userInput);
            }
        }

        // Print error message and prompt user to enter any key to continue
        std::cout << "\n\t>> ERROR: Invalid Input\n\t>> Please enter numbers.\n\t>> Enter a Key to continue:";

        // Wait for user Input and ignore up to 10,00 characters
        std::cin.ignore( 10000, '\n');
    }
}



//getter to display all transactions
std::string Transaction::getDetails()
{
    std::string transID = std::to_string(this->transactionID);
    std::string totalPrice = std::to_string(this->totalPrice);
    std::string quantity = std::to_string(this->quantity);
    std::string seats = std::to_string(this->seats);

    return transID +"\t"+movieName+ "\t"+ quantity + "\t"+ totalPrice + "\t"+ seats;
}


//functions to add
    //function to check last transaction ID -> so we can add it into the userTransaction object
    //

*/