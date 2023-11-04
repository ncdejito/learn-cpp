#include <iostream>
#include <thread>
#include <future>

void calculateSquare(std::promise<int> &p, int num) {
    int result = num * num;
    p.set_value(result); // Set the result in the promise
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();

    int inputNumber = 5;
    std::thread workerThread(calculateSquare, std::ref(p), inputNumber);

    int result = f.get(); // Get the result from the future

    workerThread.join();

    std::cout << "Square of " << inputNumber << " is " << result << std::endl;

    return 0;
}
