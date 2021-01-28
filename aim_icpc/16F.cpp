#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// guaranteed exists 
vector<int> subset(int num, int target, int low, int high) {
    vector<int> ret(num, low);
    int sum = num * low;
    while (sum < target) {
        for (int curr=0; curr<num; ++curr) {
            ret[curr]++;
            ++sum;
            if (sum == target) break; 
        }
    }
    return ret; 
}

// bipartite graph
// n is number of nodes in each set of vertices 
// m is number of edges
// degree of any vertex is from [d, D]
void solve(int n, int m, int d, int D) {
    if (n*d > m || m > n*D) {
        cout << -1 << endl;
        return;
    }
    vector<int> deg = subset(n, m, d, D); 
    vector<int> rem = deg; 
    for (int i=0; i<n; ++i) {  
        int j = i;
        int degree = deg[i];
        while (degree > 0) {
            cout << i+1 << " " << j+1 << endl;
            --degree; 
            j = (j+1)%n; 
        }
    }
}
/*
void solve(int n, int m, int d, int D) {
    if (n*d > m || m > n*D) {
        cout << -1 << endl;
        return;
    }
    vector<vector<bool>> paired(n, vector<bool>(n, false)); 
    vector<int> deg2(n, 0); 
    int curredges = 0;  
    int otherindex = 0;
    for (int j=1; j<=n && curredges<m; ++j) {
        for (int i=0; i<d; ++i) {
            while (paired[j-1][otherindex]) otherindex = (otherindex+1)%n;
            cout << j << " " << otherindex+1 << endl;
            paired[j-1][otherindex] = true;
            otherindex = (otherindex+1)%n;
            ++curredges; 
        }
    }
    // vector<int> deg1(n, 0);
    for (int i=d; i<D && curredges < m; ++i) {  // i is iteration
        for (int j=1; j<=n && curredges<m; ++j) {   // j is current node 
            while (paired[j-1][otherindex]) otherindex = (otherindex+1)%n;
            paired[j-1][otherindex] = true;
            cout << j << " " << otherindex+1 << endl; 
            otherindex = (otherindex+1)%n;
            ++curredges;
        }
    }
}
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int n, m, d, D;
        cin >> n >> m >> d >> D;
        solve(n, m, d, D);
    }
    return 0;
}