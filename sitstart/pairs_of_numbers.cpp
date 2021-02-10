// #include <bits/stdc++.h>
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

// vector<vector<ll>> memo;

ll solve(ll x, ll y) {
    ll ret = 0;
    while (x!=1 || y!=1) {
        if (x==1 || y==1) {
            ret += max(x,y)-1;
            return ret;
        } 
        // swap 
        ll tmp = x;
        x = max(x, y);
        y = min(tmp, y);
        // if (memo[x][y]!=-1) return memo[x][y];
        if (x % y == 0) {
            return -1;
        } else {
            ll p = x/y;
            ret += p;
            x = x-p*y;
        }
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
    // memo = vector<vector<ll>>(1e18+1, vector<ll>(1e18+1, -1));
    for (int t=0; t<tc; ++t) {
        ll x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    return 0;
}