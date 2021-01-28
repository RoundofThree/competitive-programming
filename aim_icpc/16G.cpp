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

string diff(vector<int> & arr) {
    string ret = "";
    for (int i=0; i<arr.size(); ++i) {
        ret += (arr[(i+1)%arr.size()]-arr[i]);
    }
    return ret;
}

int countFreq(string &pat, string &txt) { 
    int M = pat.length(); 
    int N = txt.length(); 
    int res = 0; 
    
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) 
    {  
        /* For current index i, check for  
           pattern match */
        int j; 
        for (j = 0; j < M; j++) 
            if (txt[i+j] != pat[j]) 
                break; 
   
        // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
        if (j == M)   
        { 
           res++; 
           j = 0; 
        } 
    } 
    return res; 
} 

// paralympics robots 
void solve(vector<int> & bats, vector<int> & robs) {
    // compute difference arrays 
    vector<int> bats1;
    for (int i=0; i<bats.size(); ++i) {
        if (bats[i] == 1) bats1.push_back(i); 
    }
    string diff1 = diff(bats1); 
    string diff2 = diff(robs);
    int bs = bats1.size(), rs = robs.size(); 
    if (bs > rs) {
        cout << 0 << endl; 
        return; 
    }
    diff2 = diff2 + diff2; 
    cout << countFreq(diff1, diff2) << endl; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int n, m;
        cin >> n >> m;
        vector<int> bats(n);
        vector<int> robs(m);
        for (int i=0; i<n; ++i) cin >> bats[i];
        for (int i=0; i<m; ++i) cin >> robs[i];
        solve(bats, robs);
    }
    return 0;
}