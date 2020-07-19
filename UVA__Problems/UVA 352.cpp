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


const int maxn = 35;
string a[maxn];
int vis[maxn][maxn];
int n, t = 1;

bool valid(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j]);
}

void dfs(int i, int j) {
	if (!valid(i, j)) return;
	vis[i][j] = 1;
	for (int k = 0; k < 8; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (valid(nx, ny) && a[i][j] == '1') {
			dfs(nx, ny);
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
	while (cin >> n) {
		memset(vis, 0, sizeof vis);
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int ret = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!vis[i][j] && a[i][j] == '1') {
					dfs(i, j);
					ret++;
				}
			}
		}
		cout << "Image number " << t++ << " contains " << ret << " war eagles." << endl;
	}
}
					
