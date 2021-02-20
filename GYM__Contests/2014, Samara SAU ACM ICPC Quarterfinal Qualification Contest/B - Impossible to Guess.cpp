#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e2 + 5;

int t, m, n, l, r, ans[N], alt[N], x, gt[N], a[N];
vector<int> vec[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  m = (n - 1) / 2;
  if (n < 3) {
    cout << "Q 1 1" << endl;
    cin >> m;
    cout << "A " << m;
    if (n == 2) cout << " " << 3 - m;
    cout << endl;
    return 0;
  }
  while (m--) {
    ++l;
    cout << "Q " << l + 1 << " " << n - l << endl;
    memset(gt, 0, sizeof(gt));
    for (int i = 0; i < n - 2 * l; ++i) cin >> x, gt[x] = 1, a[i] = x;
    for (int i = 1; i <= n; ++i)
      if (!gt[i] && !alt[i]) vec[l].push_back(i), alt[i] = 1;
  }
  if (!(n & 1))
    vec[++l].push_back(a[0]), vec[l].push_back(a[1]);
  else
    ans[(n + 1) / 2] = a[0];
  cout << "Q 1 " << l << endl;
  for (int i = 0; i < l; ++i) cin >> a[i];
  for (int i = 1; i <= l; ++i) {
    for (int j = 0; j < l; ++j) {
      if (a[j] == vec[i][0]) ans[i] = vec[i][0], ans[n - i + 1] = vec[i][1];
      if (a[j] == vec[i][1]) ans[i] = vec[i][1], ans[n - i + 1] = vec[i][0];
    }
  }
  cout << "A ";
  for (int i = 1; i < n; ++i) cout << ans[i] << " ";
  cout << ans[n] << endl;
}
