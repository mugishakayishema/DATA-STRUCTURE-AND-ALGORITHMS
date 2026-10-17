// Name: MUGISHA Kayishema
// Reg No: 224003729
// Program: Array Operations (findMax, calculateAverage, reverseArray)

#include <iostream>
using namespace std;

void findMax(int arr[], int size, int &maxVal) {
    maxVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
}

void calculateAverage(int arr[], int size, double &average) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    average = (double)sum / size;
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int arr[] = {4, 2, 9, 7, 5};
    int size = 5;
    int maxVal;
    double avg;

    findMax(arr, size, maxVal);
    calculateAverage(arr, size, avg);
    reverseArray(arr, size);

    cout << "Max value: " << maxVal << endl;
    cout << "Average: " << avg << endl;
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}

