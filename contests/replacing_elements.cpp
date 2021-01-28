// https://codeforces.com/contest/1473/problem/A
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

bool solve(vector<int> & arr, int d) {
    if (arr.size() == 1) {
        return arr[0]<=d;
    }
    sort(arr.begin(), arr.end()); // ascending order 
    return arr[arr.size()-1]<=d || arr[0] + arr[1] <= d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int n, d;
        cin >> n >> d;
        vector<int> arr(n);
        for (int i=0; i<n; ++i) cin >> arr[i];
        if (solve(arr, d)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}