#include <vector>
using namespace std;

#define ll long long 

// modular exponentiation 
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

// n = a0*mod0 + a1*mod1 + a2*mod2 + ...   => expresar n en base a mod 
vector<ll> get_base_digits(ll n, ll mod) {
    vector<ll> ret;
    while (n > 0) {
        ret.push_back(n % mod);
        n /= mod;
    }
    return ret; 
}

// divide and conquer: useful only when mod is small 
ll lucas_binomial(ll n, ll k, ll mod) {
    vector<ll> splitted_n = get_base_digits(n, mod);  
    vector<ll> splitted_k = get_base_digits(k, mod);
    ll ret = 1;
    for (int i=0; splitted_n.size(); ++i) {
        ll currk = 0;
        if (i < splitted_k.size()) currk = splitted_k[i];
        ret = (ret * fermat_binomial(splitted_n[i], currk, mod))%mod;
    }
    return ret;
}

// test: 
// (950 choose 100) mod 7
// lucas_binomial(950, 100, 7) == 2
// fermat_binomial(950, 100, 7) == 2

// Other ways:
ll binomialCoeffUtil(int n, int k, ll** dp, ll MOD) {
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
    dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp, MOD) +
               binomialCoeffUtil(n - 1, k, dp, MOD);
    dp[n][k] %= MOD;
    return dp[n][k];
}

ll binomialCoeff(int n, int k, ll MOD) {
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
    return binomialCoeffUtil(n, k, dp, MOD);
}
