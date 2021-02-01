// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// runtime error for some unknown reason????????

struct BIT {  // point add and range query 
    unordered_map<int, vector<ll>> bits;   // num => time => freq
    int n; // size

    BIT(int n) {
        this->n = n+1;
    }

    int LSB(int i) {
        return i & (-i);  
    }

    void add(int i, int val, int num) {  // i is time 
        i++;  // one-indexed
        if (bits.count(num) == 0) {
            bits[num].resize(n);
        } 
        vector<ll>& bit = bits[num];
        while (i<n) {
            bit[i] += val;
            i += LSB(i);
        }
    }

    // sum [0, i] of one branch 
    int sum(int i, int num) {  // i is time 
        ++i; // one-indexed
        int ret = 0;
        if (bits.count(num) == 0) return 0;
        vector<ll>& bit = bits[num];
        while (i>0) {
            ret += bit[i];
            i -= LSB(i);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc = 0;
    cin >> tc;
    int maxtime = 0;
    vector<vector<int>> ops;
    for (int i = 1; i <= tc; i++) {
        int q, t, n; 
        cin >> q >> t >> n; 
        maxtime = max(maxtime, t); 
        ops.emplace_back(vector<int>{q, t, n}); 
    }
    BIT tree(maxtime+1);
    for (auto x : ops) {
        int q = x[0], t = x[1], n = x[2];
        if (q == 1) {
            // add n to multiset
            tree.add(t, 1, n);
        } else if (q == 2) {
            // remove q from multiset 
            tree.add(t, -1, n);
        } else {
            // count multiset
            cout << tree.sum(t, n) << "\n";
        }
    }
}