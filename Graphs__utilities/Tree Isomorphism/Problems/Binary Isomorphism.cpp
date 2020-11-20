#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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

    int rootA = -1, rootB = -1;
    tree a(n), b(n);
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      if(x) {
        a.add_edge(x - 1, i);
      }else{
          rootA = i;
      }
    }

    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      if(x) {
        b.add_edge(x - 1, i);
      }else{
          rootB = i;
      }
    }

    cout << isomorphic(a, rootA, b, rootB) << endl;
  }
}
