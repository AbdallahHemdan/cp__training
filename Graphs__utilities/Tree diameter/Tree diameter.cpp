/**
 * * Tree centers: are the nodes in the tree that minimize the length of the longest path from it to any node 
 * * Worst nodes: are the nodes have maximum height (tree diameter nodes)
*/

#include <bits/stdc++.h>
#define	vll	vector<ll>

using namespace std;
using ll = long long int;


const int N = 1e4 + 14;
ll dist[N];
vll adj[N];

ll bfs(int u) {
	queue<ll> q;
	q.push(u);

	memset(dist, -1, sizeof(dist));
	dist[u] = 0;

	while (!q.empty()) {
		u = q.front();
		q.pop();

		for (auto v : adj[u]) {
			if (dist[v] == -1) { // not visited yet
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	return u;
}

ll calculateTreeDiameter(int root) {
	int u = bfs(root);
	int v = bfs(u);

	return dist[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n;
	cin >> n;
	
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << calculateTreeDiameter(1) << endl;
}
