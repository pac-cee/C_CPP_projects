#include <stdio.h>
#include <string.h>
#include <assert.h>

// Include the header file if you have one, or copy necessary structures/defines
#define MAX_INPUT 256
#define MAX_HISTORY 10

typedef struct {
    char commands[MAX_HISTORY][MAX_INPUT];
    int count;
} History;

// Function prototypes for functions we'll test
void addToHistory(History* hist, const char* cmd);
void calculateSimple(const char* input);
void toUpperCase(const char* input);
void toLowerCase(const char* input);

// Test functions
void test_history() {
    printf("Testing history functionality...\n");
    
    History hist = {0};  // Initialize empty history
    
    // Test adding commands
    addToHistory(&hist, "test1");
    assert(hist.count == 1);
    assert(strcmp(hist.commands[0], "test1") == 0);
    
    // Test history overflow
    for (int i = 0; i < MAX_HISTORY + 2; i++) {
        char cmd[20];
        sprintf(cmd, "cmd%d", i);
        addToHistory(&hist, cmd);
    }
    
    // Verify that only MAX_HISTORY commands are stored
    assert(hist.count == MAX_HISTORY);
    
    printf("History tests passed!\n");
}

void test_calculator() {
    printf("Testing calculator functionality...\n");
    
    // Redirect stdout to capture output
    char buffer[256];
    freopen("nul", "w", stdout);
    
    // Test addition
    calculateSimple("5+3");
    assert(strcmp(buffer, "5 + 3 = 8\n") == 0);
    
    // Test division by zero
    calculateSimple("5/0");
    assert(strstr(buffer, "Error: Division by zero") != NULL);
    
    // Restore stdout
    freopen("CON", "w", stdout);
    printf("Calculator tests passed!\n");
}

void test_case_conversion() {
    printf("Testing case conversion...\n");
    
    // Redirect stdout to capture output
    char buffer[256];
    freopen("nul", "w", stdout);
    
    // Test uppercase
    toUpperCase("hello");
    assert(strcmp(buffer, "HELLO\n") == 0);
    
    // Test lowercase
    toLowerCase("WORLD");
    assert(strcmp(buffer, "world\n") == 0);
    
    // Restore stdout
    freopen("CON", "w", stdout);
    printf("Case conversion tests passed!\n");
}

int main() {
    printf("Starting tests...\n\n");
    
    test_history();
    test_calculator();
    test_case_conversion();
    
    printf("\nAll tests completed successfully!\n");
    return 0;
}