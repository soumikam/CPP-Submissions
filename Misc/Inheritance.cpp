#include <iostream>
#include <string>
using namespace std;

// Base class
class Animal {
public:
    string name;
    Animal(string n) : name(n) {}
    virtual void speak() { cout << "..."; }  // virtual
    virtual ~Animal() {}
};

// Derived class
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    void speak() override { cout << "Woof!"; }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    void speak() override { cout << "Meow!"; }
};

int main() {
    Animal* a1 = new Dog("Rex");
    Animal* a2 = new Cat("Whiskers");

    a1->speak();  // Woof! — polymorphism
    a2->speak();  // Meow!

    delete a1;
    delete a2;
    return 0;
}