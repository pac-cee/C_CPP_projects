# C Programming: Arrays and Pointers

## Arrays
Arrays are collections of variables of the same type.
```c
int numbers[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    printf("%d\n", numbers[i]);
}
```

## Pointers
Pointers store memory addresses.
```c
int x = 10;
int *p = &x;
printf("Value: %d\n", *p); // Dereferencing
```

## Relationship between Arrays and Pointers
- Array name is a pointer to its first element.
- `numbers` is equivalent to `&numbers[0]`.

## Practice
- Create an array of 10 integers and print their squares.
- Write a function that takes a pointer to an int and sets its value to 100.

---
Next: Structures and file I/O.
