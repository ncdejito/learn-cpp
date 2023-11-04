#include <iostream>
#include <thread>
#include <mutex>

int sharedCounter = 0;
std::mutex mtx; // Create a mutex

void incrementCounter() {
    for (int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock(mtx); // Acquire the lock
        sharedCounter++; // Access the shared resource
    }
}

int main() {
    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    thread1.join();
    thread2.join();

    std::cout << "Shared counter value: " << sharedCounter << std::endl;

    return 0;
}
