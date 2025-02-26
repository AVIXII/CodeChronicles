#include <iostream>
#include <queue>
using namespace std;

struct createMin
{
    bool operator()(int &a, int &b)
    {
        return a > b; // a > b has to be checked because "createMin" should be equivalent in function to "greater<int>"
    }
};

int main()
{
    // Initialisation
    priority_queue<int> pq_max;                            // Max Priority Queue
    priority_queue<int, vector<int>, greater<int>> pq_min; // Min Priority Queue
    priority_queue<int, vector<int>, createMin> pq_min1;   // Min Priority Queue

    // For any other data type, replace the "int" within the angular brackets with the respective data
    // types. One common technique is to use a max priority queue with negative values for making
    // an effective min heap.

    // Considering only max priority queue hereafter

    // Insert
    pq_max.push(1); // 1
    pq_max.push(3); // 3 1
    pq_max.push(5); // 5 3 1

    // Max element
    int max = pq_max.top(); // 5

    // Size
    int len = pq_max.size(); // 3

    // Remove
    pq_max.pop(); // 3 1

    // Print all elements in a priority queue
    while (!pq_max.empty())
    {
        cout << pq_max.top() << " ";
        pq_max.pop();
    }
    cout << endl;
    return 0;
}

// For user defined classes and objects
/*
class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data < b->data;
    }
};

Node *flatten(Node *root)
{
    priority_queue<Node *, vector<Node *>, cmp> pq;
    Node *temp = root;
    while (temp)
        pq.push(temp), temp = temp->next;

    return root;
}
*/