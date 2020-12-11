#include <bits/stdc++.h>

using namespace std;

int n;
const int LOG_N = 12;
const int N = 1e3 + 13;
vector<int> adj[N];

int dist[N];
int par[N][LOG_N];


/**
 * Builds the LCA data structure.
 *
 * Complexity: O(n.log(n))
 */
void buildLCA(int u) {
  memset(par, -1, sizeof(par));
  memset(dist, -1, sizeof(dist));

  queue<int> q;
  q.push(u);

  dist[u] = 0;
  while (!q.empty()) {
    u = q.front();
    q.pop();

    for (int v  : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        par[v][0] = u;
        q.push(v);

        int curP = u;
        for (int i = 1, j = 2; j <= dist[v]; j <<= 1, i++) {
          curP = par[v][i] = par[curP][i - 1];
        }
      }
    }
  }
}

/**
 * Computes the lowest common ancestor (LCA) of of two nodes.
 *
 * Complexity: O(log(n))
 *
 * @param u the first node id.
 * @param v the second node id.
 *
 * @return the LCA of node "u" and node "v".
 */
int getLCA(int u, int v) {
  if (dist[u] > dist[v]) swap(u, v);
  int diffOfDistance = dist[v] - dist[u];

  for (int i = LOG_N, j = (1 << i); j > 0; --i, j = (1 << i)) {
    if (j <= diffOfDistance) {
      v = par[v][i];
      diffOfDistance -= j;
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = LOG_N, j = (1 << i); j > 0; --i, j = (1 << i)) {
    if (dist[u] < j) continue; // step larger than my distance
    if (par[u][i] == par[v][i]) continue; // try to get better common ancestor

    u = par[u][i];
    v = par[v][i];
  }

  return par[u][0];
}

/**
 * Computes the distance between two nodes.
 *
 * Complexity: O(log(n))
 *
 * @param u the first node id.
 * @param v the second node id.
 *
 * @return the distance between node "u" and node "v".
 */
int getDistance(int u, int v) {
  return dist[u] + dist[v] - 2 * dist[getLCA(u, v)];
}

int main() {
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    u--, v--;
    adj[u].push_back(v);
  }


  buildLCA(0); // Assuming 0 is the root of the tree

  int q;
  cin >> q;

  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    cout << getLCA(u, v) + 1 << endl; // convert back to 1-based
    cout << getDistance(u, v) << endl; // distance between 2 nodes in tree
  }
}