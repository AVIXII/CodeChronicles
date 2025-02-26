#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    // Initialisation
    bitset<10> s1;              // 000000000
    bitset<10> s2("100100101"); // Appends zeroes from left if lesser number of bits than specified while declaring

    // Print the bitset
    cout << s1 << endl;

    // Number of ones
    cout << s2 << " " << s2.count() << endl;

    // Flip the bits
    cout << s2.flip() << endl;

    // Bit operations
    bitset<10> ans = s1 & s2; // Similarly we can use &, | and ^

    return 0;
}