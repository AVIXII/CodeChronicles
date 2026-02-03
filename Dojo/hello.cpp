

/* ---------------------------------- Pragmas ---------------------------------- */
#pragma GCC optimize("O3,unroll-loops")


#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Uncomment if using ordered_set
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// --- Debugging (Terminal Only) ---
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

// --- Aliases ---




// --- Macros (Standard [a, b) half-open intervals) ---
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define ff first
#define ss second

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forg(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i >= (b); --i)

// --- Math Utils ---
template<typename T> void chmin(T& a, T b) { if (b < a) a = b; }
template<typename T> void chmax(T& a, T b) { if (b > a) a = b; }

// Use std::gcd and std::lcm (C++17) - Faster & Safer


// Optimized BinPow (Handles negative bases)
ll binpow(ll a, ll b, ll m = MOD) {
    a %= m;
     // Fix negative base
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Modular Inverse (Fermat's Little Theorem)


// Optimized Modular Arithmetic (Minimize % ops)
ll mod_add(ll a, ll b, ll m = MOD) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return (a + b) >= m ? (a + b - m) : (a + b);
}

ll mod_sub(ll a, ll b, ll m = MOD) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return (a - b) < 0 ? (a - b + m) : (a - b);
}

ll mod_mul(ll a, ll b, ll m = MOD) {
    return ((a % m) * (b % m)) % m;
}



/* ---------------------------------- Solve ---------------------------------- */

void precal() {
    // Sieve or combinatorial precalc goes here
}

void solve() {
    int n; 
    cin >> n;
    // Your solution
}

/* ---------------------------------- Main ----------------------------------- */
