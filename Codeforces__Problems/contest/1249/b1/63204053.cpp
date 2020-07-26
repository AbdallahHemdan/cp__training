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
		for (int i = 0; i < n; i++) {
			cin >> a[i]; a[i] --;
		}
		for (int i = 0; i < n; i++) {
			int cnt = 0; 
			int k = i; 
			do {
				cnt++; 
				k = a[k];
			} while (k != i);
			cout << cnt << ' ';
		}
		cout << endl;
	}
}