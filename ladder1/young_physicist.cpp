#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;



void solve() {
    int n; cin >> n;
    int xt = 0, yt = 0, zt = 0; 
    for (int i=0; i<n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        xt += x; yt += y; zt += z;
    }
    if (xt == 0 && yt == 0 && zt == 0) cout << "YES";
    else cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}

// YES input 
//3
//3 -1 7
//-5 2 -4
//2 -1 -3