// Author : Abdallah Hemdan
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
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
    int n; cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i % j == 0){
                if(i * j > n){
                    if(i / j < n){
                        cout  << i << ' ' << j << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout  << -1 << endl;

}
