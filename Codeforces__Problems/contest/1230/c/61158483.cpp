/*Author : Abdallah Hemdan */
/*Created : */
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
#define mms(a, Value) memset(a, Value, sizeof(a))
#define SetPre(Ans, num) fixed << setprecision(num) << (Ans)
#define clr clear()
#define re return
#define print(ans) cout << ans << endl
#define print2(a,b) cout << a << ' ' << b << endl 
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define pll pair<ll, ll>
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



int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

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
ll ModInverse(ll a) { re PowMod(a, MOD - 2, MOD); }
ll ExtGCD(ll a, ll b, ll& x, ll& y) { if (!b) { x = 1; y = 0; re a; } ll r = ExtGCD(b, a%b, y, x); y -= a / b*x; re r; }
ll mult(ll a, ll b) { re(1LL * a * b) % MOD; }
ll SumOfOdd(ll l, ll r) { ll Rsm = (r + 1) / 2; Rsm *= Rsm; l--; ll Lsm = (l + 1) / 2; Lsm *= Lsm; re Rsm - Lsm; }
ll NoOfOdd(ll L, ll R) { ll N = (R - L) / 2; if (R % 2 != 0 || L % 2 != 0)N++; re N; }
ll NoOfEven(ll L, ll R) { re((R - L + 1) - NoOfOdd(L, R)); }
bool isPrime(ll n) { if (n == 2)re 1; if (n<2 || n % 2 == 0)re 0; for (ll i = 3; i*i <= n; i += 2)if (n%i == 0)re 0; re 1; }
bool isPalindrome(string str) { ll l = 0; ll h = str.sz - 1; while (h > l) { if (str[l++] != str[h--]) { re 0; } } re 1; }
bool isPerfectSquare(ld x) { ld sr = sqrt(x); re((sr - floor(sr)) == 0); }
double distance(double x1, double y1, double x2, double y2) { re hypot(fabs(x1 - x2), fabs(y1 - y2)); }

const int N = 1e5 + 5;
const int M = 8;
int n, m;
int mx;
bool vis[M];
bool dom[M][M];
vi adj[M];
int a[7];
int cnt;

void Check(int it, int &cnt) {
	if (vis[it]) return;
	vis[it] = 1;
	for (auto i : adj[it]) {
		int x = a[i], y = a[it];
		if (!dom[min(x, y)][max(x, y)]) {
			dom[min(x, y)][max(x, y)] = 1;
			cnt++;
			Check(it + 1, cnt);
		}
	}
}
void GO_REC(int it = 0){
	if (it == n) {
		mms(vis,0);
		mms(dom,0);
		int cnt = 0;
		lop(i,0,n)
			if (!vis[i])
				Check(i, cnt);
		mx = max(mx, cnt);
		return;
	}
 
	lop(i,0,6) {
		a[it] = i;
		GO_REC(it + 1);
	}
}
void read(){
	sc2(n,m);
	mms(a,-1);
	lop(i,0,m) {
		int a,b; sc2(a,b);
		a-- ,b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
}
int main() {
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	IO;
	read();
	GO_REC();
	print(mx);
}