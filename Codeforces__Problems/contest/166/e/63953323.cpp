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

const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, 1, -1, 0, 0 };

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }


int n; 
const int N = 1e7 + 17;
int dp[N][4]; // a = 0 , b = 1 , c = 2 , d = 3
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	cin >> n;
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[0][3] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = ((dp[i - 1][1] + dp[i - 1][2]) % MOD + dp[i - 1][3]) % MOD;
		dp[i][1] = ((dp[i - 1][0] + dp[i - 1][2]) % MOD + dp[i - 1][3]) % MOD;
		dp[i][2] = ((dp[i - 1][1] + dp[i - 1][0]) % MOD + dp[i - 1][3]) % MOD;
		dp[i][3] = ((dp[i - 1][1] + dp[i - 1][2]) % MOD + dp[i - 1][0]) % MOD;
	}
	cout << dp[n][3] << endl;
} 