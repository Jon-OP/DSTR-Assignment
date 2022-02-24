#include "Transaction.h"
#include "Inventory.h"

/* --- Transaction ---------------------------------------------------------------------------------------------------*/


/* Method to print the details of a transaction */
void Transaction::printAllDetails(int index) {
    std::cout << "\t" << index << ".\t"
              << std::left << std::setw(14) << transactionID <<"\t"
              << std::left << std::setw(16) << movieName <<"\t"
              << std::right << totalPrice
              << std::right << std::setw(10)<< quantity << "\t"
              << std::right << std::setw(12)<< movieTime <<"\n";
}


/* Getters for transaction details like ID and total price */
int Transaction::getTransactionID() {
    return  this->transactionID;
}

int Transaction::getTransactionTotalPrice() {
    return this->totalPrice;
}


// Transaction: Constructor
Transaction::Transaction() {};

Transaction::Transaction(int transactionID, std::string movieName, int totalPrice, int quantity, std::string movieTime) {
    this->transactionID = transactionID;
    this->movieName = movieName;
    this->totalPrice = totalPrice;
    this->quantity = quantity;
    this->movieTime = movieTime;
}

/* --- TransactionList [Private] -------------------------------------------------------------------------------------*/
/* Method and Supporting Methods to placing a new purchase / adding new transaction */
void TransactionList::newPurchaseMenu(MovieList* movieList)
{
    while (true){
        std::cout << "\n\t---------------------------------------------------------\n"
                     "\t                   Creating new purchase                 \n"
                     "\t-*-------------------------------*-----------------------\n"
                     "\t-|1. View All Product            |-----------------------\n"
                     "\t-|2. Filter for Product          |-----------------------\n"
                     "\t-|3. Return to previous menu     |-----------------------\n"
                     "\t-*-------------------------------*-----------------------\n"
                     "\t>> Enter your choice:";

        int userChoice = validateInt();
        int userIndex = 0;

        switch (userChoice) {
            case 1: {
                std::cout << "\n\t---------------------------------------------------------------------------------------------------\n"
                             "\t                                       Which movie to be purchased?                                 \n"
                             "\t---------------------------------------------------------------------------------------------------\n";
                movieList->listMovies();
                std::cout << "\n\t-------------------------------------------------------------------------------------------------\n"
                             "\t>>Select the index of the movie [0 to return]:";
                userIndex = validateInt();
                int maxIndex = movieList->getMovieListNodeCount();

                if (userIndex == 0)
                {
                    return;
                }
                else if (userIndex > 0 && userIndex < maxIndex){
                    break;
                }
                else if(userIndex<1 || userIndex> maxIndex)
                {
                    std::cout << "\n\t>> There is no such index. Enter 1 to" << maxIndex <<
                              ".\n\t>> Enter any Key to retry:";
                    break;
                }
                else if (userIndex == -999) {
                    std::cout << "\n\t>>Invalid input entered. Enter 1 to " << maxIndex <<
                              ".\n\t>>Enter any Key to retry:";
                    break;
                }
            }
            case 2:
                userIndex = movieList->filterMovie("TRANSACTION");
                break;
            case 3:
                std::cout << "\n\t>> Returning to Transaction Menu."
                             "\n\t>> Enter any key to continue:";

                std::cin.ignore(10000,'\n');

                return;
            case -999:
                std::cout << "\n\t>> ERROR: Please enter an Index.\n"
                             "\t>> Press any key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
            default:
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 7\n\t>> Enter any Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
        }

        if(userIndex != 0){
            std:: cout<<"\n\tSelected movie:" <<movieList->getMovieName(userIndex-1) << "\tQuantity:"<<movieList->getTicketsLeft(userIndex-1) ;
            std::cout<<"\n\n\t>>How many tickets to purchase:";
            int userQuantity = validateInt();
            if (userQuantity == -999) {
                std::cout << "\n\tInvalid input entered. Enter an integer value." <<
                          ".\n\tEnter any Key to retry:";
                break;
            }
            if (userQuantity> movieList->getTicketsLeft(userIndex-1))
            {
                std::cout<<"\n\tInsufficient ticket(s). Try again\n";
                break;
            }
            std::cout<<"\n\tYour order:\n\t"
                     << "Movie Name: "<< movieList->getMovieName(userIndex-1)
                     << "\n\tQuantity to be purchased: "<< userQuantity
                     << " \n\tPrice to be paid: "<< movieList->getMoviePrice(userIndex-1)*userQuantity;

            std::cout<<"\n\n\t>>Confirming purchase. Do you wish to proceed?"
                     <<"\n\t>>Enter [1] to proceed; any irrelevant key to abort operation:";
            userChoice = validateInt();
            if (userChoice == 1)
            {
                movieList->deductMovieQuantity(userIndex,userQuantity);

                //Transaction:: Transaction(int transID, std::string movieName, int sum, int quantityBought)
                Transaction* newTrans = new Transaction(transactionIDGenerator++, movieList->getMovieName(userIndex-1),movieList->getMoviePrice(userIndex-1)*userQuantity,userQuantity, movieList->getTime(userIndex-1));
                insertTransactionToList(newTrans);
                std::cout <<"\n\t>>Purchase created successfully. ";
                return;
            }
            else {
                std::cout << "\n\t>>Purchase operation aborted. ";
                return;
            }
        }
    }

}

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


