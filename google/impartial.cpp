/* Problem
Aroha is a big animal lover, so she spends some free time taking care of many of her loved ones' pets. She likes to offer them treats, but wants to do that in an impartial way.

Aroha decided that it was logical for pets of the same size to get the same amount of treats and for larger pets to get strictly more treats than smaller ones. For example, if she has 4 pets with her of sizes 10,20,10, and 25, she could offer 2 treats to each pet of size 10, 3 treats to the pet of size 20, and 5 treats to the pet of size 25. This requires her to buy a total of 2+3+2+5=12 treats. However, she can offer treats to all 4 pets and comply with her own rules with a total of just 7 treats by offering 1 each to the pets of size 10, 2 to the pet of size 20, and 3 to the pet of size 25.

Help Aroha plan her next pet day. Given the sizes of all pets that will accompany her, compute the minimum number of treats she needs to buy to be able to offer at least one treat to all pets while complying with her impartiality rules.
*/ 

/* Input 
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of two lines. The first line of a test case contains a single integer N, the number of pets in Aroha's next pet day. The second line of a test case contains N integers S1,S2,…,SN, representing the sizes of each pet.
*/

/* Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of treats she needs to buy to be able to offer at least one treat to all pets while complying with her impartiality rules.
*/

/* Testcase
Input:
3
4
10 20 10 25
5
7 7 7 7 7
2
100 1

Output:
Case #1: 7
Case #2: 5
Case #3: 3

*/

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
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

int solve(vector<int>& pets) {
    map<int,int> mp;
    for (int e : pets) {
        mp[e]++;
    }
    int ret = 0;
    int curr = 1;
    for (auto& p : mp) {
        ret += curr * p.second;
        ++curr;
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
        vector<int> pets(N);
        for (int i=0; i<N; ++i) cin >> pets[i];
        cout << "Case #" << t << ": " << solve(pets) << endl;
    }
}