// Author : Abdallah Hemdan
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>

using namespace std;



#define int long long
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define MP make_pair
#define pb push_back
#define fs first
#define sc second
#define pii pair<int, int> 
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sz(x) (int)(x).size()
#define vi vector<int>


int gcd(int a, int b) {
	return a ? gcd(b%a, a) : b;
}
vector<int> a;
void GetAC() {
	int n; cin >> n;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) { a.pb(i);
			if (i * i != n)
				a.pb(n / i);
		}
	}
	a.pb(n);
	int ans = 0;
	for (int i = 0; i < sz(a); i++) ans = gcd(ans, a[i]);
	cout << ans << endl;
}
int  main() {
	IO;
	GetAC();
}