const int maxn = 51;

int n;
int dp[maxn][5];

int solve(int i, int lst) {
  if (i == n) return 1;

  int &ret = dp[i][lst];
  if (~ret) return ret;

  ret = solve(i + 1, lst);
  if (lst < 4) {
    ret += solve(i, lst + 1);
  }
  return ret;
}

class Solution {
public:
    int countVowelStrings(int _n) {
        n = _n;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
        
    }
};
