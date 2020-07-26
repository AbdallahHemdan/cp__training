// Author : Abdallah Hemdan
/*Dear online judge:
* I've read the problem, and tried to solve itr.
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
#define print(save) cout << save << endl
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

#include <ext/pb_ds/assoc_container.hpp>.
#include <ext/pb_ds/tree_policy.hpp>
#define F first
#define S second
#define pb push_back
#define ll long long
typedef long double ld;
typedef int8_t i8;
typedef uint8_t ui8;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5 + 5, INF = 1e9;
const bool debug = 0;

typedef tree<
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;

int n, m;
vector<int> arr;
vector<pair<int, int>> ve;
ordered_set s;

bool Order(pair<int, int> a, pair<int, int> b) {
	if (a.xx != b.xx) return a.xx > b.xx;
	return a.yy < b.yy;
}
void Read() {
	sc(n);
	arr.resize(n);
	lop(i, 0, n) {
		sc(arr[i]);
		ve.eb(arr[i], i);
	}
	sort(all(ve), Order);
	sc(m);
}
void Get_AC() {
	vector<pair<pll, int>> hem(m);
	vll save(m);
	lop(i, 0, m) sc2(hem[i].xx.xx, hem[i].xx.yy), hem[i].yy = i;
	sort(all(hem));
	ll itr = 0;
	ll k = 1;
	ll check_exist = 0;
	for (auto& i : ve) {
		s.in({ i.S,i.xx });
		while (itr < m && hem[itr].xx.xx == k) {
			save[hem[itr].yy] = (*s.find_by_order(hem[itr].xx.yy - 1)).yy;
			++itr;
			check_exist = 1;
		}
		++k;
	}
	for (int i : save) print(i);
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
	int t; // cin >> t;
	t = 1;
	Read();
	Get_AC();
}