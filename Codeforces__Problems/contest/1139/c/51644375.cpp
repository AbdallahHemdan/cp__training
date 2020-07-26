/*Author : Abdallah Hemdan */
/**************************/
/* Dear online judge:
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
#define mp make_pair
#define pb push_back
#define endl '\n'
#define sz size()
#define len length()
#define IO 			ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define X first
#define Y second
#define all(v) ((v).begin()), ((v).end())
#define lop(i, init, n) for (int i = init; i < n; ++i)
#define mms(Arr, Value) memset(Arr, Value, sizeof(Arr))
#define SetPre(Res, num) fixed << setprecision(num) << (Res)
#define Even(Num)		Num % 2 == 0
#define clr					clear()
typedef long long int ll;
typedef long double ld;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

// ll GCD(ll a, ll b) {
//	if (b == 0) return a;
//	return GCD(b, a%b);
//}
// ll LCM(ll a, ll b) {
//	return a / (GCD(a, b))* b;
//}

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, 1, -1 };

using namespace std;


const ll MAXI = 1e6 + 9;
ll Vis[MAXI];
vector<ll> SIZEI, Adj[MAXI];
set<ll> Set;

ll n, k, A, B, C;
ll Check = INT_MIN;
ll Res;

ll ReCalc(ll n, ll k) {
	// Handle a Node
	Check = 1;
	if (k == 1) {
		return n % MOD;
	}
	else if (k == 0) {
		return 1;
	}

	ll Save = ReCalc(n, k / 2) % MOD;

	if (Even(k)) {
		return ll(pow(Save, 2)) % MOD;
	}
	else {
		Check = 0;
		return (((n % MOD * Save) % MOD) * Save) % MOD;
	}
}


void Print() { cout << Res << endl; }

ll DFS(ll Ele) {
	ll Dumi;
	Set.insert(Ele);
	Vis[Ele] = true;

	lop(ind, 0, Adj[Ele].sz) {
		if (!Vis[Adj[Ele][ind]]) {
			DFS(Adj[Ele][ind]);
		}

	}
}

int main() {
	cin >> n >> k;

	lop(i, 1, n + 1) {
		cin >> A >> B >> C;

		// Add A ==> B && B ==> A
		if (C == 0) {
			Adj[A].pb(B);
			Adj[B].pb(A);
			Check = 0;
		}
	}

	lop(i, 1, n + 1) {
		if (!Vis[i]) {
			Set.clr;
			DFS(i);
			SIZEI.pb(Set.size());
		}
	}

	Res = ReCalc(n, k);
	Check = Res - 1;

	lop(ind, 0, SIZEI.sz) {
		ll Tm = ReCalc(SIZEI[ind], k);
		ll Tempo = ((Res - Tm) + MOD) % MOD;
		Res = Tempo;
	}
	Print();
}
