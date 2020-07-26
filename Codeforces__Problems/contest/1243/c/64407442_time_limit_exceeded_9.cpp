// Author : Abdallah Hemdan
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }




int main() {
	int n; scanf("%d", &n);
	set<int> st;
	for (int i = 2; i * i <= n; i++) {
		if (n%i == 0) { // it devise me 
			st.insert(i);
			st.insert(n / i);
		}
	}
	int ans = 0;
	if (st.sz == 0) printf("%d\n", n);
	else {
		for (auto it : st) ans = GCD(ans, it);
		printf("%d\n", ans);
	}
}
