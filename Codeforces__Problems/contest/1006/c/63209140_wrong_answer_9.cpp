#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int i = 0, j = n + 1; 
	ll smi = 0, smj = 0; 
	int it = 0;
	while (i < j) {
		if (smi < smj) {
			smi += a[++i];
		}
		else if (smi > smj) {
			smj += a[--j];
		}
		else {
			it = i;
			smi += a[++i];
			smj += a[--j];
		}
	}
	cout << accumulate(a .begin() + 1, a.begin() + 1 + it, 0) << endl;
}