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
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define vpii vector<pair<int, int> >
#define vpll vector<pair<ll, ll> >
#define pll pair<ll, ll>
#define fix(a, k) (ll(a) % ll(k) + k) % k
#define in insert
#define sc(n) cin >> n
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

const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 9;
const int MAX_N = 2;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, 1, -1 };

using namespace std;

ll GCD(ll a, ll b) { re((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { re a / (GCD(a, b))*b; }
bool PoweOf2(int n) { re !((n&(n - 1)) && n); }
ll nCr(ll n, ll r) { if (n<r)re 0; if (r == 0)re 1; re n*nCr(n - 1, r - 1) / r; }
ll PowMod(ll bs, ll ex, ll M) { if (!ex)re 1; ll p = PowMod((bs*bs) % M, ex >> 1, M); re(ex & 1) ? (p*bs) % M : p; }

// string Prod_Of_2Big(string s1, string s2) {
//	int n1 = s1.sz, n2 = s2.sz;
//	if (n1 == 0 || n2 == 0) re "0";
//	vi res(n1 + n2, 0);
//	int i_n1 = 0, i_n2 = 0;
//	for (int i = n1 - 1; i >= 0; i--) {
//		int crr = 0, n1 = s1[i] - '0';
//		i_n2 = 0;
//		for (int j = n2 - 1; j >= 0; j--) {
//			int n2 = s2[j] - '0', sumi = n1 * n2 + res[i_n1 + i_n2]
//+
// crr;
//			crr = sumi / 10;
//			res[i_n1 + i_n2] = sumi % 10;
//			i_n2++;
//		}
//		if (crr > 0) res[i_n1 + i_n2] += crr;
//		i_n1++;
//	}
//	int i = res.sz - 1;
//	while (i >= 0 && res[i] == 0) i--;
//	if (i == -1) re "0";
//	string s = "";
//	while (i >= 0) s += to_string(res[i--]);
//	re s;
//}

////////////////////          Monotonic_queue          ////////////////////

// template <class T>
// class monotonic_queue {
// 	stack<pair<T, pair<T, T>>> s1, s2;
// 	void add(stack<pair<T, pair<T, T>>>& s, T v) {
// 		T mx = std::max(v, s.top().yy.xx);
// 		T mn = std::min(v, s.top().yy.yy);
// 		s.push({ v,{ mx, mn } });
// 	}
// 	void flip() {
// 		if (s2.size() > 1) re;
// 		while (s1.size() > 1) {
// 			add(s2, s1.top().xx);
// 			s1.pop();
// 		}
// 	}
// public:
// 	monotonic_queue() {
// 		s1.push({ INT_MIN,{ INT_MIN, INT_MAX } });
// 		s2.push({ INT_MIN,{ INT_MIN, INT_MAX } });
// 	}
// 	void push(T v) { add(s1, v); }
// 	void pop() { flip(); s2.pop(); }
// 	T front() { flip(); re s2.top().xx; }
// 	T max() { re std::max(s1.top().yy.xx, s2.top().yy.xx); }
// 	T min() { re std::min(s1.top().yy.yy, s2.top().yy.yy); }
// 	T size() { re s1.size() + s2.size() - 2; }
// };
////////////////////          Monotonic_queue          ////////////////////



////////////////////          Matrix Power          ////////////////////
// struct Matrix {
//   ll mat[MAX_N][MAX_N];
// };

// Matrix matMul(Matrix a, Matrix b) {
//   Matrix ans;
//   ll k;
//   lop(i, 0, MAX_N)
//       lop(j, 0, MAX_N) for (ans.mat[i][j] = k = 0; k < MAX_N; k++) {
//     ans.mat[i][j] += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
//     ans.mat[i][j] %= MOD;
//   }
//   re ans;
// }
// Matrix matPow(Matrix base, ll p) {
//   Matrix ans;
//   lop(i, 0, MAX_N) lop(j, 0, MAX_N) ans.mat[i][j] = (i == j);
//   while (p) {
//     if (p & 1) ans = matMul(ans, base);
//     base = matMul(base, base);
//     p >>= 1;
//   }
//   re ans;
// }
////////////////////          Matrix Power          ////////////////////



// string Sum_Of_2Big(string s1, string s2) {
//	if (s1.sz > s2.sz) swap(s1, s2);
//	string str = "";
//	int n1 = s1.sz, n2 = s2.sz;
//	reverse(all(s1));
//	reverse(all(s2));
//	int crr = 0;
//	lop(i, 0, n1) {
//		int sumi = ((s1[i] - '0') + (s2[i] - '0') + crr);
//		str.PB(sumi % 10 + '0');
//		crr = sumi / 10;
//	}
//	lop(i, n1, n2) {
//		int sumi = ((s2[i] - '0') + crr);
//		str.PB(sumi % 10 + '0');
//		crr = sumi / 10;
//	}
//	if (crr) str.PB(crr + '0');
//	reverse(all(str));
//	re str;
//}
// ll NoOfOdd(ll L, ll R) {
// 	ll N = (R - L) / 2;
// 	if (R % 2 != 0 || L % 2 != 0)
// 		N += 1;
// 	re N;
// 	// #Of Even = (R-L+1)-odd(L,R)
// }
// bool isPrime(ll n) {
//	if (n == 2) re true;
//	if (n<2 || n % 2 == 0) re false;
//	for (ll i = 3; i*i <= n; i += 2) if (n%i == 0) re false;
//	re true;
//}

int main() {
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	IO;
	ll A = 0, B = 0; 
	ll n, ba; cin >> n >> ba;
	vll a(n); 
	for (ll& i : a) cin >> i;
	reverse(all(a));
	lop(i, 0, n) {
		A += a[i] * pow(ba, i);
	}
	ll m, bb; cin >> m >> bb; 
	vll b(m);
	for(ll& i:b) cin >> i;
	reverse(all(b));
	lop(i, 0, m) {
		B += b[i] * pow(bb, i);
	}
	if (A < B) print("<");
	else if (A > B) print(">");
	else print("=");
}