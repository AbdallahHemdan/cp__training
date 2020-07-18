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



ll distance(ll x1, ll y1, ll x2, ll y2) { 
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll q; cin >> q;
	// map<pair<radius, pair<x,y>>,includeOrNot> mp
	map<pair<ll, pair<ll, ll>>, ll> mp;
	while (q--) {
		string op; cin >> op; 
		ll x, y, r; cin >> x >> y >> r;
		if (op == "R") {
			if (mp.find(make_pair(r, make_pair(x, y))) == mp.end()) cout << "No" << endl;
			else {
				if (mp[make_pair(r, make_pair(x, y))]) cout << "Ok" << endl;
				else cout << "No" << endl;
				mp[make_pair(r, make_pair(x, y))] = 0;
			}
		}
		else {
			ll hasOverlapping = 0; 
			for (auto i : mp) {
				if (!i.second) continue;
				ll dist = distance(i.first.second.first, i.first.second.second, x, y);
				ll rr = i.first.first;
				if (dist < (rr + r)*(rr + r)) {
					hasOverlapping = 1;
					break;
				}
			}
			if (hasOverlapping) cout << "No" << endl;
			else {
				cout << "Ok" << endl;
				mp[make_pair(r, make_pair(x, y))] = 1;
			}
		}
	}
}