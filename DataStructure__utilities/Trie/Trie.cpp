const int ALPHA = 255;
const int N = 1e5 + 15;

int trie[N][ALPHA];
int nodesCount;
int distinctWordsCount;
int wordsCount[N];
int wordsEndCount[N];

void init() {
  nodesCount = 0;
  memset(trie, -1, sizeof(trie));
}

int addEdge(int id, char c) {
  int &nxt = trie[id][c];
  if (nxt == -1) {
    nxt = ++nodesCount;
  }
  return nxt;
}

void insert(const char *str) {
  int cur = 0;
  for (int i = 0; str[i]; i++) {
    wordsCount[cur]++;
    cur = addEdge(cur, str[i]);
  }

  wordsCount[cur]++;
  distinctWordsCount += (++wordsEndCount[cur] == 1);
}

void erase(const char *str) {
  int cur = 0;
  for (int i = 0; str[i]; i++) {
    wordsCount[cur]--;

    int nxt = trie[cur][str[i]];
    if (wordsCount[nxt] == 1) {
      trie[cur][str[i]] = -1;
    }
    cur = nxt;
  }
  wordsCount[cur]--;
  distinctWordsCount -= (--wordsEndCount[cur] == 0);
}

int search(const char *str) {
  int cur = 0;
  for (int i = 0; str[i]; i++) {
    int nxt = trie[cur][str[i]];

    if (nxt == -1) {
      return 0;
    }
    cur = nxt;
  }
  return wordsEndCount[cur];
}

int searchPrefix(const char *str) {
  int cur = 0;
  for (int i = 0; str[i]; i++) {
    int nxt = trie[cur][str[i]];

    if (nxt == -1) {
      return 0;
    }
    cur = nxt;
  }
  return wordsCount[cur];
}
