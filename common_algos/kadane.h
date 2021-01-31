#include <vector>
using namespace std;

// kadane is used to calculate the maximum (contiguous) subarray sum
int kadane(vector<int>& arr) {
    int ret = 0;  
    int currmax = -1e9;
    for (int e : arr) {
        currmax = max(currmax+e, e);  // continue or break and start at e
        if (currmax > ret) ret = currmax; // necessary to update at every step cause negative numbers
    }
    return ret; 
}