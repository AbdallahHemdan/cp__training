# PowerSet (All subsets of S)
> PowerSet of set `S` is the set of all subsets of `S`.

> If set `S` has n element, So P(S) = 2 ^ n

```cpp
for example:
S = {a, b, c}

P(S) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.
```

```
0 => 000
1 => 001
2 => 010
3 => 011
4 => 100
5 => 101
6 => 110
7 => 111
```
### Check if bit is setted or not

```
1 << i

if number of elements  = 3

(i = 0) => So => 001
(i = 1) => So => 010
(i = 2) => So => 100
```

```cpp
ll n = 3;
string s = "abc";

for (ll mask = 0; mask < (1 << n); mask++) {
  for (ll i = 0; i < n; i++) {
    if ((1 << i) & mask) {
      cout << s[i];
    }
  }
  cout << endl;
}
```

### Heavy Coins (gym/100712)

```cpp
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
	ll t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		vll a(n);
		for (auto& i : a) cin >> i;
		ll mx = LLONG_MIN;

		for (ll mask = 1; mask < (1 << n); mask++) {
			ll no = 0;
			ll sm = 0;
			ll mn = LLONG_MAX;
			
			for (ll i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					no++;
					sm += a[i];
					mn = min({ mn, a[i]});
				}
			}
			if (sm >= k && sm - k < mn) {
				mx = max({ mx, no });
			}
		}
		cout << mx << endl;
	}
}
```

