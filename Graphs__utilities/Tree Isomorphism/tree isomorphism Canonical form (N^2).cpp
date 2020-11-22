/**
 * Calculate canonical form for the tree, the isomorphic tree should have equal canonical form
 * O(n^2)
 * NOT efficient for large n
 * leaf node: ()
 * intermediate node: ( children )
 *
 * TLE for most of problems (DON'T USE IT FOR LARGE N)
 **/

int n;
const int N = 1e5 + 15;
vector<int> adj[N];

string treeCanonicalForm(int u, int p = -1) {
  vector<string> children;
  for (int v : adj[u]) {
    if (v != p) {
      children.push_back(treeCanonicalForm(v, u));
    }
  }
  string node = "(";
  sort(all(children));
  for (const string &k : children) {
    node += k;
  }
  node += ")";

  return node;
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
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout << treeCanonicalForm(1) << endl;
}
