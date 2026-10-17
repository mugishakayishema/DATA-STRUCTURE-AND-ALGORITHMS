//reg number:224003729
//Names: Mugisha Kayishema
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // O(n) example
    cout << "\nO(n) loop output:\n";
    for(int i=0; i<n; i++)
        cout << i << " ";
    cout << endl;

    // O(n^2) example
    cout << "\nO(n^2) loop output:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << "(" << i << "," << j << ") ";
        cout << endl;
    }

    // O(log n) example
    cout << "\nO(log n) loop output:\n";
    for(int i=1; i<=n; i*=2)
        cout << i << " ";
    cout << endl;

    return 0;
}
