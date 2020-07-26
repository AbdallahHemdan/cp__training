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

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	int n, k; cin >> n >> k;
	n = 2 * n + 1;
	vi a(n);
	for (int& i : a) cin >> i;
	for (int i = 1; i < n - 1; i += 2) {
		if (a[i] - 1 > a[i - 1] && a[i] - 1 > a[i + 1] && k) a[i]--, k--; 
	}
	for (int& i : a) cout << i << ' ';
	cout << endl;
}