/* Method to delete Transaction from TransactionList */
void TransactionList::deleteTransaction_prompt(){
    while(true){
        int lastIndex = displayAllTransaction();

        std::cout << "\t" << lastIndex << ". Return to Transaction Menu\n\n"
                                          "\t>> Enter the index of transaction to delete.\n\t>> Enter your choice:";

        int userChoice = validateInt();

        // 1. Error validation where userChoice == -999
        if(userChoice == -999){
            std::cout << "\n\tERROR: Please enter an Index.\n"
                         "\tPress any key to continue:";

            // Wait for user Input and ignore up to 10,00 characters
            std::cin.ignore( 10000, '\n');
        }else{
            // 2. User enters the exit index which is lastIndex
            if(userChoice == lastIndex){
                break;
            }
            else{
                // User chose a transaction to delete
                if(userChoice > 0 && userChoice < lastIndex){
                    std::cout << "\n\t>> DISCLAIMER: Transaction Data and ID is irrecoverable once deleted.\n"
                                 "\t>> Confirm your deletion by entering \"DELETE\"."
                                 "\t>> Entering other value returns you to Transaction Menu\n"
                                 "\t>> Enter your choice:";

                    std::string userConfirmation;
                    std::getline(std::cin, userConfirmation);
                    // User entered "DELETE"
                    if(userConfirmation == "DELETE"){
                        deleteTransaction(userChoice);
                        std::cout << "\n\tTransaction deleted. Returning to Transaction Menu.";
                        break;
                    }else{
                        // User did not enter "DELETE" and deletion process halts
                        std::cout << "\n\t>> Returning to Transaction Menu";
                        break;
                    }

                }else{
                    std::cout << "\n\tERROR: Please enter an Index between 1 and " << lastIndex << ".\n"
                                                                                                   "\t>> Press any key to continue:";

                    // Wait for user Input and ignore up to 10,00 characters
                    std::cin.ignore( 10000, '\n');
                }
            }
        }
    }
}

void TransactionList::deleteTransaction(int index) {
    Transaction* current = head;

    // Iterate through the Link List until the desired Index is obtained
    while(index - 1 > 0){
        current = current->nextNode;
        index--;
    }

    // Deletion
    // EX: A <--> Current <--> B
    // A -> B: Set [nextNode]A to point at B
    current->previousNode->nextNode = current->nextNode;
    // A <- B: Set [previousNode]B to point at A
    current->nextNode->previousNode = current->previousNode;

    // Check if HEAD or TAIL is deleted.
    if(current == head){
        head = current->nextNode;
    }else{
        if(current == tail){
            tail = current->previousNode;
        }
    }

    // Deallocate the current from memory
    delete current;
    current = nullptr;
    return;
}


/* Method to display the details of all Transactions */
int TransactionList::displayAllTransaction() {
    // IF LinkedList is empty
    int index = 1;
    if(head == NULL){
        std::cout << "List is empty" << std::endl;
        return index;
    }

    // There is only one Item in LinkedList
    if(tail == NULL){
        head->printAllDetails(1);
        index++;
        return index;
    }

    // Print Banner
    std::cout << "\n\t----------------------------------------------------------------------------\n"
                 "\t\t\t\t\tList of Transactions\n"
                 "\t----------------------------------------------------------------------------\n\t"
              <<"Index"
              << "\tTransaction ID"
              << "\tMovie Name"
              << std::left<<"\t   Price(RM)"
              <<std::left<<"\tQuantity"
              <<std::left<<"\tTime\n";

    Transaction* current = head;
    do{
        // Print the details
        current->printAllDetails(index);

        // Move to the next node
        current = current->nextNode;
        index++; // Index returned is size of list + 1 because of DoWhile
    }while(current != head);
    std::cout << "\t----------------------------------------------------------------------------\n";
    return index;
}


/* Method and Supporting Methods to sort Transaction by ID and total price using Merge Sort */
void TransactionList::sortTransaction_prompt() {
    while(true){
        std::cout <<"\n\t---------------------------------------------------------"
                    "\n\t            Select a transactions sorting mode\n"
                    "\t-*----------------------------*--------------------------\n"
                    "\t-|1. ID                       |--------------------------\n"
                    "\t-|2. Total Price              |--------------------------\n"
                    "\t-|3. Return to previous menu  |--------------------------\n"
                    "\t-*----------------------------*--------------------------\n"
                    "\t>> Enter your choice:";
        int userChoice = validateInt();

        switch(userChoice){
            case 1:
                sortTransaction("ID");
                return;
            case 2:
                sortTransaction("TOTALPRICE");
                return;
            case 3:
                return;
            case -999:
                std::cout << "\n\tERROR: Please enter an Index.\n"
                             "\tPress any key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;

            default:
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> Invalid Input\n\t>> Please enter index from 1 to 3\n\t>> Enter any Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
        }
    }
}

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

        // Total Price of firstList is lesser than secondList
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


