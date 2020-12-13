// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

using namespace std;
const int N = 2501;
using ll = long long int;

struct edge {
  int a, b, cost;

  edge() {}

  edge(int _a, int _b, int _c) : a(_a), b(_b), cost(_c) {}
};

int n, m;
int par[N];
ll dist[N];
vector<edge> adj;

/**
 * Verified:
 * 1. https://cses.fi/problemset/task/1197/
 * 
 * Note:
 * 1. to detect +ve cycle using Bellman-Ford, you can multiple the graph by -1 and detect -ve cycle using standard bellman
 **/
int bellman(int u) {
  memset(par, -1, sizeof(par));
  fill(dist, dist + N, 1e17);

  int x;
  dist[u] = 0;

  for (int i = 0; i < n; i++) {
    x = -1;
    bool any = true;
    for (auto e : adj) {
      if (dist[e.a] + e.cost < dist[e.b]) {
        x = e.b;
        any = false;
        par[e.b] = e.a;
        dist[e.b] = dist[e.a] + e.cost;
      }
    }
    if (any) break; // no useful work to do
  }

  return x;
}

/**
 * We need to got a node that is guaranteed to be in the negative cycle
 * (x) either in the -ve cycle or reachable from it
 *
 * 1. Starting from x go through the parents (predecessors) n-times.
 * 2. here we have a node (y) which is certainly inside the -ve cycle.
 * 3. Go from this vertex through the predecessors until we back to (y).
 **/
vector<int> getNegativeCycle(int x) {
  int y = x;
  for (int i = 0; i < n; i++) y = par[y];

  vector<int> path;
  for (int cur = y;; cur = par[cur]) {
    path.push_back(cur);

    if (cur == y && path.size() > 1) break; // welcome back, we finished
  }

  reverse(path.begin(), path.end());
  return path;
}

int main() {
  int u, v, c;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> c;
    adj.emplace_back(u, v, c);
  }

  /**
   * If x != -1, this means that we got a relaxed path in the nth iteration
   * and This means that x either in the -ve cycle or reachable from it
   **/
  int x = bellman(1); // assuming 1 is the src node
  if (~x) { // we have a -ve cycle (relaxed in the nth iteration)
    auto negCyclePath = getNegativeCycle(x);

    cout << "YES" << endl;
    for (auto i : negCyclePath) cout << i << ' ';
  } else { // we don't have a -ve cycle
    cout << "NO" << endl;
  }
}