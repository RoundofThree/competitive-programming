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

ll LSB(ll i) {
    return i & (-i);  
}

// check if it's a power of two 
bool solve(ll n) {
    return (n-LSB(n)) != 0; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        ll n;
        cin >> n;
        if (solve(n)) {
            cout << "YES" << "\n";
        } else cout << "NO" << "\n";
    }
}