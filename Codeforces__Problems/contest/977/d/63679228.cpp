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

bool cmp(ll a, ll b) {
	ll a3 = 0, b3 = 0;
	ll a2 = 0, b2 = 0;
	while (a % 3 == 0) a /= 3, a3++;
	while (b % 3 == 0) b /= 3, b3++;
	if (a3 ^ b3) return a3 > b3;

	while (a % 2 == 0) a /= 2, a2++;
	while (b % 2 == 0) b /= 2, b2++;
	return a2 < b2;
}
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;
	sort(a.begin(), a.end(), cmp);
	for (ll i : a) cout << i << ' ';
	cout << endl;
}