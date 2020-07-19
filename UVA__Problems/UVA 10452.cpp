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

const int dx[] = { 0, 0, -1};
const int dy[] = { 1, -1, 0};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }


int n, m;
int sx, sy;
int ex, ey;
string a[15];
int vis[15][15];

string dir[3] = { "right", "left", "forth" };
vector<string> ret;
bool exists(int r, int c) {
	return (a[r][c] == 'I' || a[r][c] == 'E' || a[r][c] == 'H' || a[r][c] == 'O' || a[r][c] == 'V' || a[r][c] == 'A' || a[r][c] == '@' || a[r][c] == '#');
}
bool valid(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && exists(r, c));
}

void dfs(int i, int j) {
	if (!valid(i, j)) return;
	vis[i][j] = 1;

	for (int k = 0; k < 3; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];

		if (valid(nx, ny)) {
			ret.push_back(dir[k]);
			if (a[i][j] != '#') {
				dfs(nx, ny);
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
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '@') {
					sx = i, sy = j;
				}
			}
		}
		dfs(sx, sy);
		for (int i = 0; i < ret.sz - 1; i++) {
			cout << ret[i] << ' ';
		}
		cout << ret[ret.sz - 1] << endl;
		ret.clear();
	}
}
					
