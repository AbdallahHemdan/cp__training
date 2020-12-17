// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define endl '\n'
#define sz size()
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const ll OO = 1e18;
const int oo = INT_MAX;
const double EPS = 1e-9;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }

ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0; // equal
  return (a < b) ? -1 : 1;
}

struct edge {
  int u, v, c;

  edge() {}

  edge(int from, int to, int cost) : u(from), v(to), c(cost) {}

  bool operator<(const edge &e) const {
    return c < e.c;
  }
};

int n, m;
const int N = 1e3 + 13;

int par[N];
int rnk[N];
vector<edge> adj;

int find(int u) {
  return (u == par[u]) ? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (u != v) {
    if (rnk[v] > rnk[u]) swap(u, v);

    par[v] = u;
    rnk[u] += rnk[v];
  }
}

void init() {
  for (int i = 0; i < n + 5; i++) {
    rnk[i] = 1;
    par[i] = i;
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
    adj.emplace_back(u, v, c);
  }
  sort(all(adj));

  ll ret = LLONG_MAX;
  for (int i = 0; i < m; i++) {
    init();
    int cnt = 0;
    int mn = INT_MAX;
    int mx = INT_MIN;
    for (int j = i; j < m; j++) {

      if (find(adj[j].u) != find(adj[j].v)) {
        cnt++;
        mn = min(mn, adj[j].c);
        mx = max(mx, adj[j].c);
        merge(adj[j].u, adj[j].v);
      }
      if (cnt == n - 1) {
        ret = min(ret, mx * 1LL - mn);
        break;
      }
    }

  }
  if (ret == LLONG_MAX) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << ret << endl;
  }
}