// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
/*Dear online judge:
* I've read the problem, and tried to KMP it.
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
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define MP make_pair
#define PB push_back
#define eb emplace_back
#define endl '\n'
#define xx first
#define yy second
#define sz size()
#define vi vector<int>
#define vll vector<ll>
#define ul unsigned long
#define vs vector<string>
#define si set<int>
#define sll set<ll>
#define IO \
  ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define Ceil(c, y) ((c + y - 1) / y)
#define lop(j, b, e)                                     \
  for (ll j = (b) - ((b) > (e)); j != (e) - ((b) > (e)); \
       j += 1 - 2 * ((b) > (e)))
#define lopi(j, init, n, incr) for (ll j = init; j < n; j += incr)
#define Even(Num) Num % 2 == 0
#define mms(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define SetPre(Ans, num) fixed << setprecision(num) << (Ans)
#define clr clear()
#define re return
#define print(ans) cout << ans << endl
#define prints(ans) cout << ans << " "
#define print2(a, b) cout << a << ' ' << b << endl
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pi acos(-1)
#define fix(a, k) (ll(a) % ll(k) + k) % k
#define in insert
#define sc(n) cin >> n
#define sc2(n, m) cin >> n >> m
#define sc3(a, b, c) cin >> a >> b >> c
#define sc4(a, b, c, d) cin >> a >> b >> c >> d
#define watch(c) cout << (#c) << " is " << (c) << endl
#define stringToLower(s) transform(all(s), s.begin(), ::tolower);
#define stringToUpper(s) transform(all(s), s.begin(), ::toupper);
#define noOfDigits(n) (1 + floor(log10(n)))
#define isOn(s, j) (s & (1 << j))
#define setBit(s, j) (s |= (1 << j))
#define clearBit(s, j) (s &= ~(1 << j))
#define toggleBit(s, j) (s ^= (1 << j))
#define lowBit(s) (s & (-s))
#define setAll(s, n) (s = (1 << n) - 1)
#define modulo(s, N) ((s) & (N - 1))  // returns s % N, where N is a power of 2
#define isPowerOfTwo(s) (!(s & (s - 1)))
#define nearestPowerOfTwo(s) \
  ((int)pow(2.0, (int)((log((double)s) / log(2.0)) + 0.5)))
#define turnOffLastBit(s) ((s) & (s - 1))
#define turnOnLastZero(s) ((s) | (s + 1))
#define turnOffLastConsecutiveBits(s) ((s) & (s + 1))
#define turnOnLastConsecutiveZeroes(s) ((s) | (s - 1))
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
const int oo = INT_MAX;
const ll OO = 1e18;

const int monthly[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

const int alldx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const int alldy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, 1, -1 };

using namespace std;

string Letters = "0123456789ABCDEF";
int toInt(char c) { return Letters.find(c); }
ll FromAnyBaseToDecimal(string inp, int base) {
	ll res = 0;
	lop(j, 0, inp.sz) {
		res *= base;
		res += toInt(inp[j]);
	}
	return res;
}
string FromDecimalToAnyBase(ll n, int base) {
	if (n == 0) return "0";
	string ans = "";
	while (n) {
		ans = Letters[n % base] + ans;
		n /= base;
	}
	return ans;
}
ll GCD(ll a, ll b) { re((!b) ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }
ll nCr(ll n, ll ee) {
	if (n < ee) return 0;
	if (ee == 0) return 1;
	return n * nCr(n - 1, ee - 1) / ee;
}
ll PowMod(ll bs, ll ex, ll M) {
	if (!ex) return 1;
	ll a = PowMod((bs * bs) % M, ex >> 1, M);
	re(ex & 1) ? (a * bs) % M : a;
}
ll fastpow(ll b, ll e) {
	if (!e) return 1;
	if (e & 1) return b * fastpow(b, e - 1);
	ll c = fastpow(b, e / 2);
	return c * c;
}
ll ModInverse(ll a) { return PowMod(a, MOD - 2, MOD); }
ll ExtGCD(ll a, ll b, ll& c, ll& y) {
	if (!b) {
		c = 1;
		y = 0;
		return a;
	}
	ll ee = ExtGCD(b, a % b, y, c);
	y -= a / b * c;
	return ee;
}
ll mult(ll a, ll b) { re(1LL * a * b) % MOD; }
ll SumOfOdd(ll ss, ll ee) {
	ll Rsm = (ee + 1) / 2;
	Rsm *= Rsm;
	ss--;
	ll Lsm = (ss + 1) / 2;
	Lsm *= Lsm;
	return Rsm - Lsm;
}
ll NoOfOdd(ll L, ll R) {
	ll N = (R - L) / 2;
	if (R % 2 != 0 || L % 2 != 0) N++;
	return N;
}
ll NoOfEven(ll L, ll R) { re((R - L + 1) - NoOfOdd(L, R)); }
bool PointInRectangle(ll x1, ll y1, ll x2, ll y2, ll c, ll y) {
	return (c >= x1 && c <= x2 && y >= y1 && y <= y2);
}
bool isPrime(ll n) {
	if (n == 2) return 1;
	if (n < 2 || n % 2 == 0) return 0;
	for (ll j = 3; j * j <= n; j += 2)
		if (n % j == 0) return 0;
	return 1;
}
bool isPalindrome(string str) {
	ll ss = 0;
	ll h = str.sz - 1;
	while (h > ss) {
		if (str[ss++] != str[h--]) {
			return 0;
		}
	}
	return 1;
}
bool isPerfectSquare(ld c) {
	ld sr = sqrt(c);
	re((sr - floor(sr)) == 0);
}
bool isPerfectCube(ll n) {
	ll curoot = round(pow(n, 1.0 / 3.0));
	re(pow(curoot, 3) == n);
}
double distance(double x1, double y1, double x2, double y2) {
	return hypot(fabs(x1 - x2), fabs(y1 - y2));
}

ll a, b;
string s, ret, ans;
string prv;
string toStore;
ll ss, ee;
vll aa;
void init(string st) {
	prv = st;
	reverse(all(prv));
	toStore = st;
	toStore += "#";
	toStore += prv;
	aa.resize(toStore.sz, 0);
}
void ask(ll jj) {
	ll pit = aa[jj - 1];
	while (pit > 0) {
		if (!((toStore[jj] != toStore[pit]))) break;
		ll ii = pit - 1;
		pit = aa[ii];
	}
	aa[jj] = pit;
	if (toStore[jj] == toStore[pit]) aa[jj]++;
}
ll KMP(string st) {
	init(st);
	lop(jj, 1, aa.sz) ask(jj);
	ll ret = aa[aa.sz - 1];
	return ret;
}

void getLimits() {
	sc(s);
	ss = 0;
	ee = s.sz - 1;
	while (ss < ee) {
		if (s[ss] == s[ee]) ss++, ee--;
		else break;
	}
}
void check() {
	a = 0, b = 0;
	ret = "", ans = "";
	lop(j, 0, ss) ret += s[j];
	lop(j, ee + 1, s.sz) ans += s[j];
}
void dec() {
	if (a > b) {
		ll it = ss + a;
		lop(j, ss, it) ret += s[j];
	}
	else {
		ll it = ee - b + 1;
		lop(j, it, ee + 1) ret += s[j];
	}
}
void getAns() {
	dec();
	ret += ans;
	print(ret);
}
void goProcess() {
	check();
	string c = "";
	lop(j, ss, ee + 1) c += s[j];
	a = KMP(c); reverse(all(c)); b = KMP(c);
	getAns();
}
void getAC_ISA() {
	getLimits();
	if (ss >= ee) re print(s), void();
	goProcess();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
	// freopen("Out.txt", "w", stdout);
#else
	// freopen("input.txt", "ee", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	IO;
	ll t;
	sc(t);
	// ll t; t = 1;
	while (t--) {
		getAC_ISA();
	}
	return 0;
}