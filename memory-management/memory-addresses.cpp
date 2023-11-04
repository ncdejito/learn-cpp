#include <iostream>

int main() {
    int number = 42;  // Define an integer variable 'number'
    
    // Print the memory address of 'number'
    std::cout << "Memory address of 'number': " << &number << std::endl;

    // Access and modify 'number' using its memory address
    int* addressOfNumber = &number;  // Store the memory address in a pointer
    *addressOfNumber = 73;  // Modify 'number' indirectly through the pointer

    // Print the updated value of 'number'
    std::cout << "Updated 'number' value: " << number << std::endl;

    return 0;
}
