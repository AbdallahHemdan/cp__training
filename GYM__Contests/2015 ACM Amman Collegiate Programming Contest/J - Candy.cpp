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
		ll n, m; cin >> n >> m;
		map<ll, ll> ages;
		map<ll, ll> pack;
		for (ll i = 0; i < n; i++) {
			ll x; cin >> x;
			ages[x]++;
		}
		for (ll i = 0; i < m; i++) {
			ll x; cin >> x;
			pack[x]++;
		}

		ll lst = -1;
		ll sol = 1;
		for (auto i : ages) {
			ll ok = 0;
			for (auto j : pack) {
				if (j.second >= i.second && j.first > lst) {
					lst = j.first;
					ok = 1;
					break;
				}
			}
			if (!ok) {
				cout << "NO" << endl;
				sol = 0;
				break;
			}
		}
		if (sol) {
			cout << "YES" << endl;
		}
	}
}
