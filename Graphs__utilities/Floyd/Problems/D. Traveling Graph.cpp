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
const int N = 16;
const int MaskN = (1 << N) + 1;
int in[N];
int vis[N];
vector<int> adj[N];

ll tot;
ll dp[N][N];
ll dp2[MaskN];


void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

ll solve(ll mask) {
  if (mask == 0) return 0;
  ll &ret = dp2[mask];
  if (~ret) return ret;
  ret = OO;

  for (int i = 0; i < n; i++) {
    if (mask & (1 << i)) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (mask & (1 << j)) {
          ret = min(ret, solve(mask - (1 << i) - (1 << j)) + dp[i][j]);
        }

      }
    }
  }
  return ret;
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
  memset(dp, 0x3f, sizeof(dp));

  for (int i = 0; i < m; i++) {
    int u, v, c;

    cin >> u >> v >> c;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);

    tot += c;
    if (u != v) {
      dp[u][v] = dp[v][u] = min(dp[u][v], 1LL * c);
      in[u]++, in[v]++;
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  dfs(0);
  
  for (int i = 0; i < n; i++) {
    if (adj[i].size() && !vis[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }

  ll msk = 0;
  for (int i = 0; i < n; i++) {
    if (in[i] & 1) {
      msk |= (1 << i);
    }
  }
  memset(dp2, -1, sizeof(dp2));
  tot += solve(msk);
  cout << tot << endl;
}