#ifndef ONLINE_JUDGE
#include "algo/debug.h"
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


/* ------------------------------------------------- Function Definitions ---------------------------------------------- */
void precal();
void solve();


/* ------------------------------------------------------- Types ------------------------------------------------------- */
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<long long, long long> pll;


/* ----------------------------------------------------- Custom DS ----------------------------------------------------- */
template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


/* ------------------------------------------------------ Defines ------------------------------------------------------ */
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
#define forn(i, n) for (int i = 0; i < n; i++)
#define forg(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define each(el, v) for (auto &el : v)


/* ------------------------------------------------------ Limits ------------------------------------------------------- */
#define imin INT_MIN
#define imax INT_MAX
#define lmin LONG_MIN
#define lmax LONG_MAX
#define llmin LLONG_MIN
#define llmax LLONG_MAX


/* ----------------------------------------------------- Directions ---------------------------------------------------- */
// i++ for octadirectinal, i+=2 for quadradirectional - Verified
int rotx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int roty[] = { 0, 1, 1, 1, 0, -1, -1, -1 };


/* ------------------------------------------------------ Utility ------------------------------------------------------ */
string to_upper(string a) { for (int i = 0; i < sz(a); ++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }  // O(n) - Verified

string to_lower(string a) { for (int i = 0; i < sz(a); ++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }  // O(n) - Verified

mt19937 rng(steady_clock::now().time_since_epoch().count());  // O(1) - Verified

ll random(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }  // O(1) - Verified


/* ----------------------------------------- Exponentiation & Modulo Arithmetic ---------------------------------------- */
bool prime(ll n) { if (n < 2) return false; if (n == 2 || n == 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }  // O(n) - Verified

ll gcd(ll a, ll b) { if (!a || !b) return a | b; a = abs(a); b = abs(b); ull shift = __builtin_ctzll(a | b); a >>= __builtin_ctzll(a); do { b >>= __builtin_ctzll(b); if (a > b) swap(a, b); b -= a; } while (b); return a << shift; }  // O(log(min(a, b))) [Much faster practically]- verified

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }  // O(log(min(a, b))) - Verified

void extendedGCDHelper(ll a, ll b, vector<ll> &arr) { if (!b) { arr[0] = a; arr[1] = 1; arr[2] = 0; return; } extendedGCDHelper(b, a % b, arr); arr[2] = arr[1] - (a / b) * (arr[1] = arr[2]); }  // O(log(min(a, b))) - Verified
vector<ll> extendedGCD(ll a, ll b) { vector<ll> arr(3); extendedGCDHelper(a, b, arr); return arr; } // O(log(min(a, b))) - returns (g, a, b) - Verified

ll exp(ll a, ll b, ll mod) { a = (a % mod + mod) % mod ; ll res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; } //  O(log b) - Verified

ll mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }  // O(1) - Verified

ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }  // O(1) - Verified

ll mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }  // O(1) - Verified

ll minv(ll a, ll b, bool b_is_prime = false) { assert(b != 1 && "Extended Euclidean Failed"); if (b_is_prime) return (gcd(a, b) == 1 ? exp(a, b - 2, b) : -1); vector<ll> ans = extendedGCD(a, b); assert(ans[0] == 1 && "Extended Euclidean Failed"); return (ans[1] % b + b) % b; }  // O(log b) - Verified

ll mod_div(ll a, ll b, ll m, bool m_is_prime = false) { a = a % m; b = b % m; return (mod_mul(a, minv(b, m, m_is_prime), m) + m) % m; }  // O(log b) - Verified


/* --------------------------------------------------- Number Theory --------------------------------------------------- */
vector<ll> sieve(ll n, vector<ll> *arr = new vector<ll>()) { (*arr).resize(n + 1); iota(all(*arr), 0); vector<ll> vect; for (int i = 2; i <= n; i++) if ((*arr)[i] == i) { vect.push_back(i); for (int j = i; j <= n; j += i) (*arr)[j] = (*arr)[j] / i * (i - 1); } return vect;} // O(n) - Returns primes; ETF Sieve; - Verified

vector<pair<ll, ll>> pfactors(ll n) { vector<pair<ll, ll>> ans; if (n % 2 == 0) { ll count = 0; while (n % 2 == 0) { n /= 2; count++; } ans.push_back({2, count}); } for (ll i = 3; i <= sqrt(n); i += 2) if (n % i == 0) { ll count = 0; while (n % i == 0) { n /= i; count++; } ans.push_back({i, count}); } if (n > 1) ans.push_back({n, 1}); return ans; }  // O(sqrt(n)) - Verified

ll phin(ll n) { ll res = n; if (n % 2 == 0) { res /= 2; while (n % 2 == 0) n /= 2; } for (ll i = 3; i <= sqrt(n); i += 2) if (n % i == 0) { while (n % i == 0) n /= i; res = (res / i * (i - 1)); } if (n > 1) res = (res / n * (n - 1)); return res; } // O(sqrt(n)) - verified

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) { ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return mod_mul(mod_mul(val1, val2, m), val3, m); }


/* ------------------------------------------------------ Constants ---------------------------------------------------- */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795


/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Main Function @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    auto start = high_resolution_clock::now();

    precal();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // IO
#ifndef ONLINE_JUDGE
    freopen("time.txt", "w", stderr);
    cerr << "Time: " << (float) duration.count() / 1000 << "ms" << endl;
#endif

    return 0;
}


// ######################################################### Solve ########################################################

void precal() {

}

void solve() {

}