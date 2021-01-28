#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;



void solve() {
    // find the row and col of 1 
    int n = 0;
    while (n < 25) {
        int tmp; 
        cin >> tmp; 
        if (tmp == 1) break;
        ++n;
    }
    int row = (n/5)+1;
    int col = n-5*(row-1)+1; // n=6, (2, 2)
    cout << abs(3-row)+abs(3-col);
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

//0 0 0 0 0
//0 0 0 0 0
//0 1 0 0 0
//0 0 0 0 0
//0 0 0 0 0