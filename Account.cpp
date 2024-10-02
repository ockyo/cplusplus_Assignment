#include <iostream>
#include <vector>
using namespace std;
class Account
{
protected:
    string accountNumber;
    string ownerName;
    double balance;

public:
    Account(string number, string name, double initialBalance) : accountNumber(number), ownerName(name), balance(initialBalance) {}
    virtual void desposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Da nap " << amount << " vao tai khoan." << endl;
        }
        else
        {
            cout << "So tien khong hop le." << endl;
        }
    }
    virtual bool withdraw(double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            cout << "Da rut " << amount << " tu tai khoan." << endl;
            return true;
        }
        else
        {
            cout << "Khong the rut tien. So du khong du hoac so tien khong hop le." << endl;
            return false;
        }
    }
    virtual void displayInfo() const
    {
        cout << "So tai khoan: " << accountNumber << endl;
        cout << "Chu tai khoan: " << ownerName << endl;
        cout << "So du: " << balance << endl;
    }
    virtual ~Account() {}
};
class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(string number, string name, double initialBalance, double rate) : Account(number, name, initialBalance), interestRate(rate) {}
    void applyInterest()
    {
        double interest = balance * interestRate;
        desposit(interest);
        cout << "Da cong lai: " << interest << endl;
    }
    void displayInfo() const override
    {
        Account::displayInfo();
        cout << "Lai suat: " << (interestRate * 100) << "%" << endl;
    }
};
class CheckingAccount : public Account
{
private:
    double overdraftLimit;

public:
    CheckingAccount(string number, string name, double initialBalance, double limit) : Account(number, name, initialBalance), overdraftLimit(limit) {}
    bool withdraw(double amount) override
    {
        if (amount > 0 && (balance + overdraftLimit) >= amount)
        {
            balance -= amount;
            cout << "Da rut " << amount << " tu tai khoan." << endl;
            return true;
        }
        else
        {
            cout << "Khong the rut tien. Vuot qua gioi han thau chi hoac so tien khong hop le." << endl;
            return false;
        }
    }
    void displayInfo() const override
    {
        Account::displayInfo();
        cout << "Gioi han thau chi: " << overdraftLimit << endl;
    }
};
class Bank
{
private:
    vector<Account *> accounts;

public:
    void addAccount(Account *account)
    {
        accounts.push_back(account);
    }
    void displayAllAccounts() const
    {
        for (const auto &account : accounts)
        {
            account->displayInfo();
        }
        cout << "---------------------------" << endl;
    }
    ~Bank()
    {
        for (auto accont : accounts)
        {
            delete accont;
        }
    }
};
int main()
{
    Bank myBank;
    myBank.addAccount(new SavingsAccount("SA011", "Nguyen Van A", 10000000, 0.05));
    myBank.addAccount(new CheckingAccount("CA001", "Tran Thi B", 20000000, 500000));
    cout << "Thong tin tat cac tai khoan:" << endl;
    myBank.displayAllAccounts();
    return 0;
}