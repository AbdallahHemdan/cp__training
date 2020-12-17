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

int n, m, k;
const int N = 5e4 + 3;

int par[N];
int rnk[N];

struct query {
  string op;
  int u, v;
};

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

  if (u != v) {
    if (rnk[v] > rnk[u]) swap(u, v);
    par[v] = u;
    rnk[u] += rnk[v];
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

  cin >> n >> m >> k;
  init();
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
  }

  vector<bool> ret;
  vector<query> a(k);

  for (auto &i  : a) {
    cin >> i.op >> i.u >> i.v;
  }
  for (int i = k - 1; ~i; --i) {
    if (a[i].op[0] == 'a') {
      ret.push_back(find(a[i].u) == find(a[i].v));
    } else {
      merge(a[i].u, a[i].v);
    }
  }
  reverse(all(ret));
  for (auto i : ret) cout << ((i == 1) ? "YES" : "NO") << endl;
}