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



bool operator < (const string &a, const string &b) {
	if (a.size() < b.size()) return 1;
	if (b.size() < a.size()) return 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < b[i]) return 1;
		if (b[i] < a[i]) return 0;
	}
	return 1;
}

int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	string n; cin >> n;
	string b = "127", s = "32767", i = "2147483647", l = "9223372036854775807";
	if (n < b) cout << "byte" << endl;
	else if (n < s) cout << "short" << endl;
	else if (n < i) cout << "int" << endl;
	else if (n < l) cout << "long" << endl;
	else cout << "BigInteger" << endl;
}