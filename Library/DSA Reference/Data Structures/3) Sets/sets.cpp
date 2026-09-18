#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    SETS CHEAT SHEET — C++20
    ============================================================

    CORE / MUST KNOW
    ----------------
    set<T>:
        unique + sorted
        search/insert/erase: O(log n)

    unordered_set<T>:
        unique + no ordering guarantee
        search/insert/erase: O(1) average, O(n) worst case

    multiset<T>:
        sorted + duplicates allowed
        search/insert/erase: O(log n) for single-element operations;
        operations involving multiple equivalent keys can include
        the number of matching elements.

    EXTRAS / REFERENCE
    ------------------
    bounds, equal_range, set algorithms, custom comparators,
    unordered_set buckets/hash policy, erase_if, merge/extract,
    Counter-like patterns, etc.
*/

template <class T>
void printSet(const T& s) {
    for (const auto& x : s)
        cout << x << ' ';
    cout << '\n';
}

int main() {

    // ============================================================
    // CORE — MUST KNOW
    // ============================================================

    // ------------------------------------------------------------
    // 1. INITIALISATION
    // ------------------------------------------------------------

    set<int> s;
    unordered_set<int> us;
    multiset<int> ms;

    set<int> s1 = {1, 2, 3, 4, 5};
    unordered_set<int> us1 = {1, 2, 3, 4, 5};
    multiset<int> ms1 = {1, 2, 2, 3, 4};

    // From a range:
    vector<int> values = {5, 1, 3, 3, 2};

    set<int> fromRange(values.begin(), values.end());

    // ------------------------------------------------------------
    // 2. INSERT
    // ------------------------------------------------------------

    // set: duplicates ignored
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    // The return value is {iterator, inserted}
    auto [itInsert, inserted] = s.insert(5);

    cout << "Inserted 5? " << boolalpha << inserted << '\n';

    // unordered_set
    us.insert(1);
    us.insert(3);
    us.insert(5);
    us.insert(3);                  // duplicate ignored

    // multiset: duplicates allowed
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);

    // ------------------------------------------------------------
    // 3. SIZE / EMPTY
    // ------------------------------------------------------------

    cout << "set size: " << s.size() << '\n';       // O(1)
    cout << "us size: " << us.size() << '\n';       // O(1)
    cout << "ms size: " << ms.size() << '\n';       // O(1)

    cout << "set empty: " << s.empty() << '\n';     // O(1)

    // ------------------------------------------------------------
    // 4. MEMBERSHIP
    // ------------------------------------------------------------

    bool inSet = s.count(3) > 0;                  // O(log n)
    bool inUS = us.count(3) > 0;                  // O(1) avg, O(n) worst

    cout << "3 in set: " << inSet << '\n';
    cout << "3 in unordered_set: " << inUS << '\n';

    // C++20 preferred boolean lookup:
    bool contains = s.contains(3);                 // O(log n)
    bool containsUS = us.contains(3);              // O(1) avg, O(n) worst

    // ------------------------------------------------------------
    // 5. FIND
    // ------------------------------------------------------------

    auto it = s.find(3);

    if (it != s.end())
        cout << "Found: " << *it << '\n';

    auto uit = us.find(3);

    if (uit != us.end())
        cout << "Found in unordered_set: " << *uit << '\n';

    // ------------------------------------------------------------
    // 6. ITERATION
    // ------------------------------------------------------------

    cout << "Ordered set: ";
    for (int x : s)
        cout << x << ' ';
    cout << '\n';

    cout << "Unordered set: ";
    for (int x : us)
        cout << x << ' ';
    cout << '\n';

    // std::set traversal is sorted.
    // std::unordered_set traversal has no sorted-order guarantee.

    // ------------------------------------------------------------
    // 7. SMALLEST / LARGEST IN ORDERED SET
    // ------------------------------------------------------------

    if (!s.empty()) {
        int smallest = *s.begin();                  // O(1)
        int largest = *s.rbegin();                 // O(1)

        cout << "Smallest: " << smallest << '\n';
        cout << "Largest: " << largest << '\n';
    }

    // unordered_set has no meaningful smallest/largest by iteration.

    // ------------------------------------------------------------
    // 8. ERASE
    // ------------------------------------------------------------

    // By key:
    size_t erased = s.erase(2);                    // O(log n), 0 or 1

    // By iterator:
    auto eraseIt = s.find(3);
    if (eraseIt != s.end())
        s.erase(eraseIt);                          // amortized O(1)

    // By range [first,last):
    if (!s.empty()) {
        auto first = s.begin();
        auto last = s.end();

        // Example: erase the first element safely
        s.erase(first, next(first));               // amortized O(1) for one node
    }

    // unordered_set:
    us.erase(1);                                   // O(1) avg, O(n) worst

    // multiset:
    ms.erase(2);                                   // Removes ALL 2s

    // To remove only one occurrence:
    auto mit = ms.find(3);
    if (mit != ms.end())
        ms.erase(mit);

    // IMPORTANT:
    // erase(end()) is invalid because end() is not dereferenceable.
    // An empty range erase(end(), end()) is valid, but erasing a
    // single end() iterator is not.

    // ------------------------------------------------------------
    // 9. CLEAR
    // ------------------------------------------------------------

    s.clear();
    us.clear();
    ms.clear();

    // TC: O(n)

    // ------------------------------------------------------------
    // 10. LOWER / UPPER BOUND — ORDERED SETS
    // ------------------------------------------------------------

    set<int> ts = {10, 20, 30, 40, 50};

    auto lb = ts.lower_bound(30);                   // first >= 30
    auto ub = ts.upper_bound(30);                   // first > 30

    if (lb != ts.end())
        cout << "Lower bound: " << *lb << '\n';

    if (ub != ts.end())
        cout << "Upper bound: " << *ub << '\n';

    // Both: O(log n)

    // ------------------------------------------------------------
    // 11. MULTISET
    // ------------------------------------------------------------

    multiset<int> multi = {10, 20, 20, 20, 30, 40};

    cout << "Multiset count(20): "
         << multi.count(20) << '\n';

    auto mlb = multi.lower_bound(20);
    auto mub = multi.upper_bound(20);

    // Range [mlb, mub) contains all 20s.

    if (mlb != multi.end())
        cout << "Multiset lower_bound: " << *mlb << '\n';

    if (mub != multi.end())
        cout << "Multiset upper_bound: " << *mub << '\n';

    // count(x): O(log n + number_of_matches)
    // erase(x): O(log n + number_of_matches)

    // ============================================================
    // EXTRAS — REFERENCE
    // ============================================================

    // ------------------------------------------------------------
    // 12. SET / MULTISET REVERSE TRAVERSAL
    // ------------------------------------------------------------

    set<int> ordered = {1, 2, 3, 4, 5};

    cout << "Reverse ordered set: ";
    for (auto rit = ordered.rbegin();
         rit != ordered.rend();
         ++rit) {
        cout << *rit << ' ';
    }
    cout << '\n';

    // ------------------------------------------------------------
    // 13. EQUAL RANGE
    // ------------------------------------------------------------

    multiset<int> equalSet = {1, 2, 2, 2, 3, 4};

    auto range = equalSet.equal_range(2);

    cout << "All 2s: ";
    for (auto i = range.first; i != range.second; ++i)
        cout << *i << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 14. SET ALGORITHMS
    // ------------------------------------------------------------

    set<int> A = {1, 2, 3, 4, 5};
    set<int> B = {3, 4, 5, 6, 7};

    set<int> intersectionSet;
    set<int> unionSet;
    set<int> differenceSet;
    set<int> symmetricDifferenceSet;

    // Intersection A ∩ B
    set_intersection(
        A.begin(), A.end(),
        B.begin(), B.end(),
        inserter(intersectionSet, intersectionSet.begin())
    );

    // Union A ∪ B
    set_union(
        A.begin(), A.end(),
        B.begin(), B.end(),
        inserter(unionSet, unionSet.begin())
    );

    // Difference A - B
    set_difference(
        A.begin(), A.end(),
        B.begin(), B.end(),
        inserter(differenceSet, differenceSet.begin())
    );

    // Symmetric difference (A-B) U (B-A)
    set_symmetric_difference(
        A.begin(), A.end(),
        B.begin(), B.end(),
        inserter(
            symmetricDifferenceSet,
            symmetricDifferenceSet.begin()
        )
    );

    cout << "Intersection: ";
    printSet(intersectionSet);

    cout << "Union: ";
    printSet(unionSet);

    cout << "Difference A-B: ";
    printSet(differenceSet);

    cout << "Symmetric difference: ";
    printSet(symmetricDifferenceSet);

    /*
        These algorithms require sorted/appropriately ordered
        input ranges. std::set naturally supplies sorted ranges.
    */

    // ------------------------------------------------------------
    // 15. SET RELATIONS
    // ------------------------------------------------------------

    // Is A a subset of B?
    bool A_subset_B =
        includes(
            B.begin(), B.end(),
            A.begin(), A.end()
        );

    cout << "A subset of B: "
         << A_subset_B << '\n';

    // TC: O(|A| + |B|) for sorted ranges.

    // ------------------------------------------------------------
    // 16. CUSTOM ORDERING
    // ------------------------------------------------------------

    set<int, greater<int>> descending = {
        1, 2, 3, 4, 5
    };

    cout << "Descending set: ";
    printSet(descending);

    // ------------------------------------------------------------
    // 17. CUSTOM COMPARATOR
    // ------------------------------------------------------------

    struct AbsCompare {
        bool operator()(int a, int b) const {
            if (abs(a) != abs(b))
                return abs(a) < abs(b);

            return a < b;
        }
    };

    set<int, AbsCompare> custom = {
        -4, 2, -2, 1, 4
    };

    cout << "Custom-comparator set: ";
    printSet(custom);

    // IMPORTANT:
    // Set uniqueness is determined by equivalence under Compare,
    // not necessarily operator==.

    // ------------------------------------------------------------
    // 18. COPY / MOVE / SWAP
    // ------------------------------------------------------------

    set<int> original = {1, 2, 3};

    set<int> copied = original;                 // O(n)

    set<int> moved = move(original);             // linear in general
                                                  // source remains valid
                                                  // but unspecified

    set<int> other = {7, 8};
    moved.swap(other);                          // O(1)

    // ------------------------------------------------------------
    // 19. C++20 erase_if
    // ------------------------------------------------------------

    set<int> filterSet = {1, 2, 3, 4, 5, 6};

    erase_if(
        filterSet,
        [](int x) {
            return x % 2 == 0;
        }
    );

    cout << "After erase_if: ";
    printSet(filterSet);

    // ------------------------------------------------------------
    // 20. UNORDERED_SET HASH POLICY
    // ------------------------------------------------------------

    unordered_set<int> hashSet = {
        1, 2, 3, 4, 5
    };

    cout << "Bucket count: "
         << hashSet.bucket_count() << '\n';

    cout << "Load factor: "
         << hashSet.load_factor() << '\n';

    // reserve() requests enough buckets for at least n elements.
    hashSet.reserve(100);

    // rehash() requests at least a given number of buckets.
    hashSet.rehash(50);

    /*
        Core DSA usage:
            unordered_set -> use it for fast average membership.

        You usually do NOT need bucket_count/load_factor/rehash
        in normal DSA problem solving.
    */

    // ------------------------------------------------------------
    // 21. MERGE
    // ------------------------------------------------------------

    set<int> left = {1, 2, 3};
    set<int> right = {3, 4, 5};

    left.merge(right);

    /*
        For std::set:
            elements that do not violate uniqueness are transferred.

        An element already present in left remains in right.
    */

    // ------------------------------------------------------------
    // 22. EXTRACT
    // ------------------------------------------------------------

    set<int> extractSet = {1, 2, 3};

    auto node = extractSet.extract(2);

    if (!node.empty())
        cout << "Extracted: " << node.value() << '\n';

    // node can be modified and inserted into another compatible set.

    // ------------------------------------------------------------
    // 23. PRINT FINAL CONTAINERS
    // ------------------------------------------------------------

    cout << "\nOrdered set: ";
    printSet(ordered);

    cout << "Multiset: ";
    printSet(equalSet);

    cout << "Unordered set: ";
    printSet(hashSet);

    return 0;
}
