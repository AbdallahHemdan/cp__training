// Author : Abdallah Hemdan
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
using ll = long long int;
using ld = long double;


int main(){
	IO;
	int a,b; cin >> a >> b;
	if(a == 9 && b == 1) cout << "90 100" << endl;
	else{
		if(abs(a - b) > 1) cout << -1 << endl;
		else {
			if(a == b) cout << a*10 + 1 << ' ' << b * 10  + 2 << endl;
			else cout << a * 10 + 9 << ' ' << b * 10 + 0 << endl;
		}
	}
}

