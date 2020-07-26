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

int get(int a, int c)
{
	int x = -1;
	if (a == c)
		x = 1;
	else if (c) {
		if (a % c == 0)
			x = a / c;
	}
	return x;
}

bool ok(int a, int b, int c, int d) {
	int x = get(a, c);
	int y = get(b, d);
	return (x >= 0 && y >= 0 && (x == y || (x == 1 && a == 0) || (y == 1 && b == 0)));
}

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	int x, y;  cin >> x >> y;
	string s; cin >> s;
	int dx = 0, dy = 0; 
	int dxx = 0, dyy = 0;
	for (auto c : s) {
		dx += (c == 'R') - (c == 'L');
		dy += (c == 'U') - (c == 'D');
	}
	for (int i = 0; i < s.sz; i++) {
		if (ok(x - dxx, y - dyy, dx, dy)) {
			return puts("Yes");
		}
		dxx += (s[i] == 'R') - (s[i] == 'L');
		dyy += (s[i] == 'U') - (s[i] == 'D');
	}
	puts("No");
}