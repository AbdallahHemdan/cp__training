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

int n, m;
const int N = 1e5 + 15;
vector<pair<ll, ll>> adj[N];
vector<pair<ll, ll>> adjInv[N];
vector<Edge> edge;

ll dist1[N];
ll dist2[N];

using cell = pair<ll, ll>;
int32_t main() {
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
        adj[u].push_back({v, c});
        adjInv[v].push_back({u, c});
        edge.push_back({u, v, c});
    }

    memset(dist1, 0x3f, sizeof(dist1));
    memset(dist2, 0x3f, sizeof(dist2));

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq1;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq2;
    pq1.push({0LL, 1});
    pq2.push({0LL, n});
    dist1[1] = 0LL;
    dist2[n] = 0LL;

    while (!pq1.empty()) {
        cell u = pq1.top();
        pq1.pop();

        ll v = u.second;
        ll c = u.first;

        if (dist1[v] < c) continue;
        for (auto vv : adj[v]) {
            ll nxt = vv.first;
            ll nxtC = vv.second;
            if (c + nxtC < dist1[nxt]) {
                dist1[nxt] = c + nxtC;
                pq1.push({dist1[nxt], nxt});
            }
        }
    }

    while (!pq2.empty()) {
        cell u = pq2.top();
        pq2.pop();

        ll v = u.second;
        ll c = u.first;

        if (dist2[v] < c) continue;
        // cout << u.first << ' ' << u.second << endl;
        for (auto vv : adjInv[v]) {
            ll nxt = vv.first;
            ll nxtC = vv.second;
            if (c + nxtC < dist2[nxt]) {
                dist2[nxt] = c + nxtC;
                pq2.push({dist2[nxt], nxt});
            }
        }
    }

    ll ret = LLONG_MAX;
    for (auto e : edge) {
        ll from = e.u;
        ll to = e.v;
        ll cst = e.c;

        ll tot = dist1[from] + dist2[to] + cst / 2;
        ret = min({ret, tot});
    }
    cout << ret << endl;
}