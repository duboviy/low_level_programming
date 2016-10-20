/**
 * This is a continuation of (more complex)
 * pointer examples.
 */

#include <stdio.h>

void print(int i) {
    printf("%d\n", i);
}

void swap1(int a, int b) {
    int temp = b;
    b = a;
    a = temp;
}

void swap2(int* p_a, int* p_b) {
    int temp = *p_b;
    *p_b = *p_a;
    *p_a = temp;
}

int main() {
    int a = 1;
    int b = 2;
    swap1(a, b);
    print(a); // prints 1
    print(b); // prints 2
    swap2(&a, &b);
    print(a); // prints 2
    print(b); // prints 1
    int* c;
    int* d;
    c = &a; // c = some address... but *c = 2
    d = &b; // d = some address... but *d = 1
    swap1(*c, *d);
    print(*c); // prints 2
    print(*d); // prints 1
    swap2(c, d);
    print(*c); // prints 1
    print(*d); // prints 2
}