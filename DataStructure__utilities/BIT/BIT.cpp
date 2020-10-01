const int N = 1e6 + 16;

ll n, q;
ll a[N];
ll BIT[N];

void update(ll x, ll val) {
	for (; x <= n; x += (x&-x)) {
		BIT[x] += val;
	}
}

ll get(ll x) {
	ll ret = 0;
	for (; x > 0; x -= (x&-x)) {
		ret += BIT[x];
	}
	return ret;
}

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		char state;
		cin >> state;

		if (state == 'q') { // get
			ll l, r;
			cin >> l >> r;
			cout << get(r) - get(l - 1) << endl;
		}
		else { // update
			ll idx, val;
			cin >> idx >> val;
			update(idx, val);
		}
	}
}
