/**
 * This is an example of more complex function usage in C.
 * Read structs.c before continuing.
 */

#include <stdio.h>

// Good reference:
// http://www.dirac.org/linux/programming/tutorials/function_pointers/

typedef struct {
    int legs;
    void (*sayName)(void);
} Animal;

void catSayName() {
    printf("I am a cat.\n");
}

void dogSayName() {
    printf("I am a dog.\n");
}

int sub(int a, int b) {
    return a - b;
}

int sum(int a, int b) {
    return a + b;
}

double sum_d(double a, double b) { return a + b; } // would fail if passed to operate: operate(sum_d, 1, 2)

int operate(int (*f)(int, int), int a, int b) {
    return f(a, b);
}

void do_nothing(void) {
    return;
}

int main() {
    Animal cat;
    cat.legs = 4;
    cat.sayName = catSayName;

    Animal cat1;
    cat1.legs = 4;
    cat1.sayName = catSayName;

    Animal dog;
    dog.legs = 3;
    dog.sayName = dogSayName;

    cat.sayName(); // I am a cat.
    dog.sayName(); // I am a dog.
    cat.sayLegs(cat.legs);

    int my_sum = operate(sum, 1, 2);
    printf("%d\n", my_sum); // Prints 3
    int my_sub = operate(sub, 11, 2);
    printf("%d\n", my_sub); // Prints 9

    do_nothing();
}