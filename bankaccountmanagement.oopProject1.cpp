#include <iostream>
#include <string>
using namespace std;
class BankAccount
 {
protected:
    string accountNumber;
    string accountHolder;
    double balance;
public:
    BankAccount(string accNo, string accHolder, double initialBalance) : accountNumber(accNo), accountHolder(accHolder), balance(initialBalance) {}
    virtual void deposit(double amount)
	 {
        balance += amount;
        cout << "Deposit Successful! New Balance: " << balance << endl;
    }
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal Successful! Remaining Balance: " << balance << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }
    virtual void displayDetails() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
    virtual ~BankAccount() {} 
};
class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(string accNo, string accHolder, double initialBalance, double interest) : BankAccount(accNo, accHolder, initialBalance), interestRate(interest) {}

    void addInterest() {
        double interest = balance * (interestRate / 100);
        deposit(interest);
        cout << "Interest Added! New Balance: " << balance << endl;
    }
    void displayDetails() const override {
        cout << "--- Savings Account Details ---" << endl;
        BankAccount::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};
class CurrentAccount : public BankAccount {
    double overdraftLimit;
public:
    CurrentAccount(string accNo, string accHolder, double initialBalance, double overdraft): BankAccount(accNo, accHolder, initialBalance), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawal Successful! Remaining Balance: " << balance << endl;
        } else {
            cout << "Overdraft Limit Exceeded!" << endl;
        }
    }
    void displayDetails() const override {
        cout << "--- Current Account Details ---" << endl;
        BankAccount::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};
BankAccount* createAccount() {
    string accountType, accountNumber, accountHolder;
    double initialBalance, overdraftLimit, interestRate;
    cout << "Enter account type (Savings/Current): ";
    cin >> accountType;
    if (accountType != "Savings" && accountType != "Current") {
        cout << "Invalid account type entered!" << endl;
        return nullptr;
    }
    cout << "Enter account number: ";
    cin >> accountNumber;
    cin.ignore();  
    cout << "Enter account holder name: ";
    getline(cin, accountHolder);
    cout << "Enter initial balance: ";
    cin >> initialBalance;
    if (accountType == "Savings") {
        cout << "Enter interest rate: ";
        cin >> interestRate;
        return new SavingsAccount(accountNumber, accountHolder, initialBalance, interestRate);
    } else if (accountType == "Current") {
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
        return new CurrentAccount(accountNumber, accountHolder, initialBalance, overdraftLimit);
    }
    return nullptr;  
}
int main() {
    BankAccount* account = createAccount();
    
    if (account) {
        int choice;
        do {
            cout << "\n--- Account Management ---\n";
            cout << "1. Display Account Details\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                account->displayDetails();
                break;
            case 2: {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                account->deposit(amount);
                break;
            }
            case 3: {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account->withdraw(amount);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        } while (choice != 4);
        
        delete account; 
    }

    return 0;
}
