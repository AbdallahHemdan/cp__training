#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int t, n, mx;
string s[2];
vector<int> v[2];
vector<pair<int, int>> ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> s[0] >> s[1];
  for (int i = 0; i < n; ++i) {
    t += (s[0][i] == 'b') + (s[1][i] == 'b');
    if (s[0][i] == s[1][i]) continue;
    v[s[0][i] == 'b'].push_back(i + 1);
  }
  if (t & 1) return cout << -1, 0;
  if (v[0].size() & 1) {
    ans.push_back({v[0].back(), v[0].back()});
    ans.push_back({v[0].back(), v[1].back()});
    v[0].pop_back(), v[1].pop_back();
  }
  for (int j = 0; j < 2; ++j) {
    for (int i = 1; i < v[j].size(); i += 2)
      ans.push_back({v[j][i - 1], v[j][i]});
  }
  cout << ans.size() << endl;
  for (auto i : ans) cout << i.first << " " << i.second << endl;
}
