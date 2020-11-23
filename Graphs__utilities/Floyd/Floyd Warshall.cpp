#include <bits/stdc++.h>

using namespace std;

/**
 * Floyd-Warshall O(n^3)
 * Used to find shortest-path between each pair in the Graph using Dynamic-Programming
*/

const int N = 101;
const int OO = 1e9;
const double EPS = 1e-9;

int n, m;              // The number of nodes/edges.
int adj[N][N];      // The graph adjacency matrix.
int par[N][N];      // par[u][v] : holds the parent node of "v" in the shortest path from "u" to "v".

vector<int> path;

/**
 * Initializes the graph.
 * Must be called before each test case.
 */
void init() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      adj[i][j] = (i == j ? 0 : OO);
      par[i][j] = i;
    }
  }
}

/**
 * Computes the shortest path between any pair of nodes in the graph
 * and updates the adjacency matrix in accordance by running Floyd Warshall's algorithm.
 * (i.e. All-Pair Shortest Path (APSP))
 *
 * Complexity: O(n^3)
 */
void floyd() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (adj[i][j] > adj[i][k] + adj[k][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
          par[i][j] = par[k][j];
        }
      }
    }
  }
}

/**
 * The case of real weights
 * If the weights of the edges are not integer but real, 
 * it is necessary to take the errors, which occur when working with float types
 * 
 * To avoid this the algorithm can be modified to take the error (EPS = δ) into account by using following comparison: 
 * 
*/

void floydReal() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (adj[i][k] + adj[k][j] < adj[i][j] - EPS) {
          adj[i][j] = adj[i][k] + adj[k][j];
          par[i][j] = par[k][j];
        }
      }
    }
  }
}

/**
 * assume that we only care if a their is a path or not, not caring about shortest path
 * so the graph has one 2 value
 *
 * 0 - their is no connection
 * 1 - their is a connection
 * */

void TransitiveClosure() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        adj[i][j] |= (adj[i][k] & adj[k][j]);
      }
    }
  }
}

/**
 * find the path such that max value on road is minimum
 **/
void minimax() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
      }
    }
  }
}

/**
 * find path such that min value on road is maximum
 **/
void maximin() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
      }
    }
  }
}

/**
 * assume we are caring about count the number of paths between the each pair of nodes
 * we need to initialize the graph with (0's or 1's)
 *
 * 0-means their is no a path
 * 1-means their is a path
 **/
void countPaths() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        adj[i][j] += adj[i][k] * adj[k][j];
      }
    }
  }
}

/**
 * Checks whether the graph has negative cycles or not.
 * This function must not be called before running the Floyd Warshall's algorithm.
 *
 * Complexity: O(n)
 *
 * @return {@code true} if the graph has at least one negative cycle; {@code false} otherwise.
 **/
bool checkNegativeCycle() {
  bool ret = false;
  for (int i = 0; i < n; i++) {
    ret = ret || (adj[i][i] < 0);
  }

  return ret;
}

/**
 * Find longest path between 2 nodes
 * The graph mush be DAG (directed, acyclic graph)
 **/
void longestPathDAG() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
}

/**
 * Prints the shortest path from node u to node v after running Floyd Warshall's algorithm.
 * Note that the path is encoded in reversed order, so we need to print it recursively.
 **/
void printPath(int u, int v) {
  if (u != v) {
    printPath(u, par[u][v]);
  }
  path.push_back(v + 1); // +1 for retrieve it to 1-based
}

/**
 * graph diameter: is the longest distance between 2 nodes
 * the only way to find graph diameter is Floyd Warshall
 *
 * Steps:
 * 1. Run floyd
 * 2. Loop over all nodes
 * 3. if there is a path between 2 nodes (defined)
 * 4. maximize over the mx value
 **/
int graphDiameter() {
  floyd();

  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (adj[i][j] < OO) { // there is a path
        mx = max({mx, adj[i][j]});
      }
    }
  }
}

// Example
// 4 5
// 1 3 -2
// 2 1 4
// 2 3 3
// 3 4 2
// 4 2 -1
int main() {
  // Read number of nodes
  cin >> n >> m;

  // Initializes the graph's adjacent matrix
  init();

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u - 1][v - 1] = w; // Working on 0-based
  }

  // Compute all-pairs shortest path
  floyd();

  // Print adjacent matrix after running Floyd Warshal's algorithm
  cout << endl << "All-Pairs Shortest Path:" << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << setw(4) << adj[i][j] << (" \n"[j == n - 1]);
    }
  }
  cout << endl;

  // Read pairs and print their shortest path
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    printPath(u - 1, v - 1);
  }
}