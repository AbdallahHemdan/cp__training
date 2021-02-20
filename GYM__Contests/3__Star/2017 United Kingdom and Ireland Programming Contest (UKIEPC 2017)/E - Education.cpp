// Author : Abdallah Hem
// Created : Server time: Sep/16/2019 20:23:57UTC+2 (e2).
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits\stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
using namespace std;
using ll = long long int;
using ld = long double;

const int N = 5e3 + 53;
pair<int, int> dep[N];
struct nw_Building {
  int indx, cap, cst;
  bool operator<(const nw_Building& b) {
    if (cap == b.cap) return cst < b.cst;
    return cap < b.cap;
  }
} bul[N];
bool vis[N];
int out[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
#else
  // freopen("input.in","r",stdin);
  // freopen("output.out","w",stdout);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> dep[i].first;
    dep[i].second = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> bul[i].cap;
  }
  for (int i = 0; i < m; i++) {
    cin >> bul[i].cst;
    bul[i].indx = i;
  }
  sort(dep, dep + n);
  reverse(dep, dep + n);
  for (int i = 0; i < n; i++) {
    int mnCst = 1e9;
    int ans = -1;
    for (int j = 0; j < m; j++) {
      if (dep[i].first <= bul[j].cap && !vis[j] && mnCst > bul[j].cst) {
        ans = j;
        mnCst = bul[j].cst;
      }
    }
    if (~ans) {
      out[dep[i].second] = ans;
      vis[ans] = 1;
    } else
      return puts("impossible");
  }
  for (int i = 0; i < n; i++) cout << out[i] + 1 << ' ';
  puts("");
}
