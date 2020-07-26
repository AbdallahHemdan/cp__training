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

//ax+by=gcd(a,b)
ll eGCD(ll a, ll b, ll &x, ll &y) {
	x = 1;
	y = 0;
	ll nx = 0, ny = 1;
	ll t, r;
	while (b) {
		r = a / b;
		t = a - r * b;
		a = b;
		b = t;
		t = x - r * nx;
		x = nx;
		nx = t;
		t = y - r * ny;
		y = ny;
		ny = t;
	}
	return a;
	}
//ax+by=c
bool solveLDE(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
	g = eGCD(a, b, x, y);
	x *= c / g;
	y *= c / g;
	return (c % g) == 0;
}

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll a, b, c; cin >> a >> b >> c;
	ll x, y, g;
	if (!solveLDE(a, b, -c, x, y, g)) cout << -1 << endl;
	else cout << x << ' ' << y << endl;
}