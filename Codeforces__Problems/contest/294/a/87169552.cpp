// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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

ll pow_mod(ll b, ll e, ll mod) {
	if (!e) return 1;
	ll x = pow_mod((b * b) % mod, e >> 1, mod);
	return (e & 1) ? (x * b) % mod : x;
}

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n; cin >> n; 
	vector<ll> a(n);
	for (ll& i : a) cin >> i; 
	ll t; cin >> t; 
	while (t--) {
		ll x, y; cin >> x >> y;
		x--;
		if (x - 1 >= 0) {
			a[x - 1] += y - 1;
		}
		if (x + 1 < n) {
			a[x + 1] += a[x] - y;
		}
		a[x] = 0;
	}
	for (auto i : a) cout << i << endl;
}
