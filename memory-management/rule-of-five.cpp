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

    // Destructor (Rule of Five)
    ~MyString() {
        delete[] data;
    }

    // Copy Constructor (Rule of Five)
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Copy Assignment Operator (Rule of Five)
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this; // Self-assignment check
        }

        // Deallocate existing data
        delete[] data;

        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);

        return *this;
    }

    // Move Constructor (Rule of Five)
    MyString(MyString&& other) noexcept {
        length = other.length;
        data = other.data;

        // Reset the source object
        other.length = 0;
        other.data = nullptr;
    }

    // Move Assignment Operator (Rule of Five)
    MyString& operator=(MyString&& other) noexcept {
        if (this == &other) {
            return *this; // Self-assignment check
        }

        // Deallocate existing data
        delete[] data;

        length = other.length;
        data = other.data;

        // Reset the source object
        other.length = 0;
        other.data = nullptr;

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

    // Create another MyString object by moving str1
    MyString str2 = std::move(str1);

    // Check if the move was successful
    std::cout << "str1: " << (str1.getString() ? str1.getString() : "Empty") << std::endl;
    std::cout << "str2: " << str2.getString() << std::endl;

    return 0;
}
