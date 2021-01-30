// https://codeforces.com/contest/1476/problem/D
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

//  todo 
int dfs(int pos, int step, vector<vector<int>> & dp, vector<int>& dir) {
    // treat dp as (dp[pos]+step)%2
    
}

// 
vector<int> solve(vector<int> & dir) {
    vector<int> ret(dir.size()); 
    vector<vector<int>> dp(dir.size(), vector<int>(2, false));   // dp[i][1] is -1 if not visited, otherwise no. of next steps  
    for (int i=0; i<ret.size(); ++i) {
        ret[i] = dfs(i, 0, dp, dir);
    }
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
        for (int i=0; i<n; ++i) {
            char c;
            cin >> c;
            vector<int> dir;
            if (c == 'L') dir[i] = 0;  // 0 for L
            else dir[i] = 1;
            vector<int> ret = solve(dir);
            for (int e : ret) cout << e << " ";
            cout << "\n";
        }
    }
    return 0;
}