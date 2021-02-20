#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int t, m, n, l, r, vis[N], a[N], x;
multiset<int> s;
ll ax, bx;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    s.insert(a[i]);
    if (x) {
      bx += *s.begin();
      s.erase(s.begin());
      x--;
    } else
      x++;
  }
  for (auto i : s) ax += i;
  cout << ax << " " << bx;
}
