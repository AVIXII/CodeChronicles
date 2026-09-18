// C++ STL — DSA / Competitive Programming Toolbox
// C++20
//
// PURPOSE
// -------
// This is the LANGUAGE TOOLBOX layer, not a replacement for the individual
// data-structure sheets.
//
// Detailed operations:
//   vector/array  -> Arrays sheet
//   string        -> Strings sheet
//   set           -> Sets sheet
//   map           -> Maps sheet
//   stack         -> Stacks sheet
//   queue/deque   -> Queues sheet
//   bitset        -> Bitset sheet
//   generic algorithms -> Algorithms sheet
//
// Here we focus on:
//   1) STL organization
//   2) Which tool to reach for
//   3) Iterators / utilities / adapters
//   4) STL mechanics and common traps
//
// Compile: g++ -std=c++20 cpp_stl.cpp -o cpp_stl

#include <bits/stdc++.h>
using namespace std;

void section(const string& title) {
    cout << "\n===== " << title << " =====\n";
}

int add(int a, int b) {
    return a + b;
}

struct Person {
    string name;
    int age;

    Person(string n, int a) : name(move(n)), age(a) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ============================================================
    // CORE / MUST KNOW
    // ============================================================

    // ------------------------------------------------------------
    // 1. STL mental model
    // ------------------------------------------------------------
    section("1. STL Mental Model");

    // Containers  -> store data
    // Algorithms  -> operate on ranges
    // Iterators   -> connect containers and algorithms
    // Adapters    -> provide restricted interfaces
    // Utilities   -> small reusable types/helpers

    vector<int> v = {5, 1, 4, 2, 3};
    sort(v.begin(), v.end());

    for (int x : v)
        cout << x << ' ';
    cout << '\n';

    // Core pattern:
    // container + begin/end + algorithm

    // ------------------------------------------------------------
    // 2. Sequence containers
    // ------------------------------------------------------------
    section("2. Sequence Containers");

    array<int, 3> a = {1, 2, 3};     // fixed size
    vector<int> dyn = {1, 2, 3};      // dynamic array
    deque<int> dq = {2, 3};
    dq.push_front(1);
    dq.push_back(4);

    list<int> lst = {1, 2, 3};
    lst.push_front(0);
    lst.push_back(4);

    forward_list<int> fl = {1, 2, 3};
    fl.push_front(0);

    cout << a[1] << '\n';
    cout << dyn.back() << '\n';
    cout << dq.front() << ' ' << dq.back() << '\n';
    cout << lst.front() << ' ' << lst.back() << '\n';
    cout << fl.front() << '\n';

    // Use:
    // array        -> fixed-size contiguous sequence
    // vector       -> default dynamic array / most common CP container
    // deque        -> efficient operations at both ends
    // list         -> linked-list semantics / iterator-stable insertion
    // forward_list -> singly linked list, niche in CP

    // ------------------------------------------------------------
    // 3. Associative containers
    // ------------------------------------------------------------
    section("3. Ordered Associative Containers");

    set<int> s = {4, 1, 3, 1, 2};
    map<string, int> mp = {
        {"alice", 10},
        {"bob", 20}
    };

    multiset<int> ms = {1, 1, 2, 3};
    multimap<int, string> mm = {
        {1, "A"}, {1, "B"}, {2, "C"}
    };

    cout << *s.begin() << '\n';
    cout << mp["alice"] << '\n';
    cout << ms.count(1) << '\n';
    cout << mm.count(1) << '\n';

    // Ordered tree containers:
    // set / map / multiset / multimap
    // Typical search/insert/erase: O(log n)

    // ------------------------------------------------------------
    // 4. Unordered / hash containers
    // ------------------------------------------------------------
    section("4. Unordered Containers");

    unordered_set<int> us = {1, 2, 3};
    unordered_map<string, int> ump = {
        {"alice", 10},
        {"bob", 20}
    };
    unordered_multiset<int> ums = {1, 1, 2};
    unordered_multimap<int, string> umm = {
        {1, "A"}, {1, "B"}
    };

    cout << us.count(2) << '\n';
    cout << ump["alice"] << '\n';
    cout << ums.count(1) << '\n';
    cout << umm.count(1) << '\n';

    // Hash containers:
    // average lookup/insert/erase is O(1)
    // worst case can be O(n)

    // ------------------------------------------------------------
    // 5. Container adapters
    // ------------------------------------------------------------
    section("5. Container Adapters");

    stack<int> st;
    st.push(10);
    st.emplace(20);
    cout << st.top() << '\n';
    st.pop();

    queue<int> q;
    q.push(10);
    q.emplace(20);
    cout << q.front() << ' ' << q.back() << '\n';
    q.pop();

