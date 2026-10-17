// Name: MUGISHA Kayishema
// Reg No: 224003729
// Program: String Utilities using Function Overloading

#include <iostream>
#include <string>
using namespace std;

int find(string str, char ch) {
    return str.find(ch);
}

int find(string str, string subStr) {
    return str.find(subStr);
}

int main() {
    string text = "Hello World";
    cout << "Position of 'o': " << find(text, 'o') << endl;
    cout << "Position of 'World': " << find(text, "World") << endl;
    return 0;
}

