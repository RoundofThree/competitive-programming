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
vector<vector<int>> matrix_mult(vector<vector<int>>& a, vector<vector<int>>& b) {
    if (a[0].size() != b.size()) return {};  // error
    vector<vector<int>> ret(a.size(), vector<int>(b[0].size()));
    for (int i=0; i<a.size(); ++i) {
        for (int j=0; j<b[0].size(); ++j) {
            int tmp = 0;
            for (int k=0; k<a[0].size(); ++k) {
                tmp += a[i][k] + b[k][j];
            }
            ret[i][j] = tmp;
        }
    }
    return ret;
}

// matrix should be a square matrix
vector<vector<int>> matrix_exp(vector<vector<int>>& matrix, int exp) {
    if (matrix[0].size() != matrix.size()) return {}; // error
    vector<vector<int>> ret(matrix.size(), vector<int>(matrix[0].size()));
    // fill identity matrix 
    int n = matrix.size();
    for (int i=0; i<n; ++i) {
        ret[i][i] = 1;
    }
    // iterative approach
    while (exp > 0) {
        if (exp & 1) {
            ret = matrix_mult(ret, matrix);
        }
        matrix = matrix_mult(matrix, matrix);
        exp >>= 1;
    }
    return ret;
}

// Applications:
// 1. Fibonacci number at i through transformation (matrix)
// [A, B] x [0, 1; 1, 1] = [B A+B]
// Fibonacci numbers are 0-indexed, to get F2 we have to apply 1 time the transformation
int fastfib(int n) {
    vector<vector<int>> transform{{0,1}, {1,1}};
    vector<vector<int>> ret{{1,1}};
    transform = matrix_exp(transform, n-1);
    ret = matrix_mult(ret, transform);
    return ret[0][1];
}

// 2. Big number addition (with modulo)


// 3. Apply a permutation k times

// 4. Apply geometric transformations to a set of points
// Shift operation, scaling and rotation 

// 5. Number of paths of length k in a graph
ll pathsLenK(vector<vector<int>>& graph, int k, int i, int j) {
    vector<vector<int>> tmp = matrix_exp(graph, k);
    return tmp[i][j];
}