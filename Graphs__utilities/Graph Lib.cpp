/**
 * Detect if there is a cycle in directed graph
 * hasCycle: bool will be set to true if graph has a cycle
 * */
int n, m;
int vis[maxn];
int color[maxn];
bool hasCycle = false;

void dfs(int u) {
  vis[u] = 1;
  color[u]++;

  for (auto v : adj[u]) {
    if (!vis[v]) {
      dfs(v);
    } else if (color[v] == 1) {
      hasCycle = true;
    }
  }

  color[u]++;
}
