struct Edge {
    ll a, b, cost;
};

ll n, m, x;
const ll N = 2555;
ll dist[N];
ll part[N];
vector<Edge> edges;

void bellman(int src = 1) {
    memset(part, -1, sizeof(part));
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (dist[e.a] + e.cost < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.cost;
                part[e.b] = e.a;
                x = e.b;
            }
        }
    }
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
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
    bellman();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << endl;
    }
    if (x == -1) { // has no negative cycle (couldn't relax in the nth iteration)
        cout << "NO" << endl;
    } else {  // has negative cycle (could relax in the nth iteration)
        for (int i = 0; i < n; ++i) x = part[x];

        vector<ll> cycle;
        for (ll v = x;; v = part[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }
        reverse(all(cycle));

        cout << "YES" << endl;
        for (int v : cycle) cout << v << ' ';
        cout << endl;
    }
}
