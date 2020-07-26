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



int frq[30];

string ok(int l) {
	string s;
	for (int i = 0; i < 26; i++) {
		int cnt = (frq[i] + l - 1) / l;
		s += string(cnt, 'a' + i);
	}
	return s;
}
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	string s; cin >> s; 
	int n; cin >> n;
	for (char c : s) {
		frq[c - 'a']++;
	}
	int m = 0; 
	for (int i = 0; i < 26; i++)
		if (frq[i]) // you have a frq (char in s)
			m++;

	// -1 case
	if (m > n) return cout << -1 << endl, 0;
	
	int ret = 1; 
	while (1) {
		string ss = ok(ret);
		if (ss.size() > n) {
			ret++; 
			continue;
		}
		// the rest of n
		while (ss.size() < n) ss += 'a';
		cout << ret << endl;
		cout << ss << endl;
		return 0; 
	}
}