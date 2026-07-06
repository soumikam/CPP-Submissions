#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ─────────────────────────────────────────
// DECIMAL → BINARY
// ─────────────────────────────────────────
string decToBin(int n)
{
    if (n == 0) return "0";
    string result = "";
    while (n > 0)
    {
        result += (char)('0' + n % 2);
        n /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

// ─────────────────────────────────────────
// BINARY → DECIMAL
// ─────────────────────────────────────────
int binToDec(string bin)
{
    int result = 0;
    for (char c : bin)
    {
        result = result * 2 + (c - '0');
    }
    return result;
}

// ─────────────────────────────────────────
// DECIMAL → HEX
// ─────────────────────────────────────────
string decToHex(int n)
{
    if (n == 0) return "0";
    string hex = "0123456789ABCDEF";
    string result = "";
    while (n > 0)
    {
        result += hex[n % 16];
        n /= 16;
    }
    reverse(result.begin(), result.end());
    return result;
}

// ─────────────────────────────────────────
// HEX → DECIMAL
// ─────────────────────────────────────────
int hexToDec(string hex)
{
    int result = 0;
    for (char c : hex)
    {
        int digit = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
        result = result * 16 + digit;
    }
    return result;
}

// ─────────────────────────────────────────
// DECIMAL → OCTAL
// ─────────────────────────────────────────
string decToOct(int n)
{
    if (n == 0) return "0";
    string result = "";
    while (n > 0)
    {
        result += (char)('0' + n % 8);
        n /= 8;
    }
    reverse(result.begin(), result.end());
    return result;
}

// ─────────────────────────────────────────
// OCTAL → DECIMAL
// ─────────────────────────────────────────
int octToDec(string oct)
{
    int result = 0;
    for (char c : oct)
    {
        result = result * 8 + (c - '0');
    }
    return result;
}

// ─────────────────────────────────────────
// BINARY → HEX  (group 4 bits)
// ─────────────────────────────────────────
string binToHex(string bin)
{
    // pad to multiple of 4
    while (bin.size() % 4 != 0) bin = "0" + bin;

    string hex = "0123456789ABCDEF";
    string result = "";
    for (int i = 0; i < bin.size(); i += 4)
    {
        int val = binToDec(bin.substr(i, 4));
        result += hex[val];
    }
    return result;
}

// ─────────────────────────────────────────
// HEX → BINARY  (expand each digit to 4 bits)
// ─────────────────────────────────────────
string hexToBin(string hex)
{
    string result = "";
    for (char c : hex)
    {
        int val = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
        string bits = "";
        for (int i = 3; i >= 0; i--)
            bits += (char)('0' + ((val >> i) & 1));
        result += bits;
    }
    // remove leading zeros
    size_t start = result.find('1');
    return (start == string::npos) ? "0" : result.substr(start);
}

// ─────────────────────────────────────────
// BINARY → OCTAL  (group 3 bits)
// ─────────────────────────────────────────
string binToOct(string bin)
{
    while (bin.size() % 3 != 0) bin = "0" + bin;

    string result = "";
    for (int i = 0; i < bin.size(); i += 3)
    {
        result += (char)('0' + binToDec(bin.substr(i, 3)));
    }
    return result;
}

// ─────────────────────────────────────────
// OCTAL → BINARY
// ─────────────────────────────────────────
string octToBin(string oct)
{
    return decToBin(octToDec(oct));
}

// ─────────────────────────────────────────
// MAIN — demo
// ─────────────────────────────────────────
int main()
{
    int n = 253;
    cout << "Decimal: " << n << "\n";
    cout << "  → Binary:  " << decToBin(n)  << "\n";  // 11111101
    cout << "  → Hex:     " << decToHex(n)  << "\n";  // FD
    cout << "  → Octal:   " << decToOct(n)  << "\n";  // 375
    cout << "\n";

    cout << "Binary  11111101 → Decimal: " << binToDec("11111101") << "\n";  // 253
    cout << "Hex     FD       → Decimal: " << hexToDec("FD")       << "\n";  // 253
    cout << "Octal   375      → Decimal: " << octToDec("375")      << "\n";  // 253
    cout << "\n";

    cout << "Binary  11111101 → Hex:    " << binToHex("11111101") << "\n";  // FD
    cout << "Hex     FD       → Binary: " << hexToBin("FD")       << "\n";  // 11111101
    cout << "Binary  11111101 → Octal:  " << binToOct("11111101") << "\n";  // 375
    cout << "Octal   375      → Binary: " << octToBin("375")      << "\n";  // 11111101

    return 0;
}
