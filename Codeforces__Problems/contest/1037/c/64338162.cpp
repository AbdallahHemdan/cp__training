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





int n; 
const int N = 1e6 + 16;
string a, b; 
int dp[N];
int Solve(int i) {
	if (i == n) return 0;
	int& ret = dp[i];
	if (~ret) return ret;
	ret = INT_MAX;
	if (a[i] == b[i]) ret = Solve(i + 1);
	else ret = Solve(i + 1) + 1;
	if (i + 1 < n && a[i] == b[i + 1] && a[i + 1] == b[i]) ret = min(ret, 1 + Solve(i + 2));
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
	memset(dp, -1, sizeof dp);
	cin >> n;
	cin >> a >> b;
	cout << Solve(0) << endl;
}