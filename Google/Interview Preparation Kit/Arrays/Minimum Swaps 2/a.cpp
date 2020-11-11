int minimumSwaps(vector<int> a) {
  int n = a.size();
  map<int, int> valIndex;

  for (int i = 0; i < n; i++) {
    valIndex[a[i]] = i;
  }

  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != i + 1) {
      ret++;

      int x = a[i];
      int aIndex = valIndex[i + 1];

      a[aIndex] = a[i];
      a[i] = i + 1;

      valIndex[i + 1] = i;
      valIndex[x] = aIndex;
    }
  }

  return ret;
}
