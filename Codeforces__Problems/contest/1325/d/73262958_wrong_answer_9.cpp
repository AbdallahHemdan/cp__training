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


int a, b;
void go() {
	int aa = a;
	int bb = (b - a) / 2;
	int cc = bb;
	bool ok = (aa + bb) == (aa^bb);
	if (ok) printf("2\n%d %d\n", aa + bb, bb);
	else printf("3\n%d %d %d\n", aa, bb, cc);
}

void getACISA() {
	scanf("%d%d", &a, &b);
	bool ok2 = (a > b || a % 2 != b % 2);
	if (ok2) printf("-1\n");
	else if (!a && !b) printf("0\n");
	else if (a == b) printf("1\n%d\n", a);
	else go();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
	// freopen("Out.txt", "w", stdout);
#else
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	ll t; t = 1;
	while (t--) {
		getACISA();
	}
	return 0;
}