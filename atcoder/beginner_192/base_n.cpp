// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

ll mystoll(string s, int base, ll limit) {
    ll ret = 0;
    ll mul = pow(base, s.size()-1);
    for (int i=0; i<s.size(); ++i) {
        if (ret>limit) return -1; 
        if (mul > limit) return -1;
        ret += (s[i]-'0')*mul;
        if (ret < 0) return -1;
        mul /= base;
    }
    return ret; 
}

// TLE: consider using binary search for case x.size()==3;
// consider cases x.size() == 1 and == 2 
// see: https://atcoder.jp/contests/abc192/submissions/20358286 
int solve(string x, ll m) {
    // find the max element of x 
    int g = *max_element(x.begin(), x.end()) - '0' + 1;
    // from g until it surpasses m
    // cout << g << endl;
    // cout << "Str:" << x << endl;
    ll curr = 0; 
    int ret = -1;
    do {
        ++ret;
        // std::string::size_type sz = 0;
        curr = mystoll(x, g, m);
        // cout << curr << endl;
        if (curr == -1) break; 
        ++g;
    } while (m >= curr);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        ll m;
        string x;
        cin >> x; 
        cin >> m;
        cout << solve(x, m);
    }
}