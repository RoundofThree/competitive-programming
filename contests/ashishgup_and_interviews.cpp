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

string solve(vector<int>& time, int k) {
    sort(time.begin(), time.end(), greater<int>()); // descending order 
    // check number of not solved 
    int notsolved = 0;
    int n = time.size();
    // (n-1) to 0 includes (n-1+1)-0; (n-1) to floor(n/2) includes n-floor(n/2)=ceil(n/2) elements
    for (int i=n-1; i>=0; --i) {
        if (time[i]==-1) ++notsolved; 
        else break;
    }
    if (n-notsolved < n-n/2) return "Rejected";
    // whether too slow 
    if (time[0] > k) return "Too Slow";
    // whether bot 
    if (notsolved==0 && time[n-1]<=1) return "Bot";
    return "Accepted"; 
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