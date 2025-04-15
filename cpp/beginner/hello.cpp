#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <iomanip>

class Terminal {
private:
    std::vector<std::string> history;
    const size_t MAX_HISTORY = 10;
    bool running;

    // Helper functions
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    std::string getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%H:%M:%S");
        return ss.str();
    }

    std::string getCurrentDate() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%Y-%m-%d");
        return ss.str();
    }

    void addToHistory(const std::string& cmd) {
        if (history.size() >= MAX_HISTORY) {
            history.erase(history.begin());
        }
        history.push_back(cmd);
    }

    void showHelp() {
        std::cout << "\nAvailable commands:\n"
                  << "  help     - Show this help message\n"
                  << "  clear    - Clear the screen\n"
                  << "  time     - Show current time\n"
                  << "  date     - Show current date\n"
                  << "  history  - Show command history\n"
                  << "  calc     - Calculator (e.g., calc 5 + 3)\n"
                  << "  upper    - Convert text to uppercase\n"
                  << "  lower    - Convert text to lowercase\n"
                  << "  exit     - Exit the terminal\n";
    }

    void showHistory() {
        std::cout << "\nCommand History:\n";
        for (size_t i = 0; i < history.size(); ++i) {
            std::cout << i + 1 << ": " << history[i] << '\n';
        }
    }

    void calculate(const std::string& expr) {
        std::istringstream iss(expr);
        double a, b;
        char op;
        
        if (iss >> a >> op >> b) {
            switch (op) {
                case '+': std::cout << a << " + " << b << " = " << (a + b) << '\n'; break;
                case '-': std::cout << a << " - " << b << " = " << (a - b) << '\n'; break;
                case '*': std::cout << a << " * " << b << " = " << (a * b) << '\n'; break;
                case '/':
                    if (b != 0) std::cout << a << " / " << b << " = " << (a / b) << '\n';
                    else std::cout << "Error: Division by zero\n";
                    break;
                default: std::cout << "Invalid operator\n";
            }
        } else {
            std::cout << "Invalid format. Use: calc 5 + 3\n";
        }
    }

    void toUpper(const std::string& text) {
        std::string result = text;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        std::cout << result << '\n';
    }

    void toLower(const std::string& text) {
        std::string result = text;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        std::cout << result << '\n';
    }

public:
    Terminal() : running(true) {}

    void run() {
        std::string input;
        std::cout << "Enhanced Terminal v2.0\n"
                  << "Type 'help' for available commands\n";

        while (running) {
            std::cout << "\nmyterminal> ";
            std::getline(std::cin, input);

            if (std::cin.eof() || std::cin.fail()) {
                std::cout << "\nExiting terminal...\n";
                break;
            }

            if (input.empty()) continue;
            addToHistory(input);

            // Process commands
            if (input == "exit") {
                std::cout << "Goodbye!\n";
                running = false;
            } else if (input == "help") {
                showHelp();
            } else if (input == "clear") {
                clearScreen();
            } else if (input == "time") {
                std::cout << "Current time: " << getCurrentTime() << '\n';
            } else if (input == "date") {
                std::cout << "Current date: " << getCurrentDate() << '\n';
            } else if (input == "history") {
                showHistory();
            } else if (input.substr(0, 5) == "calc ") {
                calculate(input.substr(5));
            } else if (input.substr(0, 6) == "upper ") {
                toUpper(input.substr(6));
            } else if (input.substr(0, 6) == "lower ") {
                toLower(input.substr(6));
            } else {
                std::cout << "Unknown command: " << input << '\n';
            }
        }
    }
};

int main() {
    Terminal terminal;
    terminal.run();
    return 0;
}
