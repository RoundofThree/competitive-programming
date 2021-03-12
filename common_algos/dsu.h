#include <vector> 

using namespace std;

// naive DSU 
// 1. Apply path compression in find(int val) to point directly to the furthest ancestor 
// 2. Union by size of tree or depth of tree to get a more balanced tree 
class DSU {
public:
    vector<int> parent; 
    vector<int> rank;  // depth 
    DSU(int MAX) : parent(MAX+1, -1), rank(MAX+1, 0) {
    }
    void make_set(int val) {
        parent[val] = val; 
        rank[val] = 0; 
    }
    // find the representative of the set which val belongs to 
    int find(int val) {
        int ret = val; 
        while (ret != parent[ret]) {
            ret = parent[ret];
        }
        // path compression 
        while (val != parent[val]) {
            int tmp = val;
            val = parent[val];
            parent[tmp] = ret; 
        }
        return ret; 
    }
    void union_sets(int a, int b) {
        int ap = find(a); 
        int bp = find(b);
        if (ap != bp) {
            if (rank[ap] > rank[bp]) {
                swap(ap, bp);
            }
            parent[ap] = bp; 
            if (rank[ap] == rank[bp]) {
                ++rank[bp];
            }
        }
    }
};

// Applications:
// 1. Connected components 
// 2. Connected components in an image 
