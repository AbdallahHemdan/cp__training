#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define in insert
#define f first
#define s second

const int oo = 1e9;
const int N = 1e5 + 10;

int t, n, m, in[N], x, y;
vector<int> ver[N];
int seg[N << 3], lazy[N << 4];
priority_queue<int> pq;
int cur;

void propgate(int p, int lf, int rt) {
  seg[lf] += lazy[p];
  seg[rt] += lazy[p];
  lazy[lf] += lazy[p];
  lazy[rt] += lazy[p];
  lazy[p] = 0;
}

void Build(int ind = 0, int l = 1, int r = n) {
  if (l == r) {
    seg[ind] = in[l], lazy[ind] = 0;
    return;
  }
  int mid = l + ((r - l) >> 1);
  Build((ind << 1) + 1, l, mid);
  Build((ind << 1) + 2, mid + 1, r);
  seg[ind] = min(seg[(ind << 1) + 1], seg[(ind << 1) + 2]);
  lazy[ind] = 0;
}

void Update(int qx, int qy, int qv, int ind = 0, int l = 1, int r = n) {
  propgate(ind, (ind << 1) + 1, (ind << 1) + 2);
  if (l > qy || r < qx) return;
  if (l >= qx && r <= qy) {
    lazy[ind] = qv;
    seg[ind] += qv;
    propgate(ind, (ind << 1) + 1, (ind << 1) + 2);
    return;
  }
  int mid = l + ((r - l) >> 1);
  Update(qx, qy, qv, (ind << 1) + 1, l, mid);
  Update(qx, qy, qv, (ind << 1) + 2, mid + 1, r);
  seg[ind] = min(seg[(ind << 1) + 1], seg[(ind << 1) + 2]);
}

void getAns(int ind = 0, int l = 1, int r = n) {
  propgate(ind, (ind << 1) + 1, (ind << 1) + 2);
  if (seg[ind]) return;
  if (l == r) {
    pq.push(l), seg[ind] = oo;
    return;
  }
  int mid = l + ((r - l) >> 1);
  getAns((ind << 1) + 1, l, mid);
  getAns((ind << 1) + 2, mid + 1, r);
  seg[ind] = min(seg[(ind << 1) + 1], seg[(ind << 1) + 2]);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) in[i] = i - 1, ver[i].clear();
    while (m--) scanf("%d%d", &x, &y), --in[y], ver[x].pb(y);
    Build();
    getAns();
    while (pq.size()) {
      cur = pq.top(), pq.pop();
      if (cur + 1 <= n) Update(cur + 1, n, -1);
      for (auto& e : ver[cur]) Update(e, e, 1);
      getAns();
      printf("%d%c", cur, " \n"[pq.empty()]);
    }
  }
}

/*
3
3 2
1 3
2 3
4 0
4 2
1 2
1 3
 */
