#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define ll long long
#define f first
#define s second

const int N = 1e6 + 5;

vector<int> di;
bool nPrime[N];
int n, ans;

void sieve() {
  for (ll i = 2; i < N; ++i)
    if (!nPrime[i]) {
      di.push_back(i);
      for (ll j = i * i; j < N; j += i) nPrime[j] = 1;
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#endif

  sieve();
  scanf("%d", &n);
  while (n >= 4) {
    for (auto& e : di)
      if (!nPrime[n - e]) {
        n -= (e << 1);
        break;
      }
    ++ans;
  }
  printf("%d\n", ans);
}
