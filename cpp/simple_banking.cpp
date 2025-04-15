// Simple Banking System in C++
#include <iostream>
#include <vector>
#include <string>

class Account {
    std::string owner;
    double balance;
public:
    Account(const std::string& n, double b) : owner(n), balance(b) {}
    void deposit(double amt) { balance += amt; }
    void withdraw(double amt) { if (amt <= balance) balance -= amt; }
    void display() const {
        std::cout << owner << ": $" << balance << std::endl;
    }
    std::string get_owner() const { return owner; }
};

int main() {
    std::vector<Account> accounts;
    accounts.emplace_back("Alice", 1000);
    accounts.emplace_back("Bob", 500);
    int choice;
    std::string name;
    double amt;
    while (true) {
        std::cout << "1. Deposit\n2. Withdraw\n3. Display\n4. Exit\nChoice: ";
        std::cin >> choice;
        if (choice == 4) break;
        std::cout << "Enter name: ";
        std::cin >> name;
        auto it = std::find_if(accounts.begin(), accounts.end(), [&](const Account& acc){ return acc.get_owner() == name; });
        if (it == accounts.end()) {
            std::cout << "Account not found.\n";
            continue;
        }
        switch (choice) {
            case 1:
                std::cout << "Amount to deposit: ";
                std::cin >> amt;
                it->deposit(amt);
                break;
            case 2:
                std::cout << "Amount to withdraw: ";
                std::cin >> amt;
                it->withdraw(amt);
                break;
            case 3:
                it->display();
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
