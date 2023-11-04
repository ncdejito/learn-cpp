#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

template <typename T>
class ConcurrentMessageQueue {
public:
    void Push(const T& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(message);
        condition_.notify_one();
    }

    T Pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this]() { return !queue_.empty(); });
        T message = queue_.front();
        queue_.pop();
        return message;
    }

private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable condition_;
};

int main() {
    ConcurrentMessageQueue<int> messageQueue;

    std::thread producer([&messageQueue]() {
        for (int i = 1; i <= 5; ++i) {
            messageQueue.Push(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });

    std::thread consumer([&messageQueue]() {
        for (int i = 1; i <= 5; ++i) {
            int message = messageQueue.Pop();
            std::cout << "Received: " << message << std::endl;
        }
    });

    producer.join();
    consumer.join();

    return 0;
}
