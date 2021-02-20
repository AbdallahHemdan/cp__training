#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int t, n, mx = 1e8, k, fi, ti;
string s[2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k >> s[1] >> s[0];
  for (int j = 0; j < 2; ++j) {
    for (int i = 0; i < n; ++i) {
      int lt = 0;
      for (int y = 0; y < 2; y++) {
        for (int x = 0; x < n; x++) {
          if (s[y][x] == '0') continue;
          if (y == j)
            lt = max(lt, abs(x - i));
          else
            lt = max(lt, x + i + 2 + k);
        }
      }
      if (lt < mx) mx = lt, fi = j + 1, ti = i + 1;
    }
  }
  cout << mx << endl << fi << " " << ti;
}
