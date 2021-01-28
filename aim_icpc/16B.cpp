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


// beautiful array
void solve(vector<int> arr) {
    bool found = false;
    int negone = 0, one = 0, other = 0;
    for (int i : arr) {
        if (i == -1) ++negone;
        else if (i == 1) ++one; 
        else if (i != 0) ++other;
    }
    if (other > 1) cout << "no" << endl; 
    else if (negone > 1) {
        if (one > 0) cout << "yes" << endl;
        else cout << "no" << endl;
        return;
    } 
    else cout << "yes" << endl;
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