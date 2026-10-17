//reg number:224003729
//Names: MUGISHA Kayishema
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

// ---------- Sorting Algorithms ----------
void bubbleSort(vector<int> arr) {
    for(int i=0;i<arr.size();i++)
        for(int j=0;j<arr.size()-i-1;j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

void insertionSort(vector<int> arr) {
    for(int i=1;i<arr.size();i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        int minIndex = i;
        for(int j=i+1;j<arr.size();j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

// Merge Sort
void merge(vector<int> &arr, int l, int m, int r){
    vector<int> left(arr.begin()+l, arr.begin()+m+1);
    vector<int> right(arr.begin()+m+1, arr.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<left.size() && j<right.size())
        arr[k++] = (left[i] <= right[j] ? left[i++] : right[j++]);
    while(i<left.size()) arr[k++] = left[i++];
    while(j<right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int> &arr, int l, int r){
    if(l>=r) return;
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

// Quick Sort
int partitionQS(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pi = partitionQS(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// Searching
int linearSearch(vector<int> arr, int x){
    for(int i=0;i<arr.size();i++) if(arr[i]==x) return i;
    return -1;
}

int binarySearch(vector<int> arr, int x){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Measure time
template<typename Func>
long long timeAlgorithm(Func func, vector<int> data){
    auto start = high_resolution_clock::now();
    func(data);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

int main(){
    vector<int> data;
    for(int i=5000;i>0;i--) data.push_back(i);

    cout << "Bubble Sort: " << timeAlgorithm(bubbleSort, data) << " us\n";
    cout << "Insertion Sort: " << timeAlgorithm(insertionSort, data) << " us\n";
    cout << "Selection Sort: " << timeAlgorithm(selectionSort, data) << " us\n";

    cout << "Merge Sort: ";
    auto v1 = data; auto t1 = high_resolution_clock::now();
    mergeSort(v1, 0, v1.size()-1);
    auto t2 = high_resolution_clock::now();
    cout << duration_cast<microseconds>(t2 - t1).count() << " us\n";

    cout << "Quick Sort: ";
    auto v2 = data; auto t3 = high_resolution_clock::now();
    quickSort(v2, 0, v2.size()-1);
    auto t4 = high_resolution_clock::now();
    cout << duration_cast<microseconds>(t4 - t3).count() << " us\n";

    cout << "Linear Search: " << linearSearch(data, 10) << endl;
    cout << "Binary Search: " << binarySearch(data, 10) << endl;
    return 0;
}
