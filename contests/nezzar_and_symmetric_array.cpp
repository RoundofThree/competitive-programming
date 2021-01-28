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

// SOLVED!!

void solve(vector<int64_t> & d, int n) {
    // compute difference array 
    sort(d.begin(), d.end());   // will be a,a,b,b,c,c... 
    // cout << d.back() << "\n";
    if (d.size()==2 && d[0]>0 && d[0]%2==0 && d[0]==d[1]) {
        cout << "YES" << "\n"; return;
    } else if (d.size()==2) {
        cout << "NO" << "\n"; return;
    }

    if (d[d.size()-1] % 2 != 0) {
        cout << "NO" << "\n"; 
        return; 
    }
    // cout << "I am here";
    vector<int64_t> diff;
    int x = 1;  
    for (int i=1; i<d.size()-1; i+=2) {
        if (d[i] != d[i-1] || d[i]%2 != 0 || d[i]==d[i+1] || (d[i+1]-d[i])%(2*x)!=0) {
            cout << "NO" << "\n"; return; 
        }
        diff.push_back((d[i+1]-d[i])/(2*x)); 
        ++x;
    }
    // test 
    /*
    cout << "Diff: "; 
    for (int e : diff) cout << e << ", ";
    cout << "\n"; 
    */
    if (diff.size() != n-1) {
        cout << "NO" << "\n"; return; 
    } 
    // compute the smallest number 
    int64_t sumofall = d[0]/2; 
    // if sumofall == (smallest)*n+(diff0*(n-1)+diff1*(n-2)+...) return true
    int64_t tmp = 0;
    for (int i=0; i<diff.size(); ++i) {
        tmp += diff[i]*(n-1-i); 
        // cout << "+" << diff[i] << "*" << n-1-i << "=" << diff[i]*(n-i-1) << "\n";
    }
    // cout << "Sum: " << sumofall << ", tmp: " << tmp << " and sum-tmp=" << sumofall-tmp << "=" << sumofall-tmp << "\n";
    // cout << 2%n << endl;  
    if ((sumofall>tmp) && (sumofall-tmp) % n == 0) {
        cout << "YES" << "\n"; 
    } else cout << "NO" << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int n;
        cin >> n;
        vector<int64_t> arr(2*n);
        for (int i=0; i<arr.size(); ++i) cin >> arr[i];
        solve(arr, n);
    }
    return 0;
}