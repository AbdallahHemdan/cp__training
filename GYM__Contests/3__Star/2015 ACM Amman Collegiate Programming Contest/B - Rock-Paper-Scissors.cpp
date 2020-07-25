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


const ll maxn = 1e3 + 13;
ll frqS[maxn];
ll frqR[maxn];
ll frqP[maxn];

ll solve(ll l, ll r, char e) {
	if (e == 'R') {
		return frqR[r] - ((l == 0) ? 0 : frqR[l - 1]);
	}
	else if (e == 'P') {
		return frqP[r] - ((l == 0) ? 0 : frqP[l - 1]);
	}
	else {
		return frqS[r] - ((l == 0) ? 0 : frqS[l - 1]);
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
		ll n; cin >> n;
		string s; cin >> s;

		memset(frqS, 0, sizeof frqS);
		memset(frqR, 0, sizeof frqR);
		memset(frqP, 0, sizeof frqP);

		for (ll i = 0; i < n; i++) {
			frqS[i] = (s[i] == 'S');
			frqR[i] = (s[i] == 'R');
			frqP[i] = (s[i] == 'P');
		}
		for (int i = 1; i < n + 2; i++) {
			frqS[i] += frqS[i - 1];
			frqR[i] += frqR[i - 1];
			frqP[i] += frqP[i - 1];
		}

		ll ret = 0;
		for (ll x = 0; x <= n; x++) {
			for (ll y = 0; y <= n; y++) {
				if (x + y > n) continue;
				ll z = n - x - y;

				if (x + y + z == n) {
					ll win = solve(0, x - 1, 'S') + solve(x, x + y - 1, 'R') + solve(x + y, x + y + z - 1, 'P');
					ll lose = solve(0, x - 1, 'P') + solve(x, x + y - 1, 'S') + solve(x + y, x + y + z - 1, 'R');

					if (win > lose) ret++;
				}
			}
		}
		cout << ret << endl;
	}
}
