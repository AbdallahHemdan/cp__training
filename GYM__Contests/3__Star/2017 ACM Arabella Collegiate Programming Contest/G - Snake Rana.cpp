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
  int t;
  cin >> t;
  while (t--) {
    ll n, m, k;
    cin >> n >> m >> k;

    ll tot = n * (n + 1) * m * (m + 1);
    tot /= 4LL;

    vector<pair<ll, ll>> a(k);
    for (auto &i : a) cin >> i.first >> i.second;

    for (ll mask = 1; mask < (1 << k); mask++) {
      ll frq = 0;
      ll mnX = LLONG_MAX, mnY = LLONG_MAX;
      ll mxX = LLONG_MIN, mxY = LLONG_MIN;

      for (int j = 0; j < k; ++j) {
        if (mask & (1 << j)) {
          frq++;
          mnX = min(mnX, a[j].first);
          mnY = min(mnY, a[j].second);

          mxX = max(mxX, a[j].first);
          mxY = max(mxY, a[j].second);
        }
      }

      ll ret = mnX * mnY * (n - mxX + 1LL) * (m - mxY + 1LL);
      if (frq & 1) {
        tot -= ret;
      } else {
        tot += ret;
      }
    }
    cout << tot << endl;
  }
}
