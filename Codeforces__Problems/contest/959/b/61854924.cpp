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

const int maxn = 1e5 + 15;
int gcst[maxn];
int cst[maxn];
string a[maxn];
map<string,int> gr;
int main() {
	IO;
#ifndef ONLINE_JUDGE
freopen("In.txt", "r", stdin);
#else
// freopen("input.in","r",stdin);
// freopen("output.out","w",stdout);
#endif
    int n,k,m; cin >> n >> k >> m;
    for(int i=0 ; i <n ; i++){
        cin >> a[i];
    }
    for(int i=0;  i<n ; i++){
        cin >> cst[i];
    }
    for(int i=0 ; i<k ;i++){
        gcst[i] = INT_MAX;
        int g; cin >> g;
        while(g--){
            int x; cin >> x;
            x--;
            gcst[i] = min(cst[x],gcst[i]);
            gr[a[x]] = i;
        }
    }
    ll ans = 0;
    for(int i=0 ; i<m; i++){
        string s; cin >> s;
        ans += gcst[gr[s]];
    }
    cout  << ans << endl;
}
