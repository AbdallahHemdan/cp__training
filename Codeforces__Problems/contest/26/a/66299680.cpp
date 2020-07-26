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



ll n;
const int maxn = 3e3 + 33;
ll frq[maxn];
bool isprime[maxn];
void Seive() {
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i <= maxn; i++) {
		if (isprime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				frq[j]++, isprime[j] = 0; 
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans += (frq[i] == 2);
	cout << ans << endl;
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
	memset(isprime, 1, sizeof isprime);
	Seive();
}