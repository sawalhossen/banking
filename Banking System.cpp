#include <bits/stdc++.h>
using namespace std;

class BankAccount {
protected:
    int balance;

public:
    BankAccount() {
        balance = 100;
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " Taka." << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    virtual void withdraw(int amount) = 0;
    virtual void displayBalance() const {
        cout << "Current Balance: " << balance << " Taka" << endl;
    }

    virtual ~BankAccount() {
        cout << "Your Total Balance is " << balance << " Taka." << endl;
    }
};

class User : public BankAccount {
public:
    User() {}

    void withdraw(int amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << " Taka." << endl;
        } else {
            cout << "Insufficient balance or invalid amount for withdrawal." << endl;
        }
    }
};

class Printable {
public:
    virtual void printInfo() const = 0;
};

class UserInfo : public Printable {
private:
    string name;
    int accountNumber;

public:
    UserInfo(string n, int accNum) : name(n), accountNumber(accNum) {}

    void printInfo() const override {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
    }
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount() {}

    void withdraw(int amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << " units from Checking Account." << endl;
        } else {
            cout << "Insufficient balance or invalid amount for withdrawal." << endl;
        }
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " Taka into Checking Account." << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount() {}

    void withdraw(int amount) override {
        if (amount > 0 && amount <= balance) {
            // Apply additional logic for savings withdrawal, such as interest calculations
            balance -= amount;
            cout << "Withdrawn " << amount << " Taka from Savings Account." << endl;
        } else {
            cout << "Insufficient balance or invalid amount for withdrawal." << endl;
        }
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " Taka into Savings Account." << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }
};

int main() {
    User user1;
    CheckingAccount checkingAccount;
    SavingsAccount savingsAccount;
    int choice;

    while (true) {
        cout << "\nBanking System Menu\n";
        cout << "1. Deposit to User Account\n";
        cout << "2. Withdraw from User Account\n";
        cout << "3. Withdraw from Checking Account\n";
        cout << "4. Deposit into Checking Account\n";
        cout << "5. Withdraw from Savings Account\n";
        cout << "6. Deposit into Savings Account\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int amount;
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                user1.deposit(amount);
                user1.displayBalance();
                break;
            }
            case 2: {
                int amount;
                cout << "Enter the amount to withdraw from User Account: ";
                cin >> amount;
                user1.withdraw(amount);
                user1.displayBalance();
                break;
            }
            case 3: {
                int amount;
                cout << "Enter the amount to withdraw from Checking Account: ";
                cin >> amount;
                checkingAccount.withdraw(amount);
                checkingAccount.displayBalance();
                break;
            }
            case 4: {
                int amount;
                cout << "Enter the amount to deposit into Checking Account: ";
                cin >> amount;
                checkingAccount.deposit(amount);
                checkingAccount.displayBalance();
                break;
            }
            case 5: {
                int amount;
                cout << "Enter the amount to withdraw from Savings Account: ";
                cin >> amount;
                savingsAccount.withdraw(amount);
                savingsAccount.displayBalance();
                break;
            }
            case 6: {
                int amount;
                cout << "Enter the amount to deposit into Savings Account: ";
                cin >> amount;
                savingsAccount.deposit(amount);
                savingsAccount.displayBalance();
                break;
            }
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please select again." << endl;
        }
    }

    UserInfo userInfo("John Doe", 123456);
    userInfo.printInfo();

    return 0;
}
