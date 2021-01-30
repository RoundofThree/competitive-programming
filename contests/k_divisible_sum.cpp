// https://codeforces.com/contest/1476/problem/A
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

// max element of array of n elements with sum divisible by k 
int solve(int n, int k) {
    // even array of sum n*k => all n/k except first n%k elements with 1 more 
    // n/k(+1) % k is result 
    if (n%k == 0) {
        return 1;
    }
    if (k>n) {
        if (k%n ==0) return k/n;
        else return (k/n)+1;
    } else if (k<n) {
        int curr = k;
        while (curr < n) curr += k;
        if (curr%n == 0) return curr/n;
        else return (curr/n)+1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}