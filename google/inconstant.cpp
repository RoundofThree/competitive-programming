/* Problem
We want to build a string with English alphabet uppercase letters in sorted order. However, we want the order to be sometimes strictly increasing and sometimes strictly decreasing.

The first letter of the string must be A. After that, the string must contain one or more blocks of letters. The i-th block must contain exactly Li letters. Each letter in the i-th block must be later in the alphabet than its preceding letter in the string if i is odd and earlier in the alphabet than its preceding letter if i is even. Notice that for the first letter of a block, its preceding letter exists, even though it is not in the block. Strings that follow all of these rules are called valid. There can be multiple valid strings, and we want to find the alphabetically first one.

For example, if there are 2 blocks of sizes L1=2 and L2=3, the string must have exactly 1+L1+L2=1+2+3=6 letters (the 1 is for the initial A). The strings XYZYBA, AZYCBA and AYZYBB are not valid for this case because they violate the required starting letter condition, and the ordering conditions in the first and second block, respectively. The string AYZYBA is valid. The string ABDCBA is also valid and, moreover, it is the alphabetically first valid string.

Given the sizes of the blocks, output the valid string that comes first in alphabetical order in the list of all valid strings. It can be shown that, for all inputs within the given limits, at least one valid string exists.
*/

/* Input 
The first line of the input gives the number of test cases, T. T test cases follow. Each test case is described with two lines. The first line of a test case contains a single integer N, the number of blocks. The second line contains N integers L1,L2,…,LN, the number of letters each block must have, in order.
*/

/* Output 
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the valid string that comes first in alphabetical order. It is guaranteed that at least one valid string exists.
*/

/* Testcase
Input:
3
2
2 3
2
5 1
1
2

Output:
Case #1: ABDCBA
Case #2: ABCDEFA
Case #3: ABC
*/


// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

// if i is odd, decreasing 
// if i is even, increasing
string solve(vector<int>& blocks) {
    string ret = "A";
    vector<int> tmp;
    int curr = 0;
    for (int i=0; i<blocks.size(); ++i) {
        int b = blocks[i];
        if (i % 2 == 0) {  // increasing
            // choose the smallest one greater than curr
            for (int j=0; j<b-1; ++j) {
                ++curr;
                tmp.push_back(curr);
            }
            // the last one must ensure there are enough for 
            // next block 
            if (i != blocks.size()-1) {
                curr = max(curr+1, blocks[i+1]);
            } else ++curr;
            tmp.push_back(curr);
        } else {  // decreasing
            // choose the smallest one smaller than previous
            // and enough space 
            curr = b-1; // just enough space
            tmp.push_back(curr);
            for (int j=0; j<b-1; ++j) {
                --curr;
                tmp.push_back(curr);
            }
        }
    }
    // for (int e : tmp) cout << e << ", ";
    // cout << endl;
    for (int e : tmp) {
        ret += 'A'+e;
    }
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
        int N;
        cin >> N;
        vector<int> blocks(N);
        for (int i=0; i<N; ++i) cin >> blocks[i];
        cout << "Case #" << t << ": " << solve(blocks) << endl;
    }
}