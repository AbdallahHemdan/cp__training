#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

const int N = 1e2 + 12;
int n, m; 
int a[N];
int b[N];
int dp[N][N];
int Solve(int i, int j) {
	if (i == n || j == m) return 0;
	int& ret = dp[i][j];
	if (~ret) return ret;
	ret = 0;
	if (abs(a[i] - b[j]) <= 1) {
		ret = max({ ret, Solve(i + 1, j + 1) + 1, Solve(i, j + 1), Solve(i + 1, j)
		});
	}else{
		ret = max({ ret,Solve(i + 1,j) , Solve(i,j + 1) });
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	cout << Solve(0, 0) << endl;
}