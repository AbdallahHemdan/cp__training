// Floyd-Warshall O(n^3)
// Used to find shortest-path between each pair in the Graph using Dynamic-Programming


const int N = 101;

// Assume that:
// ------------
// adj[u][u] = 0
// adj[u][v] = cost(u, v)   when direct edge exists from u to v with cost (u, v)
// adj[u][v] = INF          otherwise
// par[u][v] = u
// ----------------------------------------------------


ll n, adj[N][N], par[N][N];
vll path;
// Initializes the graph adjacent matrix
void init() {
	lop(i,0,n) lop(j,0,n)
			adj[i][j] = (i ^ j ? OO : 0),
			par[i][j] = i;
}

// Finds the shortest path between any pair of nodes in the given graph
// and updates the adjacent matrix accordingly by running Floyd Warshall's algorithm.
// O(n^3)
void floyd() {
	lop(k, 0, n) lop(i, 0, n) lop(j, 0, n)
		if (adj[i][j] > adj[i][k] + adj[k][j])
			adj[i][j] = adj[i][k] + adj[k][j],
			par[i][j] = par[k][j];
}


// asssume that we only care if a their is a path or not , not carring about shortest path
// so the graph has one 2 value 
// 0 - their is no connection
// 1 - their is a connection
void TransitiveClosure() {
	lop(k, 0, n) lop(i, 0, n) lop(j, 0, n)
		adj[i][j] |= (adj[i][k] && adj[k][j]);
}

// find the path such that max value on road is minimum
void minmax() {
	lop(k, 0, n) lop(i, 0, n) lop(j, 0, n)
		adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
}

// find path such that min value on road is maximum
void maxmin() {
	lop(k, 0, n) lop(i, 0, n) lop(j, 0, n)
		adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
}


// assume we are carring about count the number of paths between the each pair of nodes
// we need to initialize the graph with (0's or 1's)
// 0-means their is no a path
// 1-means their is a path 
void countPaths() {
	lop(k, 0, n) lop(i, 0, n) lop(j, 0, n)
		adj[i][j] += adj[i][k] * adj[k][j];
}

// Returns whether the graph has negative cycles or not
// by checking the adjacent matrix - after running Floyd Warshall's - algorithm
// O(n)
bool checkNegativeCycle() {
	bool ret = 0;
	lop(i, 0, n) {
		ret = ret || (adj[i][i] < 0);
	}
	re ret;
}

void longestPathDAG(){
	lop(k, 0, n) lop(i, 0, n) lop(j, 0, n)
			adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);	
}

// Prints the shortest path from node u to node v after running Floyd Warshall's algorithm.
// Note that the path is encoded in reversed order, so we need to print it recursively.
void printPath(ll u, ll v) {
	if (u != v) {
		printPath(u, par[u][v]);
	}
	path.PB(v + 1); // +1 for retrive it to 1-based
}


int graphDiameter(){
	// graph diamete: is the longest distance between 2 nodes
	// the only way to find graph diameter is Floyer Warshall


	// Steps: 
	// 1. Run floyd
	// 2. Loop over all nodes
	// 3. if there is a path between 2 nodes (defined)
	// 4. maximize over the mx value


	floyd();
	int mx = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j =  0 ; j < n ; j++){
			if(adj[i][j] < OO) { // there is a path 
				mx = max({ mx, adj[i][j] });
			}
		}
	}
}

// Example
// 4 5
// 1 3 -2
// 2 1 4
// 2 3 3
// 3 4 2
// 4 2 -1
int main() {
	// Read number of nodes
	sc(n);

	// Initializes the graph's adjacent matrix
	init();

	// Read edges
	ll m, u, v, w, q;
	sc(m);
	while (m--) {
		sc3(u, v, w);
		adj[u - 1][v - 1] = w; // Working on 0-based
	}

	// Compute all-pairs shortest path
	floyd();

	// Print adjacent matrix after running Floyd Warshal's algorithm
	cout << endl << "All-Pairs Shortest Path:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << setw(4) << adj[i][j] << (" \n"[j == n - 1]);
		}
	}
	cout << endl;

	// Read pairs and print their shortest path
	sc(q);
	while (q--) {
		sc2(u, v);
		printPath(u - 1, v - 1);
		print("");
	}
}

/*-------------------------------------------------------------*/

int n, m, q;
const int N = 505;
ll dp[N][N];

int main() {
    IO;
#ifndef ONLINE_JUDGE
    freopen("In.txt", "r", stdin);
    freopen("Out.txt", "w", stdout);
#else
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
#endif
    cin >> n >> m >> q;

    memset(dp, 0x3f, sizeof(dp));

    for (int i = 0; i < m; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        dp[u][v] = min(dp[u][v], c);
        dp[v][u] = min(dp[v][u], c);
    }

    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (dp[u][v] >= 1e18)
            cout << -1 << endl;
        else
            cout << dp[u][v] << endl;
    }
}
