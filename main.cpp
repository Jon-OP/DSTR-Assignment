#include <iostream>
#include "Inventory.h"      // Allow the calling of Inventory Attributes & Methods
#include "Transaction.h"    // Allow the calling of Inventory Attributes & Methods

// Main Implementation - Jonathan

int main() {
    std::cout << "This is a Test from MAIN!" << std::endl;

    // Declaration of Inventory Object
    Inventory testInventory;
    testInventory.greetings();

    // Declaration of Transaction Object
    Transaction testTransaction;
    testTransaction.greetings();

    
    return 0;
}
