// Author : Abdallah Hemdan
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
using namespace std;
using ll = long long int;
using ld = long double;


int main() {
	IO;
#ifndef ONLINE_JUDGE
freopen("In.txt", "r", stdin);
#else
// freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
	int n;cin >> n;
	if(n < 6) cout  << -1 << endl;
	else {
		for(int i= 2 ; i <= 4 ; i++) cout  << "1 " << i << endl;
		for(int i = 5 ; i<=n ; i++) cout  << "2 " << i << endl;
	}
	for(int i = 2 ; i<=n ; i++) cout  << "1 " << i << endl;
}