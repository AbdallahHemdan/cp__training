// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define endl '\n'
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
const int N = 1e6 + 6;
using ll = long long int;

int F[N];
string s, p;
vector<int> matches;

int failure(char c, int k) {
  while (k > 0 && c != p[k]) {
    k = F[k - 1];
  }

  return k += (c == p[k]);
}

void computeFailure() {
  int k = 0;
  for (int i = 1; i < p.size(); i++) {
    k = F[i] = failure(p[i], k);
  }
}

void KMP() {
  computeFailure();

  int k = 0;
  for (int i = 0; i < s.size(); i++) {
    k = failure(s[i], k);
    if (k == p.size()) {
      matches.push_back(i - p.size() + 1);
    }
  }
}

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  cin >> s >> p;
  KMP();
  cout << matches.size() << endl;
}