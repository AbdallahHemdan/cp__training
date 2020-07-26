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

ll gcd(ll a, ll b) { return ((!b) ? a : gcd(b, a%b)); }
ll LCM(ll a, ll b) { return a / (gcd(a, b))*b; }




int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll l, r;
	cin >> l >> r;
	if (r - l < 2) {
		return puts("-1");
	}
	for (ll i = l; i <= r; i++) {
		for (ll j = i + 1; j <= r; j++) {
			for (ll k = j + 1; k <= r; k++) {
				if (gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) != 1) {
					cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
	}

}