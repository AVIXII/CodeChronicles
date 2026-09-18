// Miscellaneous C++ — DSA / Competitive Programming Toolbox
// Runnable reference file. Compile with: g++ -std=c++20 misc_cpp.cpp -o misc_cpp
//
// This is intentionally a "weird/useful things I learnt along the way" file:
// small syntax tricks, conversions, gotchas, STL helpers, and CP idioms.

#include <bits/stdc++.h>
using namespace std;

// ============================================================
// CORE / MUST KNOW
// ============================================================

int add(int a, int b) {
    return a + b;
}

void section(const string& title) {
    cout << "\n===== " << title << " =====\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ------------------------------------------------------------
    // 1. string::replace()
    // ------------------------------------------------------------
    section("1. string::replace");

    string s = "rishabh";
    s.replace(0, s.length(), "ahdskfa ");
    cout << s << '\n';

    // replace(pos, count, replacement)
    string t = "abcdef";
    t.replace(2, 2, "XYZ");   // abXYZef
    cout << t << '\n';

    // ------------------------------------------------------------
    // 2. to_string() and string -> number
    // ------------------------------------------------------------
    section("2. Numeric <-> String Conversion");

    // Integer conversion to string.
    string intStr = to_string(42);
    string floatStr = to_string(3.141590);
    string doubleStr = to_string(2.718280);

    cout << intStr << '\n';
    cout << floatStr << '\n';
    cout << doubleStr << '\n';

    // Before C++26, floating-point to_string formatting behaves
    // approximately like printf's %f formatting.
    // Integer result length is proportional to the number of digits.
    //
    // String -> integer:
    cout << stoi("123") << '\n';
    cout << stoll("1234567890123") << '\n';
    cout << stoi("1010", nullptr, 2) << '\n';  // 10

    // ------------------------------------------------------------
    // 3. stringstream
    // ------------------------------------------------------------
    section("3. stringstream");

    string text = "10 20 30";
    stringstream ss(text);

    int a, b, c;
    ss >> a >> b >> c;

    cout << a << ' ' << b << ' ' << c << '\n';

    string built;
    stringstream out_ss;
    out_ss << "answer = " << 42 << ", pi = " << 3.14;
    built = out_ss.str();
    cout << built << '\n';

    // ------------------------------------------------------------
    // 4. Characters behave like small integer values
    // ------------------------------------------------------------
    section("4. Character Arithmetic");

    char ch = 'A';

    cout << static_cast<int>(ch) << '\n';  // character code
    cout << static_cast<char>(ch + 1) << '\n';  // B

    char digit = '7';
    int digitValue = digit - '0';
    cout << digitValue << '\n';

    int n = 5;
    char digitChar = char('0' + n);
    cout << digitChar << '\n';

    // ASCII-specific tricks are common in competitive programming.
    cout << char('a' + 2) << '\n';  // c

    // ------------------------------------------------------------
    // 5. pair / tuple / structured bindings
    // ------------------------------------------------------------
    section("5. pair / tuple / structured bindings");

    pair<int, string> p = {1, "one"};
    cout << p.first << ' ' << p.second << '\n';

    tuple<int, string, double> tp = {7, "seven", 7.7};
    cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << '\n';

    auto [id, name] = p;
    cout << id << ' ' << name << '\n';

    // References let structured bindings modify the original object.
    auto& [id_ref, name_ref] = p;
    id_ref = 99;
    cout << p.first << ' ' << name_ref << '\n';

    // ------------------------------------------------------------
    // 6. tie() / ignore
    // ------------------------------------------------------------
    section("6. tie / ignore");

    pair<int, int> coordinates = {10, 20};
    int x, y;
    tie(x, y) = coordinates;
    cout << x << ' ' << y << '\n';

    int only_second;
    tie(ignore, only_second) = coordinates;
    cout << only_second << '\n';

    // ------------------------------------------------------------
    // 7. swap / exchange
    // ------------------------------------------------------------
    section("7. swap / exchange");

    int u = 10, v = 20;
    swap(u, v);
    cout << u << ' ' << v << '\n';

    int old = exchange(u, 100);  // u becomes 100, old = previous u
    cout << old << ' ' << u << '\n';

    // ------------------------------------------------------------
    // 8. min / max / clamp
    // ------------------------------------------------------------
    section("8. min / max / clamp");

    cout << min(5, 8) << '\n';
    cout << max(5, 8) << '\n';

    vector<int> nums = {5, 2, 9, 1, 7};
    cout << *min_element(nums.begin(), nums.end()) << '\n';
    cout << *max_element(nums.begin(), nums.end()) << '\n';

    cout << clamp(15, 0, 10) << '\n';  // 10
    cout << clamp(-5, 0, 10) << '\n';  // 0

    // Min/max over initializer_list:
    cout << min({5, 2, 9, 1, 7}) << '\n';
    cout << max({5, 2, 9, 1, 7}) << '\n';

    // ------------------------------------------------------------
    // 9. Numeric helpers
    // ------------------------------------------------------------
    section("9. Numeric Helpers");

    cout << gcd(24, 18) << '\n';
    cout << lcm(6, 8) << '\n';

    vector<int> seq(5);
    iota(seq.begin(), seq.end(), 1);  // 1 2 3 4 5

    cout << accumulate(seq.begin(), seq.end(), 0) << '\n';

    long long product = accumulate(
        seq.begin(), seq.end(), 1LL,
        [](long long acc, int value) { return acc * value; }
    );
    cout << product << '\n';

    // 0 as initial value => integer accumulation.
    // Use 0LL / 1LL to force long long accumulation.
    vector<int> bigValues = {1000000000, 1000000000, 1000000000};
    long long safeSum = accumulate(
        bigValues.begin(), bigValues.end(), 0LL
    );
    cout << safeSum << '\n';

    // ------------------------------------------------------------
    // 10. Lambda
    // ------------------------------------------------------------
    section("10. Lambdas");

    auto square = [](int z) {
        return z * z;
    };

    cout << square(6) << '\n';

    int base = 10;
    auto addBase = [base](int z) {
        return base + z;
    };
    cout << addBase(5) << '\n';

    // Capture by reference:
    auto changeBase = [&base]() {
        base += 100;
    };
    changeBase();
    cout << base << '\n';

    // ------------------------------------------------------------
    // 11. Sorting with custom comparator
    // ------------------------------------------------------------
    section("11. Sorting / Custom Comparator");

    vector<pair<int, int>> vp = {{2, 5}, {1, 9}, {2, 3}, {1, 4}};

    sort(vp.begin(), vp.end()); // lexicographic by first, then second

    for (auto [first, second] : vp)
        cout << first << ',' << second << ' ';
    cout << '\n';

    sort(vp.begin(), vp.end(), [](const auto& lhs, const auto& rhs) {
        if (lhs.first != rhs.first)
            return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    });

    for (auto [first, second] : vp)
        cout << first << ',' << second << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 12. Common algorithms that are easy to forget
    // ------------------------------------------------------------
    section("12. Handy Algorithms");

    vector<int> a1 = {1, 2, 2, 3, 4, 2};

    cout << count(a1.begin(), a1.end(), 2) << '\n';

    auto it = find(a1.begin(), a1.end(), 4);
    if (it != a1.end())
        cout << "found at index " << (it - a1.begin()) << '\n';

    reverse(a1.begin(), a1.end());
    rotate(a1.begin(), a1.begin() + 2, a1.end());

    sort(a1.begin(), a1.end());

    if (binary_search(a1.begin(), a1.end(), 4))
        cout << "4 exists\n";

    cout << (lower_bound(a1.begin(), a1.end(), 2) - a1.begin()) << '\n';
    cout << (upper_bound(a1.begin(), a1.end(), 2) - a1.begin()) << '\n';

    // next_permutation requires the initial arrangement if all
    // permutations are to be generated.
    string perm = "123";
    do {
        cout << perm << ' ';
    } while (next_permutation(perm.begin(), perm.end()));
    cout << '\n';

    // ------------------------------------------------------------
    // 13. erase-remove idiom
    // ------------------------------------------------------------
    section("13. erase-remove idiom");

    vector<int> vals = {1, 2, 2, 3, 2, 4};

    vals.erase(remove(vals.begin(), vals.end(), 2), vals.end());

    for (int value : vals)
        cout << value << ' ';
    cout << '\n';

    // C++20:
    vector<int> vals2 = {1, 2, 2, 3, 2, 4};
    erase_if(vals2, [](int z) {
        return z == 2;
    });

    for (int value : vals2)
        cout << value << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 14. string find / npos
    // ------------------------------------------------------------
    section("14. string::find / npos");

    string word = "hello world";
    size_t pos = word.find("world");

    if (pos != string::npos)
        cout << "position = " << pos << '\n';

    // npos is an unsigned size_t sentinel, not -1 as a type.
    cout << string::npos << '\n';

    // ------------------------------------------------------------
    // 15. Division and modulo traps
    // ------------------------------------------------------------
    section("15. Integer Division / Modulo");

    cout << 7 / 2 << '\n';      // 3
    cout << 7.0 / 2 << '\n';    // 3.5

    cout << 7 % 2 << '\n';      // 1
    cout << -7 % 3 << '\n';     // -1 in C++

    // Force long long before multiplication to reduce overflow risk.
    int A = 1000000, B = 1000000;
    long long productLL = 1LL * A * B;
    cout << productLL << '\n';

    // ------------------------------------------------------------
    // 16. memset: the classic CP footgun
    // ------------------------------------------------------------
    section("16. memset");

    int arr[5];
    memset(arr, 0, sizeof(arr));  // safe for zeroing bytes

    // DO NOT generally do:
    // memset(arr, 1, sizeof(arr));
    // This writes byte pattern 0x01 into every byte, not integer 1.

    fill(begin(arr), end(arr), 1); // use fill for values

    for (int value : arr)
        cout << value << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 17. Fast I/O
    // ------------------------------------------------------------
    section("17. Fast I/O");

    // At the top of main:
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //
    // Prefer '\n' over endl when flushing is unnecessary.

    cout << "hello\n";

    // ------------------------------------------------------------
    // 18. Arrays decay to pointers in many expressions
    // ------------------------------------------------------------
    section("18. Array vs Pointer");

    int raw[5] = {10, 20, 30, 40, 50};
    int* rawPtr = raw;

    cout << sizeof(raw) << '\n';      // whole array in bytes
    cout << sizeof(rawPtr) << '\n';   // pointer size

    cout << raw[2] << ' ' << *(raw + 2) << ' ' << rawPtr[2] << '\n';

    // ------------------------------------------------------------
    // 19. vector<bool> is weird
    // ------------------------------------------------------------
    section("19. vector<bool>");

    vector<bool> bits = {true, false, true};
    cout << bits[0] << ' ' << bits[1] << '\n';

    // vector<bool> is a specialized representation and its operator[]
    // does not return a normal bool&.
    // Prefer vector<char> when ordinary references / byte storage matter.

    // ------------------------------------------------------------
    // 20. Numeric limits / infinity
    // ------------------------------------------------------------
    section("20. Limits / Infinity");

    cout << numeric_limits<int>::max() << '\n';
    cout << numeric_limits<long long>::max() << '\n';

    double inf = numeric_limits<double>::infinity();
    cout << isinf(inf) << '\n';

    double nanValue = numeric_limits<double>::quiet_NaN();
    cout << isnan(nanValue) << '\n';

    // ------------------------------------------------------------
    // 21. Common sentinels
    // ------------------------------------------------------------
    section("21. Common Sentinels");

    const int INF = 1e9;
    const long long LINF = 4e18;

    cout << INF << ' ' << LINF << '\n';

    // Be careful: LINF + LINF can overflow long long.
    // In shortest-path DP, choose a sentinel far enough from the
    // true answer and check before adding if overflow is possible.

    // ------------------------------------------------------------
    // 22. Type aliases that reduce typing
    // ------------------------------------------------------------
    section("22. Useful Aliases");

    using ll = long long;
    using pii = pair<int, int>;
    using vi = vector<int>;

    ll large = 1234567890123LL;
    pii point = {3, 4};
    vi data = {1, 2, 3};

    cout << large << '\n';
    cout << point.first << ' ' << point.second << '\n';
    cout << data.size() << '\n';

    // ------------------------------------------------------------
    // 23. Function pointers / std::function
    // ------------------------------------------------------------
    section("23. Function / Callable Objects");

    int (*fp)(int, int) = add;
    cout << fp(3, 4) << '\n';

    function<int(int, int)> fn = add;
    cout << fn(5, 6) << '\n';

    // Lambdas can also be stored in std::function:
    function<int(int)> doubler = [](int z) {
        return 2 * z;
    };
    cout << doubler(7) << '\n';

    // ------------------------------------------------------------
    // 24. Endianness / bytes: tiny curiosity
    // ------------------------------------------------------------
    section("24. Byte-level Curiosity");

    uint32_t value = 0x12345678;
    unsigned char* bytePtr =
        reinterpret_cast<unsigned char*>(&value);

    cout << "first byte in memory = "
         << hex << static_cast<int>(bytePtr[0]) << dec << '\n';

    cout << "\nMiscellaneous C++ examples completed.\n";
    return 0;
}
