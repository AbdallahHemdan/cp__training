// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define endl '\n'
#define all(v) ((v).begin()), ((v).end())

using namespace std;
const int N = 1e6 + 6;

string p;
int F[N];

int failure(char c, int k) {
  while (k > 0 && c != p[k]) {
    k = F[k - 1];
  }

  return k + (c == p[k]);
}

void computeFailure() {
  int k = 0;
  for (int i = 1; i < p.size(); i++) {
    k = F[i] = failure(p[i], k);
  }
}

/**
 * (1) to get longest suffix that is palindrome
 *
 * 1. Create a new string S = reverse(p) + "|" + p
 * 2. Get prefix (Failure) function of the new String (S)
 * 3. Longest suffix palindrome = F[S.size() - 1]
 *
 * e.g.
 * p = abcdeffe
 * S = effedcba|abcdeffe
 * F = 00010000000001234
 *
 * Longest suffix palindrome = F[S.size() - 1] = 4
 **/
int longestSuffixPal(const string &a) {
  string s = a;
  reverse(all(s));
  p = s + "|" + a;
  computeFailure();

  int n = p.size();
  return F[n - 1];
}

/**
 * (2) to get longest prefix that is palindrome
 *
 * 1. Create a new string S = p + "|" + reverse(p)
 * 2. Get prefix (Failure) function of the new String (S)
 * 3. Longest prefix palindrome = F[S.size() - 1]
 *
 * e.g.
 * p = abcbafgha
 * S = abcbafgha|aghfabcba
 * F = 0000100010100012345
 *
 * Longest prefix palindrome = F[S.size() - 1] = 5
 **/
int longestPrefixPal(const string &a) {
  string s = a;
  reverse(all(s));
  p = a + "|" + s;
  computeFailure();

  int n = p.size();
  return F[n - 1];
}

int main() {
  string a;
  cin >> a;

  int suffixPal = longestSuffixPal(a);
  cout << suffixPal << endl;
  cout << a.substr(a.size() - suffixPal, suffixPal) << endl;

  int prefixPal = longestPrefixPal(a);
  cout << prefixPal << endl;
  cout << a.substr(0, prefixPal) << endl;
}