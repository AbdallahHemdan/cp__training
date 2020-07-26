# Dynamic connectivity

> a data structure that dynamically maintains the information about thee connected components of graph.

> In simple words suppose there is a graph G(V, E) in which no. of vertices V is constant but no. of edges E is variable.


> There are three ways in which we can change the number of edges

1. Incremental Connectivity : Edges are only added to the graph.
2. Decremental Connectivity : Edges are only deleted from the graph.
3. Fully Dynamic Connectivity : Edges can both be deleted and added to the graph.



## [1] Incremental connectivity

```md
There are two types of queries 
    1.  1 x y in  this if the node 
        If x and y are connected print Yes else No
	2.  2 x y 
		Add an edge between node x and y
```


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



const ll maxn = 1e5 + 15;

ll par[maxn];
ll rnk[maxn];

ll find(ll u) {
	return (u == par[u]) ? u : par[u] = find(par[u]);
}

void join(ll u, ll v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		if (rnk[u] > rnk[v]) {
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
	ll n, m; cin >> n >> m;
	
	init();
	for (ll i = 0; i < m; i++) {
		ll t, u, v;
		cin >> t >> u >> v;

		if (t == 1) {
			if (find(u) == find(v)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
			if (find(u) != find(v)) {
				join(u, v);
			}
		}
	}
}
```
