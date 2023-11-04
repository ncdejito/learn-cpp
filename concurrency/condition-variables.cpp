#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool dataReady = false;
int sharedData = 0;

void producer() {
    // Produce data
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate data production
    {
        std::lock_guard<std::mutex> lock(mtx);
        sharedData = 42;
        dataReady = true;
    }
    cv.notify_one();
}

void consumer() {
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return dataReady; });
        // Consume data
        std::cout << "Consumer got data: " << sharedData << std::endl;
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
