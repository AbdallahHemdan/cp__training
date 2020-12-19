// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define endl '\n'
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int n, m;
const int N = 1e5 + 15;
vector<int> adj[N];
int dist[N];
vector<int> bridgeAdj[N];

int T;
int tin[N];
int low[N];
int par[N];
vector<pair<int, int>> bridges;

int find(int u) {
  return (u == par[u]) ? u : par[u] = find(par[u]);
}

void init() {
  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u != v) {
    par[v] = u;
  }
}

void findBridges(int u, int p = -1) {
  tin[u] = low[u] = ++T;

  for (auto v : adj[u]) {
    if (v == p) {
      continue;
    }

    if (tin[v] == 0) {
      findBridges(v, u);

      if (low[v] > tin[u]) {
        bridges.emplace_back(u, v);
      }
    }

    low[u] = min(low[u], low[v]);
  }
}


void findBridges() {
  for (int i = 1; i <= n; ++i) {
    if (tin[i] == 0) {
      findBridges(i);
    }
  }
}

int bfs(int u) {
  memset(dist, -1, sizeof(dist));
  queue<int> q;
  q.push(u);
  dist[u] = 0;

  while (!q.empty()) {
    u = q.front();
    q.pop();

    for (auto v : bridgeAdj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return u;
}

void clear() {
  T = 0;
  bridges.clear();

  memset(tin, 0, sizeof(tin[0]) * (n + 2));
  memset(low, 0, sizeof(low[0]) * (n + 2));
}

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
  // freopen("output.out","w",stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    clear();
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      adj[u].push_back(v);
      adj[v].push_back(u);

      if (u > v) swap(u, v);
      edges.emplace_back(u, v);
    }

    findBridges();
    if (!bridges.empty()) {
      set<pair<int, int>> st;
      for (auto i : bridges) {
        if (i.first > i.second) swap(i.first, i.second);
        st.insert(i);
      }
      init();
      for (auto i : edges) {
        if (!st.count(i)) {
          merge(i.first, i.second);
        }
      }
      for (auto i : bridges) {
        int u = find(i.first);
        int v = find(i.second);
        bridgeAdj[u].push_back(v);
        bridgeAdj[v].push_back(u);
      }

      int s = find(bridges[0].first);
      int u = bfs(s);
      int v = bfs(u);

      cout << bridges.size() - dist[v] << endl;
    } else {
      cout << "0" << endl;
    }

    for (int i = 0; i <= n; i++) {
      adj[i].clear();
      bridgeAdj[i].clear();
    }
  }
}