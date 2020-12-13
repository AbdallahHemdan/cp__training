// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 15;
using ll = long long int;


int n, m; // The number of nodes, edges.
int par[N]; // par[v] : holds the parent of "v" in the shortest path the source to node "v".
ll dist[N]; // dist[v] : holds the shortest distance between the source and node "v".
vector<pair<int, ll>> adj[N]; // The graph adjacency list.

/**
 * Computes the shortest path between the given source node and
 * all the other nodes in a weighted graph using the Dijkstra's algorithm,
 * and fills the results in the global "dis" and "par" arrays.
 * (i.e. Single-Source Shortest Path (SSSP))
 *
 * Complexity: O((n+m)log(n))
 *
 * @param src the source node.
 * Verified:
 * 1. https://codeforces.com/contest/20/problem/C
 */
void dijsktra(int u, ll c = 0) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
  pq.push({0, u});


  memset(par, -1, sizeof(par));
  fill(dist, dist + N, 1e17);

  dist[u] = 0;
  while (!pq.empty()) {
    c = pq.top().first;
    u = pq.top().second;
    pq.pop();

    if (dist[u] < c) continue;

    for (auto e : adj[u]) {
      int to = e.first;
      int cst = e.second;

      if (dist[to] > c + cst) {
        par[to] = u;
        dist[to] = c + cst;
        pq.push({dist[to], to});
      }
    }
  }
}

/**
 * Prints the shortest path from the source to node "u".
 * This function must not be called before running the Dijkstra's SSSP algorithm.
 *
 * Note that the path is encoded in reverse order,
 * that why we need to print it recursively.
 *
 * @param u the last node in the path.
 */
vector<int> getParent(int u) {
  vector<int> path;
  while (u != -1) {
    path.push_back(u);
    u = par[u];
  }
  reverse(path.begin(), path.end()); // reverse the path to get it from src to dist

  return path;
}

int main() {
  int u, v, c;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> u >> v >> c;
    adj[u].emplace_back(v, c);
    adj[v].emplace_back(u, c);
  }

  /**
   * Checks:
   * 1. Check for Overflow and update dist, priority_queue.
   * 2. Check for condition if the path is not exists.
   * 3. Check OO value if you need to change it
   **/
  dijsktra(1); // We assuming that 1 is the src node

  int target = n; // here we want to find path from src(1) to dist(n) in case it's exists

  if (par[target] == -1) {
    cout << -1 << endl;
  } else {
    for (auto i : getParent(target)) cout << i << ' ';
  }
}