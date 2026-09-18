// --- Extended GCD & Inverse ---
tuple<ll, ll, ll> extendedGCD(ll a, ll b) { if (b == 0) return {a, 1, 0}; auto [g, x1, y1] = extendedGCD(b, a % b); return {g, y1, x1 - y1 * (a / b)}; }
ll mod_inv(ll a, ll m = MOD) { auto [g, x, y] = extendedGCD(a, m); return (g != 1) ? -1 : (x % m + m) % m; }
ll mod_div(ll a, ll b, ll m = MOD) { return mod_mul(a, mod_inv(b, m), m); }

// --- Combinatorics (nCr) ---
// Requires: vector<ll> fact, invFact; precomputed in main/solve
ll nCr(int n, int r, const vector<ll>& fact, const vector<ll>& invFact, int mod = MOD) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}