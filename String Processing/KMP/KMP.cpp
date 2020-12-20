#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;

/**
 * Verified : https://www.spoj.com/problems/NAJPF/
 * https://cses.fi/problemset/task/1753/
 **/

int F[N]; // KMP longest match array.
string s, p; // original string and patter string
vector<int> matches; // array of indices of matching of pattern

/**
 * KMP failure function.
 *
 * @param c the current char.
 * @param k the length of the longest suffix ending at the previous character
 *            matching a prefix of the pattern.
 *
 * @return the length of the longest suffix ending the given character matching a prefix of the pattern.
 */
int failure(char c, int k) {
  while (k > 0 && p[k] != c) k = F[k - 1];
  return (k += (p[k] == c));
}

/**
 * Computes the length of the longest suffix ending at the i-th character
 * that match a prefix of the string, and fills the results in the global "F" array.
 *
 * Complexity: O(n)
 *
 */
void computeFailure() {
  int k = 0;
  for (int i = 1; i < p.size(); i++) {
    k = F[i] = failure(p[i], k);
  }
}

void KMP() {
  computeFailure();

  int k = 0;

  for (int i = 0; i < s.size(); i++) {
    k = failure(s[i], k);
    if (k == p.size()) {
      matches.push_back(i - k + 1); // noOfMatches  = the occurrence vector length
    }
  }
}


int main() {
  cin >> s >> p;

  KMP();
  cout << matches.size() << endl;
}