#include <iostream>
#include <cstring>

class MyString {
public:
    // Constructor
    MyString(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Constructor (Rule of Three)
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Copy Assignment Operator (Rule of Three)
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this; // Self-assignment check
        }

        delete[] data;

        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);

        return *this;
    }

    // Getter for the string
    const char* getString() const {
        return data;
    }

private:
    char* data;
    size_t length;
};

int main() {
    // Create a MyString object
    MyString str1("Hello, C++!");

    // Create another MyString object and copy the first one
    MyString str2 = str1;

    // Check if the copy is correct
    std::cout << "str1: " << str1.getString() << std::endl;
    std::cout << "str2: " << str2.getString() << std::endl;

    // Modify str2 and demonstrate the deep copy
    str2 = "Modified!";
    std::cout << "str1: " << str1.getString() << std::endl;
    std::cout << "str2: " << str2.getString() << std::endl;

    return 0;
}