/* Method to ensure user enters integers */
int TransactionList::validateInt() {
    // Read userInput
    std::string userInput;
    std::getline(std::cin, userInput);

    // Iterate and set hasChar to true if there is char in msg
    if(userInput.length() != 0){
        bool hasChar = false;
        for(int i = 0; i < userInput.length(); i++){
            if( !(std::isdigit(userInput[i]))){
                hasChar = true;
            }
        }
        // hasChar = true, return -99 to signify error
        if(hasChar){
            return -999;
        }else{
            // hasChar = false, convert msg to int and return
            return std::stoi(userInput);
        }
    }else{
        return -999;
    }
}

/* --- TransactionList [Public] --------------------------------------------------------------------------------------*/
/* TransactionList Constructors */
TransactionList::TransactionList() {
    head = NULL;
    tail = NULL;
};

/* Method to display all available functions relating to TransactionList */
void TransactionList::transactionMenu(MovieList* movieList){
    while (true){
        //movieList->listMovies();
        std::cout << "\n\t---------------------------------------------------------\n"
                     "\t                Transaction Management Menu              \n"
                     "\t-*---------------------------*---------------------------\n"
                     "\t-|1. Place a new purchase    |---------------------------\n"
                     "\t-|2. View All Purchases      |---------------------------\n"
                     "\t-|3. Sort Purchases          |---------------------------\n"
                     "\t-|4. Delete Purchase Record  |---------------------------\n"
                     "\t-|5. Return to Main Menu     |---------------------------\n"
                     "\t-*---------------------------*---------------------------\n"
                     "\t>> Enter your choice:";
        int userChoice = validateInt();
        switch (userChoice) {
            case 1:
                newPurchaseMenu(movieList); //call function for creation of new purchase
                break;
            case 2:
                displayAllTransaction();

                // Print error message and prompt user to enter any key to continue
                std::cout << "\t>> Enter any key to return to Transaction Menu: ";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
            case 3:
                //placeholder for sort purchase
                sortTransaction_prompt();
                break;
            case 4:
                // Display all transaction. Prompt user which to delete. Call delete function
                deleteTransaction_prompt();
                break;
            case 5:
                return;
            case -999:
                std::cout << "\n\tERROR: Please enter an Index.\n"
                             "\tPress any key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore( 10000, '\n');
                break;
            default:
                // Print error message and prompt user to enter any key to continue
                std::cout << "\n\t>> Invalid Input\n\t>> Please enter from 1 to 4\n\t>> Enter any Key to continue:";

                // Wait for user Input and ignore up to 10,00 characters
                std::cin.ignore(10000, '\n');
                break;
        }
    }
}

/* Method to initialize the TransactionList */
void TransactionList::initializeTransactionList(MovieList movieList) {
    movieList.deductMovieQuantity(1, 2);
    Transaction* transaction_1 = new Transaction(this->transactionIDGenerator++, "John Wick", 24, 2, "2300");
    insertTransactionToList(transaction_1);

    movieList.deductMovieQuantity(2, 3);
    Transaction* transaction_2 = new Transaction(this->transactionIDGenerator++, "Spiderman", 45, 3, "2330");
    insertTransactionToList(transaction_2);

    movieList.deductMovieQuantity(4, 1);
    Transaction* transaction_3 = new Transaction(this->transactionIDGenerator++, "Naruto", 10 ,1 ,"2100");
    insertTransactionToList(transaction_3);

    movieList.deductMovieQuantity(10, 3);
    Transaction* transaction_4 = new Transaction(this->transactionIDGenerator++, "A+ in DSTR", 63, 3, "0115");
    insertTransactionToList(transaction_4);

    movieList.deductMovieQuantity(6, 2);
    Transaction* transaction_5 = new Transaction(this->transactionIDGenerator++, "Bronze Man", 64, 2, "1315");
    insertTransactionToList(transaction_5);

    movieList.deductMovieQuantity(7, 4);
    Transaction* transaction_6 = new Transaction(this->transactionIDGenerator++, "Pengu: Retribution", 100, 4, "1145");
    insertTransactionToList(transaction_6);

    movieList.deductMovieQuantity(8, 1);
    Transaction* transaction_7 = new Transaction(this->transactionIDGenerator++, "Spiderwoman", 27, 1, "1200");
    insertTransactionToList(transaction_7);

    movieList.deductMovieQuantity(9, 2);
    Transaction* transaction_8 = new Transaction(this->transactionIDGenerator++, "My Dilemma", 46, 2, "0000");
    insertTransactionToList(transaction_8);

    movieList.deductMovieQuantity(3, 3);
    Transaction* transaction_9 = new Transaction(this->transactionIDGenerator++, "Human Centipede", 60, 3, "1140");
    insertTransactionToList(transaction_9);

    movieList.deductMovieQuantity(5, 10);
    Transaction* transaction_10 = new Transaction(this->transactionIDGenerator++, "Gordon Ramsay", 150, 10, "1500");;
    insertTransactionToList(transaction_10);

}