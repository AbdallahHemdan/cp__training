#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, x[3], miss[3];
string s;
bool ans;

int main() {
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#endif

  cin >> n >> s;
  int m = n >> 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?')
      ++miss[i / m];
    else
      x[i / m] += (s[i] - '0');
  }
  if (x[1] > x[0]) swap(x[0], x[1]), swap(miss[0], miss[1]);

  int diff = abs(miss[0] - miss[1]);
  if (x[0] == x[1])
    ans = diff > 0;
  else if (miss[0] >= miss[1])
    ans = 1;
  else
    ans = ((diff >> 1) * 9 + x[1]) != x[0];
  puts(ans ? "Monocarp" : "Bicarp");
}
