/**
 * This are a collection of examples for C 201.
 * These combine concepts you may or may not be
 * familiar with and are especially useful for
 * students new to C. There is a lot of really
 * cool stuff you can do in C without any cool
 * languages.
 * 
 * This is file in particular is an introduction
 * to fun function usage in C.
 */

#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

// This function "get_operator" takes a *char expression
// and returns a function that takes two ints and returns
// an int.
int (*get_operator(char* expression)) (int, int) {
    int i;
    // char pointers are automatically given a final character '\0'
    // to allow us to know when the char* ends.
    for (i = 0; expression[i] != '\0'; i++) {
        switch (expression[i]) {
            case '+':
                return sum;
            case '-':
                return sub;
        }
    }
}

void print_operator(char* expression) {
    // get_operator will return a function that takes two ints
    // and returns an int.
    int (*operator)(int, int) = get_operator(expression);
    // sum is automatically converted to a pointer,
    // you could also say "operator == &sum", but that is longer.
    if (operator == sum) { // comparing functions!
        printf("Expression %s is a sum.\n", expression);
    } else if (operator == sub) { // comparing functions again!!
        printf("Expression %s is a sub.\n", expression);
    } else {
        printf("Expression %s has an unknown operation.\n", expression);
    }
    // Challenge:
    // Instead of just printing out which operation it is,
    // find the two operands and perform the operation on them.
    // Then print the result of the expression instead.
}

int main() {
    char* expression1 = "2 + 2";
    char* expression2 = "5 - 3";
    char* expression3 = "9 * 7";

    print_operator(expression1);
    print_operator(expression2);
    print_operator(expression3);
}