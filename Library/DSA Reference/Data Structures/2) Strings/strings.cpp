#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    STRINGS CHEAT SHEET — C++20
    ============================================================

    CORE / MUST KNOW
    ----------------
    Main DSA string type: string

    Access character       O(1)
    Update character       O(1)
    length / size          O(1)
    empty                  O(1)
    Search                 O(n) typical / algorithm-dependent
    Concatenate            O(n + m)
    Substring              O(k)
    Insert / erase         O(n)
    Compare                O(min(n,m))
    Push back              O(1) amortized
    Pop back               O(1)
    Reverse                O(n)
    Sort characters        O(n log n)

    EXTRAS / REFERENCE
    ------------------
    rfind, replace, insert overloads, transform, count,
    min/max element, numeric conversion, character classification,
    iterator algorithms, manual substring search, etc.
*/

int main() {

    // ============================================================
    // CORE — MUST KNOW
    // ============================================================

    // ------------------------------------------------------------
    // 1. DECLARATION / INITIALISATION
    // ------------------------------------------------------------

    string a;
    a = "hello";

    string b = "hello world";
    string c("hello world");

    string d(5, 'a');                 // "aaaaa"

    string copied = b;                // copy

    // C-style character array / string literal:
    const char raw[] = "hello";

    // ------------------------------------------------------------
    // 2. INPUT
    // ------------------------------------------------------------

    /*
        cin >> inp
            Reads one whitespace-delimited token.

        getline(cin, inp)
            Reads an entire line including spaces.

        If getline() follows formatted extraction such as
        cin >> x, consume the leftover newline first.
    */

    string inp;

    // cin >> inp;

    // Correct general pattern after cin >> something:
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // getline(cin, inp);

    // Read one character, including whitespace:
    // char ch = cin.get();

    // ------------------------------------------------------------
    // 3. SIZE / LENGTH / EMPTY
    // ------------------------------------------------------------

    int n = (int)b.size();             // O(1)
    int n2 = (int)b.length();          // O(1)
    bool isEmpty = b.empty();          // O(1)

    cout << "Size: " << n << '\n';
    cout << "Length: " << n2 << '\n';
    cout << "Empty: " << boolalpha << isEmpty << '\n';

    // ------------------------------------------------------------
    // 4. CHARACTER ACCESS
    // ------------------------------------------------------------

    char ch1 = b[0];                   // O(1)
    char ch2 = b.at(0);                // O(1), bounds checked

    if (!b.empty()) {
        char first = b.front();        // O(1)
        char last = b.back();          // O(1)

        cout << ch1 << ' ' << ch2 << '\n';
        cout << first << ' ' << last << '\n';
    }

    // C++ has no Python-style negative indexing.
    // b[-1] does NOT mean the last character.

    // ------------------------------------------------------------
    // 5. UPDATE CHARACTER
    // ------------------------------------------------------------

    if (!b.empty())
        b[0] = 'H';                    // O(1)

    // ------------------------------------------------------------
    // 6. CONCATENATION / APPEND
    // ------------------------------------------------------------

    string s1 = "abc";
    string s2 = "def";

    s1 = s1 + s2;                      // O(n + m)

    s1 += "ghi";                        // append string
    s1.append("jkl");                   // append string
    s1.push_back('!');                  // append one char
    s1.append(3, '?');                  // append repeated chars

    // ------------------------------------------------------------
    // 7. CLEAR
    // ------------------------------------------------------------

    s1.clear();
    // s1 = "";

    // ------------------------------------------------------------
    // 8. COMPARISON
    // ------------------------------------------------------------

    string x = "Rishabh";
    string y = "Ramdhave";

    bool equal = (x == y);
    bool notEqual = (x != y);
    bool less = (x < y);
    bool greater = (x > y);

    int cmp = x.compare(y);

    /*
        Comparison is lexicographical.

        compare():
            < 0  -> x < y
              0  -> x == y
            > 0  -> x > y
    */

    cout << "Equal: " << equal << '\n';
    cout << "Not equal: " << notEqual << '\n';
    cout << "compare: " << cmp << '\n';

    // TC: O(min(n,m))

    // ------------------------------------------------------------
    // 9. SUBSTRING
    // ------------------------------------------------------------

    string full = "rishabh shital ramdhave";

    string part = full.substr(5, 6);
    string rest = full.substr(5);

    // TC: O(k)
    // SC: O(k) for resulting string

    // ------------------------------------------------------------
    // 10. FIND
    // ------------------------------------------------------------

    string text = "hello world";

    size_t pos = text.find("world");

    if (pos != string::npos)
        cout << "'world' found at index " << pos << '\n';

    size_t charPos = text.find('o');

    // Search from an index:
    size_t from = text.find('o', 5);

    // Last occurrence:
    size_t last = text.rfind('o');

    /*
        If not found:
            string::npos

        find() supports both characters and substrings.
    */

    // ------------------------------------------------------------
    // 11. INSERT
    // ------------------------------------------------------------

    string tst2 = "rishabh ramdhave";

    tst2.insert(8, "shital ");
    // "rishabh shital ramdhave"

    // Insert repeated characters:
    tst2.insert(0, 3, '*');

    // TC: generally O(n + inserted length)

    // ------------------------------------------------------------
    // 12. ERASE
    // ------------------------------------------------------------

    string tst1 = "rishabh shital ramdhave";

    tst1.erase(8, 7);
    // "rishabh ramdhave"

    // Erase from position to end:
    tst1.erase(8);

    // Erase one character:
    if (!tst1.empty())
        tst1.erase(0, 1);

    // TC: O(n) in general because remaining characters may shift

    // ------------------------------------------------------------
    // 13. REPLACE
    // ------------------------------------------------------------

    string tst3 = "rishabh ramdhave";

    tst3.replace(0, 7, "samruddhi");

    // Replace one character with another:
    string rep = "apples and bananas";

    std::replace(
        rep.begin(),
        rep.end(),
        'a',
        'o'
    );

    cout << "Character-replaced: " << rep << '\n';
    // "opples ond bononos"

    /*
        IMPORTANT:
        std::replace() replaces individual elements.

        string::replace() replaces a substring/range.
    */

    // ------------------------------------------------------------
    // 14. PUSH / POP
    // ------------------------------------------------------------

    tst3.push_back('a');
    tst3.pop_back();

    // push_back: O(1) amortized
    // pop_back : O(1)

    // ------------------------------------------------------------
    // 15. TRAVERSAL
    // ------------------------------------------------------------

    cout << "Index traversal: ";
    for (int i = 0; i < (int)text.size(); ++i)
        cout << text[i] << ' ';
    cout << '\n';

    cout << "Range traversal: ";
    for (char ch : text)
        cout << ch << ' ';
    cout << '\n';

    cout << "Iterator traversal: ";
    for (auto it = text.begin(); it != text.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    cout << "Reverse traversal: ";
    for (auto it = text.rbegin(); it != text.rend(); ++it)
        cout << *it << ' ';
    cout << '\n';

    // All traversals: TC O(n), SC O(1) auxiliary

    // ------------------------------------------------------------
    // 16. REVERSE
    // ------------------------------------------------------------

    string rev = "abcdef";

    reverse(rev.begin(), rev.end());

    // TC: O(n)
    // SC: O(1)

    // ------------------------------------------------------------
    // 17. SORT
    // ------------------------------------------------------------

    string sorted = "dcba";

    sort(sorted.begin(), sorted.end());
    // "abcd"

    sort(sorted.rbegin(), sorted.rend());
    // "dcba"

    // TC: O(n log n)

    // ------------------------------------------------------------
    // 18. COUNT
    // ------------------------------------------------------------

    int countA = count(
        rep.begin(),
        rep.end(),
        'o'
    );

    // TC: O(n)

    // ============================================================
    // EXTRAS — REFERENCE
    // ============================================================

    // ------------------------------------------------------------
    // 19. CASE CONVERSION
    // ------------------------------------------------------------

    string str = "hello world";

    transform(
        str.begin(),
        str.end(),
        str.begin(),
        [](unsigned char ch) {
            return (char)toupper(ch);
        }
    );

    cout << "Uppercase: " << str << '\n';

    transform(
        str.begin(),
        str.end(),
        str.begin(),
        [](unsigned char ch) {
            return (char)tolower(ch);
        }
    );

    cout << "Lowercase: " << str << '\n';

    // TC: O(n), SC: O(1) auxiliary

    // ------------------------------------------------------------
    // 20. MIN / MAX CHARACTER
    // ------------------------------------------------------------

    string letters = "dcab";

    char mn = *min_element(
        letters.begin(),
        letters.end()
    );

    char mx = *max_element(
        letters.begin(),
        letters.end()
    );

    cout << "Min char: " << mn << '\n';
    cout << "Max char: " << mx << '\n';

    // TC: O(n), SC: O(1)

    // ------------------------------------------------------------
    // 21. NUMERIC STRING CONVERSION
    // ------------------------------------------------------------

    string numString = "12345";

    int integerValue = stoi(numString);
    long long longValue = stoll(numString);
    double decimalValue = stod("12.34");

    string backToString = to_string(12345);

    cout << integerValue << ' '
         << longValue << ' '
         << decimalValue << ' '
         << backToString << '\n';

    // ------------------------------------------------------------
    // 22. CHARACTER CLASSIFICATION
    // ------------------------------------------------------------

    char q = '7';

    bool alpha = isalpha((unsigned char)q);
    bool digit = isdigit((unsigned char)q);
    bool lower = islower((unsigned char)q);
    bool upper = isupper((unsigned char)q);
    bool alnum = isalnum((unsigned char)q);
    bool whitespace = isspace((unsigned char)q);

    cout << alpha << ' '
         << digit << ' '
         << lower << ' '
         << upper << ' '
         << alnum << ' '
         << whitespace << '\n';

    // ------------------------------------------------------------
    // 23. COPY / ASSIGN / SWAP
    // ------------------------------------------------------------

    string original = "hello";

    string copied2 = original;            // O(n)

    string assigned;
    assigned = original;                  // O(n)

    string other = "world";
    original.swap(other);                 // constant-time operation

    // ------------------------------------------------------------
    // 24. DATA / ITERATORS
    // ------------------------------------------------------------

    string dataString = "hello";

    auto beginIt = dataString.begin();
    auto endIt = dataString.end();

    const char* ptr = dataString.data();

    cout << "data(): " << ptr << '\n';

    // ------------------------------------------------------------
    // 25. ACCUMULATE
    // ------------------------------------------------------------

    string digits = "12345";

    int digitSum = accumulate(
        digits.begin(),
        digits.end(),
        0,
        [](int sum, char ch) {
            return sum + (ch - '0');
        }
    );

    cout << "Digit sum: " << digitSum << '\n';

    // Generic accumulate can also be adapted for other reductions.

    // ------------------------------------------------------------
    // 26. PARTIAL SUM
    // ------------------------------------------------------------

    vector<int> numbers = {1, 2, 3, 4};
    vector<int> prefix(numbers.size());

    partial_sum(
        numbers.begin(),
        numbers.end(),
        prefix.begin()
    );

    // prefix = {1,3,6,10}
    // TC: O(n), SC: O(n) output

    // ------------------------------------------------------------
    // 27. MANUAL LINEAR CHARACTER SEARCH
    // ------------------------------------------------------------

    auto findIndex = [](const string& s, char target) -> int {
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == target)
                return i;
        }
        return -1;
    };

    cout << "Manual char search: "
         << findIndex("abcdef", 'd') << '\n';

    // TC: O(n)
    // SC: O(1)

    // ------------------------------------------------------------
    // 28. MANUAL PALINDROME
    // ------------------------------------------------------------

    auto isPalindrome = [](const string& s) -> bool {
        int l = 0;
        int r = (int)s.size() - 1;

        while (l < r) {
            if (s[l] != s[r])
                return false;

            ++l;
            --r;
        }

        return true;
    };

    cout << "Palindrome: "
         << isPalindrome("madam") << '\n';

    // TC: O(n)
    // SC: O(1)

    // ------------------------------------------------------------
    // 29. MANUAL REVERSE
    // ------------------------------------------------------------

    auto manualReverse = [](string& s) {
        int l = 0;
        int r = (int)s.size() - 1;

        while (l < r)
            swap(s[l++], s[r--]);
    };

    string manual = "abcdef";
    manualReverse(manual);

    // TC: O(n)
    // SC: O(1)

    // ------------------------------------------------------------
    // 30. NAIVE SUBSTRING SEARCH
    // ------------------------------------------------------------

    auto naiveFind = [](const string& s,
                        const string& pattern) -> int {

        if (pattern.empty())
            return 0;

        if (pattern.size() > s.size())
            return -1;

        for (int i = 0;
             i + (int)pattern.size() <= (int)s.size();
             ++i) {

            int j = 0;

            while (j < (int)pattern.size() &&
                   s[i + j] == pattern[j]) {
                ++j;
            }

            if (j == (int)pattern.size())
                return i;
        }

        return -1;
    };

    cout << "Naive substring search: "
         << naiveFind("hello world", "world") << '\n';

    // Worst-case TC: O(n*m)
    // SC: O(1)

    // ------------------------------------------------------------
    // 31. IMPORTANT LIBRARY NOTES
    // ------------------------------------------------------------

    /*
        string::find()
            Searches for a character or substring.

        std::find()
            Generic iterator algorithm; searches for an element,
            not a substring pattern.

        std::replace()
            Replaces elements/characters.

        string::replace()
            Replaces a range with a string/range.

        random_shuffle()
            Removed from modern C++.
            Use shuffle() instead.

        string::npos
            Sentinel meaning "not found".

        C++ string has mutable contiguous storage in standard
        implementations / guarantees relevant to data access,
        so data() provides access to its character buffer.
    */

    return 0;
}
