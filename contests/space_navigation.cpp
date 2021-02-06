// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// U, D, R, L
bool solve(string s, int x, int y) {
    unordered_map<char, int> freq;
    int fx = 0, fy = 0;
    for (char c : s) {
        freq[c]++; 
        if (c == 'U') fy++;
        else if (c == 'D') fy--;
        else if (c == 'R') fx++;
        else if (c == 'L') fx--;
    }
    if (fx == x && fy == y) return true; 
    if (x>0 && freq['R']<x) return false;
    if (x<0 && freq['L']<-x) return false;
    if (y>0 && freq['U']<y) return false;
    if (y<0 && freq['D']<-y) return false;
 
    // else check the diff in x
    /*
    int diffX = x-fx; // 3-5=-2 means need two L (-1)
    int diffY = y-fy; 
    if (diffX==0 || diffX>0 && freq['R']>=diffX || diffX<0 && freq['L']>=-diffX) {
        if (diffY==0 || diffY>0 && freq['U']>=diffY || diffY<0 && freq['D']>=-diffY) return true; 
    }
    */
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int x, y;
        cin >> x >> y; 
        string s; 
        cin >> s; 
        if (solve(s, x, y)) cout << "YES" << "\n";
        else cout << "NO" << "\n"; 
    }
}