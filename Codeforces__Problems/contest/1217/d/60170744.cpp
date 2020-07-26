#include <bits/stdc++.h>
#define lop(i,init,n) for(ll i = init ; i< n ;i++)
#define sc(m) cin >> m
#define print(n) cout  << n << endl
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using ll = long long int;
using ld = long double;

using namespace std;

const int maxn  = 5e3+3;
int n , m ;
vector<int> adj[maxn];
int indegree[maxn];
vector<pii> edges;
queue<int> Q;
int main(){
	IO;
	cin >> n >> m ;
	lop(i,0,m){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
		edges.push_back({u,v});
	}
	int cnt = 0;
	for(int i = 1; i<=n ;i++){
		if(!indegree[i]){
			Q.push(i);
		}
	}
	while(!Q.empty()){
		cnt++;
		auto tmp = Q.front();
		Q.pop();
		for(auto v : adj[tmp]){
			indegree[v]--;
			if(!indegree[v]){
				Q.push(v);
			}
		}
	}
	if(cnt == n){
		print(1);
		for(int i = 1 ; i<=m ;i++){
			cout << "1 " ;
		}
		print("");
	}else{
		print(2);
		for(auto i : edges){
			if(i.first < i.second){
				cout << "1 ";
			}else{
				cout << "2 ";
			}
		}
		print("");
	}
}