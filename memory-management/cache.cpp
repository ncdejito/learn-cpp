#include <iostream>
#include <chrono>
#include <cassert>  // Include the cassert header
#include <cstring>  // Include the cstring header for memset

class LRUCache {
public:
    inline static int M[10001];
    inline static int16_t L[10002][2];
    int cap, size = 0;
    const int NONE = 10001;
    int head = NONE, tail = NONE;
    
    LRUCache(int capacity) : cap(capacity) {
        memset(M, 0xff, sizeof M);
    }
    
    inline void erase(int key) {
        const int pre = L[key][0];
        const int nxt = L[key][1];
        L[pre][1] = nxt;
        L[nxt][0] = pre;
        if (head == key) head = nxt;
        if (tail == key) tail = pre;
    }
    
    inline void push_front(int key) {
        L[key][0] = NONE;
        L[key][1] = head;
        L[head][0] = key;
        head = key;
        if (tail == NONE)
            tail = key;
    }
    
    inline int pop_back() {
        int ret = tail;
        tail = L[tail][0];
        L[tail][1] = NONE;
        if (tail == NONE)
            head = NONE;
        return ret;
    }
    
    int get(int key) {
        if (M[key] == -1) return -1;
        erase(key);
        push_front(key);
        return M[key];
    }
    
    void put(int key, int value) {
        if (M[key] != -1) {
            erase(key);
        } else {
            if (size == cap) {
                int poped = pop_back();
                M[poped] = -1;
                size -= 1;
            }
            size += 1;
        }
        push_front(key);
        M[key] = value;
    }
};



// Sample function for some_expensive_computation
int some_expensive_computation(int input) {
    // Simulate a time-consuming computation
    int result = 0;
    for (int i = 0; i < input; ++i) {
        result += i;
    }
    return result;
}

int main() {
    // Initialize the LRU cache
    LRUCache lru(100);  // Adjust the cache capacity as needed

    // Without caching
    auto start = std::chrono::high_resolution_clock::now();
    int result_without_cache = some_expensive_computation(10000);  // Replace with your computation
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Without cache: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;

    // With caching
    start = std::chrono::high_resolution_clock::now();
    int some_key = 10000;  // Replace with a specific key used in your computation
    int result_with_cache = lru.get(some_key);
    if (result_with_cache == -1) {
        result_with_cache = some_expensive_computation(some_key);  // Cache miss, perform the computation
        lru.put(some_key, result_with_cache);  // Cache the result
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "With cache: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;

    // Perform assertions for testing
    assert(result_without_cache == result_with_cache);  // The results should be equal

    return 0;
}
