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

double distance(double x1, double y1, double x2, double y2) {
	return hypot(fabs(x1 - x2), fabs(y1 - y2));
}


int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll r1, r2; cin >> r1 >> r2;
	ll c1, c2; cin >> c1 >> c2;
	ll d1, d2; cin >> d1 >> d2;


	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				for (ll l = 1; l <= 9; l++) {
					if (i + j == r1) {
						if (i + k == c1) {
							if (j + l == c2) {
								if (k + l == r2) {
									if (i + l == d1) {
										if (j + k == d2) {
											if (i != j && i != k && i != l) {
												if (j != k && j != l && k != l) {
													cout << i << ' ' << j << endl;
													cout << k << ' ' << l << endl;
													return 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << -1 << endl;
}