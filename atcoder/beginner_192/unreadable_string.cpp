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

bool solve(string s) {
    for (int i=0; i<s.size(); i+=2) {
        if (s[i] > 'Z') {
            if (i+1 == s.size()) continue;
            if (s[i+1] <= 'Z') continue;
        }
        return false;
    }
    return true; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        string s;
        cin >> s;
        if (solve(s)) cout << "Yes";
        else cout << "No"; 
    }
}