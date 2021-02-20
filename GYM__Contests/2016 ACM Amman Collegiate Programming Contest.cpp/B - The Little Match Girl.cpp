#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define in insert
#define f first
#define s second
#define sc(x) scanf("%d", &x)
const int N = 100100;
int n, m, indeg[N];
int mp[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
char tmp[N];

int main() {
  int t;
  sc(t);
  while (t--) {
    int n;
    sc(n);
    scanf("%s", tmp);
    string s = tmp;
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += mp[s[i] - '0'];

    for (int i = 0; i < n; i++) {
      for (int j = 9; j >= 0; j--) {
        ll hem = sum - mp[j];
        if (hem >= 2 * (n - i - 1)) {
          if (hem <= 7 * (n - i - 1)) {
            s[i] = j + '0';
            sum -= mp[j];
            break;
          }
        }
      }
    }
    printf("%s\n", s.c_str());
  }
}
/*
2
2 2 >^<v>^^<v
3 4 >^<^vv<>v<<v

3
3 2
1 3
2 3
4 0
4 2
1 2
1 3

*/
