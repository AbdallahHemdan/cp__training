#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define forab(i,a,b){}  for(int i = a; i<b;i++){} ;

vector <pair<int, int>> g[101];
int curr_color, ans, from, to;
int vis[101];

void dfs(int node) {
    vis[node] = 1;
	if (node == to) { ans++;  return;}
	for (int i = 0; i < g[node].size(); i++) {
		pair <int, int> newnode = g[node][i];
		if (newnode.second == curr_color && vis[newnode.first] == 0) {
			dfs(newnode.first);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, c, u, v, q;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		g[u].push_back( make_pair(v,c) );
		swap(u, v);
		g[u].push_back(make_pair(v,c));
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> from >> to;
		ans = 0;
		for (int j = 0; j < g[from].size(); j++) {
			curr_color = g[from][j].second;
			memset(vis,0,sizeof vis);        
			vis[from] = 1;
			dfs(g[from][j].first);    
		}
		cout << ans << "\n";
	}


	return 0;
}