#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& i : a) cin >> i;
		sort(a.begin(), a.end());
		bool ok = 0;
		for (int i = 0; i < n - 1; i++) {
			if (abs(a[i] - a[i + 1]) == 1) ok = 1;
		}
		if (ok) cout << "2\n";
		else cout << "1\n";
	}
}