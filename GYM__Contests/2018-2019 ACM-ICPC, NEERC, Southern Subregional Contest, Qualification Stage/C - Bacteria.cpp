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
#define isPowerOfTwo(S) (!(S & (S - 1)))

using namespace std;
using ll = long long int;
using ld = long double;

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
  ll n;
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    pq.push(x);
  }

  ll ret = 0;
  ll fail = 0;
  while (pq.size() != 1) {
    ll u = pq.top();
    pq.pop();
    ll v = pq.top();
    pq.pop();

    if (u == v) {
      pq.push(2 * u);
    } else {
      ll mx = max(u, v);
      ll mn = min(u, v);
      if (mx % mn == 0) {
        ret += ll(log2(mx)) - ll(log2(mn));
        pq.push(mx * 2);
      } else {
        fail = 1;
        break;
      }
    }
  }
  if (fail) {
    cout << -1 << endl;
  } else {
    cout << ret << endl;
  }
}
