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
  string s;
  cin >> s;
  string t = s;
  sort(all(t));

  set<int> st[30];
  for (int i = 0; i < s.sz; i++) {
    st[t[i] - 'a'].insert(i);
  }

  for (int i = 0; i < s.sz; i++) {
    if (s[i] != t[i]) {
      auto ind = st[s[i] - 'a'].upper_bound(i);
      if (s[i] <= t[i])
        cout << i + 1 << ' ' << *ind + 1 << endl;
      else
        cout << *ind + 1 << ' ' << i + 1 << endl;
      int ne = (*ind);
      st[t[i] - 'a'].insert(*ind);
      st[t[i] - 'a'].erase(i);
      st[s[i] - 'a'].erase(*ind);
      swap(t[i], t[ne]);
    }
  }
}
