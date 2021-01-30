// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>  // for memset 

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// I loved this problem!
string solve(vector<int>& arr, int k) {
    while (k%2==0) k/=2;
    for (int e : arr) {
        // while (e%2==0) e/=2;
        if (e%k!=0) return "NO";
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i=0; i<n; ++i) cin >> arr[i];
        cout << solve(arr, k) << "\n";
    }
}