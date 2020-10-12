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
    ll a, b, cost;
};

ll n, m, x;
const ll N = 2555;
ll dist[N];
ll part[N];
vector<Edge> edges;

void bellman() {
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
    if (x == -1) {
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