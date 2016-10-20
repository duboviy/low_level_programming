/**
 * This is a collection of pointer examples.
 * It is a fun way to test yourself. I'm
 * sorry I couldn't think of a better way
 * to show the answers.
 */

#include <stdio.h>

void print(int i) {
    printf("%d\n", i);
}

int main() {
    int* myInt;
    int myIntsValue = 3;
    myInt = &myIntsValue; // int* somePointer; *somePointer = myIntsValue; myInt = somePointer;
    print(*myInt); // prints 3
    int mySecondInt = 2;
    *myInt = mySecondInt;
    print(*myInt); // prints 2
    print(mySecondInt); // prints 2
    print(myIntsValue); // prints 2
    myInt = &mySecondInt; // int* somePointer; *somePointer = mySecondInt; myInt = somePointer;
    mySecondInt = 5;
    print(*myInt); // prints 5
    myIntsValue = 7;
    print(*myInt); // prints 5
    mySecondInt = myIntsValue;
    print(*myInt); // prints 7
}