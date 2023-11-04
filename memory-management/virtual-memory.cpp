#include <iostream>

int main() {
    // Allocate a large array of integers
    int* largeArray = new int[1000000];

    // Access and modify elements in the array
    largeArray[0] = 42;
    largeArray[999999] = 73;

    // Deallocate the array to free up memory
    delete[] largeArray;
    std::cout<<"successful"<<std::endl;
    return 0;
}
