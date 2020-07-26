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

const int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }

const int maxn = 5e3 + 53;
int dp[maxn][5];
int a[maxn];
string s;

int solve(int i, int prt) {
	if (i == s.size()) return 0;
	int& ret = dp[i][prt];
	if (~ret) return ret;
	ret = 0;
	ret = max(ret, solve(i + 1, prt));
	if (prt == 0) {
		if (s[i] == 'a') ret = max(ret, solve(i + 1, prt) + 1);
		else ret = max(ret, solve(i + 1, 1) + 1);
	}
	else if (prt == 1) {
		if (s[i] == 'b') ret = max(ret, solve(i + 1, prt) + 1);
		else ret = max(ret, solve(i + 1, 2) + 1);
	}
	else if (prt == 2 && s[i] == 'a') {
		ret = max(ret, solve(i + 1, prt) + 1);
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
	cin >> s;
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0) << endl;
	
}
