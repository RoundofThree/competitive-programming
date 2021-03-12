// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
 
const int64_t INF = INT64_C(1) << 60;
 
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
// Use Dijkstra algorithm 
// where the distance between nodes is the minimum: ceil(currtime/Ki)*Ki+Ti ==> waiting time and travelling time 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  X--, Y--;
  vector<vector<tuple<int, int64_t, int64_t>>> G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    int64_t t, k;
    cin >> a >> b >> t >> k;
    a--, b--;
    G[a].emplace_back(make_tuple(b, t, k));
    G[b].emplace_back(make_tuple(a, t, k));
  }
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> que;
  que.push(make_pair(0, X));
  vector<int64_t> dist(N, INF);
  dist[X] = 0;
  int64_t d, t, k;
  int u, v;
  while (!que.empty()) {
    std::tie(d, u) = que.top();
    que.pop();
    if (d > dist[u]) continue;
    for (tuple<int, int64_t, int64_t> tupl : G[u]) {
      std::tie(v, t, k) = tupl;
      if (chmin(dist[v], d + t + ((k - (d % k)) % k))) {
        que.push(make_pair(dist[v], v));
      }
    }
  }
  if (dist[Y] != INF) {
    cout << dist[Y] << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}