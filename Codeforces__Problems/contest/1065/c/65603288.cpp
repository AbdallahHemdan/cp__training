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



const int maxn = 3e5 + 35; 
ll frq[maxn];
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n, k, mn = LLONG_MAX; cin >> n >> k;
	vector<ll> a(n);
	for (ll& i : a) cin >> i, frq[i]++, mn = min(mn, i);
	sort(all(a));
	ll ans = 0, sm = 0, cnt = 0; 
	for (ll i = maxn - 1; i > mn; --i) {
		cnt += frq[i];
		sm += frq[i] * i;
		if (sm - cnt*(i - 1) > k) {
			a.back() = i; 
			sm = cnt * i;
			ans++;
		}
	}
	if (a[0] != a.back()) ans++;
	cout << ans << endl;
}