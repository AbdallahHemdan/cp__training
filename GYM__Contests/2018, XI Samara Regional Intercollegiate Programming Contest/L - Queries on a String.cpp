// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

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

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0; // equal
  return (a < b) ? -1 : 1;
}

const int MAXN = 2e5 + 25;
int allLst[MAXN];

vector<int> frq[30];

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  string s;
  cin >> s;

  for (int i = 0; i < s.sz; i++) {
    frq[s[i] - 'a'].push_back(i);
  }

  int q;
  cin >> q;

  int lst = -1;
  int curSize = 0;
  allLst[0] = lst;

  while (q--) {
    string op;
    cin >> op;

    if (op == "push") {
      char x;
      cin >> x;

      auto it = upper_bound(frq[x - 'a'].begin(), frq[x - 'a'].end(), lst);

      if (it == frq[x - 'a'].end()) {
        cout << "NO" << endl;
        lst = INT_MAX;
      } else {
        lst = *it;
        cout << "YES" << endl;
      }

      curSize++;
      allLst[curSize] = lst;
    } else {
      curSize--;
      lst = allLst[curSize];

      if (lst <= int(s.size())) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
