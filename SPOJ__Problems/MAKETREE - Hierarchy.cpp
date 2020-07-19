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

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }



ll n, k; 
const ll maxn = 1e5 + 15;
vll adj[maxn];
int vis[maxn];
int par[maxn];
vll topo;

void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;

	for (auto v : adj[u]) {
		dfs(v);
	}
	topo.push_back(u);
}

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	cin >> n >> k;
	for (ll i = 1; i <= k; i++) {
		ll m; cin >> m;
		for (ll j = 0; j < m; j++) {
			ll x; cin >> x;
			adj[i].push_back(x);
		}
	}
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	for (ll i = 1; i <= n; i++) {
		if (!vis[i]) topo.push_back(i);
	}

	int pos = 0;
	for (int i = n - 1; i >= 0; i--) {
		par[topo[i]] = pos;
		pos = topo[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << par[i] << '\n';
	}
}
