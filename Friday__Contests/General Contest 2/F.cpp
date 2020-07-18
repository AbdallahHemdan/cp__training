// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
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


const ll maxn = 1e5 + 15;
ll frq[maxn];

void getAC() {
	ll n, q; cin >> n >> q;
	for (ll i = 1; i <= n; i++) {
		frq[i] = 0;
		ll x;  cin >> x;
		ll cnt = 0;
		while (x > 1) {
			if (x & 1) cnt++, x--;
			x >>= 1; cnt++;
		}
		frq[i] = cnt; 
	}
	for (ll i = 2; i <= n; i++) frq[i] += frq[i - 1];
	for (ll i = 0; i < q; i++) {
		ll l, r; cin >> l >> r;
		ll ret = frq[r] - frq[l - 1];
		cout << ret << endl;
	}
}

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
		getAC();
	}
	return 0;
}