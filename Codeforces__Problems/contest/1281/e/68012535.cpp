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
#define stringToLower(str)  transform(all(str), str.begin(), ::tolower);
#define stringToUpper(str)  transform(all(str), str.begin(), ::toupper);
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
int toInt(char c) { return Letters.find(c); }
ll FromAnyBaseToDecimal(string inp, int base) { ll ans = 0;  lop(i, 0, inp.sz) { ans *= base; ans += toInt(inp[i]); } return ans; }
string FromDecimalToAnyBase(ll n, int base) { if (n == 0) return "0";  string ans = ""; while (n) { ans = Letters[n%base] + ans;  n /= base; } return ans; }
ll GCD(ll a, ll b) { re((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }
ll nCr(ll n, ll r) { if (n<r)return 0; if (r == 0)return 1; return n*nCr(n - 1, r - 1) / r; }
ll PowMod(ll bs, ll ex, ll M) { if (!ex)return 1; ll p = PowMod((bs*bs) % M, ex >> 1, M); re(ex & 1) ? (p*bs) % M : p; }
ll fastpow(ll b, ll e) { if (!e) return 1; if (e & 1) return b * fastpow(b, e - 1); ll x = fastpow(b, e / 2); return x * x; }
ll ModInverse(ll a) { return PowMod(a, MOD - 2, MOD); }
ll ExtGCD(ll a, ll b, ll& x, ll& y) { if (!b) { x = 1; y = 0; return a; } ll r = ExtGCD(b, a%b, y, x); y -= a / b*x; return r; }
ll mult(ll a, ll b) { re(1LL * a * b) % MOD; }
ll SumOfOdd(ll l, ll r) { ll Rsm = (r + 1) / 2; Rsm *= Rsm; l--; ll Lsm = (l + 1) / 2; Lsm *= Lsm; return Rsm - Lsm; }
ll NoOfOdd(ll L, ll R) { ll N = (R - L) / 2; if (R % 2 != 0 || L % 2 != 0)N++; return N; }
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
 
const ll NN = 4e5 + 5;
ll t, k, n, K = 1e18;
ll d[202020][2], h2, subi[202020];
vector<ll> v[202020];
vector<ll> aa[202020];
ll Solve(ll it, ll parent, ll p) {
	ll ret = d[it][parent];
	if (ret == -1)
	{
		ll jj = 0, hz = 0, hi = 1e18;
		vector<ll> isi;
		for (ll i = 0; i < v[it].size(); i++)
		{
			if (v[it][i] == p)
				continue;
			jj += min(Solve(v[it][i], 0, it), Solve(v[it][i], 1, it) + aa[it][i]);
			if (Solve(v[it][i], 0, it) > Solve(v[it][i], 1, it) + aa[it][i])
				hz++;
			hi = min(hi, abs(Solve(v[it][i], 0, it) - (Solve(v[it][i], 1, it) + aa[it][i])));
		}
		if ((hz % 2) == parent)
			jj += hi;
		ret = jj;
	}
	return d[it][parent] = ret;
}
void Run_DFS(ll it, ll p) {
	subi[it] = 1;
	for (ll i = 0; i < v[it].size(); i++)
	{
		if (v[it][i] == p)
			continue;
		Run_DFS(v[it][i], it);
		subi[it] += subi[v[it][i]];
	}
	lop(i,0,v[it].sz) { 
		if (v[it][i] == p)
			continue;
		h2 += aa[it][i] * min(subi[v[it][i]], n - subi[v[it][i]]);
	}
}
void GETAC() {
	cin >> k;
	n = k * 2;
	h2 = 0;
	for (ll i = 1; i <= n; i++)
	{
		v[i].clear();
		aa[i].clear();
		d[i][0] = -1;
		d[i][1] = -1;
	}
	lop(i,1,n){
		ll ta, tb, tc;
		cin >> ta >> tb >> tc;
		v[ta].PB(tb);
		v[tb].PB(ta);
		aa[ta].PB(tc);
		aa[tb].PB(tc);
	}
	Run_DFS(1, 1);
	cout << Solve(1, 0, 1) << " " << h2 << "\n";
}
 
 
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
	// freopen("Out.txt", "aa", stdout);
#else
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "aa", stdout);
#endif
	IO;
	int t; sc(t);
	while (t--) {
		GETAC();
	}
}