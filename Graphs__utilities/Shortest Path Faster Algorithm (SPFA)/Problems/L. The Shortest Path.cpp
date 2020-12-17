#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
using ll = long long int;

const int N = 2e3 + 23;
vector<pair<int, ll>> adj[N];

int n, m;
int par[N];
int frq[N];
ll dist[N];
bool inQueue[N];


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

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#else
  // freopen("input.in","r",stdin);
  // freopen("output.out","w",stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;

    int mnEdge = INT_MAX;
    for (int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;

      adj[u].emplace_back(v, c);
      mnEdge = min(mnEdge, c);
    }
    for (int i = 1; i <= n; i++) {
      adj[0].emplace_back(i, 0);
    }

    if (mnEdge >= 0) {
      cout << mnEdge << endl;
      continue;
    }
    int x = SPFA(0);
    if (x == -1) {
      ll mn = LLONG_MAX;
      for (int i = 1; i <= n; i++) mn = min(mn, dist[i]);

      cout << mn << endl;
    } else {
      cout << "-inf" << endl;
    }

    for (int i = 0; i <= n; i++) adj[i].clear();
  }
}