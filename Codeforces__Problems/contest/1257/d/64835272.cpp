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
#define itOfFirstSetBit(n) (log2(n & -n) + 1);

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

#define pii pair < int, int >
#define pb push_back
#define ll long long
#define f first
#define s second


const int inf = (int)1e9 + 100;
const ll INF = (ll)2e18;
const int mod = 998244353;
const double eps = 1e-9;
const int MaxN = 2e5 + 1;

const int M = 800100;
ll n, m; 
ll l, tst, r; 
ll mxi = 0, k; 
ll minn = inf, cntt, R; 
ll cntt2, cx, cy, it, x, z, y;
ll t[M], a[200200];
void Build(int v, int tll, int tr) {
	if (tll == tr)
		t[v] = a[tll];
	else {
		int mid = (tll + tr) / 2;
		Build(v * 2, tll, mid);
		Build(v * 2 + 1, mid + 1, tr);
		t[v] = max(t[v * 2], t[v * 2 + 1]);
	}
}
ll GetSm(int v, int tll, int tr, int l, int r) {
	if (l > r) re 0;
	if (l == tll && r == tr) re t[v];
	int mid = (tll + tr) / 2;
	return max(GetSm(v * 2, tll, mid, l, min(r, mid))
		, GetSm(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r));
}
const int N = 200200;
ll b[N];
void Process() {
	vpii v;
	z = 0;
	lop(i, 0, m) {
		sc2(x, y);
		v.PB({ y,x });
		z = max(x, z);
	}
	if (z<mxi) {
		print(-1);
		return;
	}
	sort(all(v));
	x = v[m - 1].second;
	for (ll i = m - 1; i >= 0; i--) {
		if (v[i].second > x)x = v[i].second;
		b[i] = x;
	}
	ll it = 0;
	while (it < n) {
		l = it + 1, r = n;
		ll tst = n; 
		while (r > l) {
			ll mid = (r + l + 1) / 2;
			x = GetSm(1, 0, n - 1, it, mid - 1);
			if (mid - it> v[m - 1].first) {
				r = mid - 1;
				tst = mid - 1;
				continue;
			}
			ll l1 = 0, r1 = m - 1;
			while (r1 > l1) {
				ll md_1 = (l1 + r1) / 2;
				if (v[md_1].first >= mid - it)r1 = md_1;
				else l1 = md_1 + 1;
			}
			if (b[l1] >= x)l = mid;
			else r = mid - 1;
		}
		cntt++;
		it = r;
	}
	print(cntt);
	cntt = 0;
}
void Read_Build() {
	sc(n);
	mxi = 0;
	lop(i,0,n){
		sc(a[i]);
		mxi = max(mxi, a[i]);
	}
	Build(1, 0, n - 1);
	sc(m);
	Process();
}
int main() {
	cin >> tst;
	while (tst--) {
		Read_Build();
	}

}