//Reg number:224003729
//Names:Mugisha kayishema
#pragma once
#include <stdexcept>
#include <iostream>

template <typename K, typename V>
class Dictionary {
public:
    virtual ~Dictionary() {}

    // Insert or update a key-value pair
    virtual void put(const K& key, const V& value) = 0;

    // Retrieve value by key (throws or returns default if not found)
    virtual V get(const K& key) const = 0;

    // Remove entry by key
    virtual void remove(const K& key) = 0;

    // Check if key exists
    virtual bool containsKey(const K& key) const = 0;

    // Return number of entries
    virtual int size() const = 0;

    // Check if dictionary is empty
    virtual bool isEmpty() const = 0;

    // Clear all entries
    virtual void clear() = 0;
};

template <typename E>
class Set {
public:
    virtual ~Set() {}

    // Add element if not present
    virtual void add(const E& element) = 0;

    // Remove element if present
    virtual void remove(const E& element) = 0;

    // Check membership
    virtual bool contains(const E& element) const = 0;

    // Return number of elements
    virtual int size() const = 0;

    // Check if set is empty
    virtual bool isEmpty() const = 0;

    // Clear all elements
    virtual void clear() = 0;

    // Set operations
    virtual Set<E>* unionWith(const Set<E>& other) const = 0;
    virtual Set<E>* intersectionWith(const Set<E>& other) const = 0;
    virtual Set<E>* differenceWith(const Set<E>& other) const = 0;
};

template <typename E>
class PriorityQueue {
public:
    virtual ~PriorityQueue() {}

    // Insert element with priority
    virtual void insert(const E& element, int priority) = 0;

    // Peek at highest-priority element
    virtual E peek() const = 0;

    // Remove and return highest-priority element
    virtual E extractMax() = 0;  // or extractMin()

    // Check if queue is empty
    virtual bool isEmpty() const = 0;

    // Return number of elements
    virtual int size() const = 0;

    // Clear all elements
    virtual void clear() = 0;
};

// Minimal entry point to satisfy the linker.
// Replace with tests or a real application entry as needed.
int main() {
    std::cout << "ADT templates compiled successfully.\n";
    return 0;
}
