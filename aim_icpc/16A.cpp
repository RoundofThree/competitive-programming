#include <iostream>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// help lost robot 
void solve(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        if (y1 > y2) cout << "down" << endl;
        else cout << "up" << endl;
    } else if (y1 == y2) {
        if (x1 > x2) cout << "left" << endl;
        else cout << "right" << endl;
    } else cout << "sad" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        solve(x1, y1, x2, y2);
    }
    return 0;
}