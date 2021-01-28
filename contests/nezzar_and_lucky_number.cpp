// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// runtime error on pretest 3!! TODO

bool isLucky(int n, vector<int> & dp, int d) {
    if (n >= dp.size()) return false;
    // for (int i : dp) cout << "Test: " << i << "\n";
    // cout << "Now: " << dp[7];
    if (dp[n]!=-1) {
        return dp[n]==1? true : false;
    }
    // cout << "I"; 
    int curr = n;
    while (curr) { 
        if (curr%10 == d) {
            // cout << curr << endl;
            dp[n] = 1; 
            return true; 
        } else curr /= 10;
    }
    // else look for sums
    for (int i=n-d; i>=n/2; --i) {
        int other = n-i; 
        if (isLucky(other, dp, d) && isLucky(i, dp, d)) {
            dp[n] = 1;
            return true; 
        }
    }
    dp[n] = 0;
    return false;
}

void solve(vector<int> & arr, int di) {
    // lucky numbers are d, d+10*n>0, d*10+ 
    vector<int> dp(*max_element(arr.begin(), arr.end())+1, -1);   // or max element 
    
    for (int i : arr) {
        // cout << "II"; 
        // for (int i : dp) cout << "Test: " << i << "\n";
        if (isLucky(i, dp, di)) cout << "YES" << endl;
        else cout << "NO" << endl; 
    } 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int q, d;
        cin >> q >> d;
        vector<int> arr(q);
        for (int i=0; i<q; ++i) cin >> arr[i];
        solve(arr, d);
    }
    return 0;
}

/*
YES
NO
NO // wrong for 27 (d=7)????
YES
YES
NO
YES
YES
YES
YES
YES
YES
NO
*/