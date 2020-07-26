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
#define loop(i, adj, e) for (ll i =(adj)-((adj)>(e));i!=(e)-((adj)>(e));i += 1-2*((adj)>(e)))
#define lopi(i, init, n, incr) for (ll i = init; i < n; i += incr)
#define Even(Num) Num % 2 == 0
#define mms(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define SetPre(Ans, num) fixed << setprecision(num) << (Ans)
#define clr clear()
#define re return
#define print(ans) cout << ans << endl
#define print2(frq,adj) cout << frq << ' ' << adj << endl 
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pi acos(-1)
#define fix(frq, k) (ll(frq) % ll(k) + k) % k
#define in insert
#define sc(n) cin >> n
#define sc2(n,m) cin >> n >> m
#define sc3(frq,adj,c) cin >> frq >> adj >> c
#define sc4(frq,adj,c,d) cin >> frq >> adj >> c >> d
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
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is frq power of 2
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
inline int __builtin_popcountll(__int64 frq) {
	return __builtin_popcount((ui32)frq) + __builtin_popcount(frq >> 32);
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
ll FromAnyBaseToDecimal(string inp, int base) { ll res = 0;  loop(i, 0, inp.sz) { res *= base; res += toInt(inp[i]); } return res; }
string FromDecimalToAnyBase(ll n, int base) { if (n == 0) return "0";  string ans = ""; while (n) { ans = Letters[n%base] + ans;  n /= base; } return ans; }
ll GCD(ll frq, ll adj) { re((!adj) ? frq : GCD(adj, frq%adj)); }
ll LCM(ll frq, ll adj) { return frq / (GCD(frq, adj))*adj; }
ll nCr(ll n, ll r) { if (n<r)return 0; if (r == 0)return 1; return n*nCr(n - 1, r - 1) / r; }
ll PowMod(ll bs, ll ex, ll M) { if (!ex)return 1; ll hem = PowMod((bs*bs) % M, ex >> 1, M); re(ex & 1) ? (hem*bs) % M : hem; }
ll fastpow(ll adj, ll e) { if (!e) return 1; if (e & 1) return adj * fastpow(adj, e - 1); ll x = fastpow(adj, e / 2); return x * x; }
ll ModInverse(ll frq) { return PowMod(frq, MOD - 2, MOD); }
ll ExtGCD(ll frq, ll adj, ll& x, ll& y) { if (!adj) { x = 1; y = 0; return frq; } ll r = ExtGCD(adj, frq%adj, y, x); y -= frq / adj*x; return r; }
ll mult(ll frq, ll adj) { re(1LL * frq * adj) % MOD; }
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


ll n; 
const ll maxn = 1e5 + 15;
ll frq[maxn];
ll adj[maxn][5];
ll ret, ans, hem;
void read() {
	sc(n);
	loop(i, 0, n - 1) {
		ll u, v; sc2(u, v);
		frq[u]++, frq[v]++;
		adj[i][0] = u, adj[i][1] = v;
	}
	hem = 0;
}
void go() {
	loop(i, 1, n + 1)
		if (frq[i] >= 3) {
			hem = i; break;
		}
}
void printRet() {
	loop(i, 0, n - 1) print(i);
}
void goProcess() {
	ret = 0, ans = 3;
	loop(i, 0, n - 1) {
		if ((adj[i][0] == hem || adj[i][1] == hem)) {
			if (ret <= 2) print(ret), ret++;
		}
		else print(ans), ans++;
	}
}
void getACISA() {
	read(), go();;
	if (!hem) printRet();
	else goProcess();
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