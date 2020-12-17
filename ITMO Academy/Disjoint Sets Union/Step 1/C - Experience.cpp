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
int ret[N];

void init() {
  for (int i = 0; i <= n; i++) {
    rnk[i] = 1;
    par[i] = i;
  }
}

int find(int u) {
  return (u == par[u]) ? u : find(par[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (u != v) {
    if (rnk[u] < rnk[v]) {
      swap(u, v);
    }

    par[v] = u;
    ret[v] -= ret[u];
    if (rnk[u] == rnk[v])
      rnk[u]++;
  }
}

int get(int u) {
  return (u == par[u]) ? ret[u] : ret[u] + get(par[u]);
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

    if (op[0] == 'j') {
      cin >> u >> v;
      merge(u, v);
    } else if (op[0] == 'a') {
      cin >> u >> v;
      ret[find(u)] += v;
    } else {
      cin >> u;
      cout << get(u) << endl;
    }
  }
}