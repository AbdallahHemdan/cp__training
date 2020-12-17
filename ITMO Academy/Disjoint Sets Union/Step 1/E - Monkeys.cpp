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

int n, m, t;
const int N = 2e5 + 5;

int ret[N];
int par[N];
int adj[N][2];
bool vis[N][2];
vector<int> a[N];

void init() {
  for (int i = 0; i < N; i++) {
    par[i] = i;
    a[i].push_back(i);
  }
}

void merge(int u, int v) {
  u = par[u];
  v = par[v];

  if (u != v) {
    if (v == 1 || (u != 1 && (a[u].size() < a[v].size()))) swap(u, v);

    for (int x : a[v]) {
      par[x] = u;
      a[u].push_back(x);
      ret[x] = t == m ? -1 : t;
    }
    a[v].clear();
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
  init();
  cin >> n >> m;

  t = m;
  ret[1] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> adj[i][0] >> adj[i][1];
  }
  vector<pair<int, int>> queries(m); // first = node, second = lft = 1 | rgt = 2
  for (auto &i  : queries) {
    cin >> i.first >> i.second;
    vis[i.first][i.second - 1] = true;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      if (!vis[i][j] && ~adj[i][j]) {
        merge(i, adj[i][j]);
      }
    }
  }

  for (int i = m - 1; ~i; --i) {
    t--;
    merge(queries[i].first, adj[queries[i].first][queries[i].second - 1]);
  }
  for (int i = 1; i <= n; i++) cout << ret[i] << endl;
}