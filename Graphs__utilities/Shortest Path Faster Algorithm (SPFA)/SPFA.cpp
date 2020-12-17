#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int N = 1e5 + 15;
vector<pair<int, ll>> adj[N];

int n, m;
int par[N];
int frq[N];
ll dist[N];
bool inQueue[N];


/**
 * SPFA is a improvement of the Bellman-Ford algorithm which takes advantage of
 * the fact that not all attempts at relaxation will work.
 *
 * This algorithm can also be used to detect negative cycles as the Bellman-Ford.
 * @param u : is the source node
 *
 * Steps:
 * 1. Create graph of (n + 1) nodes
 * 2. Add edge from the extra node S(e.g. 0) to all nodes with cost = 0
 * 3. Run SPFA from the node S
 *
 * Verified:
 * 1. https://cses.fi/problemset/task/1197/
 *
 *
 * Checks:
 * 1. Check the OO value in the memset
 * 2. Clear all array in case of multiple test cases
 * 3. Overflow in dist
 **/
int SPFA(int u) {
  memset(frq, 0, sizeof(frq));
  memset(par, -1, sizeof(par));
  fill(dist, dist + N, 1e17);
  memset(inQueue, 0, sizeof(inQueue));

  queue<int> q;
  q.push(u);

  dist[u] = 0;
  inQueue[u] = true;

  while (!q.empty()) {
    u = q.front();
    q.pop();

    inQueue[u] = false;

    for (auto edge: adj[u]) {
      int to = edge.first;
      ll cost = edge.second;

      if (dist[to] > 1LL * dist[u] + cost) {
        dist[to] = 1LL * dist[u] + cost;
        if (!inQueue[to]) {
          frq[to]++;
          q.push(to);
          par[to] = u;
          inQueue[to] = true;

          if (frq[to] > n) return to; // has negative cycle (relaxed more than n time)
        }
      }
    }
  }
  return -1;
}

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
    adj[u].emplace_back(v, c);
  }

  /**
   * Create node S(e.g. 0) and add edge from it to all other nodes with cost = 0
   **/
  for (int i = 1; i <= n; i++) {
    adj[0].emplace_back(i, 0);
  }

  int x = SPFA(0);
  if (~x) {
    auto negCyclePath = getNegativeCycle(x);

    cout << "YES" << endl;
    for (auto i : negCyclePath) cout << i << ' ';
  } else {
    cout << "NO" << endl;
  }
}