    priority_queue<int> pq; // max-heap
    pq.push(3);
    pq.push(5);
    pq.push(1);
    cout << pq.top() << '\n';

    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(3);
    minpq.push(5);
    minpq.push(1);
    cout << minpq.top() << '\n';

    // ------------------------------------------------------------
    // 6. Utility types
    // ------------------------------------------------------------
    section("6. Utility Types");

    pair<int, string> p = {1, "Alice"};
    cout << p.first << ' ' << p.second << '\n';

    tuple<int, string, double> t = {1, "Alice", 9.5};
    cout << get<0>(t) << ' ' << get<1>(t) << ' '
         << get<2>(t) << '\n';

    auto [id, person] = p;
    cout << id << ' ' << person << '\n';

    // Common DSA aliases:
    using ll = long long;
    using pii = pair<int, int>;
    using vi = vector<int>;

    ll large = 10000000000LL;
    pii point = {3, 4};
    vi nums = {1, 2, 3};

    cout << large << ' ' << point.first << ' '
         << point.second << ' ' << nums.size() << '\n';

    // ------------------------------------------------------------
    // 7. Iterators
    // ------------------------------------------------------------
    section("7. Iterators");

    vector<int> iv = {10, 20, 30, 40, 50};

    auto it = iv.begin();
    cout << *it << '\n';

    ++it;
    cout << *it << '\n';

    cout << "begin/end loop: ";
    for (auto iter = iv.begin(); iter != iv.end(); ++iter)
        cout << *iter << ' ';
    cout << '\n';

    cout << "reverse loop: ";
    for (auto iter = iv.rbegin(); iter != iv.rend(); ++iter)
        cout << *iter << ' ';
    cout << '\n';

    // begin/end are commonly used with algorithms.
    // end() is one-past-the-last element and must not be dereferenced.

    // ------------------------------------------------------------
    // 8. Iterator helpers
    // ------------------------------------------------------------
    section("8. Iterator Helpers");

    auto pos = find(iv.begin(), iv.end(), 40);

    cout << "distance = " << distance(iv.begin(), pos) << '\n';
    cout << "next = " << *next(iv.begin(), 2) << '\n';
    cout << "prev = " << *prev(iv.end(), 2) << '\n';

    auto moved = iv.begin();
    advance(moved, 3);
    cout << "advance = " << *moved << '\n';

    // Complexity depends on iterator category:
    // random access -> movement/distance O(1)
    // weaker iterators -> may be O(n)

    // ------------------------------------------------------------
    // 9. Const iterators
    // ------------------------------------------------------------
    section("9. Const Iterators");

    const vector<int> cv = {1, 2, 3};

    auto cit = cv.cbegin();
    while (cit != cv.cend()) {
        cout << *cit << ' ';
        ++cit;
    }
    cout << '\n';

    // cbegin/cend prevent modification through the iterator.

    // ------------------------------------------------------------
    // 10. Generic algorithms
    // ------------------------------------------------------------
    section("10. Generic Algorithms");

    vector<int> alg = {5, 2, 4, 1, 3};

    sort(alg.begin(), alg.end());
    reverse(alg.begin(), alg.end());

    auto found = find(alg.begin(), alg.end(), 3);
    if (found != alg.end())
        cout << *found << '\n';

    cout << lower_bound(alg.begin(), alg.end(), 3) - alg.begin()
         << "  // only valid as a lower_bound example if range is sorted\n";

    // See Algorithms sheet for the full catalog.
    // Core idea:
    // algorithm(first, last, ...)

    // ------------------------------------------------------------
    // 11. Range insertion helpers
    // ------------------------------------------------------------
    section("11. Output Iterators");

    vector<int> source = {1, 2, 3};
    vector<int> destination;

    copy(source.begin(), source.end(), back_inserter(destination));

    vector<int> destination2;
    copy(source.begin(), source.end(), inserter(destination2, destination2.begin()));

    for (int x : destination)
        cout << x << ' ';
    cout << '\n';

    for (int x : destination2)
        cout << x << ' ';
    cout << '\n';

    // back_inserter(container) -> push_back()
    // front_inserter(container) -> push_front()
    // inserter(container, it) -> insert()

    // ------------------------------------------------------------
    // 12. Lambda / comparator
    // ------------------------------------------------------------
    section("12. Lambda / Comparator");

    vector<pair<int, int>> points = {
        {2, 5}, {1, 9}, {2, 3}, {1, 4}
    };

    sort(points.begin(), points.end(),
         [](const auto& a, const auto& b) {
             if (a.first != b.first)
                 return a.first < b.first;
             return a.second > b.second;
         });

