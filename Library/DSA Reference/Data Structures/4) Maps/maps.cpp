#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    MAPS CHEAT SHEET — C++20
    ============================================================

    CORE / MUST KNOW
    ----------------
    map<K,V>:
        unique keys + sorted by key
        search / insert / erase: O(log n)

    unordered_map<K,V>:
        unique keys + no ordering guarantee
        search / insert / erase: O(1) average, O(n) worst

    multimap<K,V>:
        duplicate keys + sorted by key
        search / insert: O(log n)
        key-based count/erase can include all matching entries

    Python dict:
        unique keys + insertion order preserved
        lookup / insert / delete: O(1) average, O(n) worst

    EXTRAS / REFERENCE
    ------------------
    lower_bound, upper_bound, equal_range, erase-while-iterating,
    custom comparators, hash-policy APIs, merge/extract,
    OrderedDict, defaultdict, Counter-like patterns, etc.
*/

int main() {

    // ============================================================
    // CORE — MUST KNOW
    // ============================================================

    // ------------------------------------------------------------
    // 1. INITIALISATION
    // ------------------------------------------------------------

    map<string, int> mp;
    unordered_map<string, int> unmp;
    multimap<string, int> mmp;

    map<int, string> myMap = {
        {10, "Alice"},
        {20, "Bob"},
        {30, "Charlie"}
    };

    unordered_map<string, int> um = {
        {"A", 1},
        {"B", 2},
        {"C", 3}
    };

    // ------------------------------------------------------------
    // 2. SIZE / EMPTY
    // ------------------------------------------------------------

    int sz = mp.size();             // O(1)
    bool isEmpty = mp.empty();      // O(1)

    cout << "Size: " << sz << '\n';
    cout << "Empty: " << isEmpty << '\n';

    // ------------------------------------------------------------
    // 3. INSERT / UPDATE
    // ------------------------------------------------------------

    // operator[]:
    mp["R"] = 1;
    mp["I"] = 2;
    mp["S"] = 3;
    mp["H"] = 4;
    mp["A"] = 5;
    mp["B"] = 6;

    mp["H"] = 7;                    // Updates existing key

    /*
        IMPORTANT:
        map[key] inserts key with a default-constructed value if the
        key does not already exist.

        So for map<string,int>:
            mp["X"]  -> creates {"X", 0} if X is absent.
    */

    // insert(): does NOT overwrite an existing key
    auto [itInsert, inserted] = mp.insert({"R", 100});
    cout << "Inserted new R? " << boolalpha << inserted << '\n';

    // insert_or_assign(): C++17
    mp.insert_or_assign("R", 100);

    // try_emplace(): C++17
    mp.try_emplace("NEW", 50);

    // unordered_map uses the same key APIs:
    unmp["A"] = 10;
    unmp["B"] = 20;
    unmp["A"] = 99;

    // ------------------------------------------------------------
    // 4. ACCESS
    // ------------------------------------------------------------

    int value1 = mp["R"];            // O(log n), inserts if missing

    auto value2 = mp.at("R");        // O(log n), throws if missing

    // Safe existence check before [] when insertion is unwanted:
    if (mp.find("R") != mp.end())
        cout << mp["R"] << '\n';

    /*
        IMPORTANT:
        `operator[]` is not just a read.
        On a missing key it inserts a default value.
    */

    // ------------------------------------------------------------
    // 5. MEMBERSHIP / FIND
    // ------------------------------------------------------------

    bool present = (mp.find("R") != mp.end());    // O(log n)

    bool presentUS =
        (unmp.find("A") != unmp.end());            // O(1) avg, O(n) worst

    // C++20:
    bool contains = mp.contains("R");              // O(log n)
    bool containsUS = unmp.contains("A");           // O(1) avg, O(n) worst

    cout << "R present: " << present << '\n';

    // ------------------------------------------------------------
    // 6. ERASE
    // ------------------------------------------------------------

    mp.erase("S");                  // O(log n)

    /*
        erase(iterator) returns the iterator immediately after the
        erased element.

        This is extremely useful while erasing during traversal.
    */

    map<int, int> eraseMap = {
        {0,0}, {1,1}, {2,2}, {3,3}, {4,4}
    };

    for (auto it = eraseMap.begin();
         it != eraseMap.end(); ) {

        if (it->first % 2 == 0)
            it = eraseMap.erase(it);
        else
            ++it;
    }

    // Erase by iterator after a safe find:
    auto eraseIt = mp.find("I");
    if (eraseIt != mp.end())
        mp.erase(eraseIt);

    // Erase a range [first,last):
    if (!mp.empty()) {
        auto first = mp.begin();
        auto last = next(first);
        mp.erase(first, last);
    }

    // unordered_map:
    unmp.erase("A");                // O(1) avg, O(n) worst

    // ------------------------------------------------------------
    // 7. TRAVERSAL
    // ------------------------------------------------------------

    cout << "\nmap traversal:\n";

    for (auto el : mp)
        cout << el.first << ' ' << el.second << '\n';

    // Structured bindings:
    for (auto& [key, value] : mp)
        cout << key << " -> " << value << '\n';

    // Important:
    // std::map traversal is sorted by key.
    // unordered_map traversal has no ordering guarantee.

    // ------------------------------------------------------------
    // 8. CLEAR
    // ------------------------------------------------------------

    mp.clear();                     // O(n)

    // ------------------------------------------------------------
    // 9. ORDERED MAP BOUNDS
    // ------------------------------------------------------------

    map<int, string> boundsMap;
    boundsMap[10] = "Alice";
    boundsMap[20] = "Bob";
    boundsMap[30] = "Charlie";

    auto lb = boundsMap.lower_bound(15);  // first key >= 15
    auto ub = boundsMap.upper_bound(15);  // first key > 15

    if (lb != boundsMap.end())
        cout << "Lower bound: "
             << lb->first << " -> "
             << lb->second << '\n';

    if (ub != boundsMap.end())
        cout << "Upper bound: "
             << ub->first << " -> "
             << ub->second << '\n';

    // equal_range:
    auto range = boundsMap.equal_range(20);

    // range.first  == lower_bound(20)
    // range.second == upper_bound(20)

    // ============================================================
    // EXTRAS — REFERENCE
    // ============================================================

    // ------------------------------------------------------------
    // 10. MULTIMAP
    // ------------------------------------------------------------

    multimap<int, string> mmap;

    mmap.insert({1, "apple"});
    mmap.insert({2, "banana"});
    mmap.insert({1, "cherry"});
    mmap.insert({3, "grapes"});
    mmap.insert({2, "kiwi"});

    cout << "\nmultimap traversal:\n";
    for (auto& [key, value] : mmap)
        cout << key << " -> " << value << '\n';

    /*
        Keys are sorted.
        Duplicate keys are allowed.
    */

    // Size:
    int msize = mmap.size();                    // O(1)

    // Count entries with a key:
    size_t cnt3 = mmap.count(3);                // O(log n + k)

    // Find one matching entry:
    auto mit = mmap.find(2);

    if (mit != mmap.end())
        cout << "Found multimap key 2: "
             << mit->second << '\n';

    // Lower / upper bound:
    auto mlb = mmap.lower_bound(2);
    auto mub = mmap.upper_bound(2);

    // All entries with key 2:
    for (auto it = mlb; it != mub; ++it)
        cout << it->first << " -> " << it->second << '\n';

    // Erase ALL entries with key 1:
    mmap.erase(1);

    // Erase ONE entry:
    auto one = mmap.find(2);
    if (one != mmap.end())
        mmap.erase(one);

    // Clear:
    mmap.clear();

    // ------------------------------------------------------------
    // 11. MIN / MAX KEY IN ORDERED MAP
    // ------------------------------------------------------------

    map<int, string> ordered = {
        {10, "Alice"},
        {20, "Bob"},
        {30, "Charlie"}
    };

    if (!ordered.empty()) {
        auto firstPair = *ordered.begin();
        auto lastPair = *ordered.rbegin();

        cout << "Smallest key: "
             << firstPair.first << '\n';

        cout << "Largest key: "
             << lastPair.first << '\n';
    }

    // There is no meaningful smallest/largest key by iteration
    // for unordered_map.

    // ------------------------------------------------------------
    // 12. REVERSE TRAVERSAL
    // ------------------------------------------------------------

    cout << "Reverse map:\n";

    for (auto it = ordered.rbegin();
         it != ordered.rend();
         ++it) {
        cout << it->first
             << " -> "
             << it->second << '\n';
    }

    // ------------------------------------------------------------
    // 13. MAP COPY / MOVE / SWAP
    // ------------------------------------------------------------

    map<int, string> original = ordered;

    map<int, string> copied = original;        // O(n)

    map<int, string> moved = move(original);   // linear in general

    map<int, string> another = {{5, "E"}};

    moved.swap(another);                       // O(1) for map

    // ------------------------------------------------------------
    // 14. CUSTOM ORDERING
    // ------------------------------------------------------------

    map<int, string, greater<int>> descending = {
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };

    cout << "Descending map:\n";

    for (auto& [key, value] : descending)
        cout << key << " -> " << value << '\n';

    // ------------------------------------------------------------
    // 15. CUSTOM COMPARATOR
    // ------------------------------------------------------------

    struct StringLengthCompare {
        bool operator()(const string& a,
                        const string& b) const {

            if (a.size() != b.size())
                return a.size() < b.size();

            return a < b;
        }
    };

    map<string, int, StringLengthCompare> byLength;

    byLength["cat"] = 1;
    byLength["apple"] = 2;
    byLength["dog"] = 3;

    // ------------------------------------------------------------
    // 16. C++20 erase_if
    // ------------------------------------------------------------

    map<int, int> filterMap = {
        {1, 10},
        {2, 20},
        {3, 30},
        {4, 40}
    };

    erase_if(
        filterMap,
        [](const auto& p) {
            return p.first % 2 == 0;
        }
    );

    // ------------------------------------------------------------
    // 17. UNORDERED_MAP HASH POLICY
    // ------------------------------------------------------------

    unordered_map<string, int> hashMap = {
        {"A", 1},
        {"B", 2},
        {"C", 3}
    };

    cout << "Bucket count: "
         << hashMap.bucket_count() << '\n';

    cout << "Load factor: "
         << hashMap.load_factor() << '\n';

    hashMap.reserve(100);
    hashMap.rehash(50);

    /*
        These are advanced hash-table controls.

        For normal DSA:
            unordered_map -> remember average O(1).
        You usually do not need bucket APIs.
    */

    // ------------------------------------------------------------
    // 18. MERGE
    // ------------------------------------------------------------

    map<int, string> left = {
        {1, "one"},
        {2, "two"}
    };

    map<int, string> right = {
        {2, "TWO"},
        {3, "three"}
    };

    left.merge(right);

    /*
        Key 3 moves into left.
        Key 2 cannot move because it already exists in left,
        so it remains in right.
    */

    // ------------------------------------------------------------
    // 19. EXTRACT
    // ------------------------------------------------------------

    map<int, string> extractMap = {
        {1, "one"},
        {2, "two"}
    };

    auto node = extractMap.extract(2);

    if (!node.empty())
        cout << "Extracted: "
             << node.key() << " -> "
             << node.mapped() << '\n';

    // ------------------------------------------------------------
    // 20. USEFUL FREQUENCY PATTERN
    // ------------------------------------------------------------

    vector<string> words = {
        "apple", "banana", "apple", "grape", "banana"
    };

    unordered_map<string, int> freq;

    for (const string& word : words)
        ++freq[word];

    for (const auto& [word, count] : freq)
        cout << word << " -> " << count << '\n';

    /*
        This is one of the most important practical uses of
        unordered_map in DSA:

            frequency[key]++

        Average TC over n inputs: O(n)
    */

    return 0;
}
