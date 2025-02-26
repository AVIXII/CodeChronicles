// #define LOCAL
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

//                                                         oo0oo
//                                                       88" . "88
//                                                       (| -_- |)
//                                                       0\  =  /0
//                                                     ___/`---'\___
//                                                   .' \|      |// '.
//                                                  / \|||   :  |||// \
//                                                 / _||||| -:- ||||-  \
//                                                |   | \    -  /// |   \
//                                               | \_|   ''\---/''  |_/  |
//                                               \  .-\__   '-'  ___/-. /
//                                             ___'. .'   /--.--\  `. .'___
//                                          ."" '<   `.___\_---_/___.' >' "".
//                                         | | :  `-  \`.;`\ _ /`;.`/ - ` : | |
//                                         \  \ `_.    \_ __\ /__ _/   .-` /  /
//                                     =====`-.____`.___  \_____/___.-`___.-'=====
//                                                        `=---='
//                                                    /\ \/ | >< | |

/* ------------------------------------------------------ Pragmas ------------------------------------------------------ */
#pragma GCC optimize("O3,unroll-loops")

/* ------------------------------------------------------ Includes ----------------------------------------------------- */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/* ----------------------------------------------------- Namespaces ---------------------------------------------------- */
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

/* ------------------------------------------------- Function Definitions ----------------------------------------------- */
void precal();
void solve();

/* ------------------------------------------------------- Types ------------------------------------------------------- */
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

/* ----------------------------------------------------- Custom DS ----------------------------------------------------- */
template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* ------------------------------------------------------- Defines ------------------------------------------------------ */
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define f first
#define s second
#define fo find_by_order
#define ok order_of_key
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)(x.size())
#define endl '\n'

/* ------------------------------------------------------ For Loops ---------------------------------------------------- */
#define forg(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define forn(i, n) for (int i = 0; i < n; i++)
#define each(el, v) for (auto &el : v)

/* -------------------------------------------------- Typedef Constants ------------------------------------------------ */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

/* ------------------------------------------------------ Limits ------------------------------------------------------- */
#define imax INT_MAX
#define imin INT_MIN
#define lmax LONG_MAX
#define lmin LONG_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN

/* ----------------------------------------------------- Directions ---------------------------------------------------- */
// i++ for octadirectinal, i+=2 for quadradirectional
int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

/* ------------------------------------------------------ Utility ------------------------------------------------------ */
string to_upper(string a)
{
    for (int i = 0; i < sz(a); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}

string to_lower(string a)
{
    for (int i = 0; i < sz(a); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}

void yes() { cout << "YES" << endl; }

void no() { cout << "NO" << endl; }

mt19937 rng(steady_clock::now().time_since_epoch().count());

ll random(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

/* ----------------------------------------- Exponentiation & Modulo Arithmetic ---------------------------------------- */
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

vector<ll> extendedGCD(ll a, ll b) // O(log(n))
{
    vector<ll> arr(3);
    extendedGCDHelper(a, b, arr);
    return arr;
} // returns (g, a, b)

ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}

ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

ll minv(ll a, ll b, bool b_is_prime = false) // O(log(n))
{
    // Prime
    if (b_is_prime)
        return exp(a, b - 2, b);

    // Non-prime
    vector<ll> ans = extendedGCD(a, b);
    assert(ans[0] == 1);
    return (ans[1] % b + b) % b;
}

ll mod_div(ll a, ll b, ll m, bool m_is_prime = false) // O(log(n))
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, minv(b, m, m_is_prime), m) + m) % m;
}

/* --------------------------------------------------- Number Theory --------------------------------------------------- */
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (ll i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

ll gcd(ll a, ll b)
{
    if (!a || !b)
        return a | b;
    ull shift = __builtin_ctzll(a | b);
    a >>= __builtin_ctzll(a);
    do
    {
        b >>= __builtin_ctzll(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

vector<ll> sieve(int n, vector<ll> *arr = new vector<ll>()) // O(n)
{
    (*arr).resize(n);
    iota(arr->begin(), arr->end(), 0);
    forn(i, 1)(*arr)[i] = i;
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if ((*arr)[i] == i)
        {
            vect.push_back(i);
            for (int j = i; j <= n; j += i)
                (*arr)[j] -= i / (*arr)[i];
        }
    return vect;
} // Returns primes; ETF Sieve;

vector<ll> pFactors(ll n) // O(sqrt(n))
{
    vector<ll> ans;
    ll res = n;
    if (n % 2 == 0)
    {
        res /= 2;
        while (n % 2 == 0)
        {
            ans.push_back(2);
            n /= 2;
        }
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                ans.push_back(i);
                n /= i;
            }
            res = (res / i * (i - 1));
        }
    }
    if (n > 1)
    {
        ans.push_back(n);
        res = (res / n * (n - 1));
    }
    return ans;
}

ll phin(ll n) // O(sqrt(n))
{
    ll res = n;
    if (n % 2 == 0)
    {
        res /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res = (res / i * (i - 1));
        }
    if (n > 1)
        res = (res / n * (n - 1));
    return res;
}

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return mod_mul(mod_mul(val1, val2, m), val3, m);
}

/* ------------------------------------------------------ Constants ---------------------------------------------------- */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Main Function @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precal();

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

// ######################################################## Solve ########################################################

int arr[100];

void precal() {}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (is_sorted(s.begin(), s.end()))
    {
        cout << 0 << endl;
        return;
    }

    // a - rem string, b - lex larg str
    string a, b;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1 || s[i] >= b.back())
        {
            b.push_back(s[i]);
            s[i] = '_';
        }
        else
            a.push_back(s[i]);
    }

    if (!is_sorted(a.rbegin(), a.rend()))
    {
        cout << -1 << endl;
        return;
    }

    int cnt = 0;
    for (int i = b.length() - 1; i >= 0; i--)
        if (b[i] == b.back())
            cnt++;
        else
            break;

    for (int i = 0, j = 0; i < n; i++)
        if (s[i] == '_')
            s[i] = b[j++];
    if (is_sorted(all(s)))
        cout << (b.length() - cnt) << endl;
    else
        cout << -1 << endl;
}