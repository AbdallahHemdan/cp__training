// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define IO                                                             \
    ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), \
        cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }
double distance(double x1, double y1, double x2, double y2) {
    return hypot(fabs(x1 - x2), fabs(y1 - y2));
}
int comp_double(double a, double b) {
    if (fabs(a - b) <= EPS) return 0;  // equal
    return (a < b) ? -1 : 1;
}

using cell = pair<int, int>;

const int N = 1e3 + 13;
int n, m;
char g[N][N];
cell part[N][N];
int dist[N][N];

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m &&
            (g[i][j] == '.' || g[i][j] == 'B'));
}

int main() {
    IO;
#ifndef ONLINE_JUDGE
    freopen("In.txt", "r", stdin);
#else
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
#endif
    cin >> n >> m;

    cell s, e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                s = {i, j};
            }
            if (g[i][j] == 'B') {
                e = {i, j};
            }
        }
    }

    queue<cell> q;
    q.push(s);

    memset(dist, -1, sizeof(dist));
    memset(part, -1, sizeof(part));
    dist[s.first][s.second] = 0;
    bool ok = true;
    while (!q.empty() && ok) {
        cell u = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = u.first + dx[k];
            int ny = u.second + dy[k];

            if (valid(nx, ny)) {
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[u.first][u.second] + 1;
                    part[nx][ny] = {u.first, u.second};

                    q.push({nx, ny});
                    if (e.first == nx && e.second == ny) {
                        ok = false;
                        break;
                    }
                }
            }
        }
    }

    map<pair<int, int>, string> direction;
    direction[{1, 0}] = "U";
    direction[{0, 1}] = "L";
    direction[{-1, 0}] = "D";
    direction[{0, -1}] = "R";

    if (!ok) {
        string ret;
        cout << "YES" << endl;
        cout << dist[e.first][e.second] << endl;
        while (e.first != -1 && e.second != -1) {
            int nx = part[e.first][e.second].first - e.first;
            int ny = part[e.first][e.second].second - e.second;
            ret += direction[{nx, ny}];

            e = part[e.first][e.second];
        }
        reverse(all(ret));
        cout << ret << endl;
    } else {
        cout << "NO" << endl;
    }
}