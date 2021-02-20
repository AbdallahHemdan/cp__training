#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define ll long long
#define f first
#define s second

const ll MOD = 1e9 + 9;

int k, b;
ll dp[150][1005][150];

ll solve(int ind = 0, int md = 0, int take = 0) {
  if (ind == b) return !md * take;
  ll& ret = dp[ind][md][take];
  if (~ret) return ret;
  return ret = (solve(ind + 1, (md << 1) % k, take) +
                solve(ind + 1, ((md << 1) + 1) % k, take + 1)) %
               MOD;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#endif

  memset(dp, -1, sizeof dp);
  scanf("%d%d", &k, &b);
  printf("%lld\n", solve());
}
