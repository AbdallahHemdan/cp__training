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

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };
ll __gcd(ll a, ll b) { return ((!b) ? a : __gcd(b, a%b)); }

ll a, b, c;
ll ans;
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	cin >> a >> b >> c;
	// a = x + z
	// b = x + y
	// c = y + z
	for (ll x = 0; x <= 1000050; x++) {
		ll z = a - x;
		ll y = b - x;
		if (y == c - z && x >= 0 && y >= 0 && z >= 0) 
			return cout << x << ' ' << y << ' ' << z << endl, 0;
	}
	cout << "Impossible" << endl;
}