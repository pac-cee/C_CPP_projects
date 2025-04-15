// Guess the Number Game in C++
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int number = std::rand() % 100 + 1;
    int guess, attempts = 0;
    std::cout << "Guess the number (1-100):\n";
    do {
        std::cout << "Enter guess: ";
        std::cin >> guess;
        attempts++;
        if (guess < number)
            std::cout << "Too low!\n";
        else if (guess > number)
            std::cout << "Too high!\n";
        else
            std::cout << "Correct! Attempts: " << attempts << std::endl;
    } while (guess != number);
    return 0;
}
