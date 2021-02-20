#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

#define f first
#define s second
#define sz(x) (int)(x).size()
#define em empty()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define mem(a, b, s) \
  for (int i = 0; i <= s; ++i) a[i] = b;
#define mem2(a, r, c, b)       \
  for (int i = 0; i <= r; ++i) \
    for (int j = 0; j <= c; ++j) a[i][j] = b;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mp make_pair
#define in insert
#define sc(x) scanf("%d", &(x))
#define scl(a) scanf("%lld", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define rep(x, a, b) for (auto x = a; x <= b; ++x)
#define irep(x, a, b) for (auto x = a; x >= b; --x)
#define cross(a, b) ((conj(a) * (b)).imag())
#define debug(x) cerr << #x << " is " << x << endl;
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define polar(r, t) ((r)*exp(point(0, (t))))
#define angle(v) (atan2((v).Y, (v).X))
#define length(v) ((long double)hypot((v).Y, (v).X))
#define lengthSqr(v) (dot(v, v))
#define dot(a, b) ((conj(a) * (b)).real())
#define cross(a, b) ((conj(a) * (b)).imag())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int> > vii;
typedef set<int> si;
typedef set<pair<int, int> > sii;
typedef map<int, int> mii;
typedef pair<int, char> ic;
typedef pair<int, string> is;
typedef long double ld;
typedef priority_queue<ii> pqii;
typedef priority_queue<int> pqi;
typedef string BIGINT;
typedef complex<long double> point;

const long double pi = acos(-1);
const long double EPS = 1e-9;
const int MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;
const int oo = 2e9 + 10;
const ll OO = 1e18;

int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

int n, m, a[MAXN], x, y, col, cnt;
map<int, int> f;
bool flag;

int main() {
//	srand(time(0));
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("In.txt", "r", stdin);
//	freopen("Out.txt","w",stdout);
#else
//	freopen("stations.in","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d", a + i);
    if (!f[a[i]]) ++col;
    f[a[i]]++;
  }
  scanf("%d", &m);
  if (col == 1) flag = 1, cnt = 0;
  while (m--) {
    scanf("%d%d", &x, &y);
    if (flag) continue;
    ++cnt;
    f[a[x]]--;
    if (!f[a[x]]) --col;
    a[x] = y;
    if (!f[a[x]]) ++col;
    f[a[x]]++;
    if (col == 1) flag = 1;
  }
  if (!flag) cnt = -1;
  printf("%d\n", cnt);
}
