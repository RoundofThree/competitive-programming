#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>

using namespace std;

const double EPS = 1e-9;  // epsilon
const int INF = 2;  // this just represents that the SLAE has inf solutions 

// Gauss-Jordan elimination -> O(n3)
// find the pivot row and swap --> heuristic find the largest coefficient for the target column 
// return the number of solutions
int solveSLAE(vector<vector<double>> slae, vector<double>& ans) {
    int n = slae.size();  // row
    int m = slae[0].size() - 1;  // col
    vector<int> where(m, -1);  // col -> row where the var at this col is not zero 
    for (int col=0, row=0; col<m && row<n; ++col) {
        // for each column, convert SLAE so that only one row have it not zero at row
        int pivot = row;  // use heuristics to find pivot -> largest coefficient at given col 
        for (int i=row; i<n; ++i) {
            if (abs(slae[i][col]) > abs(slae[pivot][col])) {
                pivot = i;
            }
        }
        // if the coefficient is zero, then this is an independent variable
        if (abs(slae[pivot][col]) < EPS) continue;
        // swap rows
        for (int i=col; i<=m; ++i) {
            swap(slae[pivot][i], slae[row][i]);
        }
        where[col] = row;
        // refactor all other rows
        for (int i=0; i<n; ++i) {
            if (i != row) {
                double c = slae[i][col] / slae[row][col];
                for (int j=col; j<=m; ++j) {
                    slae[i][j] -= slae[row][j] * c;
                }
            }
        }
        ++row;
    }
    // now that the slae is turned into a diagonal matrix, calculate the ans 
    ans.assign(m, 0);
    for (int i=0; i<m; ++i) {
        if (where[i] != -1) {  // not independent 
            ans[i] = slae[where[i]][m] / slae[where[i]][i];
        }
    }
    // find for inconsistencies
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j) {
            sum += ans[j] * slae[i][j];
        }
        if (abs(sum - slae[i][m]) > EPS) return 0;  // left hand not equal to right hand
    }
    // find if there are independent variables
    for (int i=0; i<m; ++i) {
        if (where[i] == -1) return INF;
    }
    return 1; 
}

// Another way to do it /2 more quickly is:
// Forward phase --> build a triangular matrix instead of a diagonal matrix
// Reverse phase --> calculate ans from bottom of triangle to up 
// TODO 

// Modular SLAE mod 2
// Use a bitset instead 
template<size_t N>
int solveSLAEmodular(vector<bitset<N>> slae, int n, int m, bitset<N>& ans) {
    vector<int> where(m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        // find a row whose column col is set 
        for (int i=row; i<n; ++i) {
            if (slae[i][col]) {
                swap(slae[i], slae[row]);
                break;
            }
        }
        // whether independent or not
        if (!slae[row][col]) continue;
        where[col] = row;
        // factor other rows by XORing 
        for (int i=0; i<n; ++i) {
            if (i != row && slae[i][col]) {
                slae[i] ^= slae[row];
            }
        }
        ++row;
    }
    // fill in ans 
    ans.reset();
    for (int i=0; i<m; ++i) {
        if (where[i] != -1) {
            ans[i] = slae[where[i]][m];
        }
    }
    // find inconsistencies 
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j) {
            sum ^= slae[i][j] * ans[j];
        }
        if (sum != slae[i][m]) return 0;
    }
    // find if inf answers
    for (int i=0; i<m; ++i) {
        if (where[i] == -1) return INF;
    }
    return 1;
}