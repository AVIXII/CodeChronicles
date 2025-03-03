#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Initialisation
    stack<int> s;

    // Push
    s.push(32);

    // Pop
    s.pop();

    // Size
    int size = s.size();

    // Empty
    bool isEmpty = s.empty();

    // Top
    int top = s.top();

    // Printing the stack elements
    while (!s.empty())
        cout << s.top(), s.pop();
    return 0;
}