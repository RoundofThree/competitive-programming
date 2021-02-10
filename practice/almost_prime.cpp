// #include <bits/stdc++.h>
// https://codeforces.com/contest/26/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// sieving prime divisors 
int solve(int n) {
    if (n==1) return 0;
    vector<int> dp(n+1, 0);  // prime divisor frequency
    // int root = sqrt(n);
    dp[2] = 1;
    for (int j=4; j<=n; j+=2) {
        dp[j]++;
    }
    for (int i=3; i<=n; i+=2) {
        if (dp[i]==0) { // is prime
            for (int j=i; j<=n; j+=i) {
                dp[j]++;
            }
        }
    }
    int ret = 0;
    for (int i : dp) if (i==2) ++ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    cout << solve(tc);
}