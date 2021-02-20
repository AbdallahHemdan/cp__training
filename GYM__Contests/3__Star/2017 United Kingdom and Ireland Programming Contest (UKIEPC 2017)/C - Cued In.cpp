// Author : Abdallah Hemdan
// Server time : Sep / 16 / 2019 18 : 14 : 17UTC + 2 (f2).
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
using namespace std;
using ll = long long int;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#else
  // freopen("input.in","r",stdin);
  // freopen("output.out","w",stdout);
#endif
  map<string, int> mp;
  mp["red"] = 1;
  mp["yellow"] = 2;
  mp["green"] = 3;
  mp["brown"] = 4;
  mp["blue"] = 5;
  mp["pink"] = 6;
  mp["black"] = 7;
  map<string, bool> found;
  int n;
  cin >> n;
  int frq = 0;
  ll sm = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    found[s] = 1;
    if (s == "red")
      frq++;
    else
      sm += mp[s];
  }
  int mx = -1;
  for (auto i : found) {
    if (i.second) {
      if (mp[i.first] > mx) mx = mp[i.first];
    }
  }
  if (frq == n)
    sm = 1;
  else
    sm += frq + frq * mx;
  cout << sm << endl;
}
