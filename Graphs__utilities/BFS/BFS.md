### [1] Standard BFS
> Standard version of bfs

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, dis[N], par[N];
vector<int> edges[N];

// Calculates the shortest path between the given node u and all other nodes
// (Single-Source Shortest Path (SSSP)) for the given unweighted graph,
// and fills the results in the global shortest path "dis" array.
// O(n)
vector<int> edges[N];
void bfs(int u) {
    queue<int> q;
    q.push(u);

    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int v : edges[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}
```

```cpp
// Prints the shortest path from node u to node v after running
// the BFS algorithm with node u as the source.
// Note that the path is encoded in reversed order, so we need to print it recursively.
vector<int> path;
void printPath(int v) {
    if (~par[v]) {
        printPath(par[v]);
    }
    path.push_back(v);
    // printf("%d ", v);
}
```

### [2] BFS topological sort (Khan's Algorithm)
> Topological sort using bfs

```cpp
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
```
