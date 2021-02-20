#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 15;
const int maxm = 512;
int sm[maxm][maxn];

int main() {
  //	ios_base::sync_with_stdio(false);
  //	cin.tie(NULL);
  //	cout.tie(NULL);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
      int a;
      scanf("%d", &a);
      int s = 0;
      for (int j = 2; j <= 10; j++) {
        if (a % j == 0) s |= 1 << (j - 2);
      }
      for (int j = 0; j < 512; j++) {
        sm[j][i] = sm[j][i - 1];
        if (j & s) sm[j][i]++;
      }
    }
    while (q--) {
      int l, r, s;
      scanf("%d%d%d", &l, &r, &s);
      if (s & 1)
        printf("%d\n", r - l + 1);
      else {
        int ans = sm[s >> 1][r] - sm[s >> 1][l - 1];
        printf("%d\n", ans);
      }
    }
  }
}
