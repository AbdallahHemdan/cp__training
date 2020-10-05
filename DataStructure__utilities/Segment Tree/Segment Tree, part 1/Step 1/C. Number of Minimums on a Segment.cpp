// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define IO                                                             \
    ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), \
        cout.tie(0)
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

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }
double distance(double x1, double y1, double x2, double y2) {
	return hypot(fabs(x1 - x2), fabs(y1 - y2));
}
int comp_double(double a, double b) {
	if (fabs(a - b) <= EPS) return 0;  // equal
	return (a < b) ? -1 : 1;
}

ll n, m;
struct segTree {
	ll size;
	vector<pll> tree;

	void init(ll n) {
		size = 1;
		while (size < n) size *= 2LL;

		tree.assign(size << 1, {LLONG_MAX, 0});
	}

	pll merge(pll a, pll b) {
		pll ret;

		if (a.first == b.first) {
			ret = { a.first, a.second + b.second };
		}
		if (a.first < b.first) {
			ret = { a.first, a.second };
		}

		if (b.first < a.first) {
			ret = { b.first, b.second};
		}

		return ret;
	}

	void build(vll& a, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			if (lx < a.sz) {
				tree[x] = { a[lx] , 1 };
			}
			return;
		}

		ll m = lx + (rx - lx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);

		tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
	}
	void build(vll& a) { build(a, 0, 0, size); }

	void set(ll i, ll v, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			tree[x] = { v, 1 };
			return;
		}

		ll m = lx + (rx - lx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}

		tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
	}
	void set(ll i, ll v) { set(i, v, 0, 0, size); }

	pll get(ll l, ll r, ll x, ll lx, ll rx) {
		if (lx >= r || rx <= l) {
			return { LLONG_MAX , 0 };
		}

		if (lx >= l && rx <= r) {
			return { tree[x].first, tree[x].second };
		}

		ll md = lx + (rx - lx) / 2;

		pll a = get(l, r, 2 * x + 1, lx, md);
		pll b = get(l, r, 2 * x + 2, md, rx);
		
		return merge(a, b);
	}
	pll get(ll l, ll r) { return get(l, r, 0, 0, size); }
};

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	cin >> n >> m;
	segTree st;
	st.init(n);

	vll a(n);
	for (ll& i : a) cin >> i;

	st.build(a);

	while (m--) {
		ll q;
		cin >> q;
		if (q == 1) {
			ll i, v;
			cin >> i >> v;

			st.set(i, v);
		}
		else {
			ll l, r;
			cin >> l >> r;

			pll ret = st.get(l, r);
			cout << ret.first << ' ' << ret.second << endl;
		}
	}
}
