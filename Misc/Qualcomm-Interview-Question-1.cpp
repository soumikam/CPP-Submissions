/*
There are two types of registers, integer and float type.
Both types have an address, Integer registers read and write integer values, while,
Float registers read and write float values.
Write classes for this potraying OOP concepts.
*/

#include <iostream>
using namespace std;

// ── ABSTRACTION & ENCAPSULATION ───────────────────────────────────────────────
// Register is an abstract base class. It hides internal address behind private
// access and exposes only a clean public interface.
class Register
{
    private:
        int address;                              // ENCAPSULATION: address is private, hidden from outside
    public:
        Register(int addr) : address(addr){}      // constructor initialises encapsulated data

        virtual void Write() = 0;                 // ABSTRACTION: pure virtual — forces subclasses to implement
        virtual void Read()  = 0;                 // ABSTRACTION: pure virtual — makes Register an abstract class

        int getAddress() const { return address; }// controlled access to private data (getter)
        virtual ~Register() {}                    // virtual destructor — needed for safe delete via base pointer
};

// ── INHERITANCE ───────────────────────────────────────────────────────────────
// IntegerRegister inherits all public members of Register (address, getAddress)
class IntegerRegister : public Register           // INHERITANCE: IntegerRegister IS-A Register
{
    int value;                                    // ENCAPSULATION: value is private to this class
    public:
        IntegerRegister(int addr) : Register(addr), value(0){} // delegates addr to base constructor

        void Write() override                     // POLYMORPHISM: overrides base class pure virtual
        {
            cout << "Enter integer value to write: ";
            cin >> value;
        }

        void Read() override                      // POLYMORPHISM: overrides base class pure virtual
        {
            cout << "Integer Register [" << getAddress() << "] = " << value << endl;
        }
};

// ── INHERITANCE ───────────────────────────────────────────────────────────────
// FloatRegister independently inherits Register — same parent, different behaviour
class FloatRegister : public Register             // INHERITANCE: FloatRegister IS-A Register
{
    float value;                                  // ENCAPSULATION: value is private to this class
    public:
        FloatRegister(int addr) : Register(addr), value(0.0){}

        void Write() override                     // POLYMORPHISM: overrides base class pure virtual
        {
            cout << "Enter float value to write: ";
            cin >> value;
        }

        void Read() override                      // POLYMORPHISM: overrides base class pure virtual
        {
            cout << "Float Register [" << getAddress() << "] = " << value << endl;
        }
};

int main()
{
    IntegerRegister ir(0x01);   // static object — type known at compile time
    ir.Write();
    ir.Read();

    FloatRegister fr(0x02);     // static object — type known at compile time
    fr.Write();
    fr.Read();

    Register* reg = new IntegerRegister(0x03);  // POLYMORPHISM: base pointer holds derived object
    reg->Write();                               // correct Write() called at runtime (dynamic dispatch)
    reg->Read();                                // correct Read()  called at runtime (dynamic dispatch)
    delete reg;                                 // virtual destructor ensures correct cleanup

    return 0;
}
