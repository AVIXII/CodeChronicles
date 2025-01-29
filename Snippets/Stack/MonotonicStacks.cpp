#include <bits/stdc++.h>
using namespace std;

void pse(vector<int> &arr)
{
    stack<int> stk;
    stk.push(-1);

    for (int i = 0; i < arr.size(); i++)
    {
        while (stk.size() > 1 && arr[stk.top()] >= arr[i])
            stk.pop();

        // Do something
        stk.push(i);
    }
}

void pge(vector<int> &arr)
{
    stack<int> stk;
    stk.push(-1);

    for (int i = 0; i < arr.size(); i++)
    {
        while (stk.size() > 1 && arr[stk.top()] <= arr[i])
            stk.pop();

        // Do something
        stk.push(i);
    }
}

void nse(vector<int> &arr)
{
    stack<int> stk;
    stk.push(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (stk.size() > 1 && arr[stk.top()] >= arr[i])
            stk.pop();

        // Do something
        stk.push(i);
    }
}

void nse(vector<int> &arr)
{
    stack<int> stk;
    stk.push(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (stk.size() > 1 && arr[stk.top()] <= arr[i])
            stk.pop();

        // Do something
        stk.push(i);
    }
}

int main()
{

    return 0;
}