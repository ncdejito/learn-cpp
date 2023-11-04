#include <iostream>

int main() {
    // Stack variable
    int stackVariable = 42;
    
    // Create a pointer to an integer in the heap
    int* heapVariable = new int(73);

    // Print the values
    std::cout << "Stack variable: " << stackVariable << std::endl;
    std::cout << "Heap variable: " << *heapVariable << std::endl;

    // Deallocate the heap variable
    delete heapVariable;

    return 0;
}
