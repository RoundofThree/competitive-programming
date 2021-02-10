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


// x choose y such that distance is same 
ll solve(int x, int y) {
    ll ret = 0;
    int space = 0; 
    // while space*(y-1) + y <= x
    while (space*(y-1)+y <= x) {
        int occ = space*(y-1)+y; 
        ret += (x-occ+1);
        ++space;
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc = 1;
    for (int t=0; t<tc; ++t) {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    return 0;
}