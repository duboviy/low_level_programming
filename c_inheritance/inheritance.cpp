#include <iostream>

using namespace std;

class Animal {
public:
  virtual void eat() = 0;
  virtual void sound() = 0;
};

class Dog : public Animal {
public:
  virtual void eat() { cout << "Eating dog chow" << endl; }
  virtual void sound() { cout << "Woof!" << endl; }
};

class Cat : public Animal {
public:
  virtual void eat() { cout << "Eating mouse" << endl; }
  virtual void sound() { cout << "Meow!" << endl; }
};

int main(void) {
  Animal *animal = new Dog();
  animal->eat();
  animal->sound();

  animal = new Cat();
  animal->eat();
  animal->sound();

  return 0;
}
