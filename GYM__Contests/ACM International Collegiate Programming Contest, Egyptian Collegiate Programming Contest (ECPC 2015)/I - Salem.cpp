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
#define clr clear()
#define re return
#define print(ans) cout << ans << endl
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define pll pair<ll, ll>
#define fix(a, k) (ll(a) % ll(k) + k) % k
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

string GetBin(ll n) {
  string s = "";
  while (n) {
    s += (n % 2 ? '1' : '0');
    n /= 2;
  }
  re s;
}

int getdiff(string s, string t) {
  int counter = 0;
  if (t.length() > s.length()) swap(s, t);
  for (int i = 0; i < t.length(); i++) {
    if (s[i] != t[i]) counter++;
  }
  lop(i, t.length(), s.length()) counter += (s[i] == '1' ? 1 : 0);
  return counter;
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  IO;
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vll arr(n);
    lop(i, 0, n) cin >> arr[i];
    vector<string> binary(n);
    lop(i, 0, n) { binary[i] = GetBin(arr[i]); }
    ll mx = -OO;
    lop(i, 0, n) {
      lop(j, i + 1, n) {
        ll ans = getdiff(binary[i], binary[j]);
        mx = max(mx, ans);
      }
    }
    print(mx);
  }
}
