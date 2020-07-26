// Author : Abdallah Hemdan
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
using namespace std;
using ll = long long int;
using ld = long double;

const int maxn = 105;
vector<ll> adj[maxn];
bool vis[maxn];
vector<int> top;
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1; 
	for (auto i : adj[u]) dfs(i);
	top.push_back(u);
}
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll& i : a) cin >> i; 
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i ^ j) {
				if ((a[i] % 3 == 0 && a[i] / 3 == a[j]) || a[i] * 2 == a[j]) {
					adj[i].push_back(j);
				}
			}
		}
	}
	vector<ll> indegree(n);
	for (int i = 0; i < n; i++) {
		for (auto u : adj[i]) {
			indegree[u]++;
		}
	}
	queue<int> topo;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (!indegree[i]) topo.push(i);
	}
	while (topo.size()) {
		int u = topo.front();
		topo.pop();
		ans.push_back(u);
		for (auto i : adj[u]) {
			if (--indegree[i] == 0) {
				topo.push(i);
			}
		}
	}
	for (auto i : ans) cout << a[i] << ' ';
	cout << endl;

}