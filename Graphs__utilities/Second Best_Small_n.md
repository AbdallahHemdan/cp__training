## 2nd MST for Small-N
> We can find 2nd MST using Krusal(eaiser)

#### Steps
> This method is applicable only for `small n`

1. Find MST
2. For each edge in the MST
	- Remove edge
	- Run MST, compare it for the min value
	- ReAdd the edge u removed
6. Display MST2 value

Problem : https://vjudge.net/problem/UVA-10600
Soltuion :
```cpp
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
double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }
int comp_double(double a, double b) {
	if (fabs(a - b) <= EPS) return 0; // equal
	return (a < b) ? -1 : 1;
}

struct edge {
	ll u, v, c;
	edge(ll _u, ll _v, ll _c) : c(_c), u(_u), v(_v) {};
	bool operator<(const edge& e) {
		return c < e.c;
	}
};


const ll maxn = 111;
ll par[maxn];
ll rnk[maxn];

vector<edge> adj;

ll find(ll u) {
	return (u == par[u]) ? u : par[u] = find(par[u]);
}

void link(ll u, ll v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		rnk[u] += rnk[v];
		par[v] = u;
	}
	else {
		rnk[v] += rnk[u];
		par[u] = v;
	}
}

void init() {
	for (ll i = 0; i < maxn; i++) {
		par[i] = i;
		rnk[i] = 1;
	}
}

bool equal(const edge& a, const edge& b) {
	return (a.u == b.u && a.v == b.v && a.c == b.c);
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
		ll n, m; cin >> n >> m; 
		adj.clear();
		init();
		for (ll i = 0; i < m; i++) {
			ll u, v, c;
			cin >> u >> v >> c;
			adj.push_back(edge(u, v, c));
		}

		sort(all(adj));
		vector<edge> ret;
		ll mn1 = 0;
		for (auto e : adj) {
			if (find(e.u) != find(e.v)) {
				link(e.u, e.v);
				ret.push_back(e);
				mn1 += e.c;
			}
		}
		ll mn2 = LLONG_MAX;
		for (auto e : ret) {
			init();
			ll cst = 0;
			ll cnt = 0;
			for (auto i : adj) {
				if (equal(i, e)) continue;
				if (find(i.u) != find(i.v)) {
					link(i.u, i.v);
					cst += i.c;
					cnt++;
				}
			}
			if (cnt != n - 1) continue;
			mn2 = min({ mn2, cst });
		}
		cout << mn1 << ' ' << mn2 << endl;
	}
}
```
