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
ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }

const int N = 1e5 + 15;
const int MOD = 1e9 + 7;
ll dp[N];
ll t, k;
ll Solve(ll i) {
	if (i < 0) return 0; 
	if (!i) return 1; 
	ll& ret = dp[i];
	if (~ret) return ret;
	ret = 0;
	ret = (Solve(i - 1) % MOD + Solve(i - k) % MOD) % MOD; 
	return MOD;
}
int main(){
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	memset(dp, -1, sizeof dp);
	cin >> t >> k; 
	for (int i = 0; i <= 100000; i++) Solve(i);
	for (int i = 1; i <= 100000; i++) dp[i] += dp[i - 1];
	while (t--) {
		ll a, b;  cin >> a >> b;
		ll ans = (dp[b] - dp[a - 1] + MOD) % MOD;
		cout << ans << endl;
	}
}