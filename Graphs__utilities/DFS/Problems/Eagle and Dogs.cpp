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

int n;
const int N = 1e5 + 15;
ll mx[N][3]; // [0] = 1st mx, [1] = 2nd mx
vector<pair<int, int>> adj[N];

void dfs(int u, int p = -1) {
  mx[u][0] = mx[u][1] = 0LL;
  for (auto v : adj[u]) {
    if (v.first != p) {
      dfs(v.first, u);
      mx[u][2] = mx[v.first][0] + v.second;
      sort(mx[u], mx[u] + 3);
      reverse(mx[u], mx[u] + 3);
    }
  }
}

void solve(int u, int p = -1) {
  for (auto v : adj[u]) {
    if (v.first == p) continue;
    if (v.second + mx[v.first][0] == mx[u][0]) { // is current branch my 1st mx
      mx[v.first][2] = mx[u][1] + v.second;
    } else {
      mx[v.first][2] = mx[u][0] + v.second;
    }
    sort(mx[v.first], mx[v.first] + 3);
    reverse(mx[v.first], mx[v.first] + 3);
    solve(v.first, u);
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
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;

      adj[u].emplace_back(v, c);
      adj[v].emplace_back(u, c);
    }
    dfs(0);

    solve(0);
    for (int i = 0; i < n; i++) {
      cout << mx[i][0] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) adj[i].clear();
  }
}