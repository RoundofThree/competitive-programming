// https://codeforces.com/contest/1473/problem/C
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

vector<int> solve(int n, int k) {
    int last = 2*k-n; 
    int inversions = k-last; 
    vector<int> ret;
    for (int i=1; i<last; ++i) ret.push_back(i);
    for (int i=k; i>=last; --i) ret.push_back(i);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, k;
        cin >> n >> k;
        vector<int> ret = solve(n, k);
        for (int i : ret) cout << i << " ";
        cout << "\n";
    }
    return 0;
}