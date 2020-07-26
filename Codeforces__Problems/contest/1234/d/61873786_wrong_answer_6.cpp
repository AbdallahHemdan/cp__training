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

set<char> st[1000];
int main() {
	IO;
#ifndef ONLINE_JUDGE
freopen("In.txt", "r", stdin);
#else
// freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
    string s; cin >> s;
    for(int i=0 ; i< s.sz ; i++){
        st[s[i] - 'a'].insert(i);
    }
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 2){
            int l,r; cin >> l >> r;
            l--,r--;
            int cnt = 0;
            for(int i=0 ; i < 26 ; i++){
                auto it = st[i].lower_bound(l);
                if(it != st[i].end() && *it <= r){
                    cnt++;
                }
            }
            cout << cnt << endl;
        }else{
            int ind;char c;
            cin >> ind >> c;
            st[s[ind - 1] - 'a'].erase(ind - 1);
            s[ind - 1] = c;
            st[c - 'a'].insert(ind - 1);
        }
    }

}
