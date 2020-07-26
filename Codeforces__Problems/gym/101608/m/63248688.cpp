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
ll __gcd(ll a, ll b) { return ((!b) ? a : __gcd(b, a%b)); }


int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n, k; cin >> n >> k;
	if (k < n / 2 || (n == 1 && k)) cout << "-1" << endl;
	else {
		if (n / 2 == k) {
			ll tmp = 0;
			for (int i = 0; i < n / 2; i++) {
				tmp += __gcd(2 * i + 1, 2 * i + 2);
				cout << 2 * i + 1 << " " << 2 * i + 2 << " ";
 			}
			if (n & 1) cout << "1000000000" << endl;
		}
		else if (n / 2 < k) {
			ll diff = k - n / 2;
			ll lst = -1;
			ll tmp = 0;
			diff--;
			for (int i = 1; i <= 2 * diff; i+= 2) {
				tmp += __gcd(2 * i, 2 * i + 2);
				cout << i * 2 << ' ' << (i * 2 + 2) << ' ';
				lst = i * 2 + 2;
			}
			if (~lst) {
				for (int i = 0; i < n / 2 - diff + 1; i++) {
					tmp += __gcd(lst + 1, lst + 2);
					cout << lst + 1 << " " << lst + 2 << " ";
					lst++;
				}
				if (n & 1) cout << "1000000000" << endl;
			}
		}
	}


}