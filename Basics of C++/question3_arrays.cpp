// Name: MUGISHA Kayishema
// Reg No: 224003729
#include <iostream>
using namespace std;

void copyString(char *dest, const char *src) {
    while (*src) *dest++ = *src++;
    *dest = '\0';
}

int compareStrings(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) { s1++; s2++; }
    return *s1 - *s2;
}

void reverseString(char *str) {
    char *end = str;
    while (*end) end++;
    end--;

    while (str < end) {
        char temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main() {
    char str1[50], str2[50];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    cout << "Comparison result: " << compareStrings(str1, str2) << endl;

    copyString(str2, str1);
    cout << "After copy, str2: " << str2 << endl;

    reverseString(str1);
    cout << "Reversed str1: " << str1 << endl;

    return 0;
}

