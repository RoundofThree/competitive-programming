// https://codeforces.com/contest/1476/problem/C
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

// debugged: use ll instead; consider a[i]>b[i] (crossed)

ll solve(vector<ll>& chains, vector<ll>& a, vector<ll>& b) {
    ll curr = abs(a[1]-b[1]);
    ll ret = 0; 
    // length is previous length+2 
    // when broken at i => a[i+1]==b[i+1] => update ret
    // last one too!!!
    for (int i=1; i<chains.size()-1; ++i) {
        // cout << curr << ", ";
        curr += 2ll;
        if (a[i+1]==b[i+1]) {
            curr += chains[i]-1ll;
            ret = max(ret, curr);
            curr = 0;
        } else {
            ret = max(ret, curr+chains[i]-1ll);
            if (a[i+1] < b[i+1]) {
                curr += (a[i+1]-1);
                curr += (chains[i]-b[i+1]);
            } else {
                curr += (b[i+1]-1);
                curr += (chains[i]-a[i+1]);
            }
            curr = max(curr, abs(a[i+1]-b[i+1]));
        }
    }
    curr += 2ll;
    curr += chains[chains.size()-1]-1ll;
    ret = max(ret, curr);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n;
        cin >> n;
        vector<ll> chains(n);
        for (int i=0; i<n; ++i) cin >> chains[i];
        vector<ll> a(n); vector<ll> b(n);
        for (int i=0; i<n; ++i) cin >> a[i];
        for (int i=0; i<n; ++i) cin >> b[i];
        cout << solve(chains, a, b) << "\n";
    }
    return 0;
}