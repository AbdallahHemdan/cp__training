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

int n, m, d;
vector<vector<char>> g;
vector<vector<bool>> vis;

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  cin >> n >> m >> d;

  g.resize(n, vector<char>(m));
  vis.resize(n, vector<bool>(m));

  pair<int, int> s, e;
  queue<pair<int, pair<int, int>>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      if (g[i][j] == 'S') {
        s = {i, j};
      } else if (g[i][j] == 'F') {
        e = {i, j};
      } else if (g[i][j] == 'M') {
        q.push({0, {i, j}});
      }
    }
  }

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    int dt = u.first;
    int i = u.second.first;
    int j = u.second.second;

    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int nx = i + dx[k];
      int ny = j + dy[k];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || dt >= d) continue;
      vis[nx][ny] = true;
      q.push({dt + 1, {nx, ny}});
    }
  }


  bool killed = false;
  if (vis[s.first][s.second]) {
    killed = true;
  }

  while (!q.empty()) q.pop();

  int ret = -1;
  q.push({0, s});
  while (!q.empty() && !killed) {
    auto u = q.front();
    q.pop();

    if (u.second == e) {
      ret = u.first;
      break;
    }

    int dt = u.first;
    int i = u.second.first;
    int j = u.second.second;
    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
      int nx = i + dx[k];
      int ny = j + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
      vis[nx][ny] = true;
      q.push({dt + 1, {nx, ny}});
    }
  }


  cout << ret << endl;
}
