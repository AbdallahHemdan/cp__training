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
ll ExtGCD(ll a, ll b, ll& x, ll& y) { if (!b) { x = 1; y = 0; return a; } ll r = ExtGCD(b, a%b, y, x); y -= a / b*x; return r; }

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll a, b, c; cin >> a >> b >> c;
	ll x, y; 
	ll g = ExtGCD(a, b, x, y);
	if (c % g) cout << -1 << endl;
	else {
		cout << x*(-c / __gcd(a, b)) << ' ' << y * (-c / __gcd(a, b)) << endl;
	}
}