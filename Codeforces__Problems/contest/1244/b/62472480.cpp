// Author : Abdallah Hemdan
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
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define Ceil(x, y) ((x + y - 1) / y)
#define lop(i, b, e) for (ll i =(b)-((b)>(e));i!=(e)-((b)>(e));i += 1-2*((b)>(e)))
#define lopi(i, init, n, incr) for (ll i = init; i < n; i += incr)
#define Even(Num) Num % 2 == 0
#define mms(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define SetPre(Ans, num) fixed << setprecision(num) << (Ans)
#define clr clear()
#define re return
#define print(ans) cout << ans << endl
#define print2(a,b) cout << a << ' ' << b << endl 
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pi acos(-1)
#define fix(a, k) (ll(a) % ll(k) + k) % k
#define in insert
#define sc(n) cin >> n
#define sc2(n,m) cin >> n >> m
#define sc3(a,b,c) cin >> a >> b >> c
#define sc4(a,b,c,d) cin >> a >> b >> c >> d
#define watch(x) cout << (#x) << " is " << (x) << endl
#define stringToLower(s)  transform(all(s), s.begin(), ::tolower);
#define stringToUpper(s)  transform(all(s), s.begin(), ::toupper);
#define noOfDigits(n)  (1+floor(log10(n)))
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
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
const int oo = INT_MAX;
const ll OO = 1e18;

const int monthly[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

const int alldx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const int alldy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, 1, -1 };

using namespace std;

string Letters = "0123456789ABCDEF";
int toInt(char c) { re Letters.find(c); }
ll FromAnyBaseToDecimal(string inp, int base) { ll res = 0;  lop(i, 0, inp.sz) { res *= base; res += toInt(inp[i]); } re res; }
string FromDecimalToAnyBase(ll n, int base) { if (n == 0) re "0";  string ans = ""; while (n) { ans = Letters[n%base] + ans;  n /= base; } re ans; }
ll GCD(ll a, ll b) { re((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { re a / (GCD(a, b))*b; }
ll nCr(ll n, ll r) { if (n<r)re 0; if (r == 0)re 1; re n*nCr(n - 1, r - 1) / r; }
ll PowMod(ll bs, ll ex, ll M) { if (!ex)re 1; ll p = PowMod((bs*bs) % M, ex >> 1, M); re(ex & 1) ? (p*bs) % M : p; }
ll fastpow(ll b, ll e) { if (!e) re 1; if (e & 1) re b * fastpow(b, e - 1); ll x = fastpow(b, e / 2); re x * x; }
ll ModInverse(ll a) { re PowMod(a, MOD - 2, MOD); }
ll ExtGCD(ll a, ll b, ll& x, ll& y) { if (!b) { x = 1; y = 0; re a; } ll r = ExtGCD(b, a%b, y, x); y -= a / b*x; re r; }
ll mult(ll a, ll b) { re(1LL * a * b) % MOD; }
ll SumOfOdd(ll l, ll r) { ll Rsm = (r + 1) / 2; Rsm *= Rsm; l--; ll Lsm = (l + 1) / 2; Lsm *= Lsm; re Rsm - Lsm; }
ll NoOfOdd(ll L, ll R) { ll N = (R - L) / 2; if (R % 2 != 0 || L % 2 != 0)N++; re N; }
ll NoOfEven(ll L, ll R) { re((R - L + 1) - NoOfOdd(L, R)); }
bool PointInRectangle(ll x1, ll y1, ll x2,
	ll y2, ll x, ll y) {
	re(x >= x1 && x <= x2 && y >= y1 && y <= y2);
}
bool isPrime(ll n) { if (n == 2)re 1; if (n<2 || n % 2 == 0)re 0; for (ll i = 3; i*i <= n; i += 2)if (n%i == 0)re 0; re 1; }
bool isPalindrome(string str) { ll l = 0; ll h = str.sz - 1; while (h > l) { if (str[l++] != str[h--]) { re 0; } } re 1; }
bool isPerfectSquare(ld x) { ld sr = sqrt(x); re((sr - floor(sr)) == 0); }
bool isPerfectCube(ll n) { ll curoot = round(pow(n, 1.0 / 3.0)); re(pow(curoot, 3) == n); }
double distance(double x1, double y1, double x2, double y2) { re hypot(fabs(x1 - x2), fabs(y1 - y2)); }
ll ans;
int n;
string s;
int l, r;
void GetAC() {
	sc(n);
	sc(s);
	l = 0;  r = 0;
	lop(i,0,s.sz){
		if (s[i] == '1') break;
		l++;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') break;
		r++;
	}
	ans = max(n, 2 * n - 2 * l);
	ans = max(ans, 2LL * n - 2 * r);
	print(ans);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
	// freopen("Out.txt", "w", stdout);
#else
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	IO;
	int t; cin >> t;
	while (t--) {
		GetAC();
	}




}

