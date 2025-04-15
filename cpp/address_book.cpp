// File-based Address Book in C++
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
};

int main() {
    std::vector<Contact> contacts;
    int choice;
    std::string name, phone;
    while (true) {
        std::cout << "1. Add Contact\n2. List Contacts\n3. Save & Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) {
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter phone: ";
            std::getline(std::cin, phone);
            contacts.push_back({name, phone});
        } else if (choice == 2) {
            for (const auto& c : contacts) {
                std::cout << c.name << " - " << c.phone << std::endl;
            }
        } else if (choice == 3) {
            std::ofstream fout("contacts.txt");
            for (const auto& c : contacts) {
                fout << c.name << "," << c.phone << std::endl;
            }
            std::cout << "Contacts saved. Exiting.\n";
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
