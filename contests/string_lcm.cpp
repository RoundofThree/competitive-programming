// https://codeforces.com/contest/1473/problem/B
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

int lcm(int a, int b) {
    if (b > a) {
        int tmp = a; 
        a = b; 
        b = tmp; 
    }
    // a >= b
    int curr = a;
    while (curr % b != 0) {
        curr += a; 
    }
    return curr; 
}

string solve(string & a, string & b) {
    int n = a.size(), m = b.size(); 
    int t = lcm(n, m);
    string a1 = "";  
    string b1 = "";
    for (int i=0; i<t/n; ++i) a1 += a;
    for (int i=0; i<t/m; ++i) b1 += b; 
    if (a1 != b1) return "-1";
    else return a1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        string a, b;
        cin >> a;
        cin >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}