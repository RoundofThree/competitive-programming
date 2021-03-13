#include <vector>
#include <algorithm>
#include <set>
using namespace std;
// using adjacency list representation 

// return {distance, parent} vector<int>
// O(n^2 + m), where n is the number of vertices and m is the number of edges
// thus this approach works better for non-sparse graphs
// Main operations:
// 1. Find the node with smallest distance[i]
// 2. Relaxation on the node
// Overall, this problem is extract a minimum and update values
pair<vector<int>, vector<int>> dijkstra(int start, vector<vector<pair<int,int>>>& graph) {
    int n = graph.size(); // number of nodes
    vector<int> distance(n, __INT_MAX__), parent(n, -1);
    vector<bool> vis(n, false);
    // start with node start
    distance[start] = 0;
    // n iterations
    for (int i=0; i<n; ++i) {
        // find the nearest not visited node 
        int nearest = -1;
        for (int j=0; j<n; ++j) {
            if (!vis[j] && (nearest==-1 || distance[j]<distance[nearest])) nearest = j;
        }
        // expand from nearest node, eg.: in the first iteration it would be the start node 
        if (distance[nearest]==__INT_MAX__) break;
        // mark as visited
        vis[nearest] = true;
        for (auto& edge : graph[nearest]) {
            int to = edge.first;
            int len = edge.second; 
            if (distance[nearest]+len < distance[to]) {
                // update the parent
                parent[to] = nearest;
                distance[to] = distance[nearest] + len;
            }
        }
    }
    return {distance, parent};
}

// with the parent vector output from dijkstra algorithm, we can easily restore the shortest path from start to any node 
vector<int> shortestPath(int start, int to, vector<int>& parent) {
    vector<int> path;
    for (int i=to; parent[i]!=start; i = parent[i]) {
        path.push_back(i);
    }
    path.push_back(start);
    reverse(path.begin(), path.end()); 
    return path;
}

// Now for sparse graphs...

// Most optimal data structure: Fibonacci heap
// 1. Extract min in O(logn)
// 2. Update values in O(1)

// TBD

// Priority queue -> heap -> both operations in O(logn) and O(logm)


// Set -> red black tree -> O(logn) and O(logm)
// can remove any, so we can replace pairs with int
pair<vector<int>, vector<int>> dijkstra(int start, vector<vector<pair<int,int>>>& graph) {
    int n = graph.size(); // number of nodes
    vector<int> distance(n, __INT_MAX__), parent(n, -1);
    // vector<bool> vis(n, false);
    // start with node start
    distance[start] = 0;
    // set 
    auto comp = [&](int a, int b){
        return distance[a]<distance[b];
    };
    set<int, decltype(comp)> s(comp);
    s.insert(start);
    // n iterations
    while (!s.empty()) {
        // find the nearest not visited node 
        int nearest = *s.begin();
        s.erase(s.begin());
        // expand from nearest node, eg.: in the first iteration it would be the start node 
        // mark as visited
        // vis[nearest] = true;
        for (auto& edge : graph[nearest]) {
            int to = edge.first;
            int len = edge.second; 
            if (distance[nearest]+len < distance[to]) {
                s.erase(to);  // erase if exists 
                // update the parent
                parent[to] = nearest;
                distance[to] = distance[nearest] + len;
                s.insert(to); // need to reinsert because the distance has changed 
            }
        }
    }
    return {distance, parent};
}