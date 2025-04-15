// Console-based Quiz Application in C
#include <stdio.h>
#include <string.h>

struct Question {
    char question[128];
    char answer[64];
};

int main() {
    struct Question quiz[] = {
        {"What is the capital of France?", "Paris"},
        {"What is 2 + 2?", "4"},
        {"Who wrote 'C'?", "Dennis Ritchie"}
    };
    int n = sizeof(quiz) / sizeof(quiz[0]);
    char user_answer[64];
    int score = 0;
    for (int i = 0; i < n; i++) {
        printf("%s\n", quiz[i].question);
        printf("Your answer: ");
        fgets(user_answer, sizeof(user_answer), stdin);
        user_answer[strcspn(user_answer, "\n")] = 0;
        if (strcasecmp(user_answer, quiz[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The answer is %s\n", quiz[i].answer);
        }
    }
    printf("Your score: %d/%d\n", score, n);
    return 0;
}
