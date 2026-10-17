//reg number: 224003729
//Names: MUGISHA Kayishema
#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[minIndex]) minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

// Display array
void displayArray(const vector<int>& arr) {
    for(int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];

    // Bubble Sort
    vector<int> arr1 = arr;
    bubbleSort(arr1);
    cout << "\nBubble Sorted Array: ";
    displayArray(arr1);

    // Insertion Sort
    vector<int> arr2 = arr;
    insertionSort(arr2);
    cout << "Insertion Sorted Array: ";
    displayArray(arr2);

    // Selection Sort
    vector<int> arr3 = arr;
    selectionSort(arr3);
    cout << "Selection Sorted Array: ";
    displayArray(arr3);

    return 0;
}
