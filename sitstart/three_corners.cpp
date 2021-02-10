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

int solve(int x, int y) {
    return min(20*(x-1), 5*(y-2+x));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc; 
    for (int t=0; t<tc; ++t) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        // find the x that isn't repeated twice --> a, c, e
        if (a==c) cout << e << " ";
        else if (a==e) cout << c << " ";
        else if (c==e) cout << a << " ";
        // find the y 
        if (b==d) cout << f;
        else if (b==f) cout << d;
        else if (d==f) cout << b;
        cout << "\n";
    }
    return 0;
}