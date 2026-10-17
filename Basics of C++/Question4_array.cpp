// Name: MUGISHA Kayishema
// Reg No: 224003729
#include <iostream>
using namespace std;

class SmartArray {
    int *arr;
    int size;

public:
    SmartArray(int s) {
        size = s;
        arr = new int[size];
    }

    ~SmartArray() {
        delete[] arr;
        cout << "\nMemory released!" << endl;
    }

    void input() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }

    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    SmartArray a1(5);
    a1.input();
    a1.display();
    return 0;
}

