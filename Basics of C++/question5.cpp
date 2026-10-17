// Name: MUGISHA Kayishema
// Reg No: 224003729
// Program: Simple Bank Account System

#include <iostream>
using namespace std;

void deposit(double &balance, double amount) {
    balance += amount;
    cout << "Deposited: " << amount << endl;
}

void withdraw(double &balance, double amount) {
    if (amount > balance)
        cout << "Insufficient balance!" << endl;
    else {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    }
}

void checkBalance(double balance) {
    cout << "Current balance: " << balance << endl;
}

void transfer(double &from, double &to, double amount) {
    if (amount > from)
        cout << "Not enough funds to transfer!" << endl;
    else {
        from -= amount;
        to += amount;
        cout << "Transferred: " << amount << endl;
    }
}

int main() {
    double acc1 = 1000, acc2 = 500;

    deposit(acc1, 200);
    withdraw(acc1, 150);
    transfer(acc1, acc2, 300);
    checkBalance(acc1);
    checkBalance(acc2);

    return 0;
}

