/*Author : Abdallah Hemdan */
/**************************/
/*Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code coMPiles and gets accepted.
 *  ___   __
 * |\  \|\  \
 * \ \  \_\  \
 *  \ \   ___ \emdan
 *   \ \  \\ \ \
 *    \ \__\\ \_\
 *     \|__| \|__|
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define MP make_pair
#define PB push_back
#define endl '\n'
#define xx first
#define yy second
#define sz size()
#define len length()
#define vi vector<int>
#define vll vector<ll>
#define ul unsigned long
#define vs vector<string>
#define si set<int>
#define sll set<ll>
#define ss set<string>
#define f first
#define s second
#define IO                 \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define Ceil(x, y) ((x + y - 1) / y)
#define lop(i, init, n) for (ll i = init; i < n; ++i)
#define lopi(i, init, n, incr) for (ll i = init; i < n; i += incr)
#define Even(Num) Num % 2 == 0
#define mms(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define SetPre(Ans, num) fixed << setprecision(num) << (Ans)
#define clr clear()
#define re return
#define print(ans) cout << ans << endl
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define pll pair<ll, ll>
#define fix(a, k) (ll(a) % ll(k) + k) % k
#define pii pair<ll, ll>
#define ppi pair<ll, pii>
#define in insert
#define sc(n) cin >> n
typedef long long int ll;
typedef long double ld;

const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

using namespace std;

ll GCD(ll a, ll b) { re((!b) ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { re a / (GCD(a, b)) * b; }

int s, p, mx;
vector<ppi> a[MAXN];
void init(int n) {
  for (int i = 0; i < n + 1; i++) a[i].clear();
}
ll dijkstra(int MW) {
  vector<ll> cost(MAXN, INT_MAX);
  vector<ll> mw(MAXN, INT_MAX);
  cost[s] = 0;
  mw[s] = 0;
  set<pair<ll, ll>> index;
  index.insert({0, s});

  while (!index.empty()) {
    int cur = index.begin()->second;
    if (cur == p) return cost[cur];
    index.erase(index.begin());
    for (auto edge : a[cur]) {
      ll tar = edge.f, c = edge.s.f, w = edge.s.s;
      if (cost[tar] > cost[cur] + c && max(mw[cur], w) <= MW) {
        mw[tar] = min(mw[tar], max(mw[cur], w));
        index.erase({cost[tar], tar});
        cost[tar] = cost[cur] + c;
        index.insert({cost[tar], tar});
      }
    }
  }
  return cost[p];
}

int main() {
  int v1, v2, w, n, c, m, wmax = 0, wmin = 1 << 30, T;
  cin >> T;
  while (T--) {
    scanf("%d%d%d", &n, &m, &mx);
    init(n);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d%d", &v1, &v2, &c, &w);
      wmax = max(wmax, w);
      wmin = min(wmin, w);
      a[v1 - 1].PB(MP(v2 - 1, MP(c, w)));
      a[v2 - 1].PB(MP(v1 - 1, MP(c, w)));
    }
    s = 0;
    p = n - 1;
    wmax += 10;
    wmin -= 10;
    int i;
    while (wmin != wmax) {
      i = (wmin + wmax) / 2;
      ll x = dijkstra(i);
      if (x >= mx)
        wmin = i + 1;
      else
        wmax = i;
    }
    printf("%d\n", (dijkstra(wmin) >= mx ? -1 : wmin));
  }
}
