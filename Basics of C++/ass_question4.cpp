// Program: Math Library (Power Function Overloading)
// Author: MUGISHA Kayishema
// Reg Number: 224003729

#include <iostream>
#include <cmath>
using namespace std;

int power(int base, int exp) {
    return pow(base, exp);
}

double power(double base, int exp) {
    return pow(base, exp);
}

int main() {
    int intBase = 2, intExp = 3;
    double dblBase = 2.5;
    int dblExp = 2;

    cout << "Power (int): " << power(intBase, intExp) << endl;
    cout << "Power (double): " << power(dblBase, dblExp) << endl;

    return 0;
}

