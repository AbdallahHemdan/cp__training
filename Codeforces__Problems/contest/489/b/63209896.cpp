#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

//const int N = 1e2 + 12;
//int n, m; 
//int a[N];
//int b[N];
//int dp[N][N];
//int Solve(int i, int j) {
//	if (i == n || j == m) return 0;
//	int& ret = dp[i][j];
//	if (~ret) return ret;
//	ret = 0;
//	if (abs(a[i] - b[j]) <= 1) {
//		ret = max({ ret, Solve(i + 1, j + 1) + 1, Solve(i, j + 1), Solve(i + 1, j)
//		});
//	}else{
//		ret = max({ ret,Solve(i + 1,j) , Solve(i,j + 1) });
//	}
//	return ret;
//}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int n, m;
	//memset(dp, -1, sizeof dp);
	//for (int i = 0; i < n; i++) cin >> a[i];
	//for (int i = 0; i < m; i++) cin >> b[i];
	//cout << Solve(0, 0) << endl;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	cin >> m;
	vector<int> b(m);
	for (int& i : b) cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (abs(a[i] - b[j]) <= 1) {	
				ans++, b[j] = 1e6;
				break;
			}
		}
	}
	cout << ans << endl;
}