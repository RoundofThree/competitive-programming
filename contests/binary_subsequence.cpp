// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int solve(string & str, int n) {
    string target = str; 
    sort(target.begin(), target.end());  // 000...111
    if (target == str) return 0;
    // compute cumulative 0's from left to right, cumulative 1's from right to left 
    int zeros[n];
    int ones[n];
    if (str[0]=='0') zeros[0] = 1;
    else zeros[0] = 0;
    for (int i=1; i<n; ++i) {
        zeros[i] = zeros[i-1];
        if (str[i]=='0') ++zeros[i];
    }
    if (str[n-1]=='1') ones[n-1] = 1;
    else ones[n-1] = 0;
    for (int i=n-2; i>=0; --i) {
        ones[i] = ones[i+1];
        if (str[i]=='1') ++ones[i];
    }
    int ret = 0; 
    for (int i=0; i<n; ++i) {
        ret = max(ret, zeros[i] + ones[i]);
    }
    return n-ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n; 
        cin >> n;
        string str; 
        cin >> str; 
        cout << solve(str, n) << "\n";
    }
}