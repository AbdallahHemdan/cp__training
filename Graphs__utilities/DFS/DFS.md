### [1] Standard DFS
> Standard version of dfs code

```cpp
const int maxn = 1e5 + 15;
vi adj[maxn];
bool vis[maxn];

vi topoSort;


void dfs(int u){
  if(vis[u]) return;
  vis[u] = 1;
  
  for(auto v : adj[u]){
    dfs(v);
  }
}

```


### [2] Count Of Connected Components
> Usage of dfs to calculate the number of connected components

```cpp

const int maxn = 1e5 + 15;
vi adj[maxn];
bool vis[maxn];

void dfs(int u){
  if(vis[u]) return;
  vis[u] = 1;
  
  for(auto v : adj[u]){
    dfs(v);
  }
}

int main(){
  int n, m; cin >> n >> m;
  for(int i = 0 ; i < n ; i ++){
    int x, y; cin >> x >> y;
    x--, y--;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  int ret = 0;
  for(int i = 0 ; i < n ; i++){
    if(!vis[i]){ // new component
      dfs(i);
      ret++;
    }
  }
}
```

### [3] Topological Sort
> Sorts all the nodes that are reachable from a given node "u" in a topological order using a DFS algorithm

```cpp
const int maxn = 1e5 + 15;
vi adj[maxn];
bool vis[maxn];

vi topoSort;


void topoSortDFS(int u){
  if(vis[u]) return;
  vis[u] = 1;
  
  for(auto v : adj[u]){
    dfs(v);
  }

  topoSort.push_back(u);
}

```


### [4] DFS with Flood-Fill
> using dfs in flood-fill problems 


```cpp
int n, m;
const int maxn = 1e5 + 15;

int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

bool valid(int r, int c){
  return (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]);
}

void dfs(int i, int j){
  if(!valid(i, j)) return;
  vis[i][j] = 1;
  
  for(int k = 0 ; k < 8 ; k++){ // try all neighbours
    int nx = i + dx[k];
    int ny = j + dy[k];
    if(valid(nx, ny)){
      dfs(nx, ny);
    }
  }
}

```

### [5] DFS with Bipartite graph
> using dfs to check if the current graph is a bipartite graph or not

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e8/Simple-bipartite-graph.svg/1200px-Simple-bipartite-graph.svg.png" width="60%" />


```cpp
// Bipartite Graph Check
const int N = 1e5 + 15;
ll color[N];
vll adj[N];
bool dfs(ll u = 1) {
	for (ll v : adj[u]) {
		if (color[v] == -1) {
			color[v] = color[u] ^ 1;
			if (!dfs(v)) {
				re 0;
			}
		}
		else if (color[v] == color[u]) {
			re 0;
		}
	}
	re 1;
}

bool isBipartiteGraph() {
	mms(color, -1);
	color[1] = 0;
	re dfs();
}

int main() {
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	IO;
	ll n, m; sc2(n, m);
	lop(i, 0, m) {
		ll u, v; sc2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	print(isBipartiteGraph());
}
```
