# Solutions to C Exercises

## 1. Count the number of words in a file
```c
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *f = fopen("input.txt", "r");
    int count = 0, in_word = 0;
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }
    fclose(f);
    printf("Word count: %d\n", count);
    return 0;
}
```

## 2. Simple Student Record System
```c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student s = {"John Doe", 20, 85.5};
    FILE *f = fopen("students.dat", "wb");
    fwrite(&s, sizeof(struct Student), 1, f);
    fclose(f);
    // Reading back
    struct Student s2;
    f = fopen("students.dat", "rb");
    fread(&s2, sizeof(struct Student), 1, f);
    fclose(f);
    printf("Name: %s, Age: %d, Grade: %.2f\n", s2.name, s2.age, s2.grade);
    return 0;
}
```
