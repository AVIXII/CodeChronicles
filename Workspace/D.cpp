// #define LOCAL
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#include <bits/stdc++.h>
using namespace std;

/* Types */
#define ll long long
#define ld long double
#define ull unsigned long long

#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define sz(x) (int)(sx.size())
#define endl '\n'

/* For Loops */
#define forg(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define forn(i, n) for (int i = 0; i < n; i++)
#define each(el, v) for (auto &el : v)

/* Defining constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

/* Limits */
#define imax INT_MAX
#define imin INT_MIN
#define lmax LONG_MAX
#define lmin LONG_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN

int minPerm(string s, int n)
{
    if (n == 2)
        return (s[0] - '0') * 10 + (s[1] - '0');
    int ans = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        int cnt1 = 0;
        vector<int> v;
        for (int j = 0, num; j < n; j++)
        {
            if (j == i)
                num = (s[j++] - '0') * 10 + (s[j] - '0');
            else
                num = (s[j] - '0');
            if (num == 1)
                cnt1++;
            v.push_back(num);
        }
        if (cnt1 == v.size())
        {
            ans = min(ans, 1);
            continue;
        }

        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 0)
                return 0;
            else if (v[i] != 1)
                sum += v[i];
        }
        ans = min(ans, sum);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    char op;
    cout << minPerm(s, n) << endl;
}

void precal()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

//                          oo0oo
//                        88" . "88
//                        (| -_- |)
//                        0\  =  /0
//                      ___/`---'\___
//                    .' \|      |// '.
//                   / \|||   :  |||// \
//                  / _||||| -:- ||||-  \
//                 |   | \    -  /// |   \
//                | \_|   ''\---/''  |_/  |
//                \  .-\__   '-'  ___/-. /
//              ___'. .'   /--.--\  `. .'___
//           ."" '<   `.___\_---_/___.' >' "".
//          | | :  `-  \`.;`\ _ /`;.`/ - ` : | |
//          \  \ `_.    \_ __\ /__ _/   .-` /  /
//      =====`-.____`.___  \_____/___.-`___.-'=====
//                         `=---='                    ~