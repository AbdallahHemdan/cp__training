#include <bits/stdc++.h>

using namespace std;

int a[3], k[3], m;
vector<int> v;

int solve1(int ind) {
  int tmp = m;
  int r1 = min(a[ind], tmp / k[ind]);
  tmp -= r1 * k[ind];
  int r2 = min(a[!ind], tmp / k[!ind]);
  return r1 + r2;
}

int solve2() {
  int tmp = m;
  tmp -= (a[0] * (k[0] - 1) + a[1] * (k[1] - 1));
  return min(max(tmp, 0), a[0] + a[1]);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#endif

  scanf("%d%d", a, a + 1);
  scanf("%d%d", k, k + 1);
  scanf("%d", &m);
  if (k[0] > k[1]) swap(k[0], k[1]), swap(a[0], a[1]);
  int mx = solve1(0);
  int mn = solve2();
  printf("%d %d\n", mn, mx);
}
