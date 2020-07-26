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

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }

const int maxn = 1e5 + 15;
ll n, src, dist;
vll adj[maxn];
ll dis[maxn];
void bfs() {
	memset(dis, -1, sizeof dis);
	queue<ll> q;
	q.push(src);
	dis[src] = 0;
	while (q.size()) {
		ll u = q.front();
		q.pop();
		for (ll x : adj[u]) {
			if (dis[x] == -1) {
				dis[x] = dis[u] + 1;
				q.push(x);
			}
		}
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
	cin >> n >> src >> dist;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		adj[i].push_back(x);
	}
	bfs();
	if (~dis[dist]) cout << dis[dist] << endl;
	else cout << -1 << endl;
}