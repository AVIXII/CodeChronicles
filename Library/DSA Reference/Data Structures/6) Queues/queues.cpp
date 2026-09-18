#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    QUEUES CHEAT SHEET — C++20
    ============================================================

    CORE / MUST KNOW
    ----------------

    FIFO QUEUE:
        std::queue
        First In, First Out

        push / pop / front / back / size / empty
        all O(1) for the default deque-backed queue

    DEQUE:
        std::deque
        Double-ended queue

        push/pop at both ends: O(1)
        random access: O(1)

    PRIORITY QUEUE:
        std::priority_queue
        Highest-priority element appears at top.

        top: O(1)
        push: O(log n)
        pop: O(log n)

    EXTRAS / REFERENCE
    ------------------
    custom comparators, min-heaps, custom objects/pointers,
    underlying containers, manual circular queue, heap algorithms,
    C++23 push_range, hash/heap-related details, etc.
*/

int main() {

    // ============================================================
    // CORE — FIFO QUEUE
    // ============================================================

    // ------------------------------------------------------------
    // 1. INITIALISATION
    // ------------------------------------------------------------

    queue<int> q;

    // ------------------------------------------------------------
    // 2. INSERT / ENQUEUE
    // ------------------------------------------------------------

    q.push(5);                 // 5
    q.push(3);                 // 5 3
    q.push(8);                 // 5 3 8

    // queue:
    // front -> 5 3 8 <- back

    // TC: O(1)

    // ------------------------------------------------------------
    // 3. FRONT
    // ------------------------------------------------------------

    if (!q.empty()) {
        int front = q.front();             // 5
        cout << "Front: " << front << '\n';
    }

    // ------------------------------------------------------------
    // 4. BACK
    // ------------------------------------------------------------

    if (!q.empty()) {
        int back = q.back();                // 8
        cout << "Back: " << back << '\n';
    }

    // ------------------------------------------------------------
    // 5. REMOVE / DEQUEUE
    // ------------------------------------------------------------

    if (!q.empty())
        q.pop();                            // removes 5

    // queue is now: 3 8
    // TC: O(1)

    /*
        IMPORTANT:
        queue.pop() does NOT return the removed element.

        Correct pattern:
            int x = q.front();
            q.pop();
    */

    // ------------------------------------------------------------
    // 6. SIZE / EMPTY
    // ------------------------------------------------------------

    int size = (int)q.size();              // O(1)
    bool isEmpty = q.empty();              // O(1)

    cout << "Size: " << size << '\n';
    cout << "Empty: " << boolalpha << isEmpty << '\n';

    // ------------------------------------------------------------
    // 7. PRINT / CONSUME QUEUE
    // ------------------------------------------------------------

    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';

    /*
        Prints front -> back and destroys the queue.

        TC: O(n)
        SC: O(1) auxiliary
    */

    // Rebuild for the non-destructive version:
    queue<int> original;
    original.push(10);
    original.push(20);
    original.push(30);

    queue<int> copy = original;             // O(n)

    while (!copy.empty()) {
        cout << copy.front() << ' ';
        copy.pop();
    }
    cout << '\n';

    // original remains intact.

    // ============================================================
    // CORE — DEQUE
    // ============================================================

    // ------------------------------------------------------------
    // 8. INITIALISATION
    // ------------------------------------------------------------

    deque<int> dq;

    // ------------------------------------------------------------
    // 9. PUSH FRONT / BACK
    // ------------------------------------------------------------

    dq.push_front(4);        // 4
    dq.push_front(3);        // 3 4
    dq.push_back(6);         // 3 4 6
    dq.push_back(2);         // 3 4 6 2

    // TC: O(1) at either end

    // ------------------------------------------------------------
    // 10. FRONT / BACK
    // ------------------------------------------------------------

    if (!dq.empty()) {
        cout << "Deque front: " << dq.front() << '\n';
        cout << "Deque back: " << dq.back() << '\n';
    }

    // ------------------------------------------------------------
    // 11. POP FRONT / BACK
    // ------------------------------------------------------------

    if (!dq.empty())
        dq.pop_front();      // 4 6 2

    if (!dq.empty())
        dq.pop_back();       // 4 6

    // ------------------------------------------------------------
    // 12. RANDOM ACCESS
    // ------------------------------------------------------------

    if (dq.size() >= 2) {
        cout << "dq[0]: " << dq[0] << '\n';
        cout << "dq[1]: " << dq.at(1) << '\n';
    }

    // Random access: O(1)

    // ------------------------------------------------------------
    // 13. DEQUE TRAVERSAL
    // ------------------------------------------------------------

    for (auto it = dq.begin(); it != dq.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    for (int x : dq)
        cout << x << ' ';
    cout << '\n';

    // ============================================================
    // CORE — PRIORITY QUEUE
    // ============================================================

    // ------------------------------------------------------------
    // 14. MAX PRIORITY QUEUE
    // ------------------------------------------------------------

    priority_queue<int> pq_max;

    pq_max.push(1);          // top = 1
    pq_max.push(3);          // top = 3
    pq_max.push(5);          // top = 5

    // Insert: O(log n)

    // ------------------------------------------------------------
    // 15. TOP / MAX
    // ------------------------------------------------------------

    if (!pq_max.empty()) {
        int mx = pq_max.top();               // 5
        cout << "Max priority: " << mx << '\n';
    }

    // top(): O(1)

    // ------------------------------------------------------------
    // 16. POP
    // ------------------------------------------------------------

    if (!pq_max.empty())
        pq_max.pop();                        // removes 5

    // pop(): O(log n)

    // ------------------------------------------------------------
    // 17. SIZE / EMPTY
    // ------------------------------------------------------------

    cout << "PQ size: " << pq_max.size() << '\n';
    cout << "PQ empty: " << pq_max.empty() << '\n';

    // ------------------------------------------------------------
    // 18. PRINT PRIORITY QUEUE
    // ------------------------------------------------------------

    while (!pq_max.empty()) {
        cout << pq_max.top() << ' ';
        pq_max.pop();
    }
    cout << '\n';

    /*
        Output order is priority order, not arbitrary heap-array order.
        This destroys the priority queue.
    */

    // ============================================================
    // EXTRAS — PRIORITY QUEUES / HEAPS
    // ============================================================

    // ------------------------------------------------------------
    // 19. MIN PRIORITY QUEUE
    // ------------------------------------------------------------

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq_min;

    pq_min.push(30);
    pq_min.push(10);
    pq_min.push(20);

    cout << "Min priority: "
         << pq_min.top() << '\n';             // 10

    // ------------------------------------------------------------
    // 20. CUSTOM MIN COMPARATOR
    // ------------------------------------------------------------

    struct createMin {
        bool operator()(const int& a, const int& b) const {
            return a > b;
        }
    };

    priority_queue<
        int,
        vector<int>,
        createMin
    > pq_min1;

    pq_min1.push(30);
    pq_min1.push(10);
    pq_min1.push(20);

    cout << "Custom min priority: "
         << pq_min1.top() << '\n';

    /*
        In std::priority_queue, the comparator defines which
        element has lower priority. Using `a > b` here makes the
        smallest element appear at top.
    */

    // ------------------------------------------------------------
    // 21. NEGATIVE VALUES FOR A MIN-HEAP EFFECT
    // ------------------------------------------------------------

    priority_queue<int> pq_negative;

    pq_negative.push(-10);
    pq_negative.push(-30);
    pq_negative.push(-20);

    cout << "Negative trick result: "
         << -pq_negative.top() << '\n';       // 30
    pq_negative.pop();

    /*
        Common DSA trick:
            max-heap of negatives
            behaves like a min-heap of original values

        But explicit greater<int> is clearer when possible.
    */

    // ------------------------------------------------------------
    // 22. PRIORITY QUEUE SIZE / EMPTY
    // ------------------------------------------------------------

    cout << "Min PQ size: "
         << pq_min.size() << '\n';

    cout << "Min PQ empty: "
         << pq_min.empty() << '\n';

    // ------------------------------------------------------------
    // 23. PAIR PRIORITY QUEUE
    // ------------------------------------------------------------

    priority_queue<pair<int, int>> pairMax;

    pairMax.push({10, 1});
    pairMax.push({20, 2});
    pairMax.push({20, 1});

    /*
        Default pair comparison is lexicographical:
            first descending,
            then second descending for max-heap.
    */

    cout << "Pair PQ top: "
         << pairMax.top().first << ", "
         << pairMax.top().second << '\n';

    // ------------------------------------------------------------
    // 24. CUSTOM OBJECT / NODE COMPARATOR
    // ------------------------------------------------------------

    struct Node {
        int data;

        Node(int data) : data(data) {}
    };

    struct cmp {
        bool operator()(const Node* a, const Node* b) const {
            return a->data < b->data;
        }
    };

    priority_queue<
        Node*,
        vector<Node*>,
        cmp
    > nodePQ;

    Node n1(10), n2(30), n3(20);

    nodePQ.push(&n1);
    nodePQ.push(&n2);
    nodePQ.push(&n3);

    cout << "Node PQ top: "
         << nodePQ.top()->data << '\n';

    // ------------------------------------------------------------
    // 25. UNDERLYING CONTAINERS
    // ------------------------------------------------------------

    priority_queue<int> defaultPQ; // vector by default

    priority_queue<
        int,
        deque<int>
    > dequePQ;

    /*
        For normal DSA, simply use:
            priority_queue<int>

        For min-heap:
            priority_queue<int, vector<int>, greater<int>>
    */

    // ------------------------------------------------------------
    // 26. MANUAL CIRCULAR QUEUE
    // ------------------------------------------------------------

    class CircularQueue {
        vector<int> data;
        int frontIndex = 0;
        int size = 0;

    public:
        explicit CircularQueue(int capacity)
            : data(capacity) {}

        bool empty() const {
            return size == 0;
        }

        bool full() const {
            return size == (int)data.size();
        }

        int getSize() const {
            return size;
        }

        void push(int x) {
            if (full())
                throw overflow_error("Queue is full");

            int idx = (frontIndex + size) % data.size();
            data[idx] = x;
            ++size;
        }

        int front() const {
            if (empty())
                throw out_of_range("Queue is empty");

            return data[frontIndex];
        }

        int pop() {
            if (empty())
                throw out_of_range("Queue is empty");

            int x = data[frontIndex];
            frontIndex = (frontIndex + 1) % data.size();
            --size;

            return x;
        }
    };

    CircularQueue cq(5);

    cq.push(10);
    cq.push(20);
    cq.push(30);

    cout << "Circular queue front: "
         << cq.front() << '\n';

    cout << "Circular queue pop: "
         << cq.pop() << '\n';

    /*
        push  O(1)
        pop   O(1)
        front O(1)
        size  O(1)
    */

    // ------------------------------------------------------------
    // 27. C++23 push_range
    // ------------------------------------------------------------

    /*
        C++23 adds push_range() to queue / priority_queue.

        Example:

        vector<int> values = {1, 2, 3};

        queue<int> q23;
        q23.push_range(values);

        This is an EXTRA API.
        For DSA, push() is the important operation.
    */

    return 0;
}
