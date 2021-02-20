#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define in insert
#define f first
#define s second
#define sc(x) scanf("%d", &x)
const int MOD = 1000000007;
int dp[155][15005][2], arr[2][155], n[2], vis[155][15005][2], vid, k, w;
int solve(int i, int rem, int f) {
  if (rem < 0) return 0;
  if (i == n[f]) return (rem == 0);
  int& ret = dp[i][rem][f];
  if (vis[i][rem][f] == vid) return ret;
  vis[i][rem][f] = vid;
  return ret = (solve(i + 1, rem - arr[f][i], f) + solve(i + 1, rem, f)) % MOD;
}
int main() {
  int t;
  sc(t);
  while (t--) {
    for (int i = 0; i < 2; ++i) sc(n[i]);
    sc(k);
    sc(w);
    for (int i = 0; i < n[0]; ++i) sc(arr[0][i]);
    for (int i = 0; i < n[1]; ++i) sc(arr[1][i]);
    ++vid;
    ll ans = 0;
    for (int i = 0; i <= w; ++i) {
      int s1 = i, s2 = w - i;
      if (abs(s1 - s2) > k) continue;
      ans += solve(0, s1, 0) * 1ll * solve(0, s2, 1);
      ans %= MOD;
    }
    printf("%lld\n", ans);
  }
}
/*
2
2 2 >^<v>^^<v
3 4 >^<^vv<>v<<v

2
4 3 5 18
2 3 4 1
10 5 5
2 1 20 20
10 30
50

*/
