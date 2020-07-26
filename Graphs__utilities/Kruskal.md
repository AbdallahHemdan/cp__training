# Kruskal Algorithm
> Kruslal used to finding minimum spanning tree (tree which has minimum sum of edges)



## Optimization over Union Find Data-Structure
> There are 2 optimizations we can do over Union-Find Data-Structure.

1. Path compression
2. Union by rank


## Code

```cpp
struct edge {
	ll u, v, w; 
	edge(ll _u, ll _v, ll _w) :u(_u), v(_v), w(_w){}
	bool operator<(const edge& e) { re w < e.w; }
};


const int maxn = 1e5 + 15;

int par[maxn];
int rnk[maxn];
vector<edge> adj, edgs;

ll find(ll u){
	(par[u] == u) ? u : par[u] = find(par[u]);
}

void join(ll a, ll b){
	a = find(a);
	b = find(b);

	if(a != b){
		if(rnk[a] >= rnk[b]){
			rnk[a] += rnk[b];
			par[b] = a;
		} else{
			rnk[b] += rnk[a];
			par[a] = b;
		}

	}
}

void init(){
	adj.clear();
	for(int i = 0 ; i < maxn ; i++){
		par[i] = i;
		rnk[i] = 1;
	}

}

int main() {
	init();
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, c; cin >> u >> v >> c;
		adj.emplace_back(edge(u, v, c));
	}

	// kruskal algorithm
	sort(all(adj));
	ll mn = 0;
	for(auto e : adj) {
		ll u = e.u;
		ll v = e.v;

		if(find(u) != find(v)){
			mn += e.c;
			join(u, v);
			edgs.push_back(e);
		}
	}
	// mn = cost of minimum spanning tree
	// edgs = list of all edges of the MST
}
```


## Applications of Kruskal

### [1] 2nd MST
> We can find 2nd MST using Krusal(eaiser) | using Prim

#### Steps

1. Find MST
2. For each edge in the MST
	- Remove edge
	- Run MST, compare it for the min value
	- ReAdd the edge u removed
6. Display MST2 value



### [2] Partial MST 
> We already connected some edges together, add minimum number of edges to make the graph full connect (every edge can reach any edge in the graph)

#### Steps
> This method is applicable only for small n

1. Take the given edges which suppose to be connect already
2. Union them together
3. For the rest of the edge (not connected already)
4. Run Kruskal
	5. Sort all the edge
	6. ...etc
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

### [3] Find MiniMax using Kruskal
> MiniMax is the path between 2 nodes such that maximum cost of edge over path is as minimum as possible



#### Steps for MiniMax of the whole graph 

1. Run Kruskal
2. Last added edge is the minimax

Problem : [F - Travelling Salesman GYM/100712](https://codeforces.com/gym/100712)
#### Steps fro MiniMax between 2 nodes

1. Run Kruskal while the 2 nodes are not connected yet
2. Last added edge is the minimax between the 2 nodes


