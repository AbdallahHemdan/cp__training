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
            if (ok) break;
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