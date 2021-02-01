#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ar array
#define ll unsigned long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// test:
// 50 19
// 47 47 47 47 47 47 47 47 47 47 47 47 47 47 47 47 47 47 47 30 47 47 47 47 47 47 47 47 25 30 47 47 47 30 47 47 47 47 47 47 47 47 47 47 17 47 47 37 25 47

ll binomialCoeffUtil(int n, int k, ll** dp)
{
    // If value in lookup table then return
    if (dp[n][k] != -1) //     
        return dp[n][k];
 
    // store value in a table before return
    if (k == 0) {
        dp[n][k] = 1;
        return dp[n][k];
    }
     
    // store value in table before return
    if (k == n) {
        dp[n][k] = 1; 
        return dp[n][k];
    }
     
    // save value in lookup table before return
    dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) +
               binomialCoeffUtil(n - 1, k, dp);
    dp[n][k] %= MOD;
    return dp[n][k];
}

ll binomialCoeff(int n, int k)
{
    ll** dp; // make a temporary lookup table
    dp = new ll*[n + 1];
 
    // loop to create table dynamically
    for (int i = 0; i < (n + 1); i++) {
        dp[i] = new ll[k + 1];
    }
 
    // nested loop to initialise the table with -1
    for (int i = 0; i < (n + 1); i++) {
        for (int j = 0; j < (k + 1); j++) {
            dp[i][j] = -1;
        }
    }
 
    return binomialCoeffUtil(n, k, dp);
}

// broken
ll choose(int n, int k) {
    // n choose m 
    if (k > n) return 0;
    if (k*2 > n) k = n-k;
    if (k==0) return 1;
    ll ret = n;
    for (int i=2; i<=k; ++i) {
        ret = (ret * (ll)(n-i+1)/(ll)i)%MOD;  // wrong because division should be product with modular inverse
        cout << ret << ", ";
    }
    cout << "\n";
    return ret;
}

// a more efficient way of nCk------------------------------------------------
ll powmod(ll base, ll exp, ll mod) {
    base %= mod;
    ll ret = 1;
    while (exp > 0) {
        if (exp & 1) ret = (ret * base)%mod;
        base = (base * base)%mod;
        exp >>= 1;
    }
    return ret; 
}

// degree of mod in n! (exponent of mod in factorization of factorial)
int fact_exp(ll n, ll mod) {
    int ret = 0;
    ll curr = mod;
    while (curr <= n) {
        ret += n/curr;
        curr *= mod;
    }
    return ret;
}

// nCk 
ll fermat_binomial(ll n, ll k, ll mod) {
    if (k == 0) return 1;
    int num_degree = fact_exp(n, mod) - fact_exp(n-k, mod);
    int den_degree = fact_exp(k, mod);
    if (num_degree > den_degree) return 0;
    if (k > n) return 0;
    // compute numerator 
    ll num = 1;
    for (ll i=n; i>n-k; --i) {
        ll curr = i;
        while (curr % mod == 0) curr /= mod;
        num = (num * curr)%mod;
    }
    // compute denominator
    ll den = 1;
    for (ll i=1; i<=k; ++i) {
        ll curr = i;
        while (curr % mod == 0) curr /= mod;
        den = (den * curr) % mod;
    }
    // apply fermat little theorem for inverse multiplicative of den
    return (num * powmod(den, mod-2, mod))%mod;
}

// ways to make k-sum equal to largest k-sum 
ll solve(vector<int> arr, int k) {
    sort(arr.begin(), arr.end(), greater<int>()); // descending order
    int repeated = 1; 
    int last = arr[k-1];
    while (k-1-repeated>=0 && arr[k-1-repeated]==last) ++repeated;
    int total = repeated;
    for (int i=k; i<arr.size(); ++i) {
        if (arr[i]==last) ++total;
        else break;
    }
    // cout << total << "choose" << repeated << "\n";
    return fermat_binomial(total, repeated, 1e9+7);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, k;
        cin >> n >> k;
        vector<int> followers(n);
        for (int i=0; i<n; ++i) cin >> followers[i];
        if (n == k) {
            cout << 1 << "\n"; continue;
        }
        cout << solve(followers, k) << "\n";
    }
}