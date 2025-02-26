#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // Initialisation
    deque<int> dq;

    // Insert
    dq.push_front(4); // 4
    dq.push_front(3); // 3 4
    dq.push_back(6);  // 3 4 6
    dq.push_back(2);  // 3 4 6 2

    // Front element
    int front = dq.front(); // 3

    // Back element
    int back = dq.back(); // 2

    // Size
    int len = dq.size(); // 4

    // Remove
    dq.pop_front(); // 4 6 2
    dq.pop_back();  // 4 6

    // Print all elements in a deque
    for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
        cout << *it << " ";
    cout << endl;

    // The deque is very helpful for printing the values from front to back or from back to front.
    // This can be achieved very easily using the same format while printing a stack or a vector using while loop.
    return 0;
}