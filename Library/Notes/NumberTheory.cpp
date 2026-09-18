// Check prime
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {

	// Check if n is 1 or 0
	if (n <= 1)
		return false;

	// Check if n is 2 or 3
	if (n == 2 || n == 3)
		return true;

	// Check whether n is divisible by 2 or 3
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	// Check from 5 to square root of n
	// Iterate i by (i+6)
	for (int i = 5; i <= sqrt(n); i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
int main() {
	int n = 65;
	if (isPrime(n)) cout << "true";
	else cout << "false";
	return 0;
}

// Sieve of Eratosthenes
int n;
vector<bool> is_prime(n + 1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
	if (is_prime[i] && (long long)i * i <= n) {
		for (int j = i * i; j <= n; j += i)
			is_prime[j] = false;
	}
}

// Optimizations to Sieve
/**
 * 1) Sieving till root
 * 2) Sieving by the odd numbers only
 * Concerns- Memory optimizations --> O(n) not required
 * 			 Speed of operations --> vector<bool> takes less space(bits instead of bytes). Read and write takes more time.
 */

// Segmented Sieve
class Solution
{

public:
	vector<int> sieveOfEratosthenes(int N)
	{
		const int S = 5;

		vector<int> primes;
		vector<bool> sieve(sqrt(N) + 2, true);
		for (int i = 2; i <= sqrt(N); i++) {
			if (sieve[i]) {
				primes.push_back(i);
				for (int j = i * i; j <= sqrt(N); j += i)
					sieve[j] = 0;
			}
		}

		vector<int> ans;
		vector<bool> block(S);
		for (int k = 0; k <= N / S; k++) {
			fill(block.begin(), block.end(), 1);
			int start = k * S;
			for (auto p : primes) {
				int j = start / p * p + (start % p == 0 ? 0 : p);
				for (; j < k * S + S; j += p) {
					if (j != p) block[j - start] = 0;
				}
			}
			if (k == 0) block[0] = block[1] = false;

			for (int i = 0; i < S && start + i <= N; i++)
				if (block[i]) ans.push_back(start + i);
		}
		return ans;
	}
};

// Find Primes in range L to R
vector<char> segmentedSieve(long long L, long long R) {
	// generate all primes up to sqrt(R)
	long long lim = sqrt(R);
	vector<char> mark(lim + 1, false);
	vector<long long> primes;
	for (long long i = 2; i <= lim; ++i) {
		if (!mark[i]) {
			primes.emplace_back(i);
			for (long long j = i * i; j <= lim; j += i)
				mark[j] = true;
		}
	}

	vector<char> isPrime(R - L + 1, true);
	for (long long i : primes)
		for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
			isPrime[j - L] = false;
	if (L == 1)
		isPrime[0] = false;
	return isPrime;
}
