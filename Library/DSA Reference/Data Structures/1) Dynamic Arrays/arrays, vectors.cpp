#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    ARRAYS CHEAT SHEET — C++20
    ============================================================

    CORE / MUST KNOW
    ----------------
    Main DSA dynamic-array type: vector<int>

    Access            O(1)
    Update            O(1)
    Search            O(n)
    Push back         O(1) amortized
    Insert middle     O(n)
    Delete middle     O(n)
    Pop back          O(1)
    Min / Max         O(n)
    Reverse           O(n)
    Sort              O(n log n)
    Binary search     O(log n), sorted data

    EXTRAS / REFERENCE
    ------------------
    C-style arrays, std::array, reserve/capacity, iterators,
    lower/upper bound, erase-remove, move/copy, data(), etc.
*/

void printVector(const vector<int>& v) {
    for (int x : v)
        cout << x << ' ';
    cout << '\n';
}

int main() {

    // ============================================================
    // CORE — MUST KNOW
    // ============================================================

    // ------------------------------------------------------------
    // 1. INITIALISATION / CREATION
    // ------------------------------------------------------------

    vector<int> v;                 // Empty vector
    vector<int> v1(10);            // 10 elements, value-initialized to 0
    vector<int> v2(15, 2);         // 15 elements, all 2
    vector<int> v3 = {1, 2, 3, 4, 5};

    // From an existing range:
    int arr[] = {1, 2, 3};
    vector<int> v4(arr, arr + 3);

    // Copy:
    vector<int> copy = v3;  // Aliasing

    // ------------------------------------------------------------
    // 2. SIZE / EMPTY
    // ------------------------------------------------------------

    int n = (int)v1.size();         // O(1)
    bool isEmpty = v.empty();       // O(1)

    cout << "Size: " << n << '\n';
    cout << "Empty: " << boolalpha << isEmpty << '\n';

    // ------------------------------------------------------------
    // 3. ACCESS
    // ------------------------------------------------------------

    if (!v2.empty()) {
        int first = v2[0];          // O(1)
        int checked = v2.at(0);     // O(1), bounds-checked
        int front = v2.front();     // O(1)
        int back = v2.back();       // O(1)

        cout << "Access: "
             << first << ' '
             << checked << ' '
             << front << ' '
             << back << '\n';
    }

    // C++ does NOT support Python-style negative indexing.
    // v2[-1] does not mean "last element".

    // ------------------------------------------------------------
    // 4. UPDATE
    // ------------------------------------------------------------

    if (!v2.empty())
        v2[0] = 99;                // O(1)

    // ------------------------------------------------------------
    // 5. INSERTION
    // ------------------------------------------------------------

    v.push_back(4);                // End; O(1) amortized

    v.insert(v.begin() + 1, 30);   // At index; O(n)

    v.insert(v.end(), 2, 6);       // Insert k copies; O(n + k) in general

    vector<int> additional = {7, 8, 9};
    v.insert(v.end(),
             additional.begin(),
             additional.end());    // Insert range

    // ------------------------------------------------------------
    // 6. DELETION
    // ------------------------------------------------------------

    if (!v.empty())
        v.pop_back();               // Last; O(1)

    if (!v.empty())
        v.erase(v.begin());         // First; O(n)

    if (v.size() >= 2)
        v.erase(v.begin(), v.begin() + 2); // Range; O(n)

    // Delete by index:
    if (!v.empty()) {
        int i = min<int>(1, v.size() - 1);
        v.erase(v.begin() + i);     // O(n)
    }

    // ------------------------------------------------------------
    // 7. SEARCH
    // ------------------------------------------------------------

    int target = 2;

    auto it = find(v2.begin(), v2.end(), target);
    bool found = (it != v2.end());  // O(n)

    int occurrences = count(
        v2.begin(), v2.end(), target
    );                              // O(n)

    cout << "Found: " << found << '\n';
    cout << "Count: " << occurrences << '\n';

    // ------------------------------------------------------------
    // 8. TRAVERSAL
    // ------------------------------------------------------------

    cout << "Index traversal: ";
    for (int i = 0; i < (int)v2.size(); ++i)
        cout << v2[i] << ' ';
    cout << '\n';

    cout << "Range traversal: ";
    for (int x : v2)
        cout << x << ' ';
    cout << '\n';

    cout << "Iterator traversal: ";
    for (auto it2 = v2.begin(); it2 != v2.end(); ++it2)
        cout << *it2 << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 9. MIN / MAX / SUM
    // ------------------------------------------------------------

    if (!v2.empty()) {
        int mn = *min_element(v2.begin(), v2.end()); // O(n)
        int mx = *max_element(v2.begin(), v2.end()); // O(n)
        int sum = accumulate(v2.begin(), v2.end(), 0); // O(n)

        cout << "Min: " << mn << '\n';
        cout << "Max: " << mx << '\n';
        cout << "Sum: " << sum << '\n';
    }

    // ------------------------------------------------------------
    // 10. REVERSE
    // ------------------------------------------------------------

    reverse(v2.begin(), v2.end());  // O(n), in-place

    // ------------------------------------------------------------
    // 11. SORT
    // ------------------------------------------------------------

    vector<int> sortable = {5, 1, 4, 2, 3};

    sort(sortable.begin(), sortable.end());             // O(n log n)
    sort(sortable.rbegin(), sortable.rend());           // Descending

    // Custom comparator:
    sort(sortable.begin(), sortable.end(),
         [](int a, int b) {
             return a > b;
         });

    // ------------------------------------------------------------
    // 12. CLEAR
    // ------------------------------------------------------------

    v.clear();                       // O(n)
    // size becomes 0
    // capacity is a separate concept

    // ------------------------------------------------------------
    // 13. BINARY SEARCH
    // ------------------------------------------------------------

    vector<int> sorted = {1, 2, 2, 3, 5, 7, 9};

    bool exists = binary_search(
        sorted.begin(),
        sorted.end(),
        5
    );                              // O(log n)

    cout << "Binary search: " << exists << '\n';

    // ============================================================
    // EXTRAS — REFERENCE
    // ============================================================

    // ------------------------------------------------------------
    // 14. FIXED-SIZE ARRAY TYPES
    // ------------------------------------------------------------

    int fixed[5] = {1, 2, 3, 4, 5};       // C-style array
    array<int, 5> fixed_std = {1, 2, 3, 4, 5}; // std::array

    // std::array:
    cout << "std::array size: " << fixed_std.size() << '\n';
    fixed_std.fill(10);                   // O(n)

    // C-style arrays:
    // Fixed size; no push_back/erase/resize.
    // sizeof(fixed) / sizeof(fixed[0]) gives element count
    // only while `fixed` is still an actual array, not after decay.

    // ------------------------------------------------------------
    // 15. CAPACITY
    // ------------------------------------------------------------

    vector<int> cap;

    cout << "Initial size: " << cap.size() << '\n';
    cout << "Initial capacity: " << cap.capacity() << '\n';

    cap.reserve(100);                      // Capacity >= 100
    // reserve() DOES NOT change size.

    cout << "After reserve: size = "
         << cap.size()
         << ", capacity = "
         << cap.capacity() << '\n';

    cap.resize(10);                        // Changes size
    cap.resize(20, 5);                     // Adds 5s

    cap.resize(5);                         // Truncates

    // shrink_to_fit() is a non-binding request.
    cap.shrink_to_fit();

    // ------------------------------------------------------------
    // 16. REVERSE ITERATION
    // ------------------------------------------------------------

    cout << "Reverse traversal: ";
    for (auto rit = sortable.rbegin();
         rit != sortable.rend();
         ++rit) {
        cout << *rit << ' ';
    }
    cout << '\n';

    // ------------------------------------------------------------
    // 17. LOWER / UPPER BOUND
    // ------------------------------------------------------------

    auto lb = lower_bound(sorted.begin(), sorted.end(), 2);
    auto ub = upper_bound(sorted.begin(), sorted.end(), 2);

    cout << "lower_bound index: "
         << (lb - sorted.begin()) << '\n';

    cout << "upper_bound index: "
         << (ub - sorted.begin()) << '\n';

    auto range = equal_range(
        sorted.begin(),
        sorted.end(),
        2
    );

    cout << "equal_range: ["
         << (range.first - sorted.begin())
         << ", "
         << (range.second - sorted.begin())
         << ")\n";

    // Assumption: sorted / appropriately partitioned range.
    // For vector / random-access iterators: O(log n).

    // ------------------------------------------------------------
    // 18. DELETE ALL OCCURRENCES OF A VALUE
    // ------------------------------------------------------------

    vector<int> values = {1, 2, 2, 3, 2, 4};

    // C++20:
    erase(values, 2);                   // O(n)

    // Classic pre-C++20 erase-remove idiom:
    values = {1, 2, 2, 3, 2, 4};

    values.erase(
        remove(values.begin(), values.end(), 2),
        values.end()
    );

    // ------------------------------------------------------------
    // 19. COPY / MOVE / SWAP
    // ------------------------------------------------------------

    vector<int> a = {1, 2, 3};

    vector<int> b = a;                  // Copy: O(n)

    vector<int> c = move(a);            // Move: O(1) for normal vector use
                                        // a remains valid but unspecified

    b.swap(c);                           // O(1) for vector

    // ------------------------------------------------------------
    // 20. RANGE COPY / SLICE-LIKE OPERATION
    // ------------------------------------------------------------

    vector<int> original = {0, 1, 2, 3, 4, 5};

    int l = 1, r = 4;                    // [l, r)
    vector<int> sub(
        original.begin() + l,
        original.begin() + r
    );

    // TC: O(r-l)
    // SC: O(r-l)

    // ------------------------------------------------------------
    // 21. CONCATENATION
    // ------------------------------------------------------------

    vector<int> x = {1, 2, 3};
    vector<int> y = {4, 5, 6};

    vector<int> combined;
    combined.reserve(x.size() + y.size());

    combined.insert(combined.end(), x.begin(), x.end());
    combined.insert(combined.end(), y.begin(), y.end());

    // TC: O(n + m)
    // SC: O(n + m) for result

    // ------------------------------------------------------------
    // 22. DATA POINTER
    // ------------------------------------------------------------

    if (!combined.empty()) {
        int* ptr = combined.data();    // Pointer to contiguous storage
        cout << "data()[0]: " << ptr[0] << '\n';
    }

    // ------------------------------------------------------------
    // 23. FILL
    // ------------------------------------------------------------

    fill(combined.begin(), combined.end(), 0); // O(n)

    // ------------------------------------------------------------
    // 24. PREFIX SUM
    // ------------------------------------------------------------

    vector<int> nums = {1, 2, 3, 4};
    vector<int> prefix(nums.size());

    partial_sum(
        nums.begin(),
        nums.end(),
        prefix.begin()
    );

    // prefix = {1, 3, 6, 10}
    // TC: O(n), SC: O(n) output

    // ------------------------------------------------------------
    // 25. MANUAL LINEAR SEARCH
    // ------------------------------------------------------------

    auto findIndex = [](const vector<int>& arr, int value) -> int {
        for (int i = 0; i < (int)arr.size(); ++i) {
            if (arr[i] == value)
                return i;
        }
        return -1;
    };

    cout << "Manual search index: "
         << findIndex(sorted, 7) << '\n';

    // TC: O(n)
    // SC: O(1)

    // ------------------------------------------------------------
    // 26. MANUAL BINARY SEARCH
    // ------------------------------------------------------------

    auto binarySearch = [](const vector<int>& arr, int value) -> int {
        int left = 0;
        int right = (int)arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == value)
                return mid;

            if (arr[mid] < value)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    };

    cout << "Manual binary search index: "
         << binarySearch(sorted, 7) << '\n';

    // TC: O(log n)
    // SC: O(1)

    // ------------------------------------------------------------
    // 27. TWO-POINTER REVERSE
    // ------------------------------------------------------------

    vector<int> twoPointer = {1, 2, 3, 4, 5};

    int left = 0;
    int right = (int)twoPointer.size() - 1;

    while (left < right) {
        swap(twoPointer[left], twoPointer[right]);
        ++left;
        --right;
    }

    // TC: O(n)
    // SC: O(1)

    // ------------------------------------------------------------
    // 28. VECTOR ITERATOR / REFERENCE INVALIDATION
    // ------------------------------------------------------------

    /*
        Important rules to remember:

        - Reallocation can invalidate all pointers/references/iterators.
        - erase() invalidates iterators/references at and after the
          erased position.
        - push_back() without reallocation preserves existing element
          references/iterators, but end() can change.
        - reserve() can itself trigger reallocation.
    */

    // ------------------------------------------------------------
    // 29. COMMON NESTED VECTOR PATTERN
    // ------------------------------------------------------------

    vector<vector<int>> matrix(
        10,
        vector<int>(10, 5)
    );

    // 10 x 10 matrix filled with 5.
    // TC: O(n*m)
    // SC: O(n*m)

    // ------------------------------------------------------------
    // 30. OUTPUT
    // ------------------------------------------------------------

    cout << "\nFinal sample vector: ";
    printVector(sortable);

    return 0;
}
