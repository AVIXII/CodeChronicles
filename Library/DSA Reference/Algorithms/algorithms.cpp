// Algorithms in C++20 — DSA / Competitive Programming Reference
// Compile: g++ -std=c++20 algorithms_cpp.cpp -o algorithms_cpp
//
// Covers the most useful generic STL algorithms, their patterns,
// iterator requirements, and common traps.
//
// CORE / MUST KNOW first, then EXTRAS / REFERENCE.

#include <bits/stdc++.h>
using namespace std;

void printVec(const vector<int>& v) {
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

template <class It>
void printRange(It first, It last) {
    for (; first != last; ++first) cout << *first << ' ';
    cout << '\n';
}

void section(const string& s) {
    cout << "\n===== " << s << " =====\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ============================================================
    // CORE / MUST KNOW
    // ============================================================

    // 1) for_each()
    section("1. for_each");
    vector<int> v = {1, 2, 3, 4, 5};
    for_each(v.begin(), v.end(), [](int x) {
        cout << x * 2 << ' ';
    });
    cout << '\n';

    // TC O(n), extra SC O(1) excluding callable/side effects.
    // Prefer a range-for in ordinary code when no generic algorithm is needed.

    // 2) find() / find_if() / find_if_not()
    section("2. find / find_if / find_if_not");
    auto it = find(v.begin(), v.end(), 4);
    if (it != v.end()) cout << "found: " << *it << '\n';

    auto firstEven = find_if(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    });
    if (firstEven != v.end()) cout << "first even: " << *firstEven << '\n';

    auto firstNotEven = find_if_not(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    });
    if (firstNotEven != v.end()) cout << "first odd: " << *firstNotEven << '\n';

    // TC O(n) worst, SC O(1).

    // 3) count() / count_if()
    section("3. count / count_if");
    cout << count(v.begin(), v.end(), 2) << '\n';
    cout << count_if(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    }) << '\n';
    // TC O(n), SC O(1).

    // 4) all_of / any_of / none_of
    section("4. all_of / any_of / none_of");
    cout << boolalpha
         << all_of(v.begin(), v.end(), [](int x) { return x > 0; }) << '\n'
         << any_of(v.begin(), v.end(), [](int x) { return x > 4; }) << '\n'
         << none_of(v.begin(), v.end(), [](int x) { return x < 0; }) << '\n';
    // TC O(n) worst; may short-circuit. SC O(1).

    // 5) sort()
    section("5. sort");
    vector<int> a = {5, 1, 4, 2, 3};
    sort(a.begin(), a.end());
    printVec(a);

    sort(a.begin(), a.end(), greater<int>());
    printVec(a);

    // Average/worst TC O(n log n) complexity guarantee since C++11.
    // SC is implementation-dependent; typically O(log n) stack.
    // Not stable.
    // stable_sort() below is stable.

    // 6) stable_sort()
    section("6. stable_sort");
    vector<pair<int, char>> pairs = {
        {2, 'a'}, {1, 'b'}, {2, 'c'}, {1, 'd'}
    };
    stable_sort(pairs.begin(), pairs.end(),
                [](const auto& x, const auto& y) {
                    return x.first < y.first;
                });
    for (auto [x, c] : pairs) cout << '(' << x << ',' << c << ") ";
    cout << '\n';
    // TC O(n log n), extra SC typically O(n) when enough memory available;
    // algorithm may fall back to O(n log n) comparisons with no extra buffer.

    // 7) reverse / reverse_copy
    section("7. reverse / reverse_copy");
    vector<int> r = {1, 2, 3, 4, 5};
    reverse(r.begin(), r.end());
    printVec(r);

    vector<int> reversedCopy(5);
    reverse_copy(r.begin(), r.end(), reversedCopy.begin());
    printVec(reversedCopy);
    // TC O(n), SC O(1) for reverse, O(n) for reverse_copy destination.

    // 8) rotate / rotate_copy
    section("8. rotate / rotate_copy");
    vector<int> rot = {1, 2, 3, 4, 5};
    rotate(rot.begin(), rot.begin() + 2, rot.end()); // 3 4 5 1 2
    printVec(rot);

    vector<int> rotCopy(5);
    rotate_copy(rot.begin(), rot.begin() + 3, rot.end(), rotCopy.begin());
    printVec(rotCopy);
    // TC O(n), SC O(1) for rotate, O(n) destination for rotate_copy.

    // 9) fill / fill_n
    section("9. fill / fill_n");
    vector<int> filled(5);
    fill(filled.begin(), filled.end(), 7);
    fill_n(filled.begin(), 2, 9);
    printVec(filled);
    // TC O(n) over written range, SC O(1).

    // 10) replace / replace_if
    section("10. replace / replace_if");
    vector<int> repl = {1, 2, 2, 3, 4};
    replace(repl.begin(), repl.end(), 2, 99);
    replace_if(repl.begin(), repl.end(), [](int x) {
        return x > 90;
    }, 0);
    printVec(repl);
    // TC O(n), SC O(1).

    // 11) remove / remove_if + erase
    section("11. remove / remove_if + erase");
    vector<int> rem = {1, 2, 2, 3, 2, 4};
    rem.erase(remove(rem.begin(), rem.end(), 2), rem.end());
    printVec(rem);

    vector<int> remIf = {1, 2, 3, 4, 5, 6};
    remIf.erase(remove_if(remIf.begin(), remIf.end(),
                           [](int x) { return x % 2 == 0; }),
                remIf.end());
    printVec(remIf);
    // remove/remove_if alone do NOT shrink a vector.
    // erase-remove is the idiomatic vector pattern.
    // TC O(n), SC O(1).

    // 12) unique()
    section("12. unique");
    vector<int> uniq = {1, 1, 2, 2, 2, 3, 1};
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    printVec(uniq);
    // Only removes consecutive duplicates.
    // Sort first if you want to collapse all equal values.
    // TC O(n), SC O(1).

    // 13) binary_search / lower_bound / upper_bound / equal_range
    section("13. binary search family");
    vector<int> sorted = {1, 2, 2, 2, 4, 6, 8};

    cout << binary_search(sorted.begin(), sorted.end(), 4) << '\n';

    auto lb = lower_bound(sorted.begin(), sorted.end(), 2);
    auto ub = upper_bound(sorted.begin(), sorted.end(), 2);
    auto [eqL, eqR] = equal_range(sorted.begin(), sorted.end(), 2);

    cout << "lower_bound index = " << (lb - sorted.begin()) << '\n';
    cout << "upper_bound index = " << (ub - sorted.begin()) << '\n';
    cout << "frequency = " << (eqR - eqL) << '\n';

    // On vector/random-access iterators: O(log n) comparisons and O(log n) iterator movement.
    // For generic forward iterators, iterator movement can be O(n).
    // Range must be appropriately partitioned/sorted for usual binary-search use.

    // 14) is_sorted / is_sorted_until
    section("14. is_sorted / is_sorted_until");
    cout << is_sorted(sorted.begin(), sorted.end()) << '\n';

    vector<int> partially = {1, 2, 3, 5, 4, 6};
    auto until = is_sorted_until(partially.begin(), partially.end());
    cout << "sorted prefix length = "
         << distance(partially.begin(), until) << '\n';
    // TC O(n) worst, SC O(1).

    // 15) min / max / min_element / max_element / minmax
    section("15. min / max family");
    cout << min(10, 20) << ' ' << max(10, 20) << '\n';
    auto minIt = min_element(v.begin(), v.end());
    auto maxIt = max_element(v.begin(), v.end());
    auto [minIt2, maxIt2] = minmax_element(v.begin(), v.end());
    cout << *minIt << ' ' << *maxIt << ' '
         << *minIt2 << ' ' << *maxIt2 << '\n';
    // min/max of two values: O(1); over range: O(n), SC O(1).

    // 16) next_permutation / prev_permutation
    section("16. permutations");
    vector<int> perm = {1, 2, 3};
    do {
        printVec(perm);
    } while (next_permutation(perm.begin(), perm.end()));

    sort(perm.begin(), perm.end(), greater<int>());
    cout << "prev permutations:\n";
    do {
        printVec(perm);
    } while (prev_permutation(perm.begin(), perm.end()));
    // Each permutation step: O(n) worst, SC O(1).
    // To enumerate all permutations exactly once, start sorted for next_permutation.
    // Do-while processes the current permutation before asking for the next one.

    // 17) is_permutation()
    section("17. is_permutation");
    vector<int> p1 = {1, 2, 3, 2};
    vector<int> p2 = {2, 3, 2, 1};
    cout << is_permutation(p1.begin(), p1.end(), p2.begin(), p2.end()) << '\n';
    // General complexity can be O(n^2); if element counts/hashing are needed,
    // a frequency map can often be faster.
    // SC O(1) for the algorithm itself (excluding comparator/hash machinery).

    // 18) merge() / inplace_merge()
    section("18. merge family");
    vector<int> m1 = {1, 3, 5};
    vector<int> m2 = {2, 4, 6};
    vector<int> merged(6);
    merge(m1.begin(), m1.end(), m2.begin(), m2.end(), merged.begin());
    printVec(merged);

    vector<int> in = {1, 3, 5, 2, 4, 6};
    inplace_merge(in.begin(), in.begin() + 3, in.end());
    printVec(in);
    // Inputs to merge must each be sorted.
    // merge: O(n+m), output destination needs space.
    // inplace_merge: O(n+m), typically O(n+m) extra if buffer available,
    // otherwise may use a more expensive fallback.

    // 19) set algorithms on sorted ranges
    section("19. set algorithms");
    vector<int> s1 = {1, 2, 2, 3, 5};
    vector<int> s2 = {2, 3, 4, 5};

    vector<int> uni, inter, diff, sym;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(),
              back_inserter(uni));
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                     back_inserter(inter));
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                   back_inserter(diff));
    set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
                             back_inserter(sym));

    cout << "union: "; printVec(uni);
    cout << "intersection: "; printVec(inter);
    cout << "difference: "; printVec(diff);
    cout << "symmetric difference: "; printVec(sym);

    // Includes:
    cout << boolalpha
         << includes(s1.begin(), s1.end(),
                     vector<int>{2, 3}.begin(), vector<int>{2, 3}.end())
         << '\n';
    // NOTE: the temporary-iterator expression above creates dangling iterators.
    // It is intentionally NOT a valid pattern to use.
    // Correct pattern shown below.
    vector<int> need = {2, 3};
    cout << includes(s1.begin(), s1.end(), need.begin(), need.end()) << '\n';

    // Complexity for set operations: O(n+m), SC proportional to output when
    // writing into a new destination.

    // 20) partition / stable_partition
    section("20. partition family");
    vector<int> part = {1, 2, 3, 4, 5, 6};
    auto mid = partition(part.begin(), part.end(),
                         [](int x) { return x % 2 == 0; });
    printVec(part);
    cout << "partition point index = "
         << distance(part.begin(), mid) << '\n';

    vector<int> stablePart = {1, 2, 3, 4, 5, 6};
    stable_partition(stablePart.begin(), stablePart.end(),
                     [](int x) { return x % 2 == 0; });
    printVec(stablePart);

    // partition: O(n), typically O(1) extra for bidirectional/random access.
    // stable_partition: O(n) if extra memory is available; may be O(n log n)
    // without it. It preserves relative order inside groups.

    // 21) nth_element()
    section("21. nth_element");
    vector<int> kth = {7, 1, 9, 2, 6, 3, 8};
    nth_element(kth.begin(), kth.begin() + 3, kth.end());
    cout << "4th smallest = " << kth[3] << '\n';
    cout << "not fully sorted: "; printVec(kth);
    // Average O(n), worst-case O(n log n) for std::nth_element's complexity guarantee.
    // Elements before nth are <= kth[nth]; elements after are >= it,
    // but neither side is sorted.

    // 22) Heap algorithms
    section("22. heap algorithms");
    vector<int> heap = {3, 1, 4, 2, 5};

    make_heap(heap.begin(), heap.end());    // max heap
    cout << "heap top = " << heap.front() << '\n';

    heap.push_back(6);
    push_heap(heap.begin(), heap.end());

    pop_heap(heap.begin(), heap.end());
    cout << "popped = " << heap.back() << '\n';
    heap.pop_back();

    sort_heap(heap.begin(), heap.end());
    printVec(heap);

    // make_heap O(n), push_heap/pop_heap O(log n), sort_heap O(n log n).
    // heap algorithms rearrange a range; priority_queue is usually easier for CP.

    // 23) distance / next / prev
    section("23. iterator helpers");
    vector<int> iv = {10, 20, 30, 40, 50};

    auto posIt = find(iv.begin(), iv.end(), 40);
    cout << distance(iv.begin(), posIt) << '\n';

    auto third = next(iv.begin(), 2);
    cout << *third << '\n';

    auto last = prev(iv.end());
    cout << *last << '\n';

    // distance: O(1) for random-access iterators, otherwise may be O(n).
    // next/prev: O(1) for random-access, otherwise linear in movement.
    // advance(it,n) modifies the iterator itself.

    // 24) transform
    section("24. transform");
    vector<int> tr = {1, 2, 3, 4};
    transform(tr.begin(), tr.end(), tr.begin(), [](int x) {
        return x * x;
    });
    printVec(tr);

    // Two-range form:
    vector<int> x1 = {1, 2, 3};
    vector<int> x2 = {10, 20, 30};
    vector<int> sums(3);
    transform(x1.begin(), x1.end(), x2.begin(), sums.begin(),
              plus<int>());
    printVec(sums);
    // TC O(n), SC O(1) besides output.

    // 25) copy / copy_if
    section("25. copy family");
    vector<int> source = {1, 2, 3, 4, 5};
    vector<int> dest(5);

    copy(source.begin(), source.end(), dest.begin());
    printVec(dest);

    vector<int> evens;
    copy_if(source.begin(), source.end(), back_inserter(evens),
            [](int x) { return x % 2 == 0; });
    printVec(evens);
    // TC O(n), SC O(1) for copy excluding destination; copy_if output O(k).

    // ============================================================
    // EXTRAS / REFERENCE
    // ============================================================

    // 26) Search operations
    section("EXTRAS: search operations");

    vector<int> hay = {1, 2, 3, 2, 3, 4, 5};
    vector<int> needle = {2, 3};

    auto firstSub = search(hay.begin(), hay.end(),
                           needle.begin(), needle.end());
    if (firstSub != hay.end())
        cout << "first subsequence index = "
             << distance(hay.begin(), firstSub) << '\n';

    auto lastSub = find_end(hay.begin(), hay.end(),
                            needle.begin(), needle.end());
    if (lastSub != hay.end())
        cout << "last subsequence index = "
             << distance(hay.begin(), lastSub) << '\n';

    vector<int> targets = {4, 5};
    auto firstOf = find_first_of(hay.begin(), hay.end(),
                                 targets.begin(), targets.end());
    if (firstOf != hay.end()) cout << "first of targets = " << *firstOf << '\n';

    auto adjacent = adjacent_find(hay.begin(), hay.end());
    if (adjacent != hay.end()) cout << "adjacent equal at = " << *adjacent << '\n';

    auto repeated = search_n(hay.begin(), hay.end(), 2, 2);
    if (repeated != hay.end())
        cout << "two consecutive 2s start at = "
             << distance(hay.begin(), repeated) << '\n';
    // search/search_n/find_end/find_first_of/adjacent_find are generally O(n*m)
    // worst case for generic input patterns (details vary by algorithm/iterator).

    // 27) equal / mismatch
    section("EXTRAS: equal / mismatch");

    vector<int> e1 = {1, 2, 3};
    vector<int> e2 = {1, 2, 4};

    cout << equal(e1.begin(), e1.end(), e2.begin()) << '\n';

    auto [mismatch1, mismatch2] =
        mismatch(e1.begin(), e1.end(), e2.begin(), e2.end());

    cout << "mismatch index = "
         << distance(e1.begin(), mismatch1) << '\n';
    // TC O(n) worst, SC O(1).

    // 28) copy_n / copy_backward
    section("EXTRAS: copy_n / copy_backward");
    vector<int> cn(5);
    copy_n(source.begin(), 3, cn.begin());
    printVec(cn);

    vector<int> cb = {1, 2, 3, 0, 0};
    copy_backward(cb.begin(), cb.begin() + 3, cb.end());
    printVec(cb);
    // TC O(n), SC O(1) excluding destination.

    // 29) generate / generate_n
    section("EXTRAS: generate");
    int cur = 1;
    vector<int> generated(5);
    generate(generated.begin(), generated.end(), [&cur]() {
        return cur++;
    });
    printVec(generated);

    // 30) shift_left / shift_right (C++20)
    section("EXTRAS: shift");
    vector<int> shifted = {1, 2, 3, 4, 5};
    shift_left(shifted.begin(), shifted.end(), 2);
    printVec(shifted);

    vector<int> shifted2 = {1, 2, 3, 4, 5};
    shift_right(shifted2.begin(), shifted2.end(), 2);
    printVec(shifted2);

    // 31) shuffle / sample
    section("EXTRAS: randomness");
    mt19937 rng(123456);
    vector<int> shuf = {1, 2, 3, 4, 5};
    shuffle(shuf.begin(), shuf.end(), rng);
    printVec(shuf);

    vector<int> sampled;
    sample(shuf.begin(), shuf.end(), back_inserter(sampled), 3, rng);
    printVec(sampled);
    // shuffle: linear, sample: linear in input (with algorithm-dependent details).

    // 32) lexicographical_compare
    section("EXTRAS: lexicographical_compare");
    string aa = "apple";
    string bb = "apply";
    cout << lexicographical_compare(
        aa.begin(), aa.end(), bb.begin(), bb.end()
    ) << '\n';

    // 33) max/min over initializer lists
    section("EXTRAS: initializer_list");
    cout << min({4, 2, 9, 1}) << '\n';
    cout << max({4, 2, 9, 1}) << '\n';
    auto [mn, mx] = minmax({4, 2, 9, 1});
    cout << mn << ' ' << mx << '\n';

    // 34) accumulate / reduce / transform_reduce
    section("EXTRAS: numeric algorithms");
    vector<int> nums = {1, 2, 3, 4};

    cout << accumulate(nums.begin(), nums.end(), 0) << '\n';
    cout << reduce(nums.begin(), nums.end(), 0) << '\n';
    cout << transform_reduce(nums.begin(), nums.end(), 0,
                             plus<int>(), [](int x) { return x * x; }) << '\n';

    vector<int> pref(4);
    partial_sum(nums.begin(), nums.end(), pref.begin());
    printVec(pref);

    // reduce/transform_reduce are designed with possible reordering, so
    // operations should satisfy suitable associativity/commutativity expectations.
    // accumulate is sequential in the specified order.

    // 35) inner_product / adjacent_difference
    section("EXTRAS: numeric sequence helpers");
    vector<int> other = {5, 6, 7, 8};
    cout << inner_product(nums.begin(), nums.end(),
                          other.begin(), 0) << '\n';

    vector<int> differences(4);
    adjacent_difference(other.begin(), other.end(), differences.begin());
    printVec(differences);

    // 36) scans
    section("EXTRAS: scans");
    vector<int> inclusive(4), exclusive(4);

    inclusive_scan(nums.begin(), nums.end(), inclusive.begin());
    exclusive_scan(nums.begin(), nums.end(), exclusive.begin(), 0);
    printVec(inclusive);
    printVec(exclusive);

    // 37) set membership / includes
    section("EXTRAS: includes");
    vector<int> big = {1, 2, 2, 3, 4, 5};
    vector<int> small = {2, 3, 5};
    cout << includes(big.begin(), big.end(),
                     small.begin(), small.end()) << '\n';

    // ============================================================
    // C++20 RANGES QUICK REFERENCE
    // ============================================================
    section("EXTRAS: C++20 ranges");

    vector<int> rv = {5, 1, 4, 2, 3};

    ranges::sort(rv);
    cout << "ranges::sort: ";
    printVec(rv);

    auto rIt = ranges::find(rv, 4);
    if (rIt != rv.end()) cout << "ranges::find: " << *rIt << '\n';

    auto lb2 = ranges::lower_bound(rv, 3);
    cout << "ranges::lower_bound index = "
         << distance(rv.begin(), lb2) << '\n';

    cout << "\nAll C++ algorithm examples completed.\n";
    return 0;
}
