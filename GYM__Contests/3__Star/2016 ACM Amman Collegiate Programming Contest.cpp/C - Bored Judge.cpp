#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define in insert
#define f first
#define s second
#define sc(x) scanf("%d", &x)
const int N = 100100;
int n, m, arr[N], live[N];
pair<int, int> logs[N];

int main() {
  int t;
  sc(t);
  while (t--) {
    sc(n);
    sc(m);
    for (int i = 0; i < m; ++i) sc(logs[i].first), sc(logs[i].second);

    set<pair<int, int> > st;
    for (int i = 1; i <= n; ++i) live[i] = 0, st.insert({live[i], -i});
    vector<int> winners;
    winners.push_back(-1);
    for (int i = 0; i < m; ++i) {
      int x = logs[i].first;
      int y = logs[i].second;
      st.erase({live[x], -x});
      live[x] += y;
      st.insert({live[x], -x});
      winners.push_back(st.rbegin()->second);
    }
    int ans = 0;
    for (int i = winners.size() - 2; ~i; --i)
      if (winners[i] != winners[i + 1]) {
        ans = i + 1;
        break;
      }

    cout << ans << endl;
  }
}
/*
2
2 2 >^<v>^^<v
3 4 >^<^vv<>v<<v

1
5 7
4 5
3 4
2 1
1 10
4 8
3 -5
4 2

*/
