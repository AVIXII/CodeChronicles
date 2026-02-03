/* ---------------------------------- Header ----------------------------------- */
//                                     oo0oo
//                                   88" . "88
//                                   (| -_- |)
//                                   0\  =  /0
//                                 ___/`---'\___
//                               .' \|      |// '.
//                              / \|||   :  |||// \
//                             / _||||| -:- ||||-  \
//                            |   | \    -  /// |   \
//                           | \_|   ''\---/''  |_/  |
//                           \  .-\__   '-'  ___/-. /
//                         ___'. .'   /--.--\  `. .'___
//                      ."" '<   `.___\_---_/___.' >' "".
//                     | | :  `-  \`.;`\ _ /`;.`/ - ` : | |
//                     \  \ `_.    \_ __\ /__ _/   .-` /  /
//                 =====`-.____`.___  \_____/___.-`___.-'=====
//                                    `=---='
//                                /\ \/ I >< I I


/* ---------------------------------- Debug ------------------------------------ */
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

/* --------------------------------- Pragmas ----------------------------------- */
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/* --------------------------------- Includes ---------------------------------- */
#include <bits/stdc++.h>

/* ----------------------------------- PBDS ------------------------------------ */
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> 
// using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* -------------------------------- Namespaces --------------------------------- */
using namespace std;
using namespace chrono;

/* ----------------------------------- Types ----------------------------------- */
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

/* --------------------------------- Constants --------------------------------- */
constexpr int MOD = 1e9 + 7; // or 998244353;
constexpr int INF_INT = 1e9 + 5;
constexpr ll INF = 1e18;
constexpr ld EPS = 1e-9;
constexpr ld PI = 3.14159265358979323846;

// Directions: +1 for Octa, +2 for Quadra
const int rotx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int roty[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

/* ---------------------------------- Defines ---------------------------------- */
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define ff first
#define ss second
#define fo find_by_order
#define ok order_of_key
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)(x.size())
#define endl '\n'
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forg(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forr(i, a, b) for (int i = (a); i >= (b); --i)
#define each(el, v) for (auto &el : v)

/* ---------------------------------- Utility ---------------------------------- */
string to_upper(string a) { for (int i = 0; i < sz(a); ++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0; i < sz(a); ++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

mt19937 rng(steady_clock::now().time_since_epoch().count()); 
ll random(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

template<typename T> void chmin(T& a, T b) { if (b < a) a = b; }
template<typename T> void chmax(T& a, T b) { if (b > a) a = b; }

/* ------------------------------ Modular Arith -------------------------------- */
ll gcd(ll a, ll b) { return std::gcd(a, b); }
ll lcm(ll a, ll b) { return std::lcm(a, b); }
ll binpow(ll a, ll b, ll m = MOD) { a %= m; if (a < 0) a += m; ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res; }
tuple<ll, ll, ll> extendedGCD(ll a, ll b) { if (b == 0) return {a, 1, 0}; auto [g, x1, y1] = extendedGCD(b, a % b); return {g, y1, x1 - y1 * (a / b)}; }
ll mod_inv(ll a, ll m = MOD) { auto [g, x, y] = extendedGCD(a, m); return (g != 1) ? -1 : (x % m + m) % m; }
ll mod_add(ll a, ll b, ll m = MOD) { a %= m; b %= m; if (a < 0) a += m; if (b < 0) b += m; return (a + b >= m) ? (a + b - m) : (a + b); }
ll mod_sub(ll a, ll b, ll m = MOD) { a %= m; b %= m; if (a < 0) a += m; if (b < 0) b += m; return (a - b < 0) ? (a - b + m) : (a - b); }
ll mod_mul(ll a, ll b, ll m = MOD) { a %= m; b %= m; return (((a * b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m = MOD) { return mod_mul(a, mod_inv(b, m), m); }
ll nCr(ll n, ll r, ll m, ll *fact, ll *ifact) { if (r < 0 || r > n) return 0; return mod_mul(mod_mul(fact[n], ifact[r], m), ifact[n - r], m); }

/* ------------------------------ Number Theory -------------------------------- */
bool prime(ll n) { if (n < 2) return 0; if (n == 2 || n == 3) return 1; if (n % 2 == 0 || n % 3 == 0) return 0; for (ll i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return 0; return 1; }
ll phi(ll n) { ll res = n; for (ll i = 2; i * i <= n; i++) { if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } } if (n > 1) res -= res / n; return res; }
vector<pll> pfactors(ll n) { vector<pll> ans; for (ll i = 2; i * i <= n; i++) { if (n % i == 0) { int c = 0; while (n % i == 0) { n /= i; c++; } ans.pb({i, c}); } } if (n > 1) ans.pb({n, 1}); return ans; }

// Sieve of Eratosthenes with SPF (Smallest Prime Factor)
const int MAXN = 1e6 + 5; int spf[MAXN];
void sieve() { iota(spf, spf + MAXN, 0); for (int i = 2; i * i < MAXN; i++) if (spf[i] == i) for (int j = i * i; j < MAXN; j += i) if (spf[j] == j) spf[j] = i; }
vector<int> get_factors_fast(int n) { vector<int> f; while (n > 1) { f.pb(spf[n]); n /= spf[n]; } return f; }

/* ---------------------------------- Solve ------------------------------------ */
void precal() {
    // sieve(); 
}

void solve() {
    int n; cin >> n;

    set<int> v; 
    forn(i, n) { int el; cin>> el; v.insert(el); }
    v.insert(sz(v));
    cout << *lower_bound(all(v), sz(v)) << endl;
}

/* ----------------------------------- Main ------------------------------------ */
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    precal();

    int t = 1;
    cin >> t;

    auto start_time = high_resolution_clock::now();

    while (t--) {
        solve();
    }

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

#ifndef ONLINE_JUDGE
    ofstream time_file("time.txt");
    time_file << "Time: " << (float)duration.count() / 1000 << "ms" << endl;
    time_file.close();
#endif

    return 0;
}