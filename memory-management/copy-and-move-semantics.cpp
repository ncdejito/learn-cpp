#include <iostream>
#include <string>
#include <utility>

class Item {
public:
    Item(std::string name, int value) : name(name), value(value) {}
    
    // Copy Constructor
    Item(const Item& other) : name(other.name), value(other.value) {
        std::cout << "Copy constructor called." << std::endl;
    }
    
    // Move Constructor
    Item(Item&& other) : name(std::move(other.name)), value(std::move(other.value)) {
        std::cout << "Move constructor called." << std::endl;
    }
    
    void display() const {
        std::cout << "Name: " << name << ", Value: " << value << std::endl;
    }

private:
    std::string name;
    int value;
};

int main() {
    // Create an Item using the regular constructor.
    Item item1("Item 1", 100);
    
    // Create a copy of item1 using the copy constructor.
    Item item2 = item1; // Copy constructor is called.

    // Create a move of item1 using the move constructor.
    Item item3 = std::move(item1); // Move constructor is called.

    // Display the items to see the results.
    item1.display(); // Empty item because ownership has been moved.
    item2.display(); // Copy of item1.
    item3.display(); // Moved item from item1.

    return 0;
}
