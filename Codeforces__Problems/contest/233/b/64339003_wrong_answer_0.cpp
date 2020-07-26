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

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }





ll smOfDigits(ll x) {
	ll sm = 0; 
	while (x) {
		sm += x % 10; 
		x /= 10;
	}
	return sm;
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
	// x^2 + s(x).x - n = 0
	// x^2 <= n  then x <= sqrt(n) then x <= 1e9
	// 1e9 with max 9 digits 999999999
	// then max s(x) = 9 * 10 = 90
	for (ll i = 0; i < 90; i++) {
		ll x = (-i + sqrt(i*i + 4 * n)) / 2; 
		if (x * x + i * x - n == 0 && x > 0 && smOfDigits(x) == n) {
			cout << x << endl;
			goto end;
		}
	}
	cout << -1 << endl;
	end:
	return 0;
}