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
    int n,k; cin >> n >> k;
    unordered_set<int> st;
    deque<int> dq;
    int cnt = 0 ;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        if(st.count(x)) {
            continue;
        }
        if(dq.size() < k){
          dq.push_front(x);
          st.insert(x);
        }else{
            int u = dq.back();
            st.erase(u);
            dq.pop_back();
            dq.push_front(x);
            st.insert(x);
        }
    }
    cout << dq.size() << endl;
    for(auto i : dq) cout << i << ' ' ;
    cout << endl;
}
