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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  int mnmode = 1e9, ans = -1;
  int h;
  cin >> h;
  for (int i = 0; i < n; i++) {
    if (h % a[i] < mnmode) {
      mnmode = h % a[i];
      ans = a[i];
    }
  }
  cout << ans << endl;
}
