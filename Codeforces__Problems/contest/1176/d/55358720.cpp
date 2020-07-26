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
#define Fir first
#define Sec second
#define sz size()
#define len length()
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define si set<int>
#define sll set<ll>
#define ss set<string>
#define IO                 \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define Ceil(x, y) ((x + y - 1) / y)
#define lop(i, init, n) for (ll i = init; i < n; ++i)
#define Even(Num) Num % 2 == 0
#define mms(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define SetPre(Ans, num) fixed << setprecision(num) << (Ans)
typedef long long int ll;
typedef long double ld;

const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 9;

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

// ll GCD(ll a, ll b) {
// 	if (b == 0) return a;
// 	return GCD(b, a%b);
// }
// ll LCM(ll a, ll b) {
// 	return a / (GCD(a, b))* b;
// }
// ll nCr(ll n, ll r) {
//  	if (n < r) return 0;
//  	if (r == 0) return 1;
//  	return n * nCr(n - 1, r - 1) / r;
// }
// ll PowMod(ll base, ll exp,ll M) {
// 	if (exp == 0) return 1;
// 	ll p = POWMOD((base * base) % M, exp >> 1, M);
// 	return (exp & 1) ? (p * base) % M : p;
// }
// bool isPrime(ll n) {
//	if (n == 2) return true;
//	if (n<2 || n % 2 == 0) return false;
//	for (ll i = 3; i*i <= n; i += 2) if (n%i == 0) return false;
//	return true;
//}

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, 1, -1 };

using namespace std;



const ll MAXI = 2750135;
int Hem[MAXI] = { 0 }, b[MAXI] = { 1 };
map<int, int> mapp;
int n;
vector<int> Arr, Vec1, Vec2, Vec3;


void Build() {
	lop(i, 2, MAXI) {
		if (Hem[i] == 0) {
			for (int j = i + i; j < MAXI; j += i) Hem[j] = 1;
		}
	}
	lop(i, 2, MAXI) {
		for (int j = i + i; j < MAXI; j += i) b[j] = i;
	}
}
int main() {
	Build();
	lop(i, 1, MAXI) {
		if (Hem[i] == 0) Arr.PB(i);
	}

	cin >> n;
	vector<int> a(n * 2);
	lop(i, 0, 2 * n) {
		cin >> a[i];
		mapp[a[i]]++;
		if (Hem[a[i]] == 0)
			Vec1.PB(a[i]);
		else
			Vec2.PB(a[i]);
	}
	sort(all(Vec1)), sort(rall(Vec2));
	lop(i, 0, Vec2.sz) {
		if (mapp[Vec2[i]] > 0) {
			Vec3.PB(Vec2[i]);
			mapp[b[Vec2[i]]]--;
			mapp[Vec2[i]]--;
		}
	}

	lop(i, 0, Vec1.sz) {
		if (mapp[Vec1[i]] > 0) {
			Vec3.PB(Vec1[i]);
			mapp[Arr[Vec1[i]]]--;
			mapp[Vec1[i]]--;
		}
	}

	for (auto a : Vec3) cout << a << " ";
	cout << endl;
}