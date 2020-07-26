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


int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n, k;  cin >> n >> k; 
	vector<ll> a(n);
	for (ll& i : a) cin >> i;
	sort(a.begin(), a.end());
	int i = 0;
	vector<ll> ans;
	for (int i = 0; i < n; i++) {
		if (a[i] <= k) {
			ans.push_back(a[i]);
			k -= a[i];
		}
		else {
			break;
		}
	}
	cout << ans.size() << endl;
	if (ans.sz) {
		for (ll i : ans) cout << i << ' ';
		cout << endl;
	}

}