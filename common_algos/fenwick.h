#include <vector>
using namespace std;

/* pseudocode 
Range query:
def sum(int r):
    res = 0
    while (r > 0):
        res += t[r]
        r = g(r)
    return res

Point update:
def increase(int i, int delta):
    for all j with g(j) < i <= j:  // else g(j) <= i <= j for zero-based indexing 
        t[j] += delta
*/ 

// one-indexed (the fact that it's one-indexed is hidden/abstracted)
// supports point/range update, and range query
struct BIT {
    vector<int> bit1;
    vector<int> bit2; 
    int n; // size

    BIT(int n) {
        this->n = n+1;
        bit1.assign(n+1, 0); 
        bit2.assign(n+1, 0); 
    }

    BIT(vector<int> & arr) : bit1(arr.size()+1, 0), bit2(arr.size()+1, 0) {
        for (size_t i=0; i<arr.size(); ++i) {
            add(true, i, arr[i]);
        }
    }

    int LSB(int i) {
        return i & (-i);  
    }

    void add(bool b1, int i, int val) {
        i++;  // one-indexed
        if (b1) {
            while (i<n) {
                bit1[i] += val;
                i += LSB(i);
            }
        } else {
            while (i<n) {
                bit2[i] += val;
                i += LSB(i);
            }
        }
    }

    void range_add(int left, int right, int val) {
        add(true, left, val);
        add(true, right+1, -val);
        add(false, left, val*(left-1));
        add(false, right+1, -val*right);
    }

    // sum [0, i] of one branch 
    int sum(bool b1, int i) {
        ++i; // one-indexed
        int ret = 0;
        if (b1) {
            while (i>0) {
                ret += bit1[i];
                i -= LSB(i);  // find j such that g(j) < i <= j, in this case, i is assigned g(j) for next iteration 
            }
        } else {
            while (i>0) {
                ret += bit2[i];
                i -= LSB(i);  // find j such that g(j) < i <= j, in this case, i is assigned g(j) for next iteration 
            }
        }
        return ret;
    }

    // get the prefix sum of array combining two branches 
    int prefix_sum(int i) {
        return sum(true, i)*i - sum(false, i);
    }
    // range sum 
    int sum(int left, int right) {
        return prefix_sum(right) - prefix_sum(left-1);
    }
};