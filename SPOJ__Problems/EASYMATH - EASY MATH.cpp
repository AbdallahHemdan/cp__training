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

ll v[5];

ll solve(ll idx, ll d, ll sign, ll n) {
	if (idx == 5) {
		return sign * ll(n / d);
	}

	ll ret = 0;
	ret += solve(idx + 1, d, sign, n);
	ret += solve(idx + 1, LCM(d, v[idx]), sign * -1, n);

	return ret;
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
		ll n, m, a, d;
		cin >> n >> m >> a >> d;
		v[0] = a;
		v[1] = a + d;
		v[2] = a + 2 * d;
		v[3] = a + 3 * d;
		v[4] = a + 4 * d;

		ll ret = solve(0, 1, 1, m) - solve(0, 1, 1, n - 1);
		cout << ret << endl;
	}
}
