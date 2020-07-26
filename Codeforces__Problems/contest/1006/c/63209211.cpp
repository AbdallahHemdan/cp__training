#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<ll> a(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll i = 0, j = n + 1; 
	ll smi = 0, smj = 0; 
	ll it = 0;
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
	cout << accumulate(a .begin() + 1, a.begin() + 1 + it, 0LL) << endl;
}