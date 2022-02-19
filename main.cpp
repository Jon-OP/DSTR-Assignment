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
    Transaction testTransaction1 = Transaction(2,12.5);
    Transaction testTransaction2 = Transaction(5, 13.2);
    Transaction testTransaction3 = Transaction(3, 10.0);
    Transaction testTransaction4 = Transaction(4, 11);
    Transaction testTransaction5 = Transaction(2, 17);
    Transaction testTransaction6 = Transaction(7, 21.2);
    Transaction testTransaction7 = Transaction(2, 82.1);
    Transaction testTransaction8 = Transaction(3, 9.2);
    //std::cout << testTransaction1.getMovieName();
    cd.insertTransaction(testTransaction1);
    cd.insertTransaction(testTransaction2);
    cd.insertTransaction(testTransaction3);
    cd.insertTransaction(testTransaction4);
    cd.insertTransaction(testTransaction5);
    cd.insertTransaction(testTransaction6);
    cd.insertTransaction(testTransaction7);
    cd.displayAllTransaction();
    std::cout << '\n';
    cd.sortTransaction("ID");
    cd.insertTransaction(testTransaction8);
    cd.sortTransaction("totalPrice");
    cd.displayAllTransaction();

    return 0;
}
