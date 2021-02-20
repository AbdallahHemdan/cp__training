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
    set<int> st;
    int a, b, n;
    cin >> a >> b >> n;

    int x = 1;
    while (true) {
      int y = a * x * x + b * x;
      if (y <= n) {
        st.insert(y);
        x++;
      } else {
        break;
      }
    }
    if (st.size() == 0) {
      cout << -1 << endl;
    } else {
      int frq[10] = {0};
      for (auto i : st) {
        int dfrq[10] = {0};
        for (auto c : to_string(i)) {
          dfrq[c - '0']++;
        }
        int mx = 0;
        int dmx = -1;

        for (int j = 0; j < 10; j++) {
          if (dfrq[j] > mx) {
            dmx = j;
            mx = dfrq[j];
          }
        }

        for (int j = 0; j < 10; j++) {
          if (dfrq[j] == mx) {
            frq[j]++;
          }
        }
      }
      int mx = 0;
      int dmx = 0;
      for (int i = 0; i < 10; i++) {
        if (frq[i] > mx) {
          dmx = i;
          mx = frq[i];
        }
      }
      cout << dmx << endl;
    }
  }
}
