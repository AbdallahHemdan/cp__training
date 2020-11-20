class Solution {
public:
  bool isSubsequence(string s, string t) {
    int n = s.size();
    int l = -1;
    for (int i = 0; i < n; i++) {
      l = t.find(s[i], l + 1);
      if (l == string::npos) {
        return false;
      }
    }

    return true;
  }
};
