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
ll n;
vector<int> a;
ll frq[N];
ll dp[N];
ll Solve(ll it) {
	if (it > 1e5) return 0;
	ll& ret = dp[it];
	if (~ret) return ret;
	ret = Solve(it + 1);
	ret = max(ret, Solve(it + 2) + it * frq[it]);
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
	cin >> n; 
	a.resize(n);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		frq[x]++;
	}
	cout << Solve(1) << endl;
}