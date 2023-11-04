#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> sharedBuffer;
std::mutex mtx;
std::condition_variable cv;

void producer() {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate some work
        std::lock_guard<std::mutex> lock(mtx);
        sharedBuffer.push(i);
        cv.notify_one();  // Notify the consumer thread
    }
}

void consumer() {
    for (int i = 0; i < 5; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !sharedBuffer.empty(); });
        int data = sharedBuffer.front();
        sharedBuffer.pop();
        lock.unlock();

        // Process the data (e.g., print it)
        std::cout << "Consumed: " << data << std::endl;
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
