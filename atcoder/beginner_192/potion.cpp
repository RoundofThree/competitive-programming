// https://atcoder.jp/contests/abc192/tasks/abc192_f
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// for len=ings.size() to len=1 
// 
ll solve(ll target, vector<int> ings) {
    // TODO
    return target;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc=1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int N;
        ll X;
        cin >> N;
        cin >> X;
        vector<int> ings;
        for (int i=0; i<N; ++i) cin >> ings[i];

        cout << solve(X, ings) << endl;
    }
}