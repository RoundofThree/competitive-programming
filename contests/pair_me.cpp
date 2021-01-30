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

bool solve(vector<int> & arr) {
    sort(arr.begin(), arr.end());
    return arr[2] == arr[0]+arr[1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        vector<int> arr(3);
        for (int i=0; i<3; ++i) {
            cin >> arr[i];
        }
        if (solve(arr)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } 
}