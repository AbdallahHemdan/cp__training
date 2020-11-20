vector<int> rotLeft(vector<int> a, int d) {
  int n = a.size();
  int nxt = n - d;

  vector<int> ret(n);
  for (int i = 0; i < n; i++) {
    ret[(i + nxt) % n] = a[i];
  }

  return ret;
}