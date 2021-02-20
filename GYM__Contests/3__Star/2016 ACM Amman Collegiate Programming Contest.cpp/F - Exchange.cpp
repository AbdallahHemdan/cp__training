#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define in insert
#define f first
#define s second

const int N = 1e5 + 10;
int t, n;
char reff[30];
int oc[30];
char s[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < 26; ++i) reff[i] = i + 'a', oc[i] = -1;
    for (int i = n - 1; ~i; --i) oc[s[i] - 'a'] = i;
    for (int i = 0; i < n; ++i) {
      bool f = 0;
      for (int j = 0; j < s[i] - 'a'; ++j)
        if (oc[j] > oc[s[i] - 'a']) {
          swap(reff[s[i] - 'a'], reff[j]);
          f = 1;
          break;
        }
      if (f) break;
    }
    for (int i = 0; i < n; ++i) s[i] = reff[s[i] - 'a'];
    printf("%s\n", s);
  }
}
/*
3
hamza
racecar
mca
 */
