#include <iostream>
#include <string>
using namespace std;

class BankingException {
public:
    string message;

    BankingException(string msg) {
        message = msg;
    }
};

int main() {
    int balance = 5000;
    int amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try {
        if (amount <= 0) {
            throw BankingException("Invalid Amount!");
        }

        if (amount > balance) {
            throw BankingException("Insufficient Balance!");
        }

        balance = balance - amount;

        cout << "Transaction Successful!" << endl;
        cout << "Remaining Balance: " << balance << endl;
    }
    catch (const BankingException& e) {
        cout << e.message << endl;
    }

    return 0;
}
