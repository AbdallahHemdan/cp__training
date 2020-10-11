int n, m;
const int N = 1e5 + 15;

vi path;
vi cycle;  // contains the path of the first cycle found
vi adj[N];
int vis[N];

int dfs(int u, int par) {
    vis[u] = 1;
    path.push_back(u);

    for (auto v : adj[u]) {
        if (!vis[v]) {
            if (dfs(v, u)) {
                return 1;
            }
        } else if (v != par) {
            path.push_back(v);

            int i = find(all(path), v) - path.begin();
            while (i < path.size()) cycle.push_back(path[i++]);

            return 1;
        }
    }
    path.pop_back();
    return 0;
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

    int ok = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ok = dfs(i, -1);
            if (ok) break; // cylce detected
        }
    }
    if (ok) {
        cout << cycle.size() << endl;
        for (int i = 0; i < cycle.size(); i++) {
            cout << cycle[i] << " \n"[i == cycle.size() - 1];
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
