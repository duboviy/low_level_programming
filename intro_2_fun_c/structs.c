/**
 * This is a brief example of typedef-ing and structs in C.
 */

typedef int Int; // int or Int

struct Person {
    char* name;
    Int age;
};

typedef struct Person APerson; // struct Person or APerson

typedef struct Animal {
    int legs;
} Animal; // struct Animal or Animal

typedef struct {
    int mpg;
} Car; // cannot use struct Car, can only use Car... the struct is anonymous

int main() {
    APerson person; // could use "struct Person person"
    person.name = "Phil";
    person.age = 10;

    Animal cat; // could use "struct Animal cat;"
    cat.legs = 4;

    Car car; // could not use "struct Car car;" because the struct was anonymous
    car.mpg = 30;
}