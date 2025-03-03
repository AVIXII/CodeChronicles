#include <bits/stdc++.h>
using namespace std;

int main()
{
    //			Set 			    	Unordered_set
    //	increasing order 	    	No particular ordering
    // Uses self balancing BST    	Hash Table
    // Search, Insert, Delete       Search, Insert, Delete
    //        O(log(n)) 				O(1), Worst - O(n)

    // Initialisation
    set<int> s;
    unordered_set<int> us;

    // Insert
    s.insert(2); // 2
    s.insert(2); // 2
    s.insert(2); // 2
    s.insert(3); // 2 3
    s.insert(4); // 2 3 4

    // Order of unordered_set elements is random
    us.insert(1);
    us.insert(3);
    us.insert(5);
    us.insert(3);
    us.insert(4);

    // Size
    int len_s = s.size();   // 3
    int len_us = us.size(); // 4

    // Front and Back of a set
    // Front and back of an unordered_set does not matter. Hence, there is no point in finding them
    // as they may yield wrong answers
    int front = *s.begin();
    int back = *(--s.end());
    cout << back << " " << front << endl;

    // Check if an element is present or not
    if (s.count(3) > 0 && us.count(2) > 0) // Second condition is false
        cout << "True" << endl;
    else
        cout << "False" << endl;

    // Erase an element from the set
    s.erase(2);           // Return value here is the 0 or 1 if element is not deleted or deleted respectively
    s.erase(++s.begin()); // Return value is the iterator just after the element being deleted

    s.erase(s.begin(), next(s.begin(), 2)); // Returns an iterator pointing to the element after deleting two elements
    // from the current location

    // Here, s.end() as a parameter will give undefined behaviour. Hence, always check if the element
    // is present in the set or not.

    // Clear
    s.clear();

    // Lower bound
    set<int> ts = {10, 20, 30, 40, 50};
    auto it = ts.lower_bound(30);
    if (it != ts.end())
        cout << "Lower Bound: " << *it << '\n';
    else
        cout << "Key not found.\n";

    // Upper bound
    set<int> ts = {10, 20, 30, 40, 50};
    auto it = ts.upper_bound(30);
    if (it != ts.end())
        cout << "Upper Bound: " << *it << '\n';
    else
        cout << "Key not found.\n";

    /*********************************************************************************************************************************/

    // Multisets

    // Initialisation
    multiset<int> s;

    // Insert
    s.insert(2); // 2
    s.insert(2); // 2 2
    s.insert(2); // 2 2 2
    s.insert(3); // 2 2 2 3
    s.insert(4); // 2 2 2 3 4

    // Size
    int len_s = s.size(); // 3

    // Front and Back of a set
    // Front and back of an unordered_set does not matter. Hence, there is no point in finding them
    // as they may yield wrong answers
    int front = *s.begin();  // 2
    int back = *(--s.end()); // 4
    cout << back << " " << front << endl;

    // Check if an element is present or not
    if (s.count(3) > 0)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    // Erase all elements from the set
    s.erase(2); // Erases all the elements from the multiset

    s.erase(s.begin()); // Erases the first element from the multiset

    // Here, s.end() as a parameter will give undefined behaviour. Hence, always check if the element
    // is present in the set or not.

    // Clear
    s.clear();

    // Lower and upper bound
    multiset<int> ms = {10, 20, 20, 30, 40};
    auto it = ms.upper_bound(20);
    if (it != ms.end())
        cout << "Upper Bound: " << *it << '\n';
    else
        cout << "Key not found.\n";

    // Pure Set Operations

    set<int> a, b, c;
    for (int i = 1; i <= 5; i++)
        a.insert(i);

    for (int i = 3; i <= 7; i++)
        b.insert(i);

    // Intersection AnB
    auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin())); // it is equivalent to  c.end() after resizing the vector

    // Union AuB
    auto it = set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));

    // Difference A-B
    auto it = set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));

    // Symmetric difference (A-B)U(B-A)
    auto it = set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));

    for (auto el : c)
        cout << el << " ";
    cout << endl;

    return 0;
}