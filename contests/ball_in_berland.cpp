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

// boys[i] = freq of boy i
// paired[boy][girl] = bool
// for each pair (a, b) => totalpairs - pairswith(a) - pairswith(b) + 1

ll solve(vector<vector<int>> & pairs, vector<int> boysfreq, vector<int> girlsfreq, int total) {
    ll ret = 0;
    for (int i=1; i<pairs.size(); ++i) {
        vector<int> & candidates = pairs[i];
        for (int b : candidates) {
            ret += (total - boysfreq[i] - girlsfreq[b]+1);
        }
    }
    return ret/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int a, b, k;
        cin >> a >> b >> k;
        vector<vector<int>> pairs(a+1, vector<int>());  // 1..a
        vector<int> boysfreq(a+1), girlsfreq(b+1);
        vector<int> boys(k, 0);
        for (int i=0; i<k; ++i) {
            cin >> boys[i];
        }
        for (int i=0; i<k; ++i) {
            int g;
            cin >> g;
            girlsfreq[g]++;
            pairs[boys[i]].push_back(g);
        }
        for (int i=1; i<pairs.size(); ++i) {
            boysfreq[i] = pairs[i].size();
        }
        cout << solve(pairs, boysfreq, girlsfreq, k) << "\n";
    }
}