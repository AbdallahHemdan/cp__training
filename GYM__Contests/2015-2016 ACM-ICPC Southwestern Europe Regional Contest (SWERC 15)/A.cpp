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
int a, b;
const int N = 5e3 + 53;
int vis[N];
vector<int> adj[N];
vector<int> adjInv[N];

int dfs1(int u) {
    if (vis[u]) return 0;

    int cnt = 1;
    vis[u] = 1;

    for (auto v : adj[u]) {
        cnt += dfs1(v);
    }
    return cnt;
}

int dfs2(int u) {
    if (vis[u]) return 0;

    int cnt = 1;
    vis[u] = 1;

    for (auto v : adjInv[u]) {
        cnt += dfs2(v);
    }
    return cnt;
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
    cin >> a >> b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adjInv[v].push_back(u);
    }

    ll ret1 = 0, ret2 = 0, ret3 = 0;

    for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof(vis));

        int ret = dfs1(i);
        ret = n - ret + 1;

        if (ret <= a) {
            ret1++;
        }

        if (ret <= b) {
            ret2++;
        }

        memset(vis, 0, sizeof(vis));

        int inv = dfs2(i);
        if (inv > b) {
            ret3++;
        }
    }

    cout << ret1 << endl;
    cout << ret2 << endl;
    cout << ret3 << endl;
}