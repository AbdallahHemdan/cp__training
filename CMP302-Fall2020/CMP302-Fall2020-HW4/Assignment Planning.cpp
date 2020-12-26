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

int main() {
  IO;
  int n;
  cin >> n;
  set<int> no_vis;
  for (int i = 1; i <= n; i++) no_vis.insert(i);

  vector<pair<ll, ll>> time_pen(n);


  for (auto &i : time_pen) cin >> i.first;
  for (auto &i : time_pen) cin >> i.second;

  sort(all(time_pen), [](pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
  });

  int t = 1;
  multiset<pair<ll, ll>> delayed;
  multiset<pair<ll, ll>> processed;
  for (int i = 0; i < n; i++) {
    if (time_pen[i].first < t) { // will be delayed
      delayed.insert(time_pen[i]);
    } else {
      processed.insert({time_pen[i].second, time_pen[i].first});
      no_vis.erase(no_vis.begin());
      t++;
    }
  }

  ll ret = 0;
  for (auto i : delayed) {
    ret += i.second;
  }


  for (auto i : delayed) {
    // empty time slot before me
    if (*no_vis.begin() <= i.first) {
      ret -= i.second;
      no_vis.erase(no_vis.begin());
    }

    // task with less penalty

    // processed.first => pen, processed.second => time
    for (auto j : processed) {
      if (j.first < i.second && j.second <= i.first) {
        ret = ret - i.second + j.first;

        processed.erase(j);
        processed.insert(make_pair(i.second, i.first));
        break;
      }
    }
  }

  cout << ret << endl;
}
