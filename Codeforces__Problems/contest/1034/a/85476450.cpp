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


const ll maxn = 15000001;
ll frq[maxn];
bool vis[maxn];

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n; 
	cin >> n;

	ll mx = LLONG_MIN;
	ll gcd = 0;

	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
		mx = max({ mx, i });
		gcd = GCD(gcd, i);
		frq[i]++;
	}

	ll ans = 1e9;

	for (ll i = gcd + 1; i <= mx; i++) {
		if (vis[i]) continue;
		ll ret = 0;
		for (ll k = i; k <= mx; k += i) {
			ret += frq[k];
			vis[k] = 1;
		}
		ans = min(ans, n - ret);
	}
	if (ans == 1e9) ans = -1;
	cout << ans << endl;

}