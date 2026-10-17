//reg number:224003729
//Names: Mugisha kayishema 
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int removeDuplicatesSorted(vector<int>& arr) {
    if (arr.empty()) return 0;
    int j = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}
vector<int> removeDuplicatesUnsorted(const vector<int>& arr) {
    unordered_set<int> seen;
    vector<int> result;

    for (int num : arr) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    vector<int> sortedArr = { 1, 1, 2, 3, 3, 4, 4, 5 };
    cout << "Original sorted array: ";
    for (int num : sortedArr) cout << num << " ";
    cout << endl;

    int newSize = removeDuplicatesSorted(sortedArr);
    cout << "After removing duplicates (sorted): ";
    for (int i = 0; i < newSize; i++) cout << sortedArr[i] << " ";
    cout << endl << endl;
    vector<int> unsortedArr = { 4, 2, 1, 2, 3, 4, 1, 5 };
    cout << "Original unsorted array: ";
    for (int num : unsortedArr) cout << num << " ";
    cout << endl;

    vector<int> result = removeDuplicatesUnsorted(unsortedArr);
    cout << "After removing duplicates (unsorted): ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}
