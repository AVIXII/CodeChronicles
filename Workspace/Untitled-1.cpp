#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll exp(ll a, ll b, ll mod)
{
    a %= mod;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void extendedGCDHelper(ll a, ll b, vector<ll> &arr)
{
    if (!b)
    {
        arr[0] = a;
        arr[1] = 1;
        arr[2] = 0;
        return;
    }
    extendedGCDHelper(b, a % b, arr);
    arr[2] = arr[1] - (a / b) * (arr[1] = arr[2]);
}

vector<ll> extendedGCD(ll a, ll b)
{
    vector<ll> arr(3);
    extendedGCDHelper(a, b, arr);
    return arr;
} // returns (g, a, b)

ll minv(ll a, ll b, bool isPrime = false)
{
    if (isPrime)
        return exp(a, b - 2, b);
    vector<ll> ans = extendedGCD(a, b);
    assert(ans[0] == 1);
    return (ans[1] % b + b) % b;
}

int main()
{

    return 0;
}
