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
	int n;
	cin >> n;
	if (n == 1) {
		cout << "I hate it" << endl;
	}
	else {
		if (n % 2 == 0) {
			for (int i = 0; i < n / 2 - 1; i++) {
				cout << "I hate that I love that ";
			}
			cout << "I hate that I love it" << endl;
		}
		else {
			for(int i = 0 ; i < n/2 ; i++){
				cout << "I hate that I love ";
				cout << "that ";
			}
			cout << "I hate it" << endl;
		}
	}
}