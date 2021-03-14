// binpow is used in operations that satisfy associativity: exponentiation of numbers, matrices and modular multiplication, and addition
#include <vector>

using namespace std;

#define ll long long

// a^b
ll binpow(ll a, ll b) {
    ll ret = 1;  
    while (b > 0) {
        if (b & 1) {
            ret = ret * a; // % m if modular mult
        }
        a = a * a; // % m if modular mult
        b >>= 1;  // floor division by 2 
    }
    return ret;
}

// matrix exponentiation
// i*k x k*j = i*j 
vector<vector<int>> matrix_mult(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> ret(a.size(), vector<int>(b[0].size()));

}

// Applications:
// 1. Fibonacci number at i through transformation (matrix)
// TBD
// [A, B] x [0, 1; 1, 1] = [B A+B]
// Fibonacci numbers are 0-indexed, to get F2 we have to apply 1 time the transformation


// 2. Big number addition
