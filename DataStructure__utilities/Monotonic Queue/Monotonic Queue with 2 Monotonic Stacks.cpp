#include <bits/stdc++.h>
using namespace std;

using sdata = int;

struct monotonicStack {
  stack<pair<sdata, sdata>> st;  // pair<val, mx>

  void push(const sdata& a) {
    if (st.empty()) {
      st.emplace(a, a);
    } else {
      st.emplace(a, ::max(st.top().second, a));
    }
  }

  void pop() { st.pop(); }

  size_t size() { return st.size(); }

  bool empty() { return st.empty(); }

  const sdata& top() { return st.top().first; }

  const sdata& max() { return st.top().second; }
};

/***
 * notes in monotonic Queue
 * 1. each element in the Queue
 *  1.1 enter add
 *  1.2 enter rmv
 *  1.3 go out
 */

struct monotonicQueue {
  monotonicStack add;
  monotonicStack rmv;

  void push(const sdata& a) { add.push(a); }

  void updateRMV() {
    if (rmv.size()) return;
    while (add.size()) {
      rmv.push(add.top());
      add.pop();
    }
  }

  void pop() {
    updateRMV();
    rmv.pop();
  }

  size_t size() { return add.size() + rmv.size(); }

  bool empty() { return add.empty() && rmv.empty(); }

  const sdata& front() {
    updateRMV();
    return rmv.top();
  }

  const sdata& max() {
    if (!add.size()) return rmv.max();
    if (!rmv.size()) return add.max();
    return ::max(add.max(), rmv.max());
  }
};

int main() {
  int n;
  cin >> n;

  monotonicQueue q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    q.push(x);
    cout << "MAX : " << q.max() << endl;
    cout << "Front : " << q.front() << endl;
  }

  while (!q.empty()) {
    cout << "MAX : " << q.max() << endl;
    cout << "Front : " << q.front() << endl;
    q.pop();
  }
}
