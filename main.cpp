#include <iostream>
#include "Inventory.h"      // Allow the calling of Inventory Attributes & Methods
#include "Transaction.h"    // Allow the calling of Transaction Attributes & Methods
#include "CDLinkedList.h"   // Allow the calling of CDLinkedList Attributes & Methods

// Main Implementation - Jonathan

int main() {
    std::cout << "This is a Test from MAIN!" << std::endl;

    // Declaration of Inventory Object
    Inventory testInventory;
    testInventory.greetings();

    // Declaration of Transaction Object
    Transaction testTransaction;
    testTransaction.greetings();


    //TEST SITE BELOW ONWARDS
    CDLinkedList cd = CDLinkedList();
    Transaction testTransaction1 = Transaction("Name 1");
    Transaction testTransaction2 = Transaction("Name 2");
    Transaction testTransaction3 = Transaction("Name 3");
    Transaction testTransaction4 = Transaction("Name 4");
    Transaction testTransaction5 = Transaction("Name 5");
    Transaction testTransaction6 = Transaction("Name 6");
    Transaction testTransaction7 = Transaction("Name 7");
    //std::cout << testTransaction1.getMovieName();
    cd.insertTransaction(testTransaction1);
    cd.insertTransaction(testTransaction2);
    cd.insertTransaction(testTransaction3);
    cd.insertTransaction(testTransaction4);
    cd.insertTransaction(testTransaction5);
    cd.insertTransaction(testTransaction6);
    cd.insertTransaction(testTransaction7);
    cd.displayAllTransaction();


    
    return 0;
}
