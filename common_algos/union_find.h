#include <vector>
#include <algorithm> 

using namespace std;

class UnionSet {
public: 
    vector<int> parent; 
    vector<int> rank;
    int n; 
    
    UnionSet(int nIn) : n(nIn), parent(nIn), rank(nIn, 0) {
        for (int i=0; i<n; ++i) {
            parent[i] = i; 
        }
    }
    // these methods CANNOT be accessed using 1-index 
    void Union(int xi, int xj) {
        int i = find(xi);
        int j = find(xj);
        if (i == j) return;
        --n;
        if (rank[i] < rank[j]) {
            parent[i] = j;
        } else if (rank[i] > rank[j]) {
            parent[j] = i; 
        } else {
            parent[j] = i; 
            rank[i]++; 
        }
    } 
    
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
};