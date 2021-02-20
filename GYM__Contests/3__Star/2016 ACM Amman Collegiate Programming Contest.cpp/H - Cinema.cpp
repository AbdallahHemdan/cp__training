#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define in insert
#define f first
#define s second

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    int c = 0;
    bool ff = 0;
    for (auto& e : s) {
      if (e == '1')
        c = 0;
      else
        ++c;
      if (c == m + 1) {
        ff = 1;
        break;
      }
    }
    if (ff)
      puts("yes");
    else
      puts("no");
  }
}
