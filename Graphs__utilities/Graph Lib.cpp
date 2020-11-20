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



/**
 * Sorts the graph in a topological order using Khan BFS algorithm,
 * and fills the result in the global "sortedNodes" vector.
 *
 * Note that it works correctly with Directed Acyclic Graphs (DAGs).
 *
 * Complexity: O(n+m)
 */
void topoSortBFS() {
    queue<int> q;
    vector<int> inDeg(n + 1, 0);

    // Compute the in degree of each node
    // (i.e. the number of in-edges towards node "u")
    for (int i = 1; i <= n; ++i) {
        for (int v : edges[i]) {
            ++inDeg[v];
        }
    }

    // Push all nodes with zero in degree in the queue
    for (int i = 1; i <= n; ++i) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        sortedNodes.push_back(u);

        for (int v : edges[u]) {
            if (--inDeg[v] == 0) {
                q.push(v);
            }
        }
    }
}
