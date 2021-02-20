#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e2 + 5;

int t, m, n, l, r, x[2], y[2], u, v;

double dist(double x0, double y0, double x1, double y1) {
  double x = x0 - x1, y = y0 - y1;
  return sqrt(x * x + y * y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> u >> v >> x[0] >> y[0] >> x[1] >> y[1];
  double ans = 1e7;
  if (u >= x[0] && u <= x[1]) ans = min(abs(v - y[0]), abs(v - y[1]));
  if (v >= y[0] && v <= y[1]) ans = min(abs(u - x[0]), abs(u - x[1]));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) ans = min(ans, dist(u, v, x[i], y[j]));
  }
  cout << fixed << setprecision(3) << ans;
}
