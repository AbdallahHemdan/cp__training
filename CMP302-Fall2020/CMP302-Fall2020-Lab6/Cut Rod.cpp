// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define endl '\n'
#define sz size()
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

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

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0; // equal
  return (a < b) ? -1 : 1;
}

int n, m;
const int N = 1e4 + 4;
int a[N];
int dp[N][N];

int solve(int l, int r) {
  int &ret = dp[l][r];
  if (~ret) return ret;

  ret = INT_MAX;
  for (int i = 1; i <= m; i++) {
    if (i > l && i < r) {
      ret = min(ret, (a[r] - a[l]) + solve(l, i) + solve(i, r));
    }
  }

  return ret = ret == INT_MAX ? 0 : ret;
}

int main() {
  IO;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }

  a[0] = 0;
  a[m + 1] = n;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, m + 1) << endl;
}
