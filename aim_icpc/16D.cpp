// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int M = 750000;
// good sets 
void solve(vector<int> arr) {
    vector<bool> nums(M+1, false);
    for (int i : arr) nums[i] = true;
    // vector<set<int>> divs = getDivisors(arr);
    vector<ll> dp(M+1, 0);
    ll sum = 0;
    for(int i = 1; i <= M; ++i) {
        if(nums[i]) {
            dp[i] = (dp[i] + 1) % MOD;
            sum = (sum + 1) % MOD;
            for(int j = 2 * i; j <= M; j += i) {
                if(nums[j]) {
                    dp[j] = (dp[j] + dp[i]) % MOD;
                    sum = (sum + dp[i]) % MOD;
                }
            }
        }
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; ++i) cin >> arr[i];
        solve(arr);
    }
    return 0;
}