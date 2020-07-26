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

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };
ll __gcd(ll a, ll b) { return ((!b) ? a : __gcd(b, a%b)); }


int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	vector<bool> lights(n + 1, 1);
	vector<ll> ans(n + 1);
	for (ll& i : a) cin >> i;
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= n; j++) {
			if (lights[j]) {
				lights[j] = 0;
				ans[j] = a[i];
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << endl;
}