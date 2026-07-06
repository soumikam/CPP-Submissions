#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ═════════════════════════════════════════════════════════════════════════════
// S — SINGLE RESPONSIBILITY PRINCIPLE
// A class should have only ONE reason to change.
// Each class does exactly one job.
// ═════════════════════════════════════════════════════════════════════════════

// BAD — one class handles both employee data AND saving to database
class Employee_BAD
{
public:
    string name;
    void getDetails()  { cout << "Employee: " << name << endl; }
    void saveToDB()    { cout << "Saving " << name << " to DB..." << endl; } // NOT its job
};

// GOOD — split into two classes, each with one responsibility
class Employee
{
public:
    string name;
    Employee(string n) : name(n) {}
    void getDetails() { cout << "Employee: " << name << endl; }
};

class EmployeeDB
{
public:
    void save(Employee& e) { cout << "Saving " << e.name << " to DB..." << endl; }
};

void SRP_Demo()
{
    cout << "── S: Single Responsibility ──" << endl;
    Employee emp("Alice");
    emp.getDetails();
    EmployeeDB db;
    db.save(emp);
    cout << endl;
}

// ═════════════════════════════════════════════════════════════════════════════
// O — OPEN/CLOSED PRINCIPLE
// Classes should be OPEN for extension, CLOSED for modification.
// Add new behaviour by adding new classes, not editing existing ones.
// ═════════════════════════════════════════════════════════════════════════════

// BAD — adding a new shape requires editing existing code
class AreaCalc_BAD
{
public:
    double area(string shape, double a, double b = 0)
    {
        if(shape == "rectangle") return a * b;
        if(shape == "circle")    return 3.14 * a * a;
        // adding triangle means editing this function — BAD
        return 0;
    }
};

// GOOD — extend by adding a new class, never touch existing ones
class Shape
{
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() override { return w * h; }
};

class Circle : public Shape
{
    double r;
public:
    Circle(double r) : r(r) {}
    double area() override { return 3.14 * r * r; }
};

class Triangle : public Shape  // new shape — no existing code touched
{
    double b, h;
public:
    Triangle(double b, double h) : b(b), h(h) {}
    double area() override { return 0.5 * b * h; }
};

void OCP_Demo()
{
    cout << "── O: Open/Closed ──" << endl;
    vector<Shape*> shapes = { new Rectangle(4,5), new Circle(3), new Triangle(6,4) };
    for(Shape* s : shapes)
        cout << "Area: " << s->area() << endl;
    for(Shape* s : shapes) delete s;
    cout << endl;
}

// ═════════════════════════════════════════════════════════════════════════════
// L — LISKOV SUBSTITUTION PRINCIPLE
// A derived class must be substitutable for its base class
// without breaking the program.
// ═════════════════════════════════════════════════════════════════════════════

// BAD — Penguin cannot fly, but is forced to override fly()
class Bird_BAD
{
public:
    virtual void fly() { cout << "Flying!" << endl; }
};

class Penguin_BAD : public Bird_BAD
{
public:
    void fly() override { cout << "ERROR: Penguins can't fly!" << endl; } // violates LSP
};

// GOOD — split into FlyingBird and NonFlyingBird
class Bird
{
public:
    virtual void eat() { cout << "Eating..." << endl; }
    virtual ~Bird() {}
};

class FlyingBird : public Bird
{
public:
    virtual void fly() { cout << "Flying!" << endl; }
};

class Sparrow : public FlyingBird
{
public:
    void fly() override { cout << "Sparrow flying!" << endl; }
};

class Penguin : public Bird  // no fly() — correct
{
public:
    void swim() { cout << "Penguin swimming!" << endl; }
};

void LSP_Demo()
{
    cout << "── L: Liskov Substitution ──" << endl;
    FlyingBird* b = new Sparrow();
    b->fly();   // works correctly for all FlyingBirds
    Penguin p;
    p.swim();
    delete b;
    cout << endl;
}

// ═════════════════════════════════════════════════════════════════════════════
// I — INTERFACE SEGREGATION PRINCIPLE
// Don't force a class to implement methods it doesn't need.
// Many small interfaces > one large interface.
// ═════════════════════════════════════════════════════════════════════════════

// BAD — Robot is forced to implement eat() it doesn't need
class Worker_BAD
{
public:
    virtual void work() = 0;
    virtual void eat()  = 0;  // robots don't eat!
};

class Robot_BAD : public Worker_BAD
{
public:
    void work() override { cout << "Robot working" << endl; }
    void eat()  override { cout << "ERROR: Robots don't eat!" << endl; } // forced — BAD
};

// GOOD — split into two interfaces
class Workable
{
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};

class Eatable
{
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};

class HumanWorker : public Workable, public Eatable
{
public:
    void work() override { cout << "Human working" << endl; }
    void eat()  override { cout << "Human eating"  << endl; }
};

class RobotWorker : public Workable  // only implements what it needs
{
public:
    void work() override { cout << "Robot working" << endl; }
};

void ISP_Demo()
{
    cout << "── I: Interface Segregation ──" << endl;
    HumanWorker human;
    human.work();
    human.eat();
    RobotWorker robot;
    robot.work();
    cout << endl;
}

// ═════════════════════════════════════════════════════════════════════════════
// D — DEPENDENCY INVERSION PRINCIPLE
// High-level modules should not depend on low-level modules.
// Both should depend on abstractions (interfaces).
// ═════════════════════════════════════════════════════════════════════════════

// BAD — Notification is tightly coupled to Email
class Email_BAD
{
public:
    void send(string msg) { cout << "Email: " << msg << endl; }
};

class Notification_BAD
{
    Email_BAD email;  // directly depends on concrete class — BAD
public:
    void notify(string msg) { email.send(msg); }
};

// GOOD — depend on an abstraction (MessageSender interface)
class MessageSender
{
public:
    virtual void send(string msg) = 0;
    virtual ~MessageSender() {}
};

class EmailSender : public MessageSender
{
public:
    void send(string msg) override { cout << "Email: " << msg << endl; }
};

class SMSSender : public MessageSender
{
public:
    void send(string msg) override { cout << "SMS: " << msg << endl; }
};

class Notification  // depends on abstraction, not concrete class
{
    MessageSender* sender;
public:
    Notification(MessageSender* s) : sender(s) {}
    void notify(string msg) { sender->send(msg); }
};

void DIP_Demo()
{
    cout << "── D: Dependency Inversion ──" << endl;
    EmailSender email;
    SMSSender   sms;

    Notification n1(&email);
    n1.notify("Hello via Email!");

    Notification n2(&sms);
    n2.notify("Hello via SMS!");
    cout << endl;
}

int main()
{
    SRP_Demo();
    OCP_Demo();
    LSP_Demo();
    ISP_Demo();
    DIP_Demo();
    return 0;
}
