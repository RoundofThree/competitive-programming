// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int solve(int s, int k) {
    string desc, asc;
    for (int i=0; i<k; ++i) {
        desc = asc = to_string(s); 
        sort(asc.begin(), asc.end()); 
        sort(desc.begin(), desc.end(), greater<char>());
        s = stoi(desc) - stoi(asc);
        if (s == 0) return 0;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int s;
        int k;
        cin >> s; 
        cin >> k;
        cout << solve(s, k);
    }
}