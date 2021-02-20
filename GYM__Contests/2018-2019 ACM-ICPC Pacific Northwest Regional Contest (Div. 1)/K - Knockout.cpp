#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define ll long long
#define f first
#define s second
#define pb push_back

string s;
int a, b, msk, ans;
vector<vector<int>> comb[15];
vector<int> tmp;
double sc, pre[1500];
double dp[1500][15];

void gen(int mx, int cur = 0, int sum = 0) {
  if (sum > mx) return;
  if (sum == mx) {
    comb[mx].push_back(tmp);
    return;
  }
  for (int i = cur + 1; i < 10; ++i)
    tmp.pb(i), gen(mx, i, sum + i), tmp.pop_back();
}

void gen2(int ind = 1, int mask = 0, int val = 0) {
  if (ind > 9) {
    pre[mask] = 1.0 * val;
    return;
  }
  gen2(ind + 1, mask, val);
  gen2(ind + 1, mask | (1 << ind), val * 10 + ind);
}

double solve1(int mask, int sum) {
  double& ret = dp[mask][sum];
  if (ret == ret) return ret;

  ret = 0;
  bool totFlag = 0;
  int retMask = 0;

  for (auto& v : comb[sum]) {
    bool flag = 0;
    int tmpMask = mask;
    for (auto& e : v) {
      if (tmpMask & (1 << e)) {
        tmpMask ^= (1 << e);
        continue;
      }
      flag = 1;
      break;
    }
    if (flag) continue;
    totFlag = 1;
    double tmpRet = 0.0;
    for (int i = 1; i < 7; ++i)
      for (int j = 1; j < 7; ++j) tmpRet += solve1(tmpMask, i + j) / 36.0;

    if (tmpRet > ret) ret = tmpRet, retMask = tmpMask;
  }
  if (!totFlag)
    ret = pre[mask], ans = -1;
  else
    ans = pre[mask ^ retMask];
  return ret;
}

double solve2(int mask, int sum) {
  double& ret = dp[mask][sum];
  if (ret == ret) return ret;

  ret = 1e14;
  bool totFlag = 0;
  int retMask = 0;

  for (auto& v : comb[sum]) {
    bool flag = 0;
    int tmpMask = mask;
    for (auto& e : v) {
      if (tmpMask & (1 << e)) {
        tmpMask ^= (1 << e);
        continue;
      }
      flag = 1;
      break;
    }
    if (flag) continue;
    totFlag = 1;
    double tmpRet = 0.0;
    for (int i = 1; i < 7; ++i)
      for (int j = 1; j < 7; ++j) tmpRet += solve2(tmpMask, i + j) / 36.0;

    if (tmpRet < ret) ret = tmpRet, retMask = tmpMask;
  }
  if (!totFlag)
    ret = pre[mask], ans = -1;
  else
    ans = pre[mask ^ retMask];
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#endif

  cin >> s >> a >> b;
  for (auto& e : s) msk |= 1 << (e - '0');
  for (int i = 1; i < 13; ++i) gen(i);
  gen2();
  memset(dp, -1, sizeof dp);
  sc = solve2(msk, a + b);
  cout << ans << " ";
  cout << fixed << setprecision(5) << sc << endl;
  memset(dp, -1, sizeof dp);
  sc = solve1(msk, a + b);
  cout << ans << " ";
  cout << fixed << setprecision(5) << sc << endl;
}
