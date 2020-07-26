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

const int N = 2e3 + 23; 
const int MOD = 1e9 + 7;
ll dp[N][N];
ll n, k;
ll Solve(ll l, ll v) {
	if (l == k - 1) return  1;
	ll& ret = dp[l][v];
	if (~ret) return ret;
	ret = 0;
	for (ll vv = v; vv <= n; vv += v) {
		ret += Solve(l + 1, vv);
		ret %= MOD;
	}
	return ret;
}
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	cin >> n >> k;
	memset(dp, -1, sizeof dp);
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += Solve(0, i) % MOD;
	}
	cout << ret << endl;
}