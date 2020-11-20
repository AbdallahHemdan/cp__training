/**
* Table of content:
* 1. Detect cycle in direct graph
* 2. Detect cycle in un-direct graph
* */


/**
 * Detect if there is a cycle in directed graph
 * hasCycle: bool will be set to true if graph has a cycle
 * */
int n, m;
int vis[N];
int color[N];
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







/**
 * Detect if there is a cycle in un-directed graph
 * detectCycle returns bool which represent if there is a cycle or not
 * */
int n, m;
bool vis[N];
vector<int> adj[N];

bool dfs(int u, int p = -1) {
  vis[u] = true;

  for (int v : adj[u]) {
    if (!vis[v]) {
      if (dfs(v, u)) return true;
    } else {
      if (v != p) {
        return true;
      }
    }
  }
  return false;
}

bool detectCycle() {
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (dfs(i)) {
        return true;
      }
    }
  }
  return false;
}

