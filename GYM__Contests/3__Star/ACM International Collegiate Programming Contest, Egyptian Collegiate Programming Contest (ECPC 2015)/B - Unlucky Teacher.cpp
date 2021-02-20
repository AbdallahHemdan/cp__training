#include <algorithm>
#include <cmath>
#include <cstring>  // getline
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>  //stringstream
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
#define ll long long int
#define FOR(i, init, n) for (int i = init; i < n; i++)
#define EPS 1e-9
#define all(v) v.begin(), v.end()
#define X first
#define Y second
#define IO                           \
  std::ios_base::sync_with_stdio(0); \
  cin.tie(NULL);
#define MAXI 100005
#define endl '\n'
#define re return
#define mp make_pair
#define NumofDigits(n) ((int)log10(n) + 1)
#define fixedpre(n) fixed << setprecision(n);

using namespace std;

ll pw(ll b, ll p) {
  if (!p) re 1;
  ll sq = pw(b, p / 2);
  sq *= sq;
  if (p % 2) sq *= b;
  re sq;
}
ll gcd(ll a, ll b) { re(b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { re((a * b) / gcd(a, b)); }
bool cmp(double a, double b) { re abs(a - b) < EPS; }
bool isint(double a) { re cmp(a, round(a)); }

const double PI = acos(-1);
ll OO = 1e18 + 8;
int oo = 1e9 + 9;

// freopen("input.txt", "r", stdin);
// freopen ("output.txt","w",stdout);

int dx[6] = {1, -1, 0, 0, 0, 0}, dy[6] = {0, 0, 1, -1, 0, 0},
    dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
  IO;
  int t, m, q;
  cin >> t;
  char a, f;
  while (t--) {
    vector<vector<int>> res(102, vector<int>(4));
    cin >> q >> m;
    FOR(i, 0, m) {
      FOR(j, 0, q) {
        // 1 means false
        cin >> a >> f;
        if (res[j][a - 'A'] == 2) continue;

        if (f == 'F')
          res[j][a - 'A'] = 1;
        else
          res[j][a - 'A'] = 2;
      }
    }
    FOR(i, 0, q) {
      if (res[i][0] == 2)
        cout << "A";
      else if (res[i][1] == 2)
        cout << "B";
      else if (res[i][2] == 2)
        cout << "C";
      else if (res[i][3] == 2)
        cout << "D";
      else {
        int counter = 0;
        FOR(j, 0, 4)
        if (res[i][j] == 1) counter++;
        if (counter == 3) {
          FOR(j, 0, 4)
          if (res[i][j] == 0) cout << (char)(j + 'A');
        } else
          cout << "?";
      }
      if (i != q - 1) cout << ' ';
    }
    if (t != 0) cout << endl;
  }
  re 0;
}
