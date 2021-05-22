// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define endl '\n'
#define sz size()
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define IO \
  ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const ll OO = 1e18;
const int oo = INT_MAX;
const double EPS = 1e-9;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }

ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }

double distance(double x1, double y1, double x2, double y2) {
  return hypot(fabs(x1 - x2), fabs(y1 - y2));
}

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0;  // equal
  return (a < b) ? -1 : 1;
}

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  ld c;
  cin >> c;

  ld ret = 0.0;
  ld l = 0.0, r = 1e9;

  for (int i = 0; i < 100; ++i) {
    ld mid = l + (r - l) / 2.0;

    if (mid * mid + sqrt(mid) - c + EPS >= 0) {
      ret = mid;
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << fixed << setprecision(9) << ret << endl;
}
