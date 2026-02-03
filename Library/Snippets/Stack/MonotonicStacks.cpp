#include <bits/stdc++.h>
using namespace std;

void pse(vector<int> &arr)  // Monotonically Increasing Stack
{
    stack<int> stk;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
            stk.pop();

        // Do something
        stk.push(i);
    }
}

void pge(vector<int> &arr)  // Monotonically Decreasing Stack
{
    stack<int> stk;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])
            stk.pop();

        // Do something
        stk.push(i);
    }
}

void nse(vector<int> &arr)  // Monotonically Increasing Stack
{
    stack<int> stk;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
            stk.pop();

        // Do something
        stk.push(i);
    }
}

void nge(vector<int> &arr)  // Monotonically Decreasing Stack
{
    stack<int> stk;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])
            stk.pop();

        // Do something
        stk.push(i);
    }
}

int main()
{
    return 0;
}