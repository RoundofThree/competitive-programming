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

// find the x in (1, mini) such that p/x == y, where y in (1, maxi)
// given x, if p/x <= y, return true, else return false 
int solve(int x, int y, int p) {
    int mini = min(x,y);
    int maxi = max(x,y);
    for (int i=min((int)sqrt(p), mini); i>0; --i) {
        if (p%i!=0) continue; 
        if (p/i <= maxi) return true; 
        else if (p/i > maxi) return false;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc; 
    for (int t=0; t<tc; ++t) {
        int n, m, p;
        cin >> n >> m >> p;
        if (solve(n,m,p)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        
    }
    return 0;
}