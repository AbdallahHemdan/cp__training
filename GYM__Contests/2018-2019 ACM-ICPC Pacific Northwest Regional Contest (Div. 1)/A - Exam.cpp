#include <bits/stdc++.h>

using namespace std;
#define sz(x) (int)(x.size())

int n, k;
string s, t;

int main() {
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#endif

  cin >> k >> s >> t;
  n = sz(s);
  int c = 0;
  for (int i = 0; i < n; ++i) c += (s[i] == t[i]);
  cout << n - max(c, k) + min(c, k) << endl;
}
