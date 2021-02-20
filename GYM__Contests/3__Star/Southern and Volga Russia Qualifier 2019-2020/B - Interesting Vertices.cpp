#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, k, x, y;
bool a[N << 1];
vector<int> ver[N << 1], ans;

int solve(int no = 1, int par = 0) {
  bool f = 1;
  int tot = a[no];
  for (auto& e : ver[no]) {
    if (e == par) continue;
    int cur = solve(e, no);
    if (!cur) f = 0;
    tot += cur;
  }

  if (f && !a[no] && (no == 1 || k - tot)) ans.push_back(no);
  return tot;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#endif

  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) scanf("%d", &x), a[x] = 1;
  for (int i = 1; i < n; ++i)
    scanf("%d%d", &x, &y), ver[x].push_back(y), ver[y].push_back(x);
  solve();
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
}
