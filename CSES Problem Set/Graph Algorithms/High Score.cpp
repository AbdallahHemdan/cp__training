// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define IO                                                             \
    ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), \
        cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }
double distance(double x1, double y1, double x2, double y2) {
    return hypot(fabs(x1 - x2), fabs(y1 - y2));
}
int comp_double(double a, double b) {
    if (fabs(a - b) <= EPS) return 0;  // equal
    return (a < b) ? -1 : 1;
}

struct Edge {
    ll u, v, c;
};

const int N = 2555;
int n, m, x;

int vis[N];
int visInv[N];
ll dist[N];
vector<Edge> edges;

vector<int> adj[N];
vector<int> adjInv[N];

void dfs1(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (!vis[v]) dfs1(v);
    }
}

void dfs2(int u) {
    if (visInv[u]) return;
    visInv[u] = 1;
    for (auto v : adjInv[u]) {
        if (!visInv[v]) dfs2(v);
    }
}

void bellman(int src = 1) {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto e : edges) {
            if (dist[e.v] > dist[e.u] + e.c && vis[e.u] && visInv[e.v]) {
                dist[e.v] = dist[e.u] + e.c;
                x = e.v;
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
        ll u, v, c;
        cin >> u >> v >> c;

        adj[u].push_back(v);
        adjInv[v].push_back(u);
        edges.push_back({u, v, -c});
    }
    dfs1(1);
    dfs2(n);

    bellman(1);

    if (~x) {
        cout << -1 << endl;
    } else {
        cout << -dist[n] << endl;
    }
}