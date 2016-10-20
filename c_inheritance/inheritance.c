#include <stdlib.h>
#include <stdio.h>

/* Inheritance emulation using Animal as abstract base class. */
typedef struct Animal_vtable {
  void (*eat)(void *);
  void (*sound)(void *);
} Animal_vtable;

typedef struct Animal {
  Animal_vtable *vtable;
} Animal;

void Animal_eat(Animal *animal) {
  animal->vtable->eat(animal);
}

void Animal_sound(Animal *animal) {
  animal->vtable->sound(animal);
}

typedef struct Dog {
  Animal base;
} Dog;

void Dog_eat(Dog *dog);
void Dog_sound(Dog *dog);

/* Assume Dog does not add more virtual functions. */
Animal_vtable Dog_vtable = {
  (void (*)(void *))Dog_eat,
  (void (*)(void *))Dog_sound
};

typedef struct Cat {
  Animal base;
} Cat;

void Cat_eat(Cat *cat);
void Cat_sound(Cat *cat);

/* Assume Cat does not add more virtual functions. */
Animal_vtable Cat_vtable = {
  (void (*)(void *))Cat_eat,
  (void (*)(void *))Cat_sound
};

/* Implementations. */

void Dog_eat(Dog *dog) {
  printf("Eating dog chow\n");
}

void Dog_sound(Dog *dog) {
  printf("Woof!\n");
}

Dog *new_Dog(void) {
  Dog *dog = malloc(sizeof(Dog));
  dog->base.vtable = &Dog_vtable;
  return dog;
}

void Cat_eat(Cat *cat) {
  printf("Eating mouse\n");
}

void Cat_sound(Cat *cat) {
  printf("Meow!\n");
}

Cat *new_Cat(void) {
  Cat *cat = malloc(sizeof(Cat));
  cat->base.vtable = &Cat_vtable;
  return cat;
}

int main(void) {
  Animal *animal = (Animal *)new_Dog();
  Animal_eat(animal);
  Animal_sound(animal);

  animal = (Animal *)new_Cat();
  Animal_eat(animal);
  Animal_sound(animal);

  return 0;
}
