// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define rep(i, a, b) for (int i=a; i<b; ++i)
#define Rep(i, a, b) for (int i=a; i>b; --i)
#define foreach(e, x) for (__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)
#define mid ((l + r) >> 1)
#define lson (k<<1)
#define rson (k<<1|1)
#define MEM(a,x) memset(a, x, sizeof a)
#define pii pair<int, int>
#define ar array
#define ll long long
#define pb push_back
#define mp make_pair
#define pi acos(-1)

// return true if T& a changed 
template<class T> bool chmax(T& a, T b) {return b>a? a=b, true : false; }
template<class T> bool chmin(T& a, T b) {return b<a? a=b, true : false; }

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}