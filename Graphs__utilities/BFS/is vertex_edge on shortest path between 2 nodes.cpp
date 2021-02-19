#include <bits/stdc++.h>
using namespace std;

/**
 * BFS Applications
 *
 * (1)
 * Find all the edges that lie on any shortest path between a given pair of vertices (a,b).
 * To do this, run two breadth first searches: one from a and one from b. Let da[] be
 * the array containing shortest distances obtained from the first BFS (from a)
 * and db[] be the array containing shortest distances obtained from the second BFS from b.
 *
 * Now for every edge (u,v) it is easy to check whether that edge lies on any shortest path
 * between a and b: the criterion is the condition da[u] + 1 + db[v] = da[b].
 *
 *
 *
 * (2)
 * Find all the vertices on any shortest path between a given pair of vertices (a,b).
 * To accomplish that, run two breadth first searches: one from a and one from b. Let da[] be
 * the array containing shortest distances obtained from the first BFS (from a)
 * and db[] be the array containing shortest distances obtained from the second BFS (from b).
 *
 * Now for each vertex it is easy to check whether it lies on any shortest path between a and b:
 * the criterion is the condition da[v]+db[v]=da[b].
 **/

int n, m;
const int maxn = 1e5 + 15;
vector<int> adj[maxn];

int dist1[maxn];
int dist2[maxn];

void bfs1(int u) {
  memset(dist1, -1, sizeof(dist1));
  queue<int> q;
  q.push(u);
  dist1[u] = 0;
  while (!q.empty()) {
    u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist1[v] == -1) {
        dist1[v] = dist1[u] + 1;
        q.push(v);
      }
    }
  }
}

void bfs2(int u) {
  memset(dist2, -1, sizeof(dist2));
  queue<int> q;
  q.push(u);
  dist2[u] = 0;

  while (!q.empty()) {
    u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist2[v] == -1) {
        dist2[v] = dist2[u] + 1;
        q.push(v);
      }
    }
  }
}

bool isVertexOnPath(int u) {
  return (dist1[n] == (dist1[u] + dist2[u]));
}

bool isEdgeOnPath(int u, int v) {
  if (dist1[u] > dist1[v]) swap(u, v);
  return (dist1[n] == (dist1[u] + dist2[v] + 1));
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int a = 1;
  int b = n;

  bfs1(a);
  bfs2(b);

  cout << isVertexOnPath(2) << endl;
  cout << isEdgeOnPath(2, 3) << endl;
}
