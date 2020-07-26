#include <bits\stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

const int N = 2e5 + 25; 
int frq[N];
int a[N];
int n, k; 
bool can(int x) {
	int sm = 0; 
	for (int i = 0; i < N; i++) sm += frq[i] / x;
	return sm >= k;
}
void get_ans(int m) {
	for (int i = 0; i < N; i++) {
		int x = frq[i] / m;
		while(x-- > 0){
			k--;
			cout << i << ' ';
			if (!k) return; 
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		frq[a[i]]++;
	}
	int l = 1, r = n;
	int ans;
	while (l <= r) {
		int mid = l + (r - l) / 2; 
		if (can(mid)) ans = mid, l = mid + 1; 
		else r = mid - 1; 
	}
	get_ans(ans);
	cout << endl;
}