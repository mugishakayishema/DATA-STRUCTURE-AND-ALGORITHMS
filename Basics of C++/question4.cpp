// Name: MUGISHA Kayishema
// Reg No: 224003729
// Program: Geometry Calculator using Function Overloading

#include <iostream>
#include <cmath>
using namespace std;

double area(double radius) { // Circle
    return M_PI * radius * radius;
}

double area(double length, double width) { // Rectangle
    return length * width;
}

double area(double base, double height, bool isTriangle) { // Triangle
    return 0.5 * base * height;
}

int main() {
    cout << "Circle area: " << area(5.0) << endl;
    cout << "Rectangle area: " << area(4.0, 6.0) << endl;
    cout << "Triangle area: " << area(3.0, 7.0, true) << endl;
    return 0;
}

