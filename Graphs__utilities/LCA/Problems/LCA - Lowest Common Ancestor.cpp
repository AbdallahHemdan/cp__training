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
const int N_LOG = 12;
const int N = 1e3 + 13;

int in[N];
int dist[N];
int par[N][N_LOG];
vector<int> adj[N];

void buildLCA(int u) {
  memset(par, -1, sizeof(par));
  memset(dist, -1, sizeof(dist));

  queue<int> q;
  q.push(u);

  dist[u] = 0;
  while (!q.empty()) {
    u = q.front();
    q.pop();

    for (int v  : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        par[v][0] = u;
        q.push(v);

        int curP = u;
        for (int i = 1, j = 2; j <= dist[v]; j <<= 1, i++) {
          curP = par[v][i] = par[curP][i - 1];
        }
      }
    }
  }
}

int getLCA(int u, int v) {
  if (dist[u] > dist[v]) swap(u, v);
  int diffOfDistance = dist[v] - dist[u];

  for (int i = N_LOG, j = (1 << i); j > 0; --i, j = (1 << i)) {
    if (j <= diffOfDistance) {
      v = par[v][i];
      diffOfDistance -= j;
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = N_LOG, j = (1 << i); j > 0; --i, j = (1 << i)) {
    if (dist[u] < j) continue;
    if (par[u][i] == par[v][i]) continue;

    u = par[u][i];
    v = par[v][i];
  }

  return par[u][0];
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
  for (int tt = 1; tt <= t; tt++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      for (int j = 0; j < m; j++) {
        int u;
        cin >> u;
        u--;

        adj[i].push_back(u);
        in[u]++;
      }
    }

    int r = -1;
    for (int i = 0; i < n; i++) {
      if (in[i] == 0) {
        r = i;
        break;
      }
    }
    buildLCA(r);

    int q;
    cin >> q;

    cout << "Case " << tt << ": " << endl;
    while (q--) {
      int u, v;
      cin >> u >> v;
      u--, v--;

      cout << getLCA(u, v) + 1 << endl;
    }
  }
}