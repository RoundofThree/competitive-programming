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

vector<int> solve(int x, int y, string s) {
    // find '00'
    vector<int> ret;
    int found = 0;
    while (x > 0) {
        --x;
        found = s.find("00", found);
        if (found != string::npos) {
            s[found] = '1';
            s[found+1] = '1';
            ret.push_back(found+1);
        } else return {};
        found += 2;
    }
    int curr = 0;
    while (y > 0) {
        while (curr < s.size() && s[curr]=='1') ++curr;
        if (curr == s.size()) return {};
        else {
            ret.push_back(curr+1);
            --y; ++curr;
        }
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
        int n, a, b;
        cin >> n >> a >> b;
        string s; 
        cin >> s;
        
        vector<int> ret = solve(a,b,s);
        if (ret.size() == 0) cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
            for (int e : ret) {
                if (a>0) {
                    cout << e << " " << e+1 << "\n"; --a;
                } else cout << e << "\n";
            }
        }
        
    }
    return 0;
}