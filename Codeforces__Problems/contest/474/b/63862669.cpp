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

const int N = 2e6 + 26;
int a[N];
int main(){
	IO;
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#else
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
#endif
	ll n; cin >> n; 
	ll id = 0; 
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		while (x--) {
			a[++id] = i + 1; 
		}
	}
	int q; cin >> q;
	while (q--) {
		int x; cin >> x; cout << a[x] << endl;
	}
}