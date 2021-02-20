#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define ll long long
#define f first
#define s second

const ll MOD = 998244353;

int n, k, x;
ll dp[1005][1005];
map<int, int> f;
vector<int> v;

ll solve(int ind = 0, int cnt = 0) {
  if (ind == n) return cnt == k;
  ll& ret = dp[ind][cnt];
  if (~ret) return ret;
  return ret =
             (solve(ind + 1, cnt) + (v[ind] * solve(ind + 1, cnt + 1)) % MOD) %
             MOD;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#endif
  memset(dp, -1, sizeof dp);

  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &x), ++f[x];
  n = sz(f);
  for (auto& e : f) v.push_back(e.s);
  printf("%lld\n", solve());
}
