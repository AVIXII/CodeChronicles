// Data Types in C++20 — DSA / Competitive Programming Reference
// Runnable reference file. Compile with: g++ -std=c++20 data_types_cpp.cpp -o data_types_cpp

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdint>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <typeinfo>
#include <type_traits>
#include <cstddef>
#include <utility>
#include <algorithm>

using namespace std;

// ------------------------------
// User-defined types
// ------------------------------
struct Point {
    int x;
    int y;
};

class Box {
public:
    int value;

    explicit Box(int v = 0) : value(v) {}
};

union Data {
    int i;
    float f;
};

enum Color { RED, GREEN, BLUE };

enum class Direction {
    LEFT,
    RIGHT
};

// Function type / pointer to function
int add(int a, int b) {
    return a + b;
}

void section(const string& title) {
    cout << "\n===== " << title << " =====\n";
}

int main() {
    // ============================================================
    // CORE / MUST KNOW
    // ============================================================

    section("1. Fundamental / Primitive Types");

    // Integral
    int i = 42;
    short sh = 100;
    long lg = 100000L;
    long long ll = 10000000000LL;
    unsigned int ui = 42U;
    unsigned long long ull = 100000000000ULL;

    // Character / boolean
    char ch = 'A';
    signed char sch = -10;
    unsigned char uch = 250;
    bool flag = true;

    // Floating-point
    float f = 3.14f;
    double d = 3.141592653589793;
    long double ld = 3.141592653589793L;

    cout << "int: " << i << "\n";
    cout << "short: " << sh << "\n";
    cout << "long: " << lg << "\n";
    cout << "long long: " << ll << "\n";
    cout << "unsigned int: " << ui << "\n";
    cout << "unsigned long long: " << ull << "\n";
    cout << "char: " << ch << "\n";
    cout << "signed char as integer: " << static_cast<int>(sch) << "\n";
    cout << "unsigned char as integer: " << static_cast<int>(uch) << "\n";
    cout << boolalpha << "bool: " << flag << "\n";
    cout << setprecision(17);
    cout << "float: " << f << "\n";
    cout << "double: " << d << "\n";
    cout << "long double: " << ld << "\n";

    // void: no object of type void can be created directly.
    // It is commonly used for functions that return nothing.
    auto print_hello = []() -> void {
        cout << "void function called\n";
    };
    print_hello();

    section("2. Size / Range Checks");

    // sizeof gives the number of bytes occupied by an object/type.
    // C++ guarantees sizeof(char) == 1, but the number of bits in a byte
    // is implementation-defined.
    cout << "sizeof(char)       = " << sizeof(char) << " bytes\n";
    cout << "sizeof(bool)       = " << sizeof(bool) << " bytes\n";
    cout << "sizeof(short)      = " << sizeof(short) << " bytes\n";
    cout << "sizeof(int)        = " << sizeof(int) << " bytes\n";
    cout << "sizeof(long)       = " << sizeof(long) << " bytes\n";
    cout << "sizeof(long long)  = " << sizeof(long long) << " bytes\n";
    cout << "sizeof(float)      = " << sizeof(float) << " bytes\n";
    cout << "sizeof(double)     = " << sizeof(double) << " bytes\n";
    cout << "sizeof(long double)= " << sizeof(long double) << " bytes\n";

    cout << "int min = " << numeric_limits<int>::min()
         << ", max = " << numeric_limits<int>::max() << "\n";
    cout << "long long min = " << numeric_limits<long long>::min()
         << ", max = " << numeric_limits<long long>::max() << "\n";
    cout << "unsigned int max = " << numeric_limits<unsigned int>::max() << "\n";

    // Exact-width integers when available.
    int32_t a32 = 123;
    int64_t a64 = 1234567890123LL;
    uint64_t u64 = 1234567890123ULL;
    cout << "int32_t: " << a32 << "\n";
    cout << "int64_t: " << a64 << "\n";
    cout << "uint64_t: " << u64 << "\n";

    section("3. Literals / Initialization");

    int dec = 42;
    int hex = 0x2A;
    int oct = 052;
    int bin = 0b101010;
    long long big = 1'000'000'000'000LL;

    char c1 = 'A';
    char newline = '\n';
    bool t = true;

    float fs = 3.14f;
    double ds = 3.14;
    long double lds = 3.14L;

    int zero_init{};     // 0
    int explicit_init = 7;
    int list_init{8};   // preferred safe initialization style

    cout << dec << ' ' << hex << ' ' << oct << ' ' << bin << ' ' << big << "\n";
    cout << c1 << " | newline char code = "
         << static_cast<int>(newline) << " | " << boolalpha << t << "\n";
    cout << fs << ' ' << ds << ' ' << lds << "\n";
    cout << zero_init << ' ' << explicit_init << ' ' << list_init << "\n";

    section("4. Modifiers / Integral Family");

    signed int si = -10;
    unsigned int non_negative = 10;
    short int short_int = 10;
    long int long_int = 100000L;
    long long int long_long_int = 10000000000LL;

    cout << si << ' ' << non_negative << ' '
         << short_int << ' ' << long_int << ' ' << long_long_int << "\n";

    section("5. Arrays / Pointers / References / Functions");

    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = &arr[0];
    int& ref = arr[0];

    ref = 99;
    cout << "array[0] through reference = " << arr[0] << "\n";
    cout << "pointer dereference = " << *ptr << "\n";
    cout << "pointer arithmetic arr[2] = " << *(ptr + 2) << "\n";
    cout << "array size = " << (sizeof(arr) / sizeof(arr[0])) << "\n";

    cout << "function result = " << add(2, 3) << "\n";
    int (*func_ptr)(int, int) = &add;
    cout << "function pointer result = " << func_ptr(4, 5) << "\n";

    // nullptr has type std::nullptr_t and is the null pointer literal.
    int* null_ptr = nullptr;
    cout << "null pointer? " << boolalpha << (null_ptr == nullptr) << "\n";

    section("6. User-Defined Types");

    Point p{10, 20};
    Box b(50);

    cout << "Point: (" << p.x << ", " << p.y << ")\n";
    cout << "Box value: " << b.value << "\n";

    Data data{};
    data.i = 123; // active member is i
    cout << "union active member i = " << data.i << "\n";

    Color color = GREEN;
    Direction direction = Direction::RIGHT;

    cout << "unscoped enum value = " << color << "\n";
    cout << "enum class value = "
         << static_cast<int>(direction) << "\n";

    section("7. Type Aliases");

    using Marks = int;
    typedef float Score;

    Marks marks = 95;
    Score score = 91.5f;

    cout << "Marks = " << marks << ", Score = " << score << "\n";

    // auto deduces a type from the initializer.
    auto x = 42;       // int
    auto y = 3.14;     // double
    auto z = "hello";  // const char*

    cout << "auto values: " << x << ", " << y << ", " << z << "\n";

    // decltype obtains a type from an expression/name.
    decltype(x) another_int = 100;
    cout << "decltype(x) value = " << another_int << "\n";

    section("8. Common STL Types");

    string s = "hello";
    vector<int> v = {1, 2, 3};
    array<int, 3> stl_array = {4, 5, 6};
    map<string, int> mp = {{"alice", 1}, {"bob", 2}};
    set<int> st = {1, 2, 2, 3};

    cout << s << "\n";
    cout << v.size() << ' ' << stl_array.size() << ' '
         << mp["alice"] << ' ' << st.size() << "\n";

    section("9. Conversions / Casting");

    int integer = 5;
    double promoted = integer;          // implicit: int -> double
    double real = 9.99;
    int truncated = static_cast<int>(real); // 9

    long long large_int = 123456789LL;
    int narrowed = static_cast<int>(large_int);

    cout << "promoted = " << promoted << "\n";
    cout << "truncated = " << truncated << "\n";
    cout << "narrowed = " << narrowed << "\n";

    // bool conversion
    cout << "bool(0) = " << static_cast<bool>(0)
         << ", bool(7) = " << static_cast<bool>(7) << "\n";

    section("10. Useful Type Traits");

    cout << "is_integral<int> = " << is_integral_v<int> << "\n";
    cout << "is_floating_point<double> = " << is_floating_point_v<double> << "\n";
    cout << "is_pointer<int*> = " << is_pointer_v<int*> << "\n";
    cout << "is_same<int, int> = " << is_same_v<int, int> << "\n";

    // ============================================================
    // EXTRAS / REFERENCE
    // ============================================================

    section("EXTRAS: Character / Wide Character Types");

    char8_t c8 = u8'A';
    char16_t c16 = u'A';
    char32_t c32 = U'A';
    wchar_t wc = L'A';

    cout << "char8_t code = " << static_cast<unsigned int>(c8) << "\n";
    cout << "char16_t code = " << static_cast<unsigned int>(c16) << "\n";
    cout << "char32_t code = " << static_cast<unsigned int>(c32) << "\n";
    cout << "wchar_t code = " << static_cast<unsigned int>(wc) << "\n";

    section("EXTRAS: Signedness / Limits");

    cout << "char is signed? " << numeric_limits<char>::is_signed << "\n";
    cout << "float digits = " << numeric_limits<float>::digits << "\n";
    cout << "double digits = " << numeric_limits<double>::digits << "\n";
    cout << "double epsilon = " << numeric_limits<double>::epsilon() << "\n";
    cout << "double infinity supported? "
         << numeric_limits<double>::has_infinity << "\n";
    cout << "unsigned wrap example: "
         << numeric_limits<unsigned int>::max() << " + 1 -> "
         << (numeric_limits<unsigned int>::max() + 1u) << "\n";

    section("EXTRAS: Type Introspection");

    cout << "typeid(x).name() is implementation-defined text: "
         << typeid(x).name() << "\n";
    cout << "sizeof(Point) = " << sizeof(Point)
         << " (may include padding)\n";
    cout << "sizeof(Data) = " << sizeof(Data)
         << " (overlapping union storage)\n";

    // Const / constexpr / pointer variants
    const int constant = 10;
    constexpr int compile_time = 20;
    const int* pointer_to_const = &constant;
    int mutable_value = 30;
    int* const const_pointer = &mutable_value;

    cout << "const = " << constant
         << ", constexpr = " << compile_time
         << ", *pointer_to_const = " << *pointer_to_const
         << ", const_pointer points to = " << *const_pointer << "\n";

    // Reference vs pointer at a glance
    int original = 7;
    int* p_int = &original;
    int& r_int = original;
    *p_int = 8;
    r_int = 9;
    cout << "original after pointer/reference updates = " << original << "\n";

    cout << "\nAll C++ data-type examples completed.\n";
    return 0;
}
