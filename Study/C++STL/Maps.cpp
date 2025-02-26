#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    //			Map 			    	Unordered_map               Multimap
    //	Non-decreasing order 	    No particular ordering       Non-decreasing
    // Uses self balancing BST    	Hash Table                   Self Balancing BST
    // Search, Insert, Delete       Search, Insert, Delete      Search, Insert, Delete
    //        O(log(n)) 				O(1), Worst-O(n)            O(log(n)+k)

    // Initialisation
    map<string, int> mp;
    unordered_map<string, int> unmp;
    multimap<string, int> mmp;

    // Size
    int sz = mp.size();

    // Insert
    mp["R"] = 1;
    mp["I"] = 2;
    mp["S"] = 3;
    mp["H"] = 4;
    mp["A"] = 5;
    mp["B"] = 6;
    mp["H"] = 7;

    // Erase
    mp.erase("S");

    // The erase function returns the first iterator after the current element which is deleted. It is useful to traverse a map in which
    // changes are made simultaneously while iterating.
    // ex: mp = {(0:0), (1:1), (2, 2), (3, 3), (4, 4)}
    // While deleting the even keys of the map, set the current traversing iterator to the iterator returned by the erase function.
    // map<int, int>::iterator it = mp.begin();
    // while (it != mp.end())
    // {
    //   if (it->first % 2 == 0)
    //     it = mp.erase(it);
    //   else
    //     it++;
    // }

    // Traverse a map
    for (auto el : mp)
        cout << el.first << " " << el.second << endl;

    for (auto &[key, value] : mp)
        cout << key << "->" << value << endl;

    // Clear a map
    mp.clear();

    // Lower_bound, upper_bound, equal_range
    map<int, std::string> myMap;
    myMap[10] = "Alice";
    myMap[20] = "Bob";
    myMap[30] = "Charlie";
    map<int, string>::iterator it1 = myMap.lower_bound(15);
    map<int, string>::iterator it2 = myMap.upper_bound(15);
    pair<map<int, string>::iterator, map<int, string>::iterator> range = myMap.equal_range(20);

    // Multisets

    // Initialisation
    multimap<int, string> mmap;

    // Insert
    // Inserting elements
    mmap.insert({1, "apple"});
    mmap.insert({2, "banana"});
    mmap.insert({1, "cherry"});
    mmap.insert({3, "grapes"});
    mmap.insert({2, "kiwi"});

    // Size
    int len_s = mmap.size(); // 4

    // Front and Back of a set
    // Front and back of an unordered_set does not matter. Hence, there is no point in finding them
    // as they may yield wrong answers
    auto front = (*mmap.begin()).first;  // 3
    auto back = (*(--mmap.end())).first; // 1
    cout << back << " " << front << endl;

    // Check if an element is present or not
    if (mmap.count(3) > 0)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    // Erase all elements from the set
    mmap.erase(1); // Erases all the elements from the multiset

    mmap.erase(mmap.begin()); // Erases the first element from the multiset

    // Here, s.end() as a parameter will give undefined behaviour. Hence, always check if the element
    // is present in the set or not.

    // Clear
    mmap.clear();

    // Lower and upper bound
    auto it = mmap.upper_bound(20);
    if (it != mmap.end())
        cout << "Upper Bound: " << it->first << '\n';
    else
        cout << "Key not found.\n";

    return 0;
}
