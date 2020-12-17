// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0; // equal
  return (a < b) ? -1 : 1;
}

int n, m;
const int N = 2e5 + 5;
int par[N];
int rnk[N];

void init() {
  for (int i = 0; i < N; i++) {
    rnk[i] = 1;
    par[i] = i;
  }
}

int find(int u) {
  return (u == par[u]) ? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (rnk[u] >= rnk[v]) {
    par[v] = u;
    rnk[u] += rnk[v];
  } else {
    par[u] = v;
    rnk[v] += rnk[u];
  }
}

struct edge {
  ll c;
  int u, v;

  edge(int _u, int _v, ll _c) {
    u = _u;
    v = _v;
    c = _c;
  }

  bool operator<(const edge &e) const {
    return c < e.c;
  }
};

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  int u, v, c;
  cin >> n >> m;
  init();

  vector<edge> a;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> c;
    a.emplace_back(edge(u, v, c));
  }
  sort(all(a));

  ll mn = 0;
  for (auto i : a) {
    if (find(i.u) != find(i.v)) {
      mn += i.c;
      merge(i.u, i.v);
    }
  }
  cout << mn << endl;
}