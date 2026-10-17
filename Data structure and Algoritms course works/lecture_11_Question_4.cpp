//reg number:224003729
//Names: Mugisha kayishema
#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <thread>

template <typename T>
class CircularBuffer {
private:
    std::vector<T> buffer;
    size_t head, tail, count, capacity;
    std::mutex mtx;
    std::condition_variable not_full, not_empty;

public:
    explicit CircularBuffer(size_t size)
        : buffer(size), head(0), tail(0), count(0), capacity(size) {
    }

    void enqueue(const T& item) {
        std::unique_lock<std::mutex> lock(mtx);
        not_full.wait(lock, [this]() { return count < capacity; });

        buffer[tail] = item;
        tail = (tail + 1) % capacity;
        count++;

        lock.unlock();
        not_empty.notify_one();
    }
    T dequeue() {
        std::unique_lock<std::mutex> lock(mtx);
        not_empty.wait(lock, [this]() { return count > 0; });

        T item = buffer[head];
        head = (head + 1) % capacity;
        count--;

        lock.unlock();
        not_full.notify_one();
        return item;
    }

    // Utility
    bool isEmpty() {
        std::lock_guard<std::mutex> lock(mtx);
        return count == 0;
    }

    bool isFull() {
        std::lock_guard<std::mutex> lock(mtx);
        return count == capacity;
    }

    size_t size() {
        std::lock_guard<std::mutex> lock(mtx);
        return count;
    }
};
//Example usage
int main() {
    CircularBuffer<int> cb(5);
    std::thread producer([&cb]() {
        for (int i = 1; i <= 10; i++) {
            cb.enqueue(i);
            std::cout << "Produced: " << i << std::endl;
        }
        });
    std::thread consumer([&cb]() {
        for (int i = 1; i <= 10; i++) {
            int val = cb.dequeue();
            std::cout << "Consumed: " << val << std::endl;
        }
        });

    producer.join();
    consumer.join();

    return 0;
}
