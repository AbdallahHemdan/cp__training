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
#define IO \
  ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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

const int N = 1e3 + 13;
ll n, m, k;
ll vis[N];
ll color[N];
ll adj[N][N];

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#else
  // freopen("input.in","r",stdin);
  // freopen("output.out","w",stdout);
#endif
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  // for each node if not colored yet => try to color it with color differne
  // of all its adj nodes
  for (int i = 1; i <= n; i++) {
    if (!color[i]) {
      memset(vis, 0, sizeof(vis));
      for (int j = 1; j <= n; j++) {
        if (adj[i][j] && i != j && color[j]) {
          vis[color[j]]++;  // mark that I can not be that
                            // color
        }
      }
    }

    // mark me with first not used color
    int s = 1;
    while (vis[s]) s++;
    color[i] = s;
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (!ok) break;
    for (int j = i + 1; j <= n; j++) {
      bool isAdj = ((color[i] == color[j]) && adj[i][j]);
      bool isNotAdj = (color[i] != color[j] && !adj[i][j]);
      if (isAdj || isNotAdj) {
        ok = false;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (color[i] > k) ok = false;
  }
  if (ok) {
    for (int i = 1; i <= n; i++) {
      cout << color[i] << ' ';
    }
    cout << endl;
  } else {
    cout << -1 << endl;  // no solution
  }
}
