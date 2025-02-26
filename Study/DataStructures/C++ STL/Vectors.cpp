#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialisation
    vector<int> v;         // Empty vector
    vector<int> v1(10);    // Initializes a vector of size 10 with all values as 0 for integer and false for bool
    vector<int> v2(15, 2); // Initializes a vector of size 15 with all values as 2
    vector<int> vec = {1, 2, 3, 4, 5};

    int arr[] = {1, 2, 3};
    vector<int> vec2(arr, arr + 3); // Vector with elements from the array

    // Size
    int len = v1.size(); // 10

    // Check if empty
    cout << v.empty() << endl;

    // Nested Vectors
    vector<vector<int>> v3(10, vector<int>(10, 5)); // 10x10 matrix filled with 5s

    // Access Elements
    v2[0]; // Use .at() for bounds safety

    // Insert elements
    v.push_back(4);
    v2.insert(v2.begin() + 2, 30);
    v.insert(v.end(), 2, 6); // Insert two 6s at the end
    vector<int> additional = {7, 8, 9};
    v.insert(v.end(), additional.begin(), additional.end()); // Insert a range

    // Remove element
    v.pop_back(); // Remove the last element
    // v.erase(iterator_to_the_element)
    // v.erase(iterator_to_the_first element, iterator_to_the_next_to_last_element)
    v2.erase(v2.begin());
    v2.erase(v2.begin(), v2.begin() + 2);

    // Clear elements - Removes all the elements from vector. After this line is executed, the vector size is 0.
    v.clear();

    // Front
    int front = v2.front(); // 2

    // Back
    int back = v2.back(); // 2

    // Printing a vector
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << endl;

    // Enhanced for loop
    for (int el : v2)
        cout << el << endl;

    cout << endl;
    // Iterators of a vector
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) // 2 2 2 2 2 2 2 2 2 2 2 2 2
        cout << *it << " ";

    // Find - Search for the target in the vector find()
    auto it = find(v2.begin(), v2.end(), 12234); // v.end()

    // The following resize() method affects only the size not the capacity.
    // Resize a vector (Increase) - without a value
    v2.resize(20); // 2 2 2 2 2 2 2 2 2 2 2 2 2 0 0 0 0 0 0 0

    // Resize a vector (Increase) - with a value
    v2.resize(20, 5); // 2 2 2 2 2 2 2 2 2 2 2 2 2 5 5 5 5 5

    // Resize a vector (Decrease) - truncate the vector
    v2.resize(10); // 2 2 2 2 2 2 2 2 2 2

    // shrink_to_fit() - Reduce the capacity of the vector to its current size
    v2.shrink_to_fit(); // Capacity of v2 is now 10

    return 0;
}