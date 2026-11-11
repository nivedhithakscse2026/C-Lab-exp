#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Custom exception class
class BankingException : public runtime_error
{
public:
    BankingException(const string& message)
        : runtime_error(message)
    {
    }
};

// Bank Account class
class BankAccount
{
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initialBalance)
    {
        if (initialBalance < 0)
            throw BankingException("Initial balance cannot be negative.");

        accountHolder = name;
        balance = initialBalance;
    }

    // Deposit function
    void deposit(double amount)
    {
        if (amount <= 0)
            throw BankingException("Deposit amount must be positive.");

        balance += amount;

        cout << "Deposited Rs. " << amount << endl;
    }

    // Withdraw function
    void withdraw(double amount)
    {
        if (amount <= 0)
            throw BankingException("Withdrawal amount must be positive.");

        if (amount > balance)
            throw BankingException("Insufficient balance for withdrawal.");

        balance -= amount;

        cout << "Withdrawn Rs. " << amount << endl;
    }

    // Display account details
    void display() const
    {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    try
    {
        BankAccount account("Arun", 10000);

        cout << "Initial Account Details:" << endl;
        account.display();

        cout << "\nDepositing Rs. 5000..." << endl;
        account.deposit(5000);

        cout << "\nWithdrawing Rs. 3000..." << endl;
        account.withdraw(3000);

        cout << "\nWithdrawing Rs. 10000..." << endl;
        account.withdraw(10000);
    }
    catch (const BankingException& e)
    {
        cout << "\nError: " << e.what() << endl;
    }
    catch (const exception& e)
    {
        cout << "\nUnexpected Error: " << e.what() << endl;
    }

    cout << "\nFinal Account Details:" << endl;

    // Create account again to demonstrate a final balance
    BankAccount account("Arun", 12000);
    account.display();

    return 0;
}