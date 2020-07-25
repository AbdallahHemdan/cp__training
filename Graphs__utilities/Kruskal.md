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
	3. Remove edge
	4. Run MST, compare it for the min value
	5. ReAdd the edge u removed
6. Display MST2 value



### [2] Partial MST 
> We already connected some edges together, add minimum number of edges to make the graph full connect (every edge can reach any edge in the graph)

#### Steps

1. Take the given edges which suppose to be connect already
2. Union them together
3. For the rest of the edge (not connected already)
4. Run Kruskal
	5. Sort all the edge
	6. ...etc


### [3] Find MiniMax using Kruskal
> MiniMax is the path between 2 nodes such that maximum cost of edge over path is as minimum as possible



#### Steps for MiniMax of the whole graph

1. Run Kruskal
2. Last added edge is the minimax


#### Steps fro MiniMax between 2 nodes

1. Run Kruskal while the 2 nodes are not connected yet
2. Last added edge is the minimax between the 2 nodes


