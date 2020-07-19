// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }


ll n, m;
const ll maxn = 1e2 + 12;
vll adj[maxn];
int vis[maxn];

vll top;
void dfs(ll u) {
	if (vis[u]) return;
	vis[u] = 1;

	for (auto v : adj[u]) {
		dfs(v);
	}
	top.push_back(u);
}



int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	while (cin >> n >> m && n != 0) {
		for (int i = 0; i < m; i++) {
			int u, v;

			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++) {
			dfs(i);
		}
		reverse(all(top));

		for (auto i : top) {
			cout << i << ' ';
		}
		cout << endl;
		top.clear();
		memset(vis, 0, sizeof vis);
	}
}
