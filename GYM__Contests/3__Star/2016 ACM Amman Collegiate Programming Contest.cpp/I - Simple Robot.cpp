#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define in insert
#define f first
//#define s second

const int oo = 1e9;
const int N = 2e5 + 10;

int n, m, l, t;
char str[N];

int Calc(const vector<int>& s, int idx, int siz) {
  int ret = 0;
  int cur = idx;
  for (auto& e : s) {
    cur += e;
    if (cur > siz || !cur) cur -= e, ++ret;
  }
  return ret;
}

int solve(const vector<int>& s, int siz) {
  int st = 1, ed = siz;
  while (ed - st > 15) {
    int m1 = st + (ed - st) / 3;
    int m2 = ed - (ed - st) / 3;
    if (Calc(s, m1, siz) < Calc(s, m2, siz))
      ed = m2;
    else
      st = m1;
  }
  int ret = oo;
  for (int i = st; i <= ed; ++i) ret = min(ret, Calc(s, i, siz));
  return ret;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%s", &n, &m, str);
    l = strlen(str);
    vector<int> v, h;
    for (int i = 0; i < l; ++i) {
      if (str[i] == '>')
        v.pb(1);
      else if (str[i] == '<')
        v.pb(-1);
      else {
        if (str[i] == '^')
          h.pb(1);
        else
          h.pb(-1);
      }
    }
    printf("%d\n", solve(v, m) + solve(h, n));
  }
}
