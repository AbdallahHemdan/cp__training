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

const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, m, t;
const int N = 55;
char g[N][N];
int vis[N][N];

int dfs(int i, int j, char cur) {
  int ret = 0;
  vis[i][j] = 1;

  for (int k = 0; k < 8; k++) {
    int nx = i + dx[k];
    int ny = j + dy[k];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && g[nx][ny] == char(cur + 1)) {
      ret = max(ret, dfs(nx, ny, char(cur + 1)));
    }
  }
  return ret + 1;
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
  while (true) {
    cin >> n >> m;
    if (!n && !m) break;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> g[i][j];
      }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == 'A') {
          memset(vis, 0, sizeof(vis));
          ret = max(ret, dfs(i, j, g[i][j]));
        }
      }
    }

    cout << "Case " << t++ << ": " << ret << endl;
  }
}