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
 
const int dx[] = { 1, -1, 0, 0};
const int dy[] = { 0, 0, 1, -1};
 
ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }
 
ll PowMod(ll bs, ll ex, ll M) { if (!ex)return 1; ll p = PowMod((bs*bs) % M, ex >> 1, M); return (ex & 1) ? (p*bs) % M : p; }
 
 
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
    ll n; cin >> n;
    ll ans = PowMod(1378,n,10);
    cout << ans << endl;
}