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

// number of consecutive numbers 
void solve(vector<int> & arr) {
    int ret = 1, last = -1, curr = 1;
    for (int i : arr) {
        if (i == last) {
            curr++;
        } else {
            ret = max(ret, curr); 
            curr = 1; 
            last = i;
        }
    }
    ret = max(ret, curr);
    cout << ret << endl; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; ++i) cin >> arr[i];
        solve(arr);
    }
    return 0;
}