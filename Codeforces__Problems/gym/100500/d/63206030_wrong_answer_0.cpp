#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

int n, t; 
const int N = 3e4 + 34; 
vector<int> adj[N];
bool vis[N];
void dfs(int u) {
	if (vis[u]) return; 
	vis[u] = 1; 
	for (int i : adj[u]) dfs(i);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> t;
	for (int i = 1; i < n; i++) {
		int x; cin >> x;
		if (i + x <= n) adj[i].push_back(i + x);
	}
	dfs(1);
	if (vis[t]) cout << "YES" << endl;
	else cout << "NO" << endl;
}