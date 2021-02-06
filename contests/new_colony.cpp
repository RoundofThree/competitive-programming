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

int solve(vector<int> & m, int k) {
    // surely goes to incinerator
    int maxe = *max_element(m.begin(), m.end()); 
    if (maxe*(m.size()-1)<k) return -1;
    // simulate
    int ret = -1;
    for (int i=0; i<k; ++i) {
        // find inflection point (valley)
        int valley = 0;
        while (valley<m.size()-1 && m[valley]>=m[valley+1]) ++valley;
        if (valley >= m.size()-1) return -1; // will fall to incinerator 
        ret = valley+1; // one-indexed 
        m[valley]++;
    } 
    return ret; 
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
        vector<int> mountains(n);
        for (int i=0; i<n; ++i) cin >> mountains[i];
        
        cout << solve(mountains, k) << "\n";
    }
}