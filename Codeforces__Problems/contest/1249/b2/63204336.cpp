#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

const int N = 2e5 + 25; 
int par[N];
int sz[N];
int find(int u) {
	if (par[u] != u) par[u] = find(par[u]);
	return par[u];
}
void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u != v) {
		if (sz[u] >= sz[v]) {
			par[v] = u; 
			sz[u] += sz[v];
		}
		else {
			par[u] = v;
			sz[v] += sz[u];
		}
	}
}
vector<int> adj[N];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; 
		for (int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
		for (int i = 0; i < n; i++) {
			int u; cin >> u; u--; 
			if (find(u) != find(i)) merge(u, i);
		}
		for (int i = 0; i < n; i++) {
			cout << sz[find(i)] << ' ';
		}
		cout << endl;
	}
}