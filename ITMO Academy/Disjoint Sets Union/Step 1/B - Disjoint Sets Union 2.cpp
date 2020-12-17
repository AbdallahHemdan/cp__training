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

const int N = 3e5 + 5;

int n, m;
int mx[N];
int mn[N];
int par[N];
int rnk[N];

void init() {
  for (int i = 0; i < N; i++) {
    rnk[i] = 1;
    par[i] = mx[i] = mn[i] = i;
  }
}

int find(int u) {
  return (u == par[u]) ? u : par[u] = find(par[u]);
}

void get(int u) {
  u = find(u);
  cout << mn[u] << ' ' << mx[u] << ' ' << rnk[u] << endl;
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (rnk[u] >= rnk[v]) {
    par[v] = u;
    rnk[u] += rnk[v];
    mx[u] = max(mx[u], mx[v]);
    mn[u] = min(mn[u], mn[v]);
  } else {
    par[u] = v;
    rnk[v] += rnk[u];
    mx[v] = max(mx[u], mx[v]);
    mn[v] = min(mn[u], mn[v]);
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
  int u, v;
  string op;

  cin >> n >> m;
  init();

  for (int i = 0; i < m; i++) {
    cin >> op;
    if (op[0] == 'u') {
      cin >> u >> v;
      if (find(u) != find(v)) {
        merge(u, v);
      }
    } else {
      cin >> u;
      get(u);
    }
  }
}