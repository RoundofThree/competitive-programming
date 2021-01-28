// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;


// watson and digit sums 
void solve(int d) {
    int ret = d%9 + 1;
    cout << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int d;
        cin >> d;
        solve(d);
    }
    return 0;
}