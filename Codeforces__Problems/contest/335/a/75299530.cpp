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


const int maxn = 30;
int cnt[maxn];
string s;
int n;

string solve(int ret) {
	string t;
	for (int i = 0; i < 26; i++) {
		int cc = cnt[i] / ret;
		if (cnt[i] % ret) cc++;
		t += string(cc, 'a' + i);
	}
	return t;
}
int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	cin >> s;
	cin >> n;
	int cc = 0; 
	for (char c : s)cnt[c - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (cnt[i]) cc++;
	}
	if (cc > n) { // number of char > sketch length
		cout << -1 << endl;
		return 0;
	}
	int ret = 1; 
	while (1) { // while cover our string
		string t = solve(ret);
		if (t.size() > n) {
			ret++; 
			continue;
		}
		while (t.size() < n) t += "h";
		cout << ret << endl;
		cout << t << endl;
		return 0;
	}
}