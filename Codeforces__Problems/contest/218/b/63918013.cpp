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
	multiset<int> st_1;
	multiset<int,greater<int>> st_2;
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		st_1.insert(x);
		st_2.insert(x);
	}
	int mn = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		int top = *st_1.begin();
		st_1.erase(st_1.find(top));
		mn += top;
		if(top - 1) st_1.insert(top - 1);
	}
	for (int i = 0; i < n; i++) {
		int top = *st_2.begin();
		st_2.erase(st_2.find(top));
		mx += top;
		if (top - 1) st_2.insert(top - 1);
	}
	cout << mx << ' ' << mn << endl;

}