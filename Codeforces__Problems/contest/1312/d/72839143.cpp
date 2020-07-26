// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
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
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define Ceil(x, y) ((x + y - 1) / y)
#define lop(i, a, e) for (ll i =(a)-((a)>(e));i!=(e)-((a)>(e));i += 1-2*((a)>(e)))
#define lopi(i, init, n, incr) for (ll i = init; i < n; i += incr)
#define Even(Num) Num % 2 == 0
#define mms(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define SetPre(Ans, num) fixed << setprecision(num) << (Ans)
#define clr clear()
#define re return
#define print(ret) cout << ret << endl
#define print2(ret,a) cout << ret << ' ' << a << endl 
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pi acos(-1)
#define fix(ret, k) (ll(ret) % ll(k) + k) % k
#define in insert
#define sc(n) cin >> n
#define sc2(n,m) cin >> n >> m
#define sc3(ret,a,c) cin >> ret >> a >> c
#define sc4(ret,a,c,d) cin >> ret >> a >> c >> d
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
#define modulo(S, n) ((S) & (n - 1))   // returns S % n, where n is ret power of 2
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
inline int __builtin_popcountll(__int64 ret) {
	return __builtin_popcount((ui32)ret) + __builtin_popcount(ret >> 32);
}
#endif
#endif

int MOD = 998244353;
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
int toInt(char c) { return Letters.find(c); }
ll FromAnyBaseToDecimal(string inp, int base) { ll res = 0;  lop(i, 0, inp.sz) { res *= base; res += toInt(inp[i]); } return res; }
string FromDecimalToAnyBase(ll n, int base) { if (n == 0) return "0";  string ret = ""; while (n) { ret = Letters[n%base] + ret;  n /= base; } return ret; }
ll GCD(ll ret, ll a) { re((!a) ? ret : GCD(a, ret%a)); }
ll LCM(ll ret, ll a) { return ret / (GCD(ret, a))*a; }
ll nCr(ll n, ll r) { if (n<r)return 0; if (r == 0)return 1; return n*nCr(n - 1, r - 1) / r; }
ll PowMod(ll bs, ll ex, ll M) { if (!ex)return 1; ll MOD = PowMod((bs*bs) % M, ex >> 1, M); re(ex & 1) ? (MOD*bs) % M : MOD; }
ll fastpow(ll a, ll e) { if (!e) return 1; if (e & 1) return a * fastpow(a, e - 1); ll x = fastpow(a, e / 2); return x * x; }
ll ModInv(ll ret) { return PowMod(ret, MOD - 2, MOD); }
ll ExtGCD(ll ret, ll a, ll& x, ll& y) { if (!a) { x = 1; y = 0; return ret; } ll r = ExtGCD(a, ret%a, y, x); y -= ret / a*x; return r; }
ll mult(ll ret, ll a) { re(1LL * ret * a) % MOD; }
ll SumOfOdd(ll l, ll r) { ll Rsm = (r + 1) / 2; Rsm *= Rsm; l--; ll Lsm = (l + 1) / 2; Lsm *= Lsm; return Rsm - Lsm; }
ll NoOfOdd(ll L, ll R) { ll n = (R - L) / 2; if (R % 2 != 0 || L % 2 != 0)n++; return n; }
ll NoOfEven(ll L, ll R) { re((R - L + 1) - NoOfOdd(L, R)); }
bool PointInRectangle(ll x1, ll y1, ll x2,
	ll y2, ll x, ll y) {
	return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}
bool isPrime(ll n) { if (n == 2)return 1; if (n<2 || n % 2 == 0)return 0; for (ll i = 3; i*i <= n; i += 2)if (n%i == 0)return 0; return 1; }
bool isPalindrome(string str) { ll l = 0; ll h = str.sz - 1; while (h > l) { if (str[l++] != str[h--]) { return 0; } } return 1; }
bool isPerfectSquare(ld x) { ld sr = sqrt(x); re((sr - floor(sr)) == 0); }
bool isPerfectCube(ll n) { ll curoot = round(pow(n, 1.0 / 3.0)); re(pow(curoot, 3) == n); }
double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }



const ll N = 9e5 + 95;
ll hem[N];
ll n, m, ret;
vll getFact;
void getFactorial(ll n){
	getFact.resize(n + 1), getFact[0] = 1;
	lop(i, 1, n + 1) getFact[i] = getFact[i - 1] * i%MOD;
}
ll nCrModified(ll n, ll r) {
	if (!r) re 1;
	getFactorial(n);
	ll toRet = (getFact[n] * ModInv(getFact[r]) % MOD *
		ModInv(getFact[n - r]) % MOD) % MOD;
	return toRet;
}
void preProcess() {
	hem[0] = 1;
	lop(i, 1, N) hem[i] = (2 * hem[i - 1]) % MOD;
}
void getAns() {
	ll aa = n - 2, bb = n - 3;
	ret = nCrModified(m, n - 1), ret = (ret * aa) % MOD, ret = (ret * hem[bb]) % MOD;
}
void getACISA() {
	preProcess(), sc2(n, m);
	getAns(), print(ret);
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
	ll t; t = 1;
	while (t--) {
		getACISA();
	}
	return 0;
}