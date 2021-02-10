#include <vector>
#include <cmath>
#define ll long long 

using namespace std; 

// find all prime numbers until n => (0, n]
vector<bool> sieve(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    int root = sqrt(n);
    for (int i=2; i<=root; ++i) {
        if (isPrime[i]) {
            for (int j=i*i; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime; 
}

// find all primes in [L, R]
vector<bool> segmentedSieveNoPreGen(ll L, ll R) {
    vector<bool> isPrime(R-L+1, true); 
    ll root = sqrt(R);
    for (ll i=2; i<=root; ++i) {
        if (isPrime[i]) {
            // for (int j=min(i*i, (L+i-1)/i*i); j<=R; ++j)
        }
    }
}
