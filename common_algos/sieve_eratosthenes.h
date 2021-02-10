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
        // find the first j in [L, R] which is a multiple of i
        for (ll j=max(i*i, ((L+i-1)/i)*i); j<=R; j+=i) {  // when L=17 and i=2, then j=max(4, 18)
            isPrime[j-L] = false;
        }
    }
    if (L == 1) {
        isPrime[0] = false; // 1 is not prime
    }
    return isPrime;
}

// same as above but save time by sacrificing memory 
vector<bool> segmentedSieve(ll L, ll R) {
    // generate all primes up to sqrt(R)
    ll root = sqrt(R);
    vector<bool> mark(root+1, false);
    vector<ll> primes;
    for (ll i=2; i<=root; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (ll j=i*i; j<=root; j+=i) {
                mark[j] = true;
            }
        }
    }

    vector<bool> isPrime(R-L+1, true);
    for (ll prime : primes) {
        // find first j in [L, R] such that j is a multiple of prime 
        for (ll j=max(prime*prime, ((L+prime-1)/prime)*prime); j<=R; j+=prime) {
            isPrime[j-L] = false;
        }
    }
    if (L == 1) isPrime[0] = false;
    return isPrime; 
}
