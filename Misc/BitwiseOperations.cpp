#include <iostream>
#include <bitset>
using namespace std;

void printBits(string label, int n) {
    cout << label << bitset<8>(n) << "  (" << n << ")\n";
}

int main()
{
    int a = 0b00101100;  // 44
    int b = 0b00011010;  // 26

    cout << "a = "; printBits("", a);
    cout << "b = "; printBits("", b);
    cout << "\n";

    // ─────────────────────────────────────────
    // BASIC OPERATORS
    // ─────────────────────────────────────────

    printBits("AND  a & b  = ", a & b);   // 1 only if both bits are 1
    printBits("OR   a | b  = ", a | b);   // 1 if either bit is 1
    printBits("XOR  a ^ b  = ", a ^ b);   // 1 if bits are different
    printBits("NOT  ~a     = ", ~a);       // flip all bits
    printBits("SHL  a << 2 = ", a << 2);  // multiply by 4
    printBits("SHR  a >> 2 = ", a >> 2);  // divide by 4
    cout << "\n";

    // ─────────────────────────────────────────
    // COMMON TRICKS
    // ─────────────────────────────────────────

    int n = 44;

    // check if even/odd
    cout << "Is odd:           " << (n & 1) << "\n";         // 0 = even, 1 = odd

    // check if power of 2
    cout << "Is power of 2:    " << (n && !(n & (n-1))) << "\n";

    // get nth bit  (0-indexed from right)
    int bit = 3;
    cout << "Get bit " << bit << ":        " << ((n >> bit) & 1) << "\n";

    // set nth bit
    printBits("Set bit 1:        ", n | (1 << 1));

    // clear nth bit
    printBits("Clear bit 3:      ", n & ~(1 << 3));

    // toggle nth bit
    printBits("Toggle bit 2:     ", n ^ (1 << 2));

    // clear lowest set bit
    printBits("Clear lowest bit: ", n & (n - 1));

    // isolate lowest set bit
    printBits("Isolate lowest:   ", n & (-n));

    // count set bits (Brian Kernighan)
    int count = 0, temp = n;
    while (temp) { temp &= (temp - 1); count++; }
    cout << "Count set bits:   " << count << "\n";

    // swap without temp
    int x = 5, y = 9;
    x ^= y; y ^= x; x ^= y;
    cout << "Swap x,y:         x=" << x << " y=" << y << "\n";  // x=9 y=5

    // multiply / divide by power of 2
    cout << "n * 8  (n<<3):    " << (n << 3) << "\n";
    cout << "n / 4  (n>>2):    " << (n >> 2) << "\n";

    // check if two numbers have opposite signs
    int p = 5, q = -3;
    cout << "Opposite signs:   " << ((p ^ q) < 0) << "\n";  // 1 = yes
    cout << "\n";

    // ─────────────────────────────────────────
    // XOR TRICKS
    // ─────────────────────────────────────────

    // XOR with itself = 0
    cout << "5 ^ 5 = " << (5 ^ 5) << "\n";   // 0

    // XOR with 0 = same number
    cout << "5 ^ 0 = " << (5 ^ 0) << "\n";   // 5

    // find the one unique number in array where all others appear twice
    int arr[] = {2, 3, 5, 3, 2};
    int unique = 0;
    for (int x : arr) unique ^= x;
    cout << "Unique number:    " << unique << "\n";  // 5

    return 0;
}
