// Program: Grade Calculator
// Author: MUGISHA Kayishema
// Reg Number: 224003729

#include <iostream>
using namespace std;

float calculateAverage(float a, float b, float c) {
    return (a + b + c) / 3;
}

float findMaximum(float a, float b, float c) {
    float max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

char determineGrade(float avg) {
    if (avg >= 80) return 'A';
    else if (avg >= 70) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 50) return 'D';
    else return 'F';
}

int main() {
    float m1, m2, m3;
    cout << "Enter 3 marks: ";
    cin >> m1 >> m2 >> m3;

    float avg = calculateAverage(m1, m2, m3);
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << findMaximum(m1, m2, m3) << endl;
    cout << "Grade: " << determineGrade(avg) << endl;

    return 0;
}

