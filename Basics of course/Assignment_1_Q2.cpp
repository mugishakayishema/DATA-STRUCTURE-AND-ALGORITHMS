//Reg number:224003729
//Names:MUGISHA Kayishema
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // for std::sort (optional check)

using namespace std;
using namespace std::chrono;

// ---------------- Sorting Algorithms ----------------

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Merge Sort Helper
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ---------------- Searching Algorithms ----------------

// Linear Search
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Binary Search (array must be sorted)
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

// ---------------- Performance Measurement ----------------

void measureSort(void (*sortFunc)(vector<int>&), vector<int> arr, string name) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << name << " took " << duration << " microseconds.\n";
}

int main() {
    // Sample dataset
    int count;
    vector<int> data;
    while (true) {
        cout << "Enter elements (space-separated), enter  -1 to end:\n";
        cin >> count;
        if (count != -1) {
            data.push_back(count);
        }
        else {
            break;
        }
    }
    // Sorting performance
    measureSort(bubbleSort, data, "Bubble Sort");
    measureSort(insertionSort, data, "Insertion Sort");
    measureSort(selectionSort, data, "Selection Sort");

    auto start = high_resolution_clock::now();
    vector<int> arr = data;
    mergeSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Merge Sort took " << duration << " microseconds.\n";

    // Searching performance
    vector<int> sortedData = data;
    sort(sortedData.begin(), sortedData.end()); // ensure sorted for binary search
	int key;
	cout << "Enter key to search: ";
	cin >> key;
    cout << "\nSearching for " << key << "...\n";

    start = high_resolution_clock::now();
    int idx1 = linearSearch(sortedData, key);
    end = high_resolution_clock::now();
    cout << "Linear Search found at index " << idx1
        << " in " << duration_cast<microseconds>(end - start).count() << " microseconds.\n";

    start = high_resolution_clock::now();
    int idx2 = binarySearch(sortedData, key);
    end = high_resolution_clock::now();
    cout << "Binary Search found at index " << idx2
        << " in " << duration_cast<microseconds>(end - start).count() << " microseconds.\n";

    return 0;
}
