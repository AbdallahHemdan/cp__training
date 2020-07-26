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
    ll n,k; cin >> n >> k;
    set<ll> st;
    for(ll i=0 ; i < n ; i++){
        ll x; cin >> x;
        st.insert(x);
    }
    auto it = st.begin();
    ll sm = 0;
    while(k--){
        if(it == st.end()) cout  << 0 << endl;
        else {
            cout  << (*it) - sm << endl;
            sm += ((*it) - sm);
            it++;
        }
    }
}
