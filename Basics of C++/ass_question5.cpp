// Program: Inline vs Regular Function Performance
// Author: MUGISHA Kayishema
// Reg Number: 224003729

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

inline int addInline(int a, int b) {
    return a + b;
}

int addRegular(int a, int b) {
    return a + b;
}

int main() {
    int a = 5, b = 10;
    long long sum = 0;

    // Inline function test
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < 100000000; i++)
        sum += addInline(a, b);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);

    // Regular function test
    sum = 0;
    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < 100000000; i++)
        sum += addRegular(a, b);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);

    cout << "Inline Function Time: " << duration1.count() << " ms" << endl;
    cout << "Regular Function Time: " << duration2.count() << " ms" << endl;

    return 0;
}

