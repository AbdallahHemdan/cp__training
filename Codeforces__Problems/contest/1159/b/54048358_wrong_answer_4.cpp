#include <bits\stdc++.h>
using namespace std;
int main() {
	int n; cin >> n; 
	vector<int> Arr(n); 
	for (int i = 0; i < n; i++) cin >> Arr[i]; 
	int mini = min(Arr[0], Arr[n - 1]); 
	if (mini < (n - 1)) cout << 0 << endl;
	else cout << mini / (n - 1) << endl;
}