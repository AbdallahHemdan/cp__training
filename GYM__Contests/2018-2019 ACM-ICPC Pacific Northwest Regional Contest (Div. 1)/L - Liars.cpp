#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 5;

int t, m = -1, n, l, r, a[N], b[N];

bool check(int x) {
  int ret = 0;
  for (int i = 0; i < n; ++i) ret += x >= a[i] && x <= b[i];
  return ret == x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  for (int i = 1; i <= n; ++i)
    if (check(i)) m = i;
  cout << m;
}
