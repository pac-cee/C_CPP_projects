#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT 256
#define MAX_HISTORY 10

// Structure to store command history
typedef struct {
    char commands[MAX_HISTORY][MAX_INPUT];
    int count;
} History;

// Function prototypes
void clearScreen(void);
void showHelp(void);
void showTime(void);
void showDate(void);
void addToHistory(History* hist, const char* cmd);
void showHistory(const History* hist);
void calculateSimple(const char* input);
void toUpperCase(const char* input);
void toLowerCase(const char* input);

int main(void) {
    char input[MAX_INPUT];
    History cmdHistory = {0};  // Initialize history structure

    // Display welcome message
    printf("Enhanced Terminal v1.0\n");
    printf("Type 'help' for available commands\n");

    while (1) {
        // Display prompt with current directory
        printf("\nMyTerminal > ");

        // Read user input safely
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nExiting terminal...\n");
            break;
        }

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';

        // Skip empty input
        if (strlen(input) == 0) continue;

        // Add command to history
        addToHistory(&cmdHistory, input);

        // Process commands
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(input, "help") == 0) {
            showHelp();
        } else if (strcmp(input, "clear") == 0) {
            clearScreen();
        } else if (strcmp(input, "time") == 0) {
            showTime();
        } else if (strcmp(input, "date") == 0) {
            showDate();
        } else if (strcmp(input, "history") == 0) {
            showHistory(&cmdHistory);
        } else if (strncmp(input, "calc ", 5) == 0) {
            calculateSimple(input + 5);  // Skip "calc " prefix
        } else if (strncmp(input, "upper ", 6) == 0) {
            toUpperCase(input + 6);
        } else if (strncmp(input, "lower ", 6) == 0) {
            toLowerCase(input + 6);
        } else {
            printf("Unknown command: %s\n", input);
        }
    }
    return 0;
}

// Function implementations
void clearScreen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showHelp(void) {
    printf("\nAvailable commands:\n");
    printf("  help     - Show this help message\n");
    printf("  clear    - Clear the screen\n");
    printf("  time     - Show current time\n");
    printf("  date     - Show current date\n");
    printf("  history  - Show command history\n");
    printf("  calc     - Simple calculator (e.g., calc 5+3)\n");
    printf("  upper    - Convert text to uppercase\n");
    printf("  lower    - Convert text to lowercase\n");
    printf("  exit     - Exit the terminal\n");
}

void showTime(void) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char buffer[26];
    strftime(buffer, 26, "%H:%M:%S", tm_info);
    printf("Current time: %s\n", buffer);
}

void showDate(void) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char buffer[26];
    strftime(buffer, 26, "%Y-%m-%d", tm_info);
    printf("Current date: %s\n", buffer);
}

void addToHistory(History* hist, const char* cmd) {
    if (hist->count >= MAX_HISTORY) {
        // Shift all commands one position up
        for (int i = 0; i < MAX_HISTORY - 1; i++) {
            strcpy(hist->commands[i], hist->commands[i + 1]);
        }
        hist->count = MAX_HISTORY - 1;
    }
    strcpy(hist->commands[hist->count++], cmd);
}

void showHistory(const History* hist) {
    printf("\nCommand History:\n");
    for (int i = 0; i < hist->count; i++) {
        printf("%d: %s\n", i + 1, hist->commands[i]);
    }
}

void calculateSimple(const char* input) {
    int a, b;
    char op;
    if (sscanf(input, "%d%c%d", &a, &op, &b) != 3) {
        printf("Invalid format. Use: calc 5+3\n");
        return;
    }
    
    switch (op) {
        case '+': printf("%d + %d = %d\n", a, b, a + b); break;
        case '-': printf("%d - %d = %d\n", a, b, a - b); break;
        case '*': printf("%d * %d = %d\n", a, b, a * b); break;
        case '/': 
            if (b != 0) printf("%d / %d = %.2f\n", a, b, (float)a / b);
            else printf("Error: Division by zero\n");
            break;
        default: printf("Unsupported operator\n");
    }
}

void toUpperCase(const char* input) {
    while (*input) {
        putchar(toupper(*input));
        input++;
    }
    putchar('\n');
}

void toLowerCase(const char* input) {
    while (*input) {
        putchar(tolower(*input));
        input++;
    }
    putchar('\n');
}
