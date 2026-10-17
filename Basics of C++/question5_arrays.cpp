// Name: MUGISHA Kayishema
// Reg No: 224003729
// Program: Demonstrate common pointer errors

#include <iostream>
using namespace std;

int main() {
    int *p = new int(10);
    cout << "Value: " << *p << endl;

    delete p;
    // ? Common Error 1: Double delete
    // delete p; // Uncomment to see error

    // ? Common Error 2: Dangling pointer
    // cout << *p << endl; // Access after delete

    // ? Common Error 3: Memory leak
    int *q = new int[5];
    // Forgot to delete[] q;

    return 0;
}
