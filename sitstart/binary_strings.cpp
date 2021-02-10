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

// wrong answer 
ll solve(ll n, vector<ll> & sett, vector<ll>& unsett) {
    ll ret = 0;
    if (sett[n] != -1) {
        ret = (sett[n] + unsett[n])%MOD;
        return ret;
    }
    for (int i=2; i<=n; ++i) {
        if (sett[i]!=-1) continue;
        unsett[i] = (unsett[i-1] + sett[i-1])%MOD;
        // compute conflict
        ll conflict = 0;
        if (i%2==0 && i%3==0) {
            ll x = i/2, y = i/3;
            conflict = sett[x]*(i-x) + sett[y]*(i-x-1);
        } else if (i%2==0) {
            conflict = sett[i/2]*(i-i/2);
        } else if (i%3==0) {
            conflict = sett[i/3]*(i-i/3);
        }
        sett[i] = (unsett[i-1] + sett[i-1] - conflict)%MOD;
    }
    return (sett[n] + unsett[n])%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc; 
    vector<ll> sett(1e6+1, -1);
    vector<ll> unsett(1e6+1, -1);
    sett[1] = 1;
    unsett[1] = 1;
    sett[2] = 1; unsett[2] = 2;
    sett[3] = 2; unsett[3] = 3;
    for (int t=0; t<tc; ++t) {
        ll n;
        cin >> n;
        cout << solve(n, sett, unsett) << "\n";
    }
    // for (int i=0; i<7; ++i) cout << i << ": " << sett[i] << " " << unsett[i] << "\n";
    return 0;
}