//Reg number:224003729
//Names:Mugisha kayishema 
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <random>
#include <algorithm>
using namespace std;
using namespace std::chrono;

// Algorithms

// Constant Time O(1)
int constantTime(const vector<int>& arr) {
    return arr[0]; // just access first element
}

// Linear Time O(n)
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Logarithmic Time O(log n)
int binarySearch(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Quadratic Time O(n^2) - Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// Exponential Time O(2^n) - Fibonacci
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

//Performance Test

template <typename Func, typename... Args>
void measurePerformance(string name, Func func, Args... args) {
    auto start = high_resolution_clock::now();
    func(args...);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << name << " took " << duration << " microseconds.\n";
}

int main() {
    vector<int> sizes = { 10, 100, 1000, 5000 }; // test input sizes

    // random engine for std::shuffle
    std::mt19937 rng(std::random_device{}());

    for (int n : sizes) {
        cout << "\n--- Input size: " << n << " ---\n";
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i;

        // Constant
        measurePerformance("O(1) Constant", constantTime, arr);

        // Linear
        measurePerformance("O(n) Linear Search", linearSearch, arr, n - 1);

        // Logarithmic
        measurePerformance("O(log n) Binary Search", binarySearch, arr, n - 1);

        // Quadratic - run for all input sizes (may be slow for large n)
        {
            vector<int> arrCopy = arr;
            std::shuffle(arrCopy.begin(), arrCopy.end(), rng);
            measurePerformance("O(n^2) Bubble Sort", bubbleSort, arrCopy);
        }

        // Exponential - include measurement for all input sizes but cap the Fibonacci input
        // to avoid impractical runtimes on large n. Adjust `fibArg` if you want different behavior.
        {
            int fibArg = std::min(n, 50); // safe cap to keep runtime reasonable
            measurePerformance(string("O(2^n) Fibonacci (n=") + to_string(fibArg) + ")", fibonacci, fibArg);
        }
    }

    return 0;
}

