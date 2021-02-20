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
#define _CRT_SECURE_NO_WARNINGS
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
#define ep emplace_back
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
#define IO                 \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define Ceil(x, y) ((x + y - 1) / y)
#define lop(i, b, e)                                     \
  for (ll i = (b) - ((b) > (e)); i != (e) - ((b) > (e)); \
       i += 1 - 2 * ((b) > (e)))
#define lopi(i, init, n, incr) for (ll i = init; i < n; i += incr)
#define Even(Num) Num % 2 == 0
#define mms(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define SetPre(Ans, num) fixed << setprecision(num) << (Ans)
#define clr clear()
#define re return
#define print(ans) cout << ans << endl
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define pll pair<ll, ll>
#define fix(a, k) (ll(a) % ll(k) + k) % k
#define in insert
#define sc(n) cin >> n
#define sc2(n, m) cin >> n >> m
#define sc3(a, b, c) cin >> a >> b >> c
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))  // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) \
  ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define posOfFirstSetBit(n) (log2(n & -n) + 1);

typedef long long int ll;
typedef long double ld;
typedef int8_t i8;
typedef uint8_t ui8;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;

#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#ifdef _WIN64
#define __builtin_popcountll __popcnt64
#else
inline int __builtin_popcountll(__int64 a) {
  return __builtin_popcount((ui32)a) + __builtin_popcount(a >> 32);
}
#endif
#endif

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAXN = 1e5 + 9;
const int MAX_N = 2;
const int oo = INT_MAX;
const ll OO = 1e18;

const int alldx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int alldy[] = {0, 1, 0, -1, 1, 1, -1, -1};

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

using namespace std;

ll GCD(ll a, ll b) { re((!b) ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { re a / (GCD(a, b)) * b; }
ll nCr(ll n, ll r) {
  if (n < r) re 0;
  if (r == 0) re 1;
  re n* nCr(n - 1, r - 1) / r;
}
ll PowMod(ll bs, ll ex, ll M) {
  if (!ex) re 1;
  ll p = PowMod((bs * bs) % M, ex >> 1, M);
  re(ex & 1) ? (p * bs) % M : p;
}
ll ModInverse(ll a) { re PowMod(a, MOD - 2, MOD); }
ll ExtGCD(ll a, ll b, ll& x, ll& y) {
  if (!b) {
    x = 1;
    y = 0;
    re a;
  }
  ll r = ExtGCD(b, a % b, y, x);
  y -= a / b * x;
  re r;
}
ll mult(ll a, ll b) { re(1LL * a * b) % MOD; }
bool isPrime(ll n) {
  if (n == 2) re 1;
  if (n < 2 || n % 2 == 0) re 0;
  for (ll i = 3; i * i <= n; i += 2)
    if (n % i == 0) re 0;
  re 1;
}
bool isPalindrome(string str) {
  ll l = 0;
  ll h = str.sz - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      re 0;
    }
  }
  re 1;
}
//#Of Even=(R-L+1)-odd(L,R)
ll NoOfOdd(ll L, ll R) {
  ll N = (R - L) / 2;
  if (R % 2 != 0 || L % 2 != 0) N++;
  re N;
}
bool isPerfectSquare(ld x) {
  ld sr = sqrt(x);
  re((sr - floor(sr)) == 0);
}

int main() {
  int T;
  scanf("%d", &T);
  int a, b;
  char c[5];
  while (T--) {
    scanf("%d%s%d", &a, c, &b);
    if (strlen(c) == 1) {
      if (c[0] == '<')
        printf("%s\n", (a < b ? "true" : "false"));
      else
        printf("%s\n", (a > b ? "true" : "false"));
    } else {
      if (c[0] == '!')
        printf("%s\n", (a != b ? "true" : "false"));
      else if (c[0] == '=')
        printf("%s\n", (a == b ? "true" : "false"));
      else if (c[0] == '<')
        printf("%s\n", (a <= b ? "true" : "false"));
      else
        printf("%s\n", (a >= b ? "true" : "false"));
    }
  }
}
