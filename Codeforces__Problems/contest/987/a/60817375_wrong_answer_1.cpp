#include <bits/stdc++.h>
using namespace std;
int main() {
	map<string, string> mp;
	mp["purple"] = "Power"; 
	mp["green"] = "Time";
	mp["blue"] = "Space";
	mp["orange"] = "Soul";
	mp["red"] = "Reality";
	mp["purple"] = "Mind";

	map<string, int> frq;
	int n; cin >> n; 
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		frq[s] = 1;
	}
	cout << 6 - frq.size() << endl;
	for (auto i : mp) {
		if (!frq[i.first]) cout << i.second << endl;
	}
}
