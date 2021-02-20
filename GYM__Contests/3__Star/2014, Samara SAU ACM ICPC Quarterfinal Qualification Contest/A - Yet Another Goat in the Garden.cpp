// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define IO \
  ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define pi acos(-1)

using namespace std;
using ll = long long int;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;
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
#else
  // freopen("input.in","r",stdin);
  // freopen("output.out","w",stdout);
#endif
  ll a, b, c, r;
  cin >> a >> b >> c >> r;
  double cir = a + b + c;
  double half = cir / 2;

  double triArea = sqrt(half * (half - a) * (half - b) *
                        (half - c));  // total area of triangle

  double cosA = acos((b * b + c * c - a * a) / (2.0 * b * c));
  double cosB = acos((a * a + c * c - b * b) / (2.0 * a * c));
  double cosC = acos((b * b + a * a - c * c) / (2.0 * a * b));

  double s1 = r * r *
              ((1.0 / tan(cosC / 2.0) -
                (pi - (double)cosC) / 2.0));  // first corner surface
  double s2 = r * r *
              ((1.0 / tan(cosA / 2.0) -
                (pi - (double)cosA) / 2.0));  // second corner surface
  double s3 = r * r *
              ((1.0 / tan(cosB / 2.0) -
                (pi - (double)cosB) / 2.0));  // third corner surface

  double ret = (s1 + s2 + s3) / triArea;
  ret = 1 - ret;
  cout << fixed << setprecision(10) << ret << endl;
}
