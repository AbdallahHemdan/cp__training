#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 1e5 + 15;
int dist[N];
vector<pair<int, int>> adj[N];


/**
 * 0-1 bfs
 * if all edges have cost either 0 or 1
 * you can use it to get single shortest path
 *
 *
 * test on:
 * 5 5
 * 1 2 1
 * 2 3 0
 * 2 4 0
 * 3 4 1
 * 4 5 1
 **/
void bfs01(int s) {
  memset(dist, 0x3f, sizeof(dist));
  dist[s] = 0;

  deque<int> dq;
  dq.push_front(s);

  while (!dq.empty()) {
    int u = dq.front();
    dq.pop_front();


    for (auto v : adj[u]) {
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
        if (v.second == 1) {
          dq.push_back(v.first);
        } else {
          dq.push_front(v.first);
        }
      }
    }
  }
}


int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].emplace_back(v, c);
    adj[v].emplace_back(u, c);
  }

  int s = 1; // source node
  bfs01(s);

  for (int i = 1; i <= n; i++) {
    cout << i << ' ' << dist[i] << endl;
  }
}