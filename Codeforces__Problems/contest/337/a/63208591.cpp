#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(m);
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());
	int ans = a[n - 1] - a[0];
	for (int i = 1; i <= m - n; i++) {
		ans = min(ans, a[i + n - 1] - a[i]);
	}
	cout << ans << endl;
}