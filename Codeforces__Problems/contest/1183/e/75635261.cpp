// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
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




int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	queue<string> q;
	set<string> st;
	ll ret = 0;
	q.push(s);
	st.insert(s);
	while (!q.empty()) {
		if (st.sz >= k) break;
		string u = q.front();
		q.pop();
		for (int i = 0; i < u.sz; i++) {
			string v = u;
			v.erase(i, 1);
			if (st.count(v) == 0) {
				if (st.sz < k) {
					q.push(v);
					st.insert(v);
					ret += n - v.sz;
				}
			}
		}
	}
	(st.sz < k) ? cout << -1 << endl : cout << ret << endl;
}