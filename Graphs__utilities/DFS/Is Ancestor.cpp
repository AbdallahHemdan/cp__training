/**
 * Check if a vertex in a tree is an ancestor of some other vertex:
 * At the beginning and end of each search call we remember the entry and exit "time" of each vertex.
 * Now you can find the answer for any pair of vertices (i,j) in O(1):
 * vertex i is an ancestor of vertex j if and only if (entry[i] < entry[j]) and (exit[i] > exit[j]).
 **/

int n, t;
vector<int> adj[N];

int in[N];
int out[N];

void dfs(int u, int p = -1) {
  in[u] = t++;
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  out[u] = t++;
}

bool isAncestor(int u, int v) {
  return (in[u] < in[v] && out[u] > out[v]);
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  dfs(1);

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << isAncestor(u, v) << endl;
  }
}
