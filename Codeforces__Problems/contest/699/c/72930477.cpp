// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
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


const int maxn = 1e2 + 12;
int a[maxn], n;
// previous activity (0 = rest | 1 = gym | 2 = contest)
int dp[maxn][3]; // days - previous activity

int solve(int i, int prv) {
	if (i == n) return 0;
	int& ret = dp[i][prv];
	if (~ret) return ret;

	ret = INT_MAX;
	ret = min(ret, solve(i + 1, 0) + 1);
	if (a[i] == 1 || a[i] == 3) { // gym is avalible
		if (prv != 1) { // last activity was not a gym
			ret = min(ret, solve(i + 1, 1));
		}
	}
	if (a[i] == 2 || a[i] == 3) { // contest is avalible
		if (prv != 2) {// last activity was not a contest
			ret = min(ret, solve(i + 1, 2));
		}
	}
	return ret;
}
int main() {
	IO;
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << solve(0, 0) << endl;
}