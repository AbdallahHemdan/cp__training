// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>
using namespace std;

const int LOG_N = 13;
const int N = 1e3 + 15;

int n, l;
int timer;
int tin[N];
int tout[N];

int par[N][LOG_N];
vector<int> adj[N];

void dfs(int u, int p) {
  tin[u] = ++timer;
  par[u][0] = p;

  for (int i = 1; i <= l; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }

  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }

  tout[u] = ++timer;
}


void buildLCA(int u) {
  timer = 0;
  l = ceil(log2(n));
  dfs(u, u);
}

/**
 * Check if node u is ancestor of node v
 *
 * Complexity: O(1)
 *
 * @param u the first node id.
 * @param v the second node id.
 *
 * @return true if node "u" is ancestor of "v" otherwise return false.
 */
bool isAncestor(int u, int v) {
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
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
  if (isAncestor(u, v)) return u;
  if (isAncestor(v, u)) return v;

  for (int i = l; ~i; --i) {
    if (!isAncestor(par[u][i], v)) {
      u = par[u][i];
    }
  }

  return par[u][0];
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
  }
}