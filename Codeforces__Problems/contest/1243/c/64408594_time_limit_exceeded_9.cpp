// Author : Abdallah Hemdan
#include <bits\stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n ;
	set<int> st;
	for (int i = 2; i * i <= n; i++) {
		if (n%i == 0) { // it devise me 
			st.insert(i);
			st.insert(n / i);
		}
	}
	int ans = 0;
	if (st.empty()) cout << n;
	else {
		for (auto it : st) ans = __gcd(ans, it);
		cout << ans;
	}
}
