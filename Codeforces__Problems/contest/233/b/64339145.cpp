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




ll n, dis, x, ans = 2e9;
int sumDigits(ll x) {
	int res = 0;
	while (x) res += x % 10, x /= 10;
	return res;
}
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	// x^2 + s(x).x - n = 0
	// x^2 <= n  then x <= sqrt(n) then x <= 1e9
	// 1e9 with max 9 digits 999999999
	// then max s(x) = 9 * 10 = 90
	cin >> n;
	for (ll i = 1; i <= 90; i++) {
		dis = sqrt(i * i + 4 * n);
		x = (dis - i) / 2; 
		if (x > 0 && x*x + x * i - n == 0 && sumDigits(x) == i) {
			ans = min(ans, x);
		}
	}
	cout << (ans < 2e9 ? ans : -1) << endl;
}