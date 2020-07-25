// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
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

double distance(double x1, double y1, double x2, double y2) { 
	return hypot(fabs(x1 - x2), fabs(y1 - y2)); 
}


struct rect {
	pair<ld, ld> lft;
	pair<ld, ld> rgt;
	rect(pair<ld, ld> l, pair<ld, ld> r) {
		lft = l;
		rgt = r;
	}
};
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
  vector<rect> a;
	a.clear();
	string s; 
	while (true) {
		cin >> s;
		if (s == "r") {
			ld x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			a.push_back(rect({ x1, y1 }, { x2, y2 }));
		}
		else if (s == "*") {
			break;
		}
	}
	ld x0, y0;
	ll t = 1;
	while (cin >> x0 >> y0) {
		if (fabs(x0 - 9999.9) < 1e-3 && fabs(y0 - 9999.9) < 1e-3) break;
		bool isContained = 0;
		for(int i = 0 ; i  < a.sz ; i++) {
			auto u = a[i];
			if (x0 > u.lft.first && x0 < u.rgt.first) {
				if (y0 > u.rgt.second && y0 < u.lft.second) {
					cout << "Point " << t << " is contained in figure " << i + 1 << endl;
					isContained = 1;
				}
			}
		}
		if (!isContained) {
			cout << "Point " << t << " is not contained in any figure" << endl;
		}
		t++;
	}
}
