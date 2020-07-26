#include <bits\stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s; 
	int sum = 0; 
	for (auto i : s) {
		if (i == '+') sum++;
		else sum--;
		sum = max(0, sum);
	}
	cout << sum << endl;
}