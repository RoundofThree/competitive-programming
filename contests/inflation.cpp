// https://codeforces.com/contest/1476/problem/B
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

// debugged: use ll instead of int; care about ceiling and floor division 

// min sum of changes 
ll solve(vector<ll>& arr, ll k) {
    // start from bottom => last/(sum of all -last) * 100 has to be smaller than k
    // return the largest difference from ideal sumofall-last and actual one 
    vector<ll> ps(arr.size(), 0);
    for (int i=1; i<arr.size(); ++i) ps[i] = ps[i-1]+arr[i-1];
    ll ret = 0; 
    for (int i=1; i<ps.size(); ++i) {
        double curr = (arr[i]*100.0)/ps[i];
        ll tmp = 1l+(arr[i]*100-1)/k - ps[i]; 
        if (curr <= (double)k) continue;
        else ret = max(ret, tmp); 
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (int i=0; i<n; ++i) cin >> arr[i];
        cout << solve(arr, k) << "\n";
    }
    return 0;
}