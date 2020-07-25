// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll,ll>
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


struct edge {
	ll u, v, c;
	edge(ll _u, ll _v, ll _c) : u(_u), v(_v), c(_c) {};
	bool operator<(const edge& e) {
		return c < e.c;
	}
};


vector<edge> adj;
const int maxn = 1e5 + 15;
ll par[maxn];
ll rnk[maxn];


void init() {
	adj.clear();
	for (int i = 0; i < maxn; i++) {
		par[i] = i;
		rnk[i] = 1;
	}
}

ll find(ll u) {
	return (u == par[u]) ? u : par[u] = find(par[u]);
}

void join(ll u, ll v) {
	u = find(u);
	v = find(v);

	if (u != v) {
		if (rnk[u] >= rnk[v]) {
			rnk[u] += rnk[v];
			par[v] = u;
		}
		else {
			rnk[v] += rnk[u];
			par[u] = v;
		}
	}
}

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll t; cin >> t;
	while (t--) {
		init();
		ll n, m; cin >> n >> m;
		for (ll i = 0; i < m; i++) {
			ll u, v, c; cin >> u >> v >> c;
			adj.emplace_back(edge(u, v, c));
		}

		sort(all(adj));
		ll lst = 0;
		for (auto e : adj) {
			ll u = e.u;
			ll v = e.v;
			if (find(u) != find(v)) {
				lst = e.c;
				join(u, v);
			}
		}
		cout << lst << endl;
	}
}