    for (auto [x, y] : points)
        cout << x << ',' << y << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 13. emplace vs push
    // ------------------------------------------------------------
    section("13. emplace vs push");

    vector<Person> people;

    Person p1("Alice", 20);
    people.push_back(p1);

    people.emplace_back("Bob", 21);

    for (const auto& personObj : people)
        cout << personObj.name << ' ' << personObj.age << '\n';

    // emplace constructs the object from constructor arguments.
    // Do not blindly assume emplace is "always faster"; context matters.

    // ------------------------------------------------------------
    // 14. swap / exchange
    // ------------------------------------------------------------
    section("14. swap / exchange");

    vector<int> x = {1, 2, 3};
    vector<int> y = {4, 5};

    swap(x, y);

    int value = 10;
    int old = exchange(value, 99);

    cout << x.size() << ' ' << y.size() << '\n';
    cout << old << ' ' << value << '\n';

    // ------------------------------------------------------------
    // 15. erase-remove
    // ------------------------------------------------------------
    section("15. Erase-Remove");

    vector<int> er = {1, 2, 2, 3, 2, 4};

    er.erase(remove(er.begin(), er.end(), 2), er.end());

    for (int z : er)
        cout << z << ' ';
    cout << '\n';

    // C++20:
    erase_if(er, [](int z) {
        return z % 2 == 0;
    });

    // ------------------------------------------------------------
    // 16. Range-for and structured bindings
    // ------------------------------------------------------------
    section("16. Modern Traversal");

    for (int z : iv)
        cout << z << ' ';
    cout << '\n';

    for (auto& [key, value2] : mp)
        cout << key << ':' << value2 << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 17. Common STL constructors / initialization
    // ------------------------------------------------------------
    section("17. Common Initialization");

    vector<int> a1(5);          // 5 zero-initialized ints
    vector<int> a2(5, 7);       // five 7s
    vector<int> a3 = {1, 2, 3}; // initializer list

    set<int> s1 = {3, 1, 2};
    unordered_set<int> s2 = {3, 1, 2};

    map<int, string> m1 = {
        {1, "one"},
        {2, "two"}
    };

    cout << a1.size() << ' ' << a2.front() << ' '
         << a3.back() << ' ' << s1.size() << ' '
         << s2.size() << ' ' << m1.size() << '\n';

    // ------------------------------------------------------------
    // 18. Capacity vs size (vector)
    // ------------------------------------------------------------
    section("18. Size vs Capacity");

    vector<int> cap;
    cap.reserve(100);

    cout << "size = " << cap.size()
         << ", capacity = " << cap.capacity() << '\n';

    cap.resize(10);

    cout << "size = " << cap.size()
         << ", capacity = " << cap.capacity() << '\n';

    // reserve -> capacity management; does not create elements.
    // resize  -> changes number of elements.

    // ------------------------------------------------------------
    // 19. Ordered vs unordered reach-for rule
    // ------------------------------------------------------------
    section("19. Ordered vs Unordered");

    // Need sorted order / predecessor / successor / lower_bound?
    // -> set / map

    // Need average O(1) lookup and ordering does not matter?
    // -> unordered_set / unordered_map

    // Need duplicates with sorted order?
    // -> multiset / multimap

    set<int> ordered = {1, 3, 5};
    auto low = ordered.lower_bound(4);

    if (low != ordered.end())
        cout << *low << '\n';

    // ------------------------------------------------------------
    // 20. String is an STL type too
    // ------------------------------------------------------------
    section("20. string");

    string str = "hello";
    str += " world";
    cout << str << '\n';

    // See Strings sheet for detailed string operations.

    // ============================================================
    // EXTRAS / REFERENCE
    // ============================================================

    // ------------------------------------------------------------
    // 21. Other containers worth recognizing
    // ------------------------------------------------------------
    section("EXTRAS: Other Containers");

    // These are primarily awareness/reference for DSA.
    unordered_set<int> us2 = {1, 2, 3};
    unordered_map<int, int> um2 = {{1, 10}, {2, 20}};

    cout << us2.size() << ' ' << um2.size() << '\n';

    // C-style raw arrays are language arrays, not STL containers.
    int raw[] = {1, 2, 3};
    cout << size(raw) << '\n'; // std::size

