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

/*
vector<int> solve(vector<int>& arr, vector<int>& target, vector<int>& painters) {
    vector<int> avail(arr.size()+1, 0);
    for (int c : painters) {
        avail[c]++;
    }
    vector<int> ret(painters.size(), -1); 
    // in target array
    vector<vector<int>> targeted(arr.size()+1);
    for (int i=0; i<target.size(); ++i) targeted[target[i]].push_back(i); 
    // current [0..painters.size()]
    for (int i=0; i<painters.size(); ++i) {
        int p = painters[i];
        avail[p]--;
        // case 1: it's in the target array 
        if (targeted[p].size() != 0) {
            // find the first one unassigned or last assigned if no choice 
            auto & cand = targeted[p];
            int toassign = cand[0];
            int next = 1;
            while (next < cand.size() && arr[toassign]==target[toassign]) toassign = cand[next++];
            ret[i] = toassign; 
            arr[toassign] = p;
            continue; 
        }
        // case 2: not in target array, choose one whose target is available to be painted 
        for (int j=0; j<arr.size(); ++j) {
            if (avail[target[j]]>0) {
                arr[j] = p;
                ret[i] = j;
                break; 
            } 
        }
        if (ret[i]==-1) return {};
    }
    for (int& i : ret) i++;
    return ret; 
}
*/

vector<int> solve(vector<int>& arr, vector<int>& target, vector<int>& painters) {
    vector<int> ret(painters.size(), -1); 
    // in target array
    vector<vector<int>> targeted(arr.size()+1);
    for (int i=0; i<target.size(); ++i) targeted[target[i]].push_back(i); 
    // current [0..painters.size()]
    for (int i=painters.size()-1; i>=0; --i) {
        int p = painters[i]; 
        if (targeted[p].size()!=0) {
            // choose an unassigned 
            for (int j : targeted[p]) {
                if (arr[j] == target[j]) continue; 
                else {
                    ret[i] = j; 
                    arr[j] = target[j]; break; 
                }
            }
            if (ret[i]==-1) ret[i] = targeted[p][0];
        } else {  // not targeted
            if (i+1!=ret.size()) {
                ret[i] = ret[i+1];  // will be overriden 
            } else return {}; 
        }
    }
    if (arr!=target) return {};
    for (int& i : ret) i++;
    return ret; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, m; 
        cin >> n >> m; 
        vector<int> arr(n);
        for (int i=0; i<n; ++i) cin >> arr[i];
        vector<int> target(n);
        for (int i=0; i<n; ++i) cin >> target[i];
        vector<int> painters(m);
        for (int i=0; i<m; ++i) cin >> painters[i];
        vector<int> ans = solve(arr, target, painters);
        if (ans.empty()) cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
            for (int i : ans) cout << i << " "; 
            cout << "\n";
        }
    }
}