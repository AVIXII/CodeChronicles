#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    BITSET CHEAT SHEET — C++20
    ============================================================

    CORE / MUST KNOW
    ----------------
    std::bitset<N>:
        Fixed-size sequence of N bits.

    Common operations:
        test / operator[]       O(1) per bit
        set / reset / flip      O(1) per bit
        count                   O(N) conceptually
        any / all / none        O(N) worst case
        &, |, ^, ~              O(N) over the bitset
        <<, >>                  O(N) over the bitset
        size                    O(1)
        to_string               O(N)
        to_ullong / to_ulong    conversion; may throw on overflow

    EXTRAS / REFERENCE
    ------------------
    whole-set modifiers, custom string digits, stream I/O,
    hash support, vector<bool>/dynamic bitsets, C++20 <bit>
    bit utilities, manual bit operations, etc.
*/

int main() {

    // ============================================================
    // CORE — MUST KNOW
    // ============================================================

    // ------------------------------------------------------------
    // 1. INITIALISATION
    // ------------------------------------------------------------

    bitset<10> s1;                  // 0000000000

    // 9-bit string is padded with leading zero to fit 10 bits.
    bitset<10> s2("100100101");     // 0100100101

    // From an unsigned integer:
    bitset<10> s3(13);              // 0000001101

    cout << "s1: " << s1 << '\n';
    cout << "s2: " << s2 << '\n';
    cout << "s3: " << s3 << '\n';

    // ------------------------------------------------------------
    // 2. SIZE
    // ------------------------------------------------------------

    cout << "Size: " << s2.size() << '\n';   // 10

    // The size is fixed at compile time.

    // ------------------------------------------------------------
    // 3. COUNT SET BITS
    // ------------------------------------------------------------

    cout << "Number of 1s: "
         << s2.count() << '\n';

    // TC: O(N) conceptually
    // N = bitset width

    // ------------------------------------------------------------
    // 4. CHECK ANY / ALL / NONE
    // ------------------------------------------------------------

    cout << "Any set?  " << s2.any() << '\n';
    cout << "All set?  " << s2.all() << '\n';
    cout << "None set? " << s2.none() << '\n';

    // ------------------------------------------------------------
    // 5. ACCESS INDIVIDUAL BIT
    // ------------------------------------------------------------

    // Bit index 0 is the least-significant/rightmost bit
    // in the usual string representation.

    bool bit0 = s2[0];               // O(1)

    bool bit3 = s2.test(3);          // O(1), bounds-checked

    cout << "bit 0: " << bit0 << '\n';
    cout << "bit 3: " << bit3 << '\n';

    // IMPORTANT:
    // test(pos) throws std::out_of_range if pos >= size().
    // operator[] does not perform bounds checking.

    // ------------------------------------------------------------
    // 6. SET INDIVIDUAL BIT
    // ------------------------------------------------------------

    s1.set(2);                       // Set bit 2 to 1
    s1.set(5, false);                // Explicitly set bit 5 to 0

    cout << "After set: " << s1 << '\n';

    // ------------------------------------------------------------
    // 7. RESET INDIVIDUAL / ALL BITS
    // ------------------------------------------------------------

    s1.reset(2);                     // Set bit 2 to 0
    s1.reset();                      // Reset all bits to 0

    // ------------------------------------------------------------
    // 8. FLIP INDIVIDUAL / ALL BITS
    // ------------------------------------------------------------

    s1.flip(1);                      // Toggle bit 1
    s1.flip();                       // Toggle every bit

    cout << "After flip: " << s1 << '\n';

    // ------------------------------------------------------------
    // 9. BITWISE OPERATIONS
    // ------------------------------------------------------------

    bitset<10> a("1010101010");
    bitset<10> b("1001001011");

    bitset<10> andAns = a & b;
    bitset<10> orAns  = a | b;
    bitset<10> xorAns = a ^ b;
    bitset<10> notAns = ~a;

    cout << "A & B: " << andAns << '\n';
    cout << "A | B: " << orAns  << '\n';
    cout << "A ^ B: " << xorAns << '\n';
    cout << "~A:    " << notAns << '\n';

    // Compound forms:
    a &= b;
    a |= b;
    a ^= b;

    // ------------------------------------------------------------
    // 10. SHIFT
    // ------------------------------------------------------------

    bitset<10> sh("0000011010");

    bitset<10> leftShift  = sh << 2;
    bitset<10> rightShift = sh >> 2;

    cout << "Left shift:  " << leftShift << '\n';
    cout << "Right shift: " << rightShift << '\n';

    // In-place:
    sh <<= 1;
    sh >>= 1;

    // Bits shifted beyond the fixed width are discarded.

    // ------------------------------------------------------------
    // 11. STRING CONVERSION
    // ------------------------------------------------------------

    string binary = s2.to_string();

    cout << "String: " << binary << '\n';

    // ------------------------------------------------------------
    // 12. INTEGER CONVERSION
    // ------------------------------------------------------------

    bitset<10> numberBits(42);

    unsigned long x = numberBits.to_ulong();
    unsigned long long y = numberBits.to_ullong();

    cout << "to_ulong:  " << x << '\n';
    cout << "to_ullong: " << y << '\n';

    // Conversion can throw overflow_error if the bitset value
    // cannot be represented by the requested integer type.

    // ============================================================
    // EXTRAS — REFERENCE
    // ============================================================

    // ------------------------------------------------------------
    // 13. OPERATOR[] FOR MODIFICATION
    // ------------------------------------------------------------

    bitset<8> mutableBits;

    mutableBits[0] = true;
    mutableBits[3] = false;
    mutableBits[7] = 1;

    cout << "Modified through []: "
         << mutableBits << '\n';

    // Non-const operator[] returns a proxy reference.

    // ------------------------------------------------------------
    // 14. INPUT
    // ------------------------------------------------------------

    /*
        bitset<8> inputBits;
        cin >> inputBits;

        Input must contain a valid bitset string.
    */

    // ------------------------------------------------------------
    // 15. CUSTOM STRING CHARACTERS
    // ------------------------------------------------------------

    bitset<8> custom("10101010");

    cout << custom.to_string('O', 'I') << '\n';
    // I/O-like representation using custom zero/one characters

    // ------------------------------------------------------------
    // 16. STREAM OUTPUT
    // ------------------------------------------------------------

    cout << custom << '\n';

    // ------------------------------------------------------------
    // 17. EQUALITY
    // ------------------------------------------------------------

    bitset<8> e1("10101010");
    bitset<8> e2("10101010");
    bitset<8> e3("00101010");

    cout << boolalpha
         << (e1 == e2) << '\n'
         << (e1 != e3) << '\n';

    // TC: O(N) in general

    // ------------------------------------------------------------
    // 18. MANUAL BIT OPERATIONS WITH INTEGERS
    // ------------------------------------------------------------

    unsigned int mask = 0;

    // Set bit i:
    int i = 3;
    mask |= (1u << i);

    // Test bit i:
    bool isSet = (mask & (1u << i)) != 0;

    // Reset bit i:
    mask &= ~(1u << i);

    // Toggle bit i:
    mask ^= (1u << i);

    cout << "Manual integer mask: "
         << mask << '\n';

    // These patterns are important for DSA bit manipulation.

    // ------------------------------------------------------------
    // 19. POPCOUNT FOR INTEGER (C++20)
    // ------------------------------------------------------------

    unsigned int value = 0b10110100;

    cout << "popcount: "
         << popcount(value) << '\n';

    /*
        <bit> provides bit-level integer utilities such as:

        popcount
        has_single_bit
        countl_zero
        countl_one
        countr_zero
        countr_one
    */

    // ------------------------------------------------------------
    // 20. DYNAMIC BITSET NOTE
    // ------------------------------------------------------------

    /*
        std::bitset<N> requires N at compile time.

        If width must be runtime-sized, alternatives include:
            vector<bool>
            boost::dynamic_bitset<>
            a custom vector<uint64_t>-based implementation

        These are beyond the core std::bitset sheet.
    */

    // ------------------------------------------------------------
    // 21. HASH SUPPORT
    // ------------------------------------------------------------

    /*
        std::hash<bitset<N>> is available.

        This allows bitset to be used with hash-based containers
        such as unordered_set / unordered_map when appropriate.
    */

    return 0;
}