    // ------------------------------------------------------------
    // 22. Custom hash
    // ------------------------------------------------------------
    section("EXTRAS: Custom Hash");

    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>{}(p.first) ^
                   (hash<int>{}(p.second) << 1);
        }
    };

    unordered_set<pair<int, int>, PairHash> pairSet;
    pairSet.insert({1, 2});
    pairSet.insert({3, 4});

    cout << pairSet.count({1, 2}) << '\n';

    // ------------------------------------------------------------
    // 23. Custom comparator type
    // ------------------------------------------------------------
    section("EXTRAS: Custom Comparator");

    struct Desc {
        bool operator()(int a, int b) const {
            return a > b;
        }
    };

    set<int, Desc> descending = {1, 5, 3, 2};

    for (int z : descending)
        cout << z << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 24. Map insertion variants
    // ------------------------------------------------------------
    section("EXTRAS: map insertion variants");

    map<int, string> mapOps;

    mapOps[1] = "one";                    // inserts if missing
    mapOps.insert({2, "two"});            // does not overwrite existing key
    mapOps.insert_or_assign(2, "TWO");    // insert or overwrite
    mapOps.try_emplace(3, "three");       // construct value only if inserted

    for (auto [k, val] : mapOps)
        cout << k << ':' << val << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 25. Node handles / extract / merge
    // ------------------------------------------------------------
    section("EXTRAS: extract / merge");

    set<int> setA = {1, 2, 3};
    set<int> setB = {4, 5};

    auto node = setA.extract(2);
    if (!node.empty())
        setB.insert(move(node));

    set<int> setC = {6, 7};
    setB.merge(setC);

    for (int z : setB)
        cout << z << ' ';
    cout << '\n';

    // ------------------------------------------------------------
    // 26. Hash-table tuning
    // ------------------------------------------------------------
    section("EXTRAS: Hash Policy");

    unordered_map<int, int> hm;

    cout << "bucket_count = " << hm.bucket_count() << '\n';
    cout << "load_factor = " << hm.load_factor() << '\n';

    hm.reserve(1000);

    cout << "after reserve buckets = "
         << hm.bucket_count() << '\n';

    // reserve is useful when a large number of insertions is known.

    // ------------------------------------------------------------
    // 27. priority_queue with custom objects
    // ------------------------------------------------------------
    section("EXTRAS: priority_queue comparator");

    struct Node {
        int cost;
        int id;

        bool operator<(const Node& other) const {
            return cost > other.cost; // min-heap behavior
        }
    };

    priority_queue<Node> nodes;
    nodes.push({10, 1});
    nodes.push({5, 2});

    cout << nodes.top().cost << ' ' << nodes.top().id << '\n';

    // ------------------------------------------------------------
    // 28. tuple helpers
    // ------------------------------------------------------------
    section("EXTRAS: tuple helpers");

    tuple<int, string, double> tt = {1, "one", 1.5};

    apply([](const auto&... args) {
        ((cout << args << ' '), ...);
        cout << '\n';
    }, tt);

    // ------------------------------------------------------------
    // 29. optional / variant awareness
    // ------------------------------------------------------------
    section("EXTRAS: optional / variant");

    optional<int> maybeValue = 42;

    if (maybeValue)
        cout << *maybeValue << '\n';

    variant<int, string> data = string("hello");

    if (holds_alternative<string>(data))
        cout << get<string>(data) << '\n';

    // Low priority for ordinary DSA, but part of modern C++ utility knowledge.

    // ------------------------------------------------------------
    // 30. function / callable storage
    // ------------------------------------------------------------
    section("EXTRAS: callable");

    function<int(int, int)> fn = add;
    cout << fn(2, 3) << '\n';

    function<int(int)> twice = [](int z) {
        return 2 * z;
    };

    cout << twice(10) << '\n';

    // ------------------------------------------------------------
    // 31. C++20 ranges
    // ------------------------------------------------------------
    section("EXTRAS: C++20 ranges");

    vector<int> rangeVec = {5, 4, 3, 2, 1};

    ranges::sort(rangeVec);
    auto rangeIt = ranges::find(rangeVec, 3);

    if (rangeIt != rangeVec.end())
        cout << *rangeIt << '\n';

    // ranges reduce iterator boilerplate:
    // sort(v)
    // find(v, x)
    // lower_bound(v, x)

    // ============================================================
    // COMMON STL TRAPS
    // ============================================================

    section("Common STL Traps");

    cout <<
        "1. end() is one-past-last; never dereference it.\n"
        "2. vector push_back is O(1) amortized, not unconditional O(1).\n"
        "3. vector reserve changes capacity, not size.\n"
        "4. remove() does not erase elements from the container.\n"
        "5. generic lower_bound needs the required ordering/partitioning.\n"
        "6. unordered containers provide average, not worst-case O(1).\n"
        "7. map[key] inserts a default value when key is missing.\n"
        "8. iterator/reference validity can change after container mutation.\n"
        "9. priority_queue is max-heap by default.\n"
        "10. list has no random-access operator[].\n";

    cout << "\nC++ STL toolbox completed.\n";
    return 0;
}
