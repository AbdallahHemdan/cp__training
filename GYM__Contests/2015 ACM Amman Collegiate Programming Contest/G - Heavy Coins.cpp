// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll,ll>
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


int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		vll a(n);
		for (auto& i : a) cin >> i;
		ll mx = LLONG_MIN;

		for (ll mask = 1; mask < (1 << n); mask++) {
			ll no = 0;
			ll sm = 0;
			ll mn = LLONG_MAX;
			
			for (ll i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					no++;
					sm += a[i];
					mn = min({ mn, a[i]});
				}
			}
			if (sm >= k && sm - k < mn) {
				mx = max({ mx, no });
			}
		}
		cout << mx << endl;
	}
}
