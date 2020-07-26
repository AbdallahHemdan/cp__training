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
ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a%b)); }


int main() {
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n; cin >> n;
	if (n <= 2) return cout << "1\n1" << endl, 0;
	if (n == 3) return cout << "2\n1 3" << endl, 0;
	if (n == 4) return cout << "4\n3 1 4 2" << endl, 0;
	cout << n << endl;
	for (int i = 1; i <= n; i += 2) cout << i << ' ';
	for (int i = 2; i <= n; i += 2) cout << i << ' ';
	cout << endl;
}