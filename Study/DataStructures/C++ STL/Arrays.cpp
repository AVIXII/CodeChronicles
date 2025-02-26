/**
 * Cstyle arrays are comparitively slower than stl array, but the difference is miniscule.
 * STL array is fully compatible with all the stl functions and algorithms. It is like a fixed size vector.
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // CStyle arrays - Legacy Array
    int arr[5] = {1, 2, 3, 4, 5}; // No method of getting the size. 'n' must be specified.

    /********************************************************************************************************************************/

    // STL Arrays
    // Initialisation
    array<int, 5> arr1;                    // {GV, GV, GV, GV, GV}
    array<int, 5> arr2 = {1, 2, 3, 4, 5};  // {1, 2, 3, 4, 5}
    array<int, 10> arr3 = {1, 2, 3, 4, 5}; // {1, 2, 3, 4, 5, 0, 0, 0, 0, 0}
    array<int, 7> arr4 = {};               // {0, 0, 0, 0, 0, 0, 0}

    // Number of elements
    int len = arr1.size(); // 5

    // Access elements using index
    cout << "First element: " << arr1[0] << endl;

    // Access using at() (bounds-checked)
    cout << "Element at index 3: " << arr1.at(3) << endl;

    // Sort the array
    sort(arr1.begin(), arr1.end(), greater<int>());

    // Fill array with the value
    arr1.fill(5); // 5 5 5 5 5

    // Check if empty
    bool isEmpty = arr1.empty(); // False

    // Printing all the values of an array
    for (int i = 0; i < 10; ++i)
        cout << arr3[i] << endl; // Use .at() to provide exceptions

    // Front
    int front = arr3.front(); // 1

    // Back
    int back = arr3.back(); // 0

    // Traversing over the array
    for (array<int, 5>::iterator it = arr2.begin(); it != arr2.end(); it++)
        cout << *it << " "; // Use auto instead of the iterator template naming
    cout << endl;

    return 0;
}