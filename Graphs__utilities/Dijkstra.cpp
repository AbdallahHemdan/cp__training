// example problem : https://codeforces.com/contest/20/problem/C
const int N = 1e5 + 15;
vector<pair<ll, ll>> adj[N];
ll dis[N];
ll par[N];

ll n, m;


void dijkstra(ll src) {
	for (int i = 0; i < N; i++) {
		dis[i] = OO;
	}
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({ 0,src });
	dis[src] = 0;
	while (!pq.empty()) {
		ll c = pq.top().first;
		ll u = pq.top().second;
		pq.pop();
		if (dis[u] < c) continue;
		
		for (auto &edge : adj[u]) {
			ll to = edge.first;
			ll cost = edge.second;
			if (c + cost < dis[to]) {
				dis[to] = c + cost;
				pq.push({ dis[to], to });
				par[to] = u;
			}
		}
	}
}

vector<int> path;
void findPath(ll u) {
	if (u == 1) { // 1 here represent the src node
		path.push_back(1);
		return;
	}
	findPath(par[u]);
	path.push_back(u);
}


int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	dijkstra(1);
	if (dis[n] >= OO) {
		cout << -1 << endl;
	}
	else {
		findPath(n);
		for (ll i : path)
			cout << i << ' ';
		cout << endl;
	}
}
