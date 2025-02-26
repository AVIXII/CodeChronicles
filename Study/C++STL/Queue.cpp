#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Initialisation
    queue<int> q;

    // Insert
    q.push(5); // 5
    q.push(3); // 5 3
    q.push(8); // 5 3 8

    // Remove
    q.pop(); // 3 8

    // front element
    int front = q.front(); // 3

    // back element
    int back = q.back(); // 8

    // Check if empty
    bool isEmpty = q.empty();

    // Size of the queue
    int size = q.size(); // 1

    // Printing the queue
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }

    return 0;
}