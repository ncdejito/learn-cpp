#include <iostream>
#include <memory>

struct Person {
    std::string name;

    Person(const std::string& n) : name(n) {
        std::cout << "Person " << name << " created." << std::endl;
    }

    ~Person() {
        std::cout << "Person " << name << " destroyed." << std::endl;
    }
};

int main() {
    // Create a unique_ptr
    std::unique_ptr<Person> uniquePerson = std::make_unique<Person>("Alice");

    // Create a shared_ptr
    std::shared_ptr<Person> sharedPerson1 = std::make_shared<Person>("Bob");
    std::shared_ptr<Person> sharedPerson2 = sharedPerson1;

    // Create a weak_ptr
    std::weak_ptr<Person> weakPerson = sharedPerson1;

    // Using unique_ptr
    if (uniquePerson) {
        std::cout << "uniquePerson's name: " << uniquePerson->name << std::endl;
    }

    // Using shared_ptr
    std::cout << "sharedPerson1's name: " << sharedPerson1->name << std::endl;
    std::cout << "sharedPerson2's name: " << sharedPerson2->name << std::endl;

    // Using weak_ptr
    if (auto sharedPerson3 = weakPerson.lock()) {
        std::cout << "weakPerson's name (via shared_ptr): " << sharedPerson3->name << std::endl;
    } else {
        std::cout << "weakPerson is expired." << std::endl;
    }

    return 0;
}
