#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    STACKS CHEAT SHEET — C++20
    ============================================================

    CORE / MUST KNOW
    ----------------
    Main DSA type: stack<T>

    Stack = LIFO
        Last In, First Out

    push / push_back      O(1) amortized in common back-based forms
    pop                   O(1)
    top                   O(1)
    size                  O(1)
    empty                 O(1)

    std::stack is a container adaptor.
    It does NOT provide iterators or random indexing.

    EXTRAS / REFERENCE
    ------------------
    emplace, swap, custom underlying container, vector/list/deque
    implementations, safe printing via copying, manual array/linked-
    list stacks, C++23 push_range, etc.
*/

int main() {

    // ============================================================
    // CORE — MUST KNOW
    // ============================================================

    // ------------------------------------------------------------
    // 1. INITIALISATION
    // ------------------------------------------------------------

    stack<int> s;

    // ------------------------------------------------------------
    // 2. PUSH
    // ------------------------------------------------------------

    s.push(32);
    s.push(10);
    s.push(20);

    // Stack:
    // top -> 20
    //        10
    //        32

    // ------------------------------------------------------------
    // 3. TOP
    // ------------------------------------------------------------

    if (!s.empty()) {
        int top = s.top();              // O(1)
        cout << "Top: " << top << '\n';
    }

    // IMPORTANT:
    // Calling top() on an empty stack is invalid.
    // Always check empty() first when emptiness is possible.

    // ------------------------------------------------------------
    // 4. POP
    // ------------------------------------------------------------

    if (!s.empty())
        s.pop();                        // O(1)

    // pop() removes the top element.
    // It does NOT return the removed value.

    // If you need the value:
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        cout << "Popped: " << x << '\n';
    }

    // ------------------------------------------------------------
    // 5. SIZE
    // ------------------------------------------------------------

    int size = (int)s.size();           // O(1)
    cout << "Size: " << size << '\n';

    // ------------------------------------------------------------
    // 6. EMPTY
    // ------------------------------------------------------------

    bool isEmpty = s.empty();            // O(1)
    cout << "Empty: " << boolalpha << isEmpty << '\n';

    // ------------------------------------------------------------
    // 7. COMMON STACK PATTERN
    // ------------------------------------------------------------

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';

    /*
        This prints from TOP -> BOTTOM and destroys the stack.

        TC: O(n)
        SC: O(1) auxiliary
    */

    // ------------------------------------------------------------
    // 8. REBUILD + SAFE COPY FOR PRINTING
    // ------------------------------------------------------------

    stack<int> original;

    original.push(1);
    original.push(2);
    original.push(3);
    original.push(4);

    stack<int> copy = original;          // O(n)

    while (!copy.empty()) {
        cout << copy.top() << ' ';
        copy.pop();
    }

    cout << '\n';

    /*
        original is preserved.
        TC: O(n)
        SC: O(n) because of the copied stack
    */

    // ============================================================
    // EXTRAS — REFERENCE
    // ============================================================

    // ------------------------------------------------------------
    // 9. EMPLACE
    // ------------------------------------------------------------

    stack<pair<int, string>> pairs;

    pairs.emplace(1, "one");             // Construct element in place

    if (!pairs.empty()) {
        cout << pairs.top().first
             << ' '
             << pairs.top().second << '\n';
    }

    // ------------------------------------------------------------
    // 10. SWAP
    // ------------------------------------------------------------

    stack<int> a;
    stack<int> b;

    a.push(1);
    b.push(2);

    a.swap(b);                           // O(1) for compatible underlying
                                         // containers

    // ------------------------------------------------------------
    // 11. CUSTOM UNDERLYING CONTAINER
    // ------------------------------------------------------------

    stack<int, deque<int>> dqStack;      // default-style choice

    stack<int, vector<int>> vecStack;    // vector-backed stack

    stack<int, list<int>> listStack;     // list-backed stack

    dqStack.push(1);
    vecStack.push(2);
    listStack.push(3);

    /*
        std::stack is an adaptor.

        Common underlying containers:
            deque  -> default
            vector
            list

        For normal DSA, `stack<int>` is all you need to write.
    */

    // ------------------------------------------------------------
    // 12. MANUAL ARRAY-BASED STACK
    // ------------------------------------------------------------

    class ArrayStack {
        vector<int> data;

    public:
        void push(int x) {
            data.push_back(x);
        }

        void pop() {
            if (!data.empty())
                data.pop_back();
        }

        int top() const {
            if (data.empty())
                throw out_of_range("Stack is empty");

            return data.back();
        }

        bool empty() const {
            return data.empty();
        }

        int size() const {
            return (int)data.size();
        }
    };

    ArrayStack manualStack;

    manualStack.push(10);
    manualStack.push(20);

    cout << "Manual stack top: "
         << manualStack.top() << '\n';

    /*
        push       O(1) amortized
        pop        O(1)
        top        O(1)
        size       O(1)
    */

    // ------------------------------------------------------------
    // 13. MANUAL LINKED-LIST STACK
    // ------------------------------------------------------------

    class LinkedStack {
        struct Node {
            int value;
            Node* next;

            Node(int value, Node* next = nullptr)
                : value(value), next(next) {}
        };

        Node* head = nullptr;
        int n = 0;

    public:
        ~LinkedStack() {
            while (head)
                pop();
        }

        void push(int x) {
            head = new Node(x, head);
            ++n;
        }

        void pop() {
            if (!head)
                return;

            Node* temp = head;
            head = head->next;
            delete temp;
            --n;
        }

        int top() const {
            if (!head)
                throw out_of_range("Stack is empty");

            return head->value;
        }

        bool empty() const {
            return head == nullptr;
        }

        int size() const {
            return n;
        }
    };

    LinkedStack linked;

    linked.push(100);
    linked.push(200);

    cout << "Linked stack top: "
         << linked.top() << '\n';

    /*
        push  O(1)
        pop   O(1)
        top   O(1)
        size  O(1)
        Extra storage: O(n)
    */

    // ------------------------------------------------------------
    // 14. C++23: push_range
    // ------------------------------------------------------------

    /*
        In C++23, stack has push_range().

        Example:

        vector<int> values = {1,2,3};
        stack<int> st;
        st.push_range(values);

        This is an EXTRA feature.
        For DSA revision, push() is much more important.
    */

    // ------------------------------------------------------------
    // 15. NO DIRECT ITERATION
    // ------------------------------------------------------------

    /*
        std::stack does NOT expose:
            begin()
            end()
            operator[]
            front()
            back()

        You can only work through:
            top()
            push()
            pop()
            empty()
            size()

        To inspect all elements, copy the stack and pop from the copy.
    */

    return 0;
}
