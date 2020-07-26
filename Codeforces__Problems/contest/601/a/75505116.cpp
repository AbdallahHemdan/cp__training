// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
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



int n, m; 
const int maxn = 405;
vector<int> adj[maxn];
vector<int> adj2[maxn];
int dis[maxn];
int vis[maxn][maxn];

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	cin >> n >> m; 
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		vis[u][v] = 1;
		vis[v][u] = 1;
	}
	queue<int> q;
	q.push(1);
	memset(dis, -1, sizeof dis);
	dis[1] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	// no relawy path
	if (dis[n] == -1) return cout << -1 << endl, 0; 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			//if (i == 1 && j == n) continue;
			if (!vis[i][j]) {
				adj2[i].push_back(j);
				adj2[j].push_back(i);
			}
		}
	}
	int a = dis[n];
	while (!q.empty()) q.pop();
	q.push(1);
	memset(dis, -1, sizeof dis);
	dis[1] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj2[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	if (dis[n] == -1) return cout << -1 << endl, 0;
	cout << max(a, dis[n]) << endl;
}