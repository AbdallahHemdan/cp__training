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

const int maxn = 1e5 + 15;
const int oo = INT_MAX;
vi adj[maxn];
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n, m, k; cin >> n >> m >> k;
	vector<pair<pair<int, int>, int>> a(m);
	set<int> st;
	for (int i = 0; i < m; i++) {
		cin >> a[i].first.first >> a[i].first.second >> a[i].second;
	}
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		st.insert(x);
	}
	int mn = oo;
	for (int i = 0; i < m; i++) {
		if (st.count(a[i].first.first) || st.count(a[i].first.second))
			mn = min(mn, a[i].second);
	}
	if (mn == oo || n == k) cout << -1 << endl;
	else cout << mn << endl;
	
}