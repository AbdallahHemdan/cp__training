// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

const int LOG = 33;
const int N = 2e5 + 25;

int n, q;
int par[N][LOG];


/**
 * Applying for Successor (Functional) graph
 * Directed graphs in which every vertex has exactly one outgoing edge.
 *
 * Since each node of a successor graph has a unique successor, we can also
 * define a function succ(x,k) that gives the node that we will reach if we begin at
 * node x and walk k steps forward.
 *
 *  lvl  |     x     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
 * i = 0 | succ(x,1) | 3 | 5 | 7 | 6 | 2 | 2 | 1 | 6 | 3
 * i = 1 | succ(x,2) | 7 | 2 | 1 | 2 | 5 | 5 | 3 | 2 | 7
 * i = 2 | succ(x,4) | 3 | 2 | 7 | 2 | 5 | 5 | 1 | 2 | 3
 * i = 3 | succ(x,8) | 7 | 2 | 1 | 2 | 5 | 5 | 3 | 2 | 7
 *
 **/
int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> par[i][0];
    par[i][0]--;
  }

  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i < n; i++) {
      par[i][j] = par[par[i][j - 1]][j - 1];
    }
  }

  auto succ = [](int x, int k) {
    x--;

    for (int i = 0; i < LOG; i++) {
      if (k & (1LL << i)) {
        x = par[x][i];
      }
    }

    return x + 1;
  };

  while (q--) {
    int x, k;
    cin >> x >> k;

    cout << succ(x, k) << endl;
  }
}