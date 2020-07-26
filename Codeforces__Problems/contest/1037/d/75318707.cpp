// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
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

const int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }


const int maxn = 2e5 + 25; 
vector<int> adj[maxn];
vector<int> ans;
int inorder[maxn], outorder[maxn];
int vis[maxn];

bool cmp(int a, int b) {
	return outorder[a] < outorder[b];
}
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	int n; cin >> n; 
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		outorder[inorder[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		sort(all(adj[i]), cmp);
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {

		int u = q.front();
		q.pop();
		ans.push_back(u);
		vis[u] = 1;
		for (int v : adj[u]) {
			if (!vis[v]) {
				q.push(v);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] != inorder[i]) return puts("No");
	}
	puts("Yes");
}
