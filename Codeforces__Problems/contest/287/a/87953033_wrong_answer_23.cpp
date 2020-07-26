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


char a[4][4];
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	for (ll i = 0; i < 4; i++) {
		for (ll j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			
			ll w = 0, b = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 2; l++) {
					if (a[k][l] == '#') b++;
					else w++;
				}
			}
			if (b >= 3 || w >= 3) {
				cout << "YES" << endl;
				return 0;
			}

		}
	}
	cout << "NO" << endl;
}