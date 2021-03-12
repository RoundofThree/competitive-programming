#include <string>
#include <vector>
#include <set>

using namespace std; 
#define ll long long

ll compute_hash(const string& s) {
    const int p = 31; // lowercase: 31, uppercase+lowercase: 53
    const int m = 1e9+9; // less collision 
    ll hash = 0; 
    ll currpow = 1; 
    for (char c : s) {
        hash = (hash + (c-'a'+1)*currpow) % m; 
        currpow = (currpow * p) % m;
    }
    return hash; 
}

// collision rate is more or less 1/m, when m is prime 
// Applications:
// 1. Rabin Karp for pattern matching 
// TODO


// 2. Number of different substrings in string  
int count_unique_substrings(const string& s) {
    int n = s.size(); 
    const int p = 31; 
    const int m = 1e9+9; 
    vector<ll> power_p(n); 
    power_p[0] = 1; 
    for (int i=1; i<n; ++i) {
        power_p[i] = (power_p[i-1]*p) % m;
    }
    // vector of hashes 
    vector<ll> hash(n+1, 0); 
    for (int i=0; i<n; ++i) {
        hash[i+1] = (hash[i] + (s[i]-'a'+1)*power_p[i]) % m;
    }
    int ret = 0;
    for (int len=1; len<n; ++len) {
        set<ll> hashes; 
        for (int i=0; i<=n-len; ++i) {
            ll curr = (hash[i+len]+m-hash[i])%m; 
            curr = (curr * power_p[n-i-1])%m; 
            hashes.insert(curr); 
        }
        ret += hashes.size(); 
    }
    return ret; 
}
