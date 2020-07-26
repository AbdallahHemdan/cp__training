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

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

//ll GCD(ll a, ll b) {
//	if (b == 0) return a;
//	return GCD(b, a%b);
//}
//ll LCM(ll a, ll b) {
//	return a / (GCD(a, b))* b;
//}

const int dx[] = { 1,-1,0,0,0,0 };
const int dy[] = { 0,0,1,-1,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };

using namespace std;


#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int pow(int a, int b, int m)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans*a) % m;
		b /= 2;
		a = (a*a) % m;
	}
	return ans;
}

int n, k, sz, ans = 0;
bool vis[N];
vector<int> g[N];

void dfs(int u)
{
	if (vis[u])
		return;
	sz++;
	vis[u] = 1;
	for (auto &it : g[u])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin >> n >> k;
	int ans = pow(n, k, MOD);
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v, x;
		cin >> u >> v >> x;
		if (x == 0)
			g[u].push_back(v), g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		sz = 0;
		dfs(i);
		ans -= pow(sz, k, MOD);
		ans += MOD;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}