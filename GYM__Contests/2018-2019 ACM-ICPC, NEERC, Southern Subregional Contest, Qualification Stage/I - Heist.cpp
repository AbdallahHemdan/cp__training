/*Author : Abdallah Hemdan */
/**************************/
/*Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
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
#define re return
#define print(ans) cout << ans << endl
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define fix(a, k) (ll(a) % ll(k) + k) % k
#define in insert
typedef long long int ll;
typedef long double ld;

const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 9;
const int OO = INT_MAX;

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

using namespace std;

int main() {
  IO;
  int n;
  cin >> n;
  vll arr(n);
  ll mn = OO, mx = -OO;
  lop(i, 0, n) {
    ll a;
    cin >> a;
    mn = min(a, mn);
    mx = max(a, mx);
  }
  print(mx - mn + 1 - n);
}
