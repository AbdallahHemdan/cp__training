#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
using ll = long long int;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	 freopen("In.txt", "r", stdin);
	// freopen("Out.txt", "w", stdout);
#else
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	if (n & 1) cout << "black" << endl;
	else {
		cout << "white" << endl;
		cout << "1 2" << endl;
	}
}



