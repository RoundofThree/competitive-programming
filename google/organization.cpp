/*
After Apricot Rules LLC went through a reorganization, a new large team was formed containing M managers and N non-managers. Since many people within the team do not know each other, a number of introduction sessions are to be scheduled. We know exactly which pairs of members already know each other.

The introduction sessions are organized into time slots that take 1 minute. The first time slot starts at 8:00 AM and ends at 8:01 AM. The i-th time slot starts i−1 minutes after 8:00 AM and ends i minutes after 8:00 AM. During each time slot, there can be one or more introduction sessions. A team member can be assigned to at most one introduction session per time slot. Each introduction session must have exactly three members: an assigned manager a who must be a manager and two others b and c who can be managers or non-managers. The assigned manager a must already know b and c for the session to be scheduled. After the introduction session, b and c are considered to know each other too. If b and/or c are managers, either of them can be the assigned manager of a future introduction session that includes both.

For some pairs of people in the team, we want to know the shortest time that is needed for them to finally know each other, or whether it is impossible for that to happen through the described process. If two people know each other before any introduction sessions happen, we define that shortest time to be 0 minutes.

Even though we are interested in multiple pairs of people, we are considering the situations independently. That is, the minimum time for each pair can depend on a specific organization of the introduction that is particular to that pair only.
*/

/* Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing three integers M, N, and P: the number of managers on the new team, the number of non-managers on the new team, and the number of pairs of team members we are going to ask about, respectively. Managers are numbered from 1 through M and non-managers are numbered from M+1 through M+N. Then, M+N lines follow with M+N characters each. The j-th character on the i-th of these lines Ci,j is Y if team members i and j know each other before the introduction process starts, and N otherwise. Then, there are P more lines; the k-th of which contains a pair of integers Ak and Bk each, representing the team member numbers of the k-th pair we are interested in.
*/

/* Output 
For each test case, output one line containing Case #x: y1 y2 y3⋯yP, where x is the test case number (starting from 1) and yi is −1 if team members Ak and Bk cannot get to know each other, or the shortest amount of time (in minutes) since the process starts until they do.
*/

/* Testcase
Input:
3
2 2 3
YYYY
YYNN
YNYN
YNNY
2 3
2 4
1 4
3 2 2
YYYNN
YYNYN
YNYNY
NYNYN
NNYNY
2 5
4 5
1 1 1
YN
NY
1 2

Output:
Case #1: 1 1 0
Case #2: 2 3
Case #3: -1
*/

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ar array
#define ll long long

// return true if T& a changed 
template<class T> bool chmax(T& a, T b) {return b>a? a=b, true : false; }
template<class T> bool chmin(T& a, T b) {return b<a? a=b, true : false; }

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// bfs, starting from all managers that know a
// expand managers to pair a with anyone the manager knows
// continue with all managers that know a 
// heuristics is min distance to a or b
int solve(vector<vector<bool>> adj, int a, int b, int M) {
    --a; --b;
    if (adj[a][b]) return 0;
    int depth = 0;
    deque<int> managers;
    for (int i=0; i<M; ++i) {
        
        if (adj[a][i] || adj[b][i]) managers.push_back(i);
    }
    while (managers.size()) {
        int size = managers.size();
        for (int k=0; k<size; ++k) {
            // update adj
            int m = managers.front();
            managers.pop_front();
            if (adj[a][m]) {
                for (int i=0; i<adj[0].size(); ++i) {
                    if (adj[m][i]) {
                        if (!adj[a][i] && i<M) managers.push_back(i);
                        adj[a][i] = true;
                        adj[i][a] = true;
                    }
                }
            } else {
                for (int i=0; i<adj[0].size(); ++i) {
                    if (adj[m][i]) {
                        if (!adj[b][i] && i<M) managers.push_back(i);
                        adj[b][i] = true;
                        adj[i][b] = true;
                    }
                }
            }
            // check goal
            if (adj[a][b]) return depth;
        }
        ++depth;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int M, N, P;
        cin >> M >> N >> P;
        // adjacency matrix 
        vector<vector<bool>> adj(M+N, vector<bool>(M+N, false));
        for (int i=0; i<M+N; ++i) {
            string s;
            cin >> s;
            int j = 0;
            for (char c : s) {
                adj[i][j] = c=='Y'; 
                ++j;
            }
        }
        cout << "Case #" << t << ": ";
        // queries
        for (int i=0; i<P; ++i) {
            int a, b;
            cin >> a >> b;
            cout << solve(adj, a, b, M) << " ";
        }
        cout << endl;
    }
}