/**
 * 2-Graphs G1, G2 are isomorphic if you can make them equal by re-labeling their vertices
 *                  G1                  G2
 *              v1 ---- v2          v2 ---- v1
 *              |     /  |          |     /  |
 *              |   /    |          |   /    |
 *               v3 ---- v4          v4 ---- v3
 *  G1 and G2 are isomorphic as by labeling vertices in G2 (v2 -> v1, v4 -> v3) we get G1
 **/

/**
 * Description:
 * Rooted trees (S,s) and (T,t) are isomorphic
 * iff there is a bijection between childs of s and childs of t
 * such that s.child[i] and t.child[pi[i]] is isomorphic.
 * Two trees are isomorphic iff these are isomorphic with some roots.
 *
 *
 * Algorithm:
 * Aho-Hopcroft-Ullman's algorithm for rooted isomorphism.
 * It simultaneously scans the vertices in the two trees from bottom to root,
 * and assigns unique id (among the level) for each subtrees.
 *
 *
 * For un-rooted isomorphism, it first finds centers of tree,
 * and try all possibility of rooted tree isomorphism.
 * Since the number of centers in a tree is at most two,
 * it can be performed as the same complexity as rooted isomorphism.
 *
 * Complexity:
 * O(n log n).
 *
 * Verified:
 * 1. https://csacademy.com/contest/round-73/task/binary-isomorphism/
 * 2. https://www.spoj.com/problems/TREEISO/
 *
 * Notes:
 * If your trees are already rooted call isomorphic(tree S, int s, tree T, int t)
 * else call isomorphic(tree S, tree T)
 * */
 
 #include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(v) ((v).begin()), ((v).end())

using namespace std;


struct tree {
  int n;
  vector<vector<int>> adj;

  tree(int n) : n(n), adj(n) {}

  void add_edge(int src, int dst) {
    adj[src].push_back(dst);
    adj[dst].push_back(src);
  }

  vector<int> centers() {
    vector<int> prev;
    int u = 0;
    for (int k = 0; k < 2; ++k) { // double sweep
      queue<int> que;
      prev.assign(n, -1);
      que.push(prev[u] = u);
      while (!que.empty()) {
        u = que.front();
        que.pop();
        for (auto v: adj[u]) {
          if (prev[v] >= 0) continue;
          que.push(v);
          prev[v] = u;
        }
      }
    }
    vector<int> path = {u}; // median on a path
    while (u != prev[u])
      path.push_back(u = prev[u]);
    int m = path.size();
    if (m % 2 == 0) return {path[m / 2 - 1], path[m / 2]};
    else return {path[m / 2]};
  }

  vector<vector<int>> layer;
  vector<int> prev;

  int levelize(int r) { // split vertices into levels
    prev.assign(n, -1);
    prev[r] = n;
    layer = {{r}};
    while (true) {
      vector<int> next;
      for (int u: layer.back()) {
        for (int v: adj[u]) {
          if (prev[v] >= 0) continue;
          prev[v] = u;
          next.push_back(v);
        }
      }
      if (next.empty()) break;
      layer.push_back(next);
    }
    return layer.size();
  }
};

bool isomorphic(tree S, int s, tree T, int t) {
  if (S.n != T.n) return false;
  if (S.levelize(s) != T.levelize(t)) return false;

  vector<vector<int>> longcodeS(S.n + 1), longcodeT(T.n + 1);
  vector<int> codeS(S.n), codeT(T.n);
  for (int h = S.layer.size() - 1; h >= 0; --h) {
    map<vector<int>, int> bucket;
    for (int u: S.layer[h]) {
      sort(all(longcodeS[u]));
      bucket[longcodeS[u]] = 0;
    }
    for (int u: T.layer[h]) {
      sort(all(longcodeT[u]));
      bucket[longcodeT[u]] = 0;
    }
    int id = 0;
    for (auto &p: bucket) p.second = id++;
    for (int u: S.layer[h]) {
      codeS[u] = bucket[longcodeS[u]];
      longcodeS[S.prev[u]].push_back(codeS[u]);
    }
    for (int u: T.layer[h]) {
      codeT[u] = bucket[longcodeT[u]];
      longcodeT[T.prev[u]].push_back(codeT[u]);
    }
  }
  return codeS[s] == codeT[t];
}

bool isomorphic(tree S, tree T) {
  auto x = S.centers(), y = T.centers();
  if (x.size() != y.size()) return false;
  if (isomorphic(S, x[0], T, y[0])) return true;
  return x.size() > 1 && isomorphic(S, x[1], T, y[0]);
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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    tree a(n), b(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;

      u--, v--;
      a.add_edge(u, v);
    }

    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;

      u--, v--;
      b.add_edge(u, v);
    }

    if (isomorphic(a, b)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
