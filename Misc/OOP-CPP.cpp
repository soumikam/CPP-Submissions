#include <iostream>
#include <string>
using namespace std;

// ═════════════════════════════════════════════════════
// 1. CLASS & OBJECT
//    class = blueprint, object = instance of the class
// ═════════════════════════════════════════════════════

class Animal
{
// ─────────────────────────────────────────
// 2. ACCESS SPECIFIERS
//    private   → only accessible inside the class
//    protected → accessible inside class + derived classes
//    public    → accessible from anywhere
// ─────────────────────────────────────────
private:
    string name;
    int age;

public:
// ─────────────────────────────────────────
// 3. CONSTRUCTOR & DESTRUCTOR
//    constructor → called automatically when object is created
//    destructor  → called automatically when object is destroyed
// ─────────────────────────────────────────
    Animal(string n, int a) : name(n), age(a)
    {
        cout << name << " created\n";
    }

    ~Animal()
    {
        cout << name << " destroyed\n";
    }

// ─────────────────────────────────────────
// 4. ENCAPSULATION
//    private data exposed only through public getters/setters
// ─────────────────────────────────────────
    string getName() const { return name; }
    int    getAge()  const { return age;  }
    void   setAge(int a)   { if (a > 0) age = a; }

// ─────────────────────────────────────────
// 5. VIRTUAL FUNCTION (enables polymorphism)
//    virtual → can be overridden by derived class
//    = 0     → pure virtual, makes class abstract
// ─────────────────────────────────────────
    virtual void speak() const
    {
        cout << name << " makes a sound\n";
    }

    virtual string type() const = 0;  // pure virtual → Animal is abstract
};

// ═════════════════════════════════════════════════════
// 6. INHERITANCE
//    Dog inherits all public/protected members of Animal
// ═════════════════════════════════════════════════════

class Dog : public Animal
{
private:
    string breed;

public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}

// ─────────────────────────────────────────
// 7. POLYMORPHISM — FUNCTION OVERRIDING
//    same function name, different behavior in derived class
// ─────────────────────────────────────────
    void speak() const override
    {
        cout << getName() << " barks\n";
    }

    string type() const override { return "Dog"; }
    string getBreed() const      { return breed; }
};

class Cat : public Animal
{
public:
    Cat(string n, int a) : Animal(n, a) {}

    void speak() const override
    {
        cout << getName() << " meows\n";
    }

    string type() const override { return "Cat"; }
};

// ═════════════════════════════════════════════════════
// 8. FUNCTION OVERLOADING (compile-time polymorphism)
//    same name, different parameters
// ═════════════════════════════════════════════════════

class Calculator
{
public:
    int    add(int a, int b)          { return a + b; }
    double add(double a, double b)    { return a + b; }
    int    add(int a, int b, int c)   { return a + b + c; }
};

// ═════════════════════════════════════════════════════
// 9. OPERATOR OVERLOADING
// ═════════════════════════════════════════════════════

class Vector2D
{
public:
    float x, y;
    Vector2D(float x, float y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const
    {
        return Vector2D(x + other.x, y + other.y);
    }

    void print() const { cout << "(" << x << ", " << y << ")\n"; }
};

// ═════════════════════════════════════════════════════
// 10. STATIC MEMBERS
//     shared across ALL instances of the class
// ═════════════════════════════════════════════════════

class Counter
{
private:
    static int count;  // shared by all objects

public:
    Counter()  { count++; }
    ~Counter() { count--; }
    static int getCount() { return count; }
};

int Counter::count = 0;  // must define static member outside class

// ═════════════════════════════════════════════════════
// 11. COPY CONSTRUCTOR
//     called when object is copied
// ═════════════════════════════════════════════════════

class Box
{
public:
    int* data;

    Box(int val)
    {
        data = new int(val);
    }

    // deep copy — allocates new memory instead of copying pointer
    Box(const Box& other)
    {
        data = new int(*other.data);
        cout << "Copy constructor called\n";
    }

    ~Box() { delete data; }
};

// ═════════════════════════════════════════════════════
// 12. FRIEND FUNCTION
//     non-member function that can access private members
// ═════════════════════════════════════════════════════

class Secret
{
private:
    int value = 42;
    friend void reveal(Secret& s);  // grant access
};

void reveal(Secret& s)
{
    cout << "Secret value: " << s.value << "\n";
}

// ═════════════════════════════════════════════════════
// MAIN
// ═════════════════════════════════════════════════════

int main()
{
    cout << "── Inheritance & Polymorphism ──\n";
    Dog dog("Rex",  3, "Labrador");
    Cat cat("Luna", 2);

    dog.speak();   // Rex barks
    cat.speak();   // Luna meows

    // runtime polymorphism via base pointer
    Animal* animals[] = {&dog, &cat};
    for (Animal* a : animals)
    {
        cout << a->type() << ": ";
        a->speak();
    }

    cout << "\n── Encapsulation ──\n";
    dog.setAge(4);
    cout << dog.getName() << " age: " << dog.getAge() << "\n";

    cout << "\n── Overloading ──\n";
    Calculator calc;
    cout << "int add:    " << calc.add(1, 2)       << "\n";  // 3
    cout << "double add: " << calc.add(1.5, 2.5)   << "\n";  // 4.0
    cout << "3-arg add:  " << calc.add(1, 2, 3)    << "\n";  // 6

    cout << "\n── Operator Overloading ──\n";
    Vector2D v1(1, 2), v2(3, 4);
    Vector2D v3 = v1 + v2;
    v3.print();  // (4, 6)

    cout << "\n── Static Members ──\n";
    {
        Counter c1, c2, c3;
        cout << "Count: " << Counter::getCount() << "\n";  // 3
    }
    cout << "Count: " << Counter::getCount() << "\n";  // 0 (destructors ran)

    cout << "\n── Copy Constructor ──\n";
    Box b1(10);
    Box b2 = b1;  // copy constructor called
    *b2.data = 99;
    cout << "b1: " << *b1.data << "\n";  // 10 (unchanged — deep copy)
    cout << "b2: " << *b2.data << "\n";  // 99

    cout << "\n── Friend Function ──\n";
    Secret s;
    reveal(s);  // 42

    return 0;
}
