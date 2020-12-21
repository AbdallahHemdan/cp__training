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

string p;
const int N = 1e6 + 6;
int F[N];

int failure(char c, int k) {
  while (k > 0 && c != p[k]) {
    k = F[k - 1];
  }
  return k + (c == p[k]);
}

void computeFailure() {
  int k = 0;
  for (int i = 1; i < p.size(); i++) {
    k = F[i] = failure(p[i], k);
  }
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
  cin >> p;
  computeFailure();
  int cnt = 0;
  for (int i = 0; i < p.size(); i++) {
    if (F[i] == F[p.size() - 1]) cnt++;
  }

  int mx = 0;
  int n = p.size();
  int len = F[n - 1];

  for (int i = 0; i < n - 1; i++) mx = max(mx, F[i]);
  while (len > mx) len = F[len - 1];

  if (len) {
    cout << p.substr(0, len) << endl;
  } else {
    cout << "Just a legend" << endl;
  }
}