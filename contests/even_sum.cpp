// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int solve(vector<int>& arr) {
    int ret = 0; 
    for (int e : arr) {
        ret += (e%2);
        ret %= 2;
    }
    return ret + 1; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; ++i) cin >> arr[i];
        cout << solve(arr) << "\n";
    }
}