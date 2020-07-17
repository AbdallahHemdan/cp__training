// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pii pair<int, int>
#define IO \
  ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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

// #Long Multiply
string longMult(string s1, string s2) {
  int n1 = s1.sz, n2 = s2.sz;
  if (n1 == 0 || n2 == 0) return "0";
  vi res(n1 + n2, 0);
  int i_n1 = 0, i_n2 = 0;
  for (int i = n1 - 1; i >= 0; i--) {
    int crr = 0, n1 = s1[i] - '0';
    i_n2 = 0;
    for (int j = n2 - 1; j >= 0; j--) {
      int n2 = s2[j] - '0', sumi = n1 * n2 + res[i_n1 + i_n2] + crr;
      crr = sumi / 10;
      res[i_n1 + i_n2] = sumi % 10;
      i_n2++;
    }
    if (crr > 0) res[i_n1 + i_n2] += crr;
    i_n1++;
  }
  int i = res.sz - 1;
  while (i >= 0 && res[i] == 0) i--;
  if (i == -1) return "0";
  string s = "";
  while (i >= 0) s += to_string(res[i--]);
  return s;
}

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#else
// freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  string s, t;
  while (cin >> s >> t) {
    cout << longMult(s, t) << endl;
  }
}
