#include <iostream>
#include <cstdlib> // Include the necessary library for malloc and free

int main() {
    // Declare a pointer to an integer
    int* dynamicVar;

    // Allocate memory for an integer using malloc
    dynamicVar = (int*)malloc(sizeof(int));
    
    if (dynamicVar == nullptr) {
        std::cerr << "Memory allocation failed!" << std::endl;
        return 1;
    }

    // Assign a value to the dynamically allocated integer
    *dynamicVar = 42;

    // Print the value
    std::cout << "Dynamically allocated variable: " << *dynamicVar << std::endl;

    // Deallocate the memory using free
    free(dynamicVar);

    return 0;
}
