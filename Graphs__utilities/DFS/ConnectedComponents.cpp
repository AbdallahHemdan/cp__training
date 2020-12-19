// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define endl '\n'
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
const int N = 1e5 + 5;


int n, m;
int vis[N];
vector<int> comp;
vector<int> adj[N];

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  comp.push_back(u);

  for (auto v : adj[u]) {
    dfs(v);
  }
}

auto findComponents() {
  vector<vector<int>> comps;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      comp.clear();
      dfs(i);
      comps.push_back(comp);
    }
  }
  return comps;
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
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto allComponents = findComponents();
  for (const auto &single: allComponents) {
    for (auto u : single) {
      cout << u << ' ';
    }
    cout << endl;
  }
}