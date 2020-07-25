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
	edge(ll _u, ll _v, ll _c) :c(_c), v(_v), u(_u) {};
	bool operator<(const edge& e) {
		return c < e.c;
	}
};

vector<pll> a;
vector<edge> adj;
const ll maxn = 1e3;
ll par[maxn];
ll rnk[maxn];


ll find(ll u) {
	return (u == par[u]) ? u : par[u] = find(par[u]);
}

void link(ll u, ll v) {
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

void init() {
	adj.clear();
	for (ll i = 0; i < maxn; i++) {
		par[i] = i;
		rnk[i] = 1;
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
		ll n; cin >> n;
		ll cnt = 0;
		vector<pll> a(n + 5);
		for (ll i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

		ll m; cin >> m;
		for(ll i = 0 ; i < m ; i++){
			ll u, v; cin >> u >> v;
			if (find(u) != find(v)) cnt++;
			link(u, v);
		}
		if (cnt == n - 1) cout << "No new highways need" << endl;
		else {
			m = 0;
			for(ll i = 1 ; i<= n ; i++){
				for(ll j = i + 1 ; j <= n ; j++){
					adj.emplace_back(edge(i, j, ((a[i].first - a[j].first)*(a[i].first - a[j].first) + (a[i].second - a[j].second)*(a[i].second - a[j].second))));
					m++;
				}
			}
			sort(all(adj));
			for(auto e : adj){
				if (find(e.u) != find(e.v)) {
					link(e.u, e.v);
					cout << e.u << ' ' << e.v << endl;
				}
			}
		}
		if (t) cout << endl;
	}
}
