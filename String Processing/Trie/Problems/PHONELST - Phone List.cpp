// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
using ll = long long int;

const int ALPHA = 10;
const int N = 1e5 + 15;

string s;
char cstr[12];

int trie[N][ALPHA];         // The trie.
int nodesCount;             // The number of nodes in the trie.
int distinctWordsCount;     // The number of distinct word in the trie.
int wordsCount[N];          // Number of words sharing node "i"
int wordsEndCount[N];       // Number of words ending at node "i"

/**
 * Initializes the trie.
 * Must be called before each test case.
 */
void init() {
  nodesCount = 0;
  distinctWordsCount = 0;
  memset(trie, -1, sizeof(trie));
  memset(wordsCount, 0, sizeof(wordsCount));
  memset(wordsEndCount, 0, sizeof(wordsEndCount));
}

/**
 * Outs a new edge from the given node if not exists.
 *
 * @param id the node id to out the edge from
 * @param c  the type (or the character) of the edges.
 *
 * @return the id of the node following the added edge.
 */
int addEdge(int id, char c) {
  int &nxt = trie[id][c];
  if (nxt == -1) {
    nxt = ++nodesCount;
  }
  return nxt;
}

/**
 * Inserts a new word in the trie.
 *
 * Complexity: O(n)
 *
 * @param str the word to insert.
 */
bool insert(const char *str) {
  int cur = 0;

  for (int i = 0; str[i]; ++i) {
    wordsCount[cur]++;
    cur = addEdge(cur, char(str[i] - '0'));

    if (wordsEndCount[cur]) {
      return true;
    }
  }
  wordsCount[cur]++;
  distinctWordsCount += (++wordsEndCount[cur] == 1);

  for (int i = 0; i < ALPHA; i++) if (trie[cur][i] != -1) return true;
  return false;
}

int main() {
  IO;
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);
#else
  // freopen("input.in","r",stdin);
  // freopen("output.out","w",stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    init();
    int n;
    cin >> n;

    bool hasPrefix = false;
    vector<string> a(n);
    for (string &i : a) cin >> i;

    for (int i = 0; i < n; i++) {
      strcpy(cstr, a[i].c_str());

      hasPrefix |= insert(cstr);;
    }

    if (hasPrefix) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
} 