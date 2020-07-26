// Author : Abdallah Hemdan
// Problem : C
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



const int maxn = 1e5 + 15;
ll a[maxn];
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n, m; cin >> n >> m; 
	vector<int> a(n), b(m);
	ll xoL = 0, xoR = 0; 
	for (auto& i : a) cin >> i, xoL ^= i;
	for (auto& i : b) cin >> i, xoR ^= i;
	if (xoL != xoR) return puts("NO");
	else {
		cout << "YES" << endl;
		ll a11 = a[0]; 
		for (int i = 1; i < m; i++) a11 ^= b[i];
		cout << a11 << ' ';
		for (int i = 0; i < m - 1; i++) cout << b[i + 1] << ' ';
		cout << endl;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (!j) cout << a[i + 1] << ' ';
				else cout << "0 ";
			}
		}
		cout << endl;
	}
}