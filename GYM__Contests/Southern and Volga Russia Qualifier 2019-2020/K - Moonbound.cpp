#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int t, n, a[60][60], m = n * n;
vector<pair<pair<int, int>, int>> ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i += 2) {
    a[i][1] = a[i + 1][n] = 1;
    a[1][i] = a[n][i + 1] = 1;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (a[i][j]) ans.push_back({{i, j}, 1}), m--;
  for (int i = n - 1; i > 0; i -= 2) {
    for (int j = 1; j <= n; j += 2) {
      ans.push_back({{i, j}, 2});
      if (i - 1 > 0 && !a[i - 1][j + 1]) ans.push_back({{i - 1, j + 1}, 1});
      if (j + 2 <= n && !a[i][j + 2]) ans.push_back({{i, j + 2}, 1});
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans)
    cout << i.second << " " << i.first.first << " " << i.first.second << " "
         << i.second << endl;
